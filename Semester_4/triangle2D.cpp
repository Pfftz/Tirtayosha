#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Bersihkan layar
    glBegin(GL_TRIANGLES); // Mulai menggambar segitiga
    glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5, -0.5); // Titik 1
    glColor3f(0.0, 1.0, 0.0); glVertex2f(0.5, -0.5);  // Titik 2
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.0, 0.5);   // Titik 3
    glEnd();
    glFlush(); // Bersihkan buffer
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Segitiga 2D"); // Buat jendela
    glutDisplayFunc(display); // Set fungsi display
    glutMainLoop(); // Mulai loop GLUT
    return 0;
}