import numpy as np
import time


def standard_matrix_multiplication(A, B):
    return np.dot(A, B)


def strassen_matrix_multiplication(A, B):
    # Implement Strassen's Algorithm here
    def strassen_matrix_multiplication(A, B):
        n = len(A)
    if n == 1:
        return A * B
    else:
        # divide matrices into quarters
        mid = n // 2
        a11, a12, a21, a22 = A[:mid, :mid], A[:mid,
                                              mid:], A[mid:, :mid], A[mid:, mid:]
        b11, b12, b21, b22 = B[:mid, :mid], B[:mid,
                                              mid:], B[mid:, :mid], B[mid:, mid:]

        # calculate p1 to p7
        p1 = strassen_matrix_multiplication(a11 + a22, b11 + b22)
        p2 = strassen_matrix_multiplication(a21 + a22, b11)
        p3 = strassen_matrix_multiplication(a11, b12 - b22)
        p4 = strassen_matrix_multiplication(a22, b21 - b11)
        p5 = strassen_matrix_multiplication(a11 + a12, b22)
        p6 = strassen_matrix_multiplication(a21 - a11, b11 + b12)
        p7 = strassen_matrix_multiplication(a12 - a22, b21 + b22)

        # calculate c11, c12, c21, c22
        c11 = p1 + p4 - p5 + p7
        c12 = p3 + p5
        c21 = p2 + p4
        c22 = p1 - p2 + p3 + p6

        # combine c11, c12, c21, c22
        C = np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22))))

        return C

    # Membuat matriks dengan ordo yang telah disebutkan
matrix_1000x1000 = np.random.rand(1000, 1000)
matrix_1000x2000 = np.random.rand(1000, 2000)
matrix_1000x5000 = np.random.rand(1000, 5000)
matrix_10000x100000 = np.random.rand(10000, 100000)

# Mengukur waktu eksekusi metode perkalian matrix biasa
start_time = time.time()
result_standard = standard_matrix_multiplication(
    matrix_1000x1000, matrix_1000x1000)
end_time = time.time()
execution_time_standard = end_time - start_time

# Mengukur waktu eksekusi metode Strassen's Algorithm
start_time = time.time()
result_strassen = strassen_matrix_multiplication(
    matrix_1000x1000, matrix_1000x1000)
end_time = time.time()
execution_time_strassen = end_time - start_time

print(f"Waktu eksekusi metode perkalian matrix biasa: {
      execution_time_standard:.6f} detik")
print(f"Waktu eksekusi metode Strassen's Algorithm: {
      execution_time_strassen:.6f} detik")
