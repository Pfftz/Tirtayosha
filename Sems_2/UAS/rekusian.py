#watermark Abdulhadi
# Import library
import time

def val_kecil(x, y):
    return x if x <= y else y

def fibonacci_skibidi(arroy, x, n):
    if n > 0:
        fibMMm2 = 0
        fibMMm1 = 1
        fibM = fibMMm2 + fibMMm1

        while (fibM < n):
            fibMMm2 = fibMMm1
            fibMMm1 = fibM
            fibM = fibMMm2 + fibMMm1

        fibonacciaOffset = -1

        while (fibM > 1):
            i = val_kecil(fibonacciaOffset+fibMMm2, n-1)

            if (arroy[i] < x):
                fibM = fibMMm1
                fibMMm1 = fibMMm2
                fibMMm2 = fibM - fibMMm1
                fibonacciaOffset = i
            elif (arroy[i] > x):
                fibM = fibMMm2
                fibMMm1 = fibMMm1 - fibMMm2
                fibMMm2 = fibM - fibMMm1
            else:
                return i

        if (fibMMm1 and arroy[fibonacciaOffset+1] == x):
            return fibonacciaOffset+1

        return -1
    else:
        return -1

# Recursive function for recursive search
def recursive_cari(arroy, x, y, z):
    if y >= x:
        tengah = x + (y - x) // 2
        if arroy[tengah] == z:
            return tengah
        elif arroy[tengah] > z:
            return recursive_cari(arroy, x, tengah-1, z)
        else:
            return recursive_cari(arroy, tengah + 1, y, z)
    else:
        return -1

# Data to search
data = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

data.reverse()

# Elements to search
search_elements = [10, 20, 30, 1, 4]


for element in search_elements:
    start = time.perf_counter()
    result = fibonacci_skibidi(data, element, len(data))
    end = time.perf_counter()
    print(f"Fibonacci search for {element} found at index {result} in {end - start} seconds")

    start = time.perf_counter()
    result = recursive_cari(data, 0, len(data)-1, element)
    end = time.perf_counter()
    print(f"Recursive search for {element} found at index {result} in {end - start} seconds")
    
print("\n Lead Them To Paradise! - Abdulhadi")