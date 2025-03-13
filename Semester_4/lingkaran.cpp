#include <GLFW/glfw3.h>
#include <cmath>

#define PI 3.14159265359
const int numSegments = 100;

void drawCircle(float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(600, 600, "Circle", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawCircle(0.5f);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
