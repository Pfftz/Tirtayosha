import numpy as np
import time


def generate_matrices(rows, cols):
    return np.random.rand(rows, cols)


def normal_matrix_multiply(matrix1, matrix2):
    return np.dot(matrix1, matrix2)


def strassen_multiply(matrix1, matrix2):
    if min(matrix1.shape) <= 64:
        return np.dot(matrix1, matrix2)

    rows1, cols1 = matrix1.shape
    rows2, cols2 = matrix2.shape

    if cols1 != rows2:
        raise ValueError(
            "Matrices dimensions are not compatible for multiplication")

    n = max(rows1, cols1, cols2)
    m = 2 ** int(np.ceil(np.log2(n)))
    matrix1_padded = np.zeros((m, m))
    matrix2_padded = np.zeros((m, m))
    matrix1_padded[:rows1, :cols1] = matrix1
    matrix2_padded[:rows2, :cols2] = matrix2

    if m <= 128:
        return normal_matrix_multiply(matrix1_padded, matrix2_padded)

    else:
        a11 = matrix1_padded[:m//2, :m//2]
        a12 = matrix1_padded[:m//2, m//2:]
        a21 = matrix1_padded[m//2:, :m//2]
        a22 = matrix1_padded[m//2:, m//2:]

        b11 = matrix2_padded[:m//2, :m//2]
        b12 = matrix2_padded[:m//2, m//2:]
        b21 = matrix2_padded[m//2:, :m//2]
        b22 = matrix2_padded[m//2:, m//2:]

        p1 = strassen_multiply(a11 + a22, b11 + b22)
        p2 = strassen_multiply(a21 + a22, b11)
        p3 = strassen_multiply(a11, b12 - b22)
        p4 = strassen_multiply(a22, b21 - b11)
        p5 = strassen_multiply(a11 + a12, b22)
        p6 = strassen_multiply(a21 - a11, b11 + b12)
        p7 = strassen_multiply(a12 - a22, b21 + b22)

        c11 = p1 + p4 - p5 + p7
        c12 = p3 + p5
        c21 = p2 + p4
        c22 = p1 - p2 + p3 + p6

        result_matrix = np.vstack(
            (np.hstack((c11, c12)), np.hstack((c21, c22))))

        return result_matrix[:rows1, :cols2]


def measure_execution_time(matrix_size, multiplication_function):
    matrix1 = generate_matrices(matrix_size[0], matrix_size[1])
    matrix2 = generate_matrices(matrix_size[1], matrix_size[0])

    start_time = time.time()
    multiplication_function(matrix1, matrix2)
    end_time = time.time()

    return end_time - start_time


matrix_sizes = [(1000, 1000), (1000, 2000), (1000, 5000), (10000, 100000)]

for size in matrix_sizes:
    print(f"Ukuran Matrix: {size}")
    print("Perkalian Matrix Umum:", measure_execution_time(
        size[0], normal_matrix_multiply))
    print("Algoritma Strassen's :", measure_execution_time(
        size[0], strassen_multiply))
