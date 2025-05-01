#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Velocity
float velocityX = 0.0f;
float velocityY = 0.0f;
float speed = 0.01f; // Adjust for desired speed

// Function to handle keyboard input
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
            velocityY = speed;
            break;
        case GLFW_KEY_DOWN:
            velocityY = -speed;
            break;
        case GLFW_KEY_LEFT:
            velocityX = -speed;
            break;
        case GLFW_KEY_RIGHT:
            velocityX = speed;
            break;
        }
    }
    else if (action == GLFW_RELEASE)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
        case GLFW_KEY_DOWN:
            velocityY = 0.0f;
            break;
        case GLFW_KEY_LEFT:
        case GLFW_KEY_RIGHT:
            velocityX = 0.0f;
            break;
        }
    }
}

int main()
{
    if (!glfwInit())
        return -1;
    GLFWwindow *window = glfwCreateWindow(800, 600, "negro", NULL, NULL);
    if (!window)
        return -1;
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return -1;

    // Register key callback
    glfwSetKeyCallback(window, key_callback);

    float point[] = {0.0f, 0.0f};
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Update point position based on velocity
        point[0] += velocityX;
        point[1] += velocityY;

        // Update VBO with new point position
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(point), point, GL_STATIC_DRAW);

        glBindVertexArray(VAO);
        glPointSize(10.0f);
        glDrawArrays(GL_POINTS, 0, 1);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}