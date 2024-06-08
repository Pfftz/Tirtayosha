#WATERMARK ADMIN Hd
import numpy as np
import multiprocessing as mp
import time

# Create a global Pool object
pool = None
if __name__ == '__main__':
    pool = mp.Pool(processes=7)


def normal_matrix_mult(A, B):
    return np.dot(A, B)


def pad_matrix(A):
    next_power_of_2 = int(2**np.ceil(np.log2(max(A.shape))))
    new_A = np.zeros((next_power_of_2, next_power_of_2))
    new_A[:A.shape[0], :A.shape[1]] = A
    return new_A


def strassen_matrix_mult(A, B):
    if pool is None:
        return normal_matrix_mult(A, B)

    original_shape = A.shape
    A = pad_matrix(A)
    B = pad_matrix(B)

    if len(A) <= 64:
        return normal_matrix_mult(A, B)

    mid = len(A) // 2
    A11, A12, A21, A22 = A[:mid, :mid], A[:mid,
                                          mid:], A[mid:, :mid], A[mid:, mid:]
    B11, B12, B21, B22 = B[:mid, :mid], B[:mid,
                                          mid:], B[mid:, :mid], B[mid:, mid:]

    p1 = pool.apply_async(strassen_matrix_mult, [A11 + A22, B11 + B22])
    p2 = pool.apply_async(strassen_matrix_mult, [A21 + A22, B11])
    p3 = pool.apply_async(strassen_matrix_mult, [A11, B12 - B22])
    p4 = pool.apply_async(strassen_matrix_mult, [A22, B21 - B11])
    p5 = pool.apply_async(strassen_matrix_mult, [A11 + A12, B22])
    p6 = pool.apply_async(strassen_matrix_mult, [A21 - A11, B11 + B12])
    p7 = pool.apply_async(strassen_matrix_mult, [A12 - A22, B21 + B22])

    p1, p2, p3, p4, p5, p6, p7 = p1.get(), p2.get(
    ), p3.get(), p4.get(), p5.get(), p6.get(), p7.get()

    C11 = p1 + p4 - p5 + p7
    C12 = p3 + p5
    C21 = p2 + p4
    C22 = p1 - p2 + p3 + p6

    C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))
    return C[:original_shape[0], :original_shape[1]]


def berhitung_execution_time(matrix_sizes):
    for size in matrix_sizes:
        A = np.random.rand(size[0], size[1])
        B = np.random.rand(size[1], size[0])

        start = time.time()
        normal_matrix_mult(A, B)
        normal_time = time.time() - start

        start = time.time()
        strassen_matrix_mult(A, B)
        strassen_time = time.time() - start

        print(f"Untuk ukuran matriks {size}: \n normal multiplication memakan waktu {
              normal_time} seconds \n Strassen's algorithm memakan waktu {strassen_time} seconds")


if __name__ == '__main__':
    ukuran_sigma = [(700, 700), (1000, 1000), (2000, 2000)]
    print('watermark admin Hd \n')
    berhitung_execution_time(ukuran_sigma)
    print("\n Long Live the Fighter! - Abdulhadi")
