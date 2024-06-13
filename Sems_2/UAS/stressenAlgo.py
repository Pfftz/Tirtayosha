#WATERMARK ADMIN Hd
import numpy as np
import multiprocessing as mp
import time

# buat pool untuk multiprocessing
pool_object = None
if __name__ == '__main__':
    pool_object = mp.Pool(processes=7)


def normalMatrixmult(A, B):
    return np.dot(A, B)


def matrixPadding(A):
    next_power_of_2 = int(2**np.ceil(np.log2(max(A.shape))))
    new_A = np.zeros((next_power_of_2, next_power_of_2))
    new_A[:A.shape[0], :A.shape[1]] = A
    return new_A


def strassenMatrixmult(A, B):
    if pool_object is None:
        return normalMatrixmult(A, B)

    original_shape = A.shape
    A = matrixPadding(A)
    B = matrixPadding(B)

    if len(A) <= 64:
        return normalMatrixmult(A, B)

    pertengahan = len(A) // 2
    A11, A12, A21, A22 = A[:pertengahan, :pertengahan], A[:pertengahan,
                                          pertengahan:], A[pertengahan:, :pertengahan], A[pertengahan:, pertengahan:]
    B11, B12, B21, B22 = B[:pertengahan, :pertengahan], B[:pertengahan,
                                          pertengahan:], B[pertengahan:, :pertengahan], B[pertengahan:, pertengahan:]

    p1 = pool_object.apply_async(strassenMatrixmult, [A11 + A22, B11 + B22])
    p2 = pool_object.apply_async(strassenMatrixmult, [A21 + A22, B11])
    p3 = pool_object.apply_async(strassenMatrixmult, [A11, B12 - B22])
    p4 = pool_object.apply_async(strassenMatrixmult, [A22, B21 - B11])
    p5 = pool_object.apply_async(strassenMatrixmult, [A11 + A12, B22])
    p6 = pool_object.apply_async(strassenMatrixmult, [A21 - A11, B11 + B12])
    p7 = pool_object.apply_async(strassenMatrixmult, [A12 - A22, B21 + B22])

    p1, p2, p3, p4, p5, p6, p7 = p1.get(), p2.get(
    ), p3.get(), p4.get(), p5.get(), p6.get(), p7.get()

    C11 = p1 + p4 - p5 + p7
    C12 = p3 + p5
    C21 = p2 + p4
    C22 = p1 - p2 + p3 + p6

    C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))
    return C[:original_shape[0], :original_shape[1]]


def berhitungExecutiontime(matrix_sizes):
    for size in matrix_sizes:
        A = np.random.rand(size[0], size[1])
        B = np.random.rand(size[1], size[0])

        start = time.time()
        normalMatrixmult(A, B)
        normal_time = time.time() - start

        start = time.time()
        strassenMatrixmult(A, B)
        strassen_time = time.time() - start

        print(f"Untuk ukuran matriks {size}: \n normal multiplication memakan waktu {
              normal_time} seconds \n Strassen's algorithm memakan waktu {strassen_time} seconds")


if __name__ == '__main__':
    ukuran_sigma = [(700, 700), (1000, 1000), (2000, 2000)]
    print('watermark admin Hd \n')
    berhitungExecutiontime(ukuran_sigma)
    print("\n Long Live the Fighter! - Abdulhadi")
