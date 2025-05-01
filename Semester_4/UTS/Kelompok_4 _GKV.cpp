#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
float angle = 0.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void generateOctagon(float* vertices, int vertexCount) {
    float radius = 0.4f;
    for (int i = 0; i < vertexCount; i++) {
        float theta = 2.0f * M_PI * i / vertexCount;
        vertices[i * 2] = cos(theta) * radius;
        vertices[i * 2 + 1] = sin(theta) * radius;
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Sunset Octagon", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // ================== SHADERS ==================
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;
        uniform float angle;
        void main() {
            float s = sin(angle);
            float c = cos(angle);
            mat2 rotation = mat2(c, -s, s, c);
            gl_Position = vec4(rotation * aPos, 0.0, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0, 0.84, 0.0, 1.0); // Keemasan (sun color)
        }
    )";

    const char* bgVertexShaderSrc = R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;
        out vec2 fragPos;
        void main() {
            fragPos = aPos;
            gl_Position = vec4(aPos, 0.0, 1.0);
        }
    )";

    const char* bgFragmentShaderSrc = R"(
        #version 330 core
        in vec2 fragPos;
        out vec4 FragColor;
        void main() {
            float t = (fragPos.y + 1.0) / 2.0;
            vec3 bottomColor = vec3(1.0, 0.5, 0.0);  // Sunset orange
            vec3 topColor = vec3(0.2, 0.0, 0.4);     // Deep purple sky
            FragColor = vec4(mix(bottomColor, topColor, t), 1.0);
        }
    )";

    const char* glowFragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0, 0.84, 0.0, 0.3); // Transparan keemasan
        }
    )";
    
    const char* moonFragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(0.9, 0.9, 1.0, 1.0); // Putih kebiruan
        }
    )";
    

    // ========== Background Shader Compilation ==========
    unsigned int bgVertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(bgVertexShader, 1, &bgVertexShaderSrc, NULL);
    glCompileShader(bgVertexShader);

    unsigned int bgFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(bgFragmentShader, 1, &bgFragmentShaderSrc, NULL);
    glCompileShader(bgFragmentShader);

    unsigned int bgShaderProgram = glCreateProgram();
    glAttachShader(bgShaderProgram, bgVertexShader);
    glAttachShader(bgShaderProgram, bgFragmentShader);
    glLinkProgram(bgShaderProgram);

    glDeleteShader(bgVertexShader);
    glDeleteShader(bgFragmentShader);

    // ========== Octagon Shader Compilation ==========
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // ========== Octagon Geometry ==========
    const int vertexCount = 8;
    float octagonVertices[vertexCount * 2];
    generateOctagon(octagonVertices, vertexCount);

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(octagonVertices), octagonVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // ========== Background Fullscreen Quad ==========
    float bgVertices[] = {
        -1.0f, -1.0f,
         1.0f, -1.0f,
        -1.0f,  1.0f,
         1.0f,  1.0f,
    };

    unsigned int bgVAO, bgVBO;
    glGenVertexArrays(1, &bgVAO);
    glGenBuffers(1, &bgVBO);

    glBindVertexArray(bgVAO);
    glBindBuffer(GL_ARRAY_BUFFER, bgVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bgVertices), bgVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    float glowVertices[vertexCount * 2];
float glowRadius = 0.6f;
for (int i = 0; i < vertexCount; ++i) {
    float theta = 2.0f * M_PI * i / vertexCount;
    glowVertices[i * 2] = cos(theta) * glowRadius;
    glowVertices[i * 2 + 1] = sin(theta) * glowRadius;
}
unsigned int glowVAO, glowVBO;
glGenVertexArrays(1, &glowVAO);
glGenBuffers(1, &glowVBO);
glBindVertexArray(glowVAO);
glBindBuffer(GL_ARRAY_BUFFER, glowVBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(glowVertices), glowVertices, GL_STATIC_DRAW);
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);

float moonVertices[vertexCount * 2];
float moonRadius = 0.1f;
float moonX = 0.6f, moonY = 0.6f; // posisi moon
for (int i = 0; i < vertexCount; ++i) {
    float theta = 2.0f * M_PI * i / vertexCount;
    moonVertices[i * 2] = cos(theta) * moonRadius + moonX;
    moonVertices[i * 2 + 1] = sin(theta) * moonRadius + moonY;
}
unsigned int moonVAO, moonVBO;
glGenVertexArrays(1, &moonVAO);
glGenBuffers(1, &moonVBO);
glBindVertexArray(moonVAO);
glBindBuffer(GL_ARRAY_BUFFER, moonVBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(moonVertices), moonVertices, GL_STATIC_DRAW);
glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);

// Glow Shader
unsigned int glowFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(glowFragmentShader, 1, &glowFragmentShaderSource, NULL);
glCompileShader(glowFragmentShader);
unsigned int glowShaderProgram = glCreateProgram();
glAttachShader(glowShaderProgram, vertexShader); // gunakan vertex shader yg sama
glAttachShader(glowShaderProgram, glowFragmentShader);
glLinkProgram(glowShaderProgram);
glDeleteShader(glowFragmentShader);

// Moon Shader
unsigned int moonFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(moonFragmentShader, 1, &moonFragmentShaderSource, NULL);
glCompileShader(moonFragmentShader);
unsigned int moonShaderProgram = glCreateProgram();
glAttachShader(moonShaderProgram, vertexShader); // gunakan vertex shader yg sama
glAttachShader(moonShaderProgram, moonFragmentShader);
glLinkProgram(moonShaderProgram);
glDeleteShader(moonFragmentShader);


    // ========== Main Loop ==========
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. Background
glUseProgram(bgShaderProgram);
glBindVertexArray(bgVAO);
glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

// 2. Moon
glUseProgram(moonShaderProgram);
glBindVertexArray(moonVAO);
glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);

// 3. Glow (di belakang octagon)
glUseProgram(glowShaderProgram);
glUniform1f(glGetUniformLocation(glowShaderProgram, "angle"), angle);
glBindVertexArray(glowVAO);
glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);

// 4. Octagon
angle += 0.003f;
glUseProgram(shaderProgram);
glUniform1f(glGetUniformLocation(shaderProgram, "angle"), angle);
glBindVertexArray(VAO);
glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
