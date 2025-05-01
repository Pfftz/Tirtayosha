#include <glad/glad.h> // Library untuk memuat fungsi OpenGL
#include <GLFW/glfw3.h> // Library untuk membuat jendela dan menangani input pengguna
#include <iostream> // Digunakan untuk debugging dengan output terminal

int main() {
    // Inisialisasi GLFW
    if (!glfwInit()) return -1;
    
    // Membuat jendela dengan ukuran 800x600 piksel
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Line", NULL, NULL);
    if (!window) return -1; // Jika gagal membuat jendela, keluar dari program
    glfwMakeContextCurrent(window); // Menggunakan konteks OpenGL pada jendela ini
    
    // Memuat fungsi OpenGL menggunakan GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return -1;
    
    // Mendefinisikan koordinat dua titik yang membentuk garis
    float line[] = {
        -0.5f, -0.5f, // Titik awal (kiri bawah)
         0.5f,  0.5f   // Titik akhir (kanan atas)
    };
    
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO); // Membuat VAO (Vertex Array Object)
    glGenBuffers(1, &VBO); // Membuat VBO (Vertex Buffer Object)
    
    glBindVertexArray(VAO); // Mengaktifkan VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // Mengaktifkan VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW); // Mengisi buffer dengan data koordinat garis
    
    // Menentukan bagaimana data vertex dibaca
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // Mengaktifkan atribut vertex

    // Loop utama untuk menggambar garis
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar sebelum menggambar
        glBindVertexArray(VAO); // Menggunakan VAO yang sudah dikonfigurasi
        glLineWidth(2.0f); // Menentukan ketebalan garis
        glDrawArrays(GL_LINES, 0, 2); // Menggambar garis dari titik 0 ke titik 1
        glfwSwapBuffers(window); // Menampilkan hasil gambar di layar
        glfwPollEvents(); // Mengecek input pengguna
    }
    
    // Membersihkan resource sebelum keluar
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate(); // Mengakhiri GLFW
    return 0; // Program selesai dengan sukses
}