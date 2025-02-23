#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Clear color (black)
    glEnable(GL_DEPTH_TEST);          // Enable depth testing
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);           // Set viewport to window dimensions
    glMatrixMode(GL_PROJECTION);      // Switch to the projection matrix
    glLoadIdentity();                 // Reset the projection matrix
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);       // Switch back to modelview
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity();                                   // Reset the modelview matrix
    glTranslatef(0.0f, 0.0f, -5.0f);                      // Move the cube into view
    glRotatef(25, 1.0f, 1.0f, 0.0f);                     // Rotate cube for better 3D effect

    glBegin(GL_QUADS);
        // Front face (red)
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f( 0.5,  0.5,  0.5);
        glVertex3f(-0.5,  0.5,  0.5);

        // Back face (green)
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5);

        // Left face (blue)
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f(-0.5,  0.5,  0.5);
        glVertex3f(-0.5,  0.5, -0.5);

        // Right face (yellow)
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5, -0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f( 0.5,  0.5,  0.5);

        // Top face (cyan)
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-0.5,  0.5,  0.5);
        glVertex3f( 0.5,  0.5,  0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);

        // Bottom face (magenta)
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f(-0.5, -0.5,  0.5);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("3D Cube using GLUT");

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}