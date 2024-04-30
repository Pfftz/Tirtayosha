import numpy as np
import time


def normal_matrix_mult(A, B):
    return np.dot(A, B)


def pad_matrix(A):
    next_power_of_2 = int(2**np.ceil(np.log2(max(A.shape))))
    new_A = np.zeros((next_power_of_2, next_power_of_2))
    new_A[:A.shape[0], :A.shape[1]] = A
    return new_A


def strassen_matrix_mult(A, B):
    original_shape = A.shape
    A = pad_matrix(A)
    B = pad_matrix(B)

    # Use the standard matrix multiplication method for small matrices
    if len(A) <= 128:
        return normal_matrix_mult(A, B)

    mid = len(A) // 2
    A11, A12, A21, A22 = A[:mid, :mid], A[:mid,
                                          mid:], A[mid:, :mid], A[mid:, mid:]
    B11, B12, B21, B22 = B[:mid, :mid], B[:mid,
                                          mid:], B[mid:, :mid], B[mid:, mid:]

    p1 = strassen_matrix_mult(A11 + A22, B11 + B22)
    p2 = strassen_matrix_mult(A21 + A22, B11)
    p3 = strassen_matrix_mult(A11, B12 - B22)
    p4 = strassen_matrix_mult(A22, B21 - B11)
    p5 = strassen_matrix_mult(A11 + A12, B22)
    p6 = strassen_matrix_mult(A21 - A11, B11 + B12)
    p7 = strassen_matrix_mult(A12 - A22, B21 + B22)

    C11 = p1 + p4 - p5 + p7
    C12 = p3 + p5
    C21 = p2 + p4
    C22 = p1 - p2 + p3 + p6

    C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))
    return C[:original_shape[0], :original_shape[1]]


def calculate_execution_time(matrix_sizes):
    for size in matrix_sizes:
        A = np.random.rand(size[0], size[1])
        B = np.random.rand(size[1], size[0])  # Changed this line

        start = time.time()
        normal_matrix_mult(A, B)
        normal_time = time.time() - start

        start = time.time()
        strassen_matrix_mult(A, B)
        strassen_time = time.time() - start

        print(f"For matrix size {size}, normal multiplication took {
              normal_time} seconds, Strassen's algorithm took {strassen_time} seconds")


matrix_sizes = [(1000, 1000), (1000, 2000), (1000, 5000), (10000, 100000)]
calculate_execution_time(matrix_sizes)
