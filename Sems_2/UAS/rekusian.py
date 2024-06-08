#watermark Admin Hd
# Import library
import time

# Function to get the minimum of two values
def min_val(x, y):
    return x if x <= y else y

# Recursive function for fibonacci search
def fibonacci_skibidi(arr, x, n):
    if n > 0:
        fibMMm2 = 0
        fibMMm1 = 1
        fibM = fibMMm2 + fibMMm1

        while (fibM < n):
            fibMMm2 = fibMMm1
            fibMMm1 = fibM
            fibM = fibMMm2 + fibMMm1

        offset = -1

        while (fibM > 1):
            i = min_val(offset+fibMMm2, n-1)

            if (arr[i] < x):
                fibM = fibMMm1
                fibMMm1 = fibMMm2
                fibMMm2 = fibM - fibMMm1
                offset = i
            elif (arr[i] > x):
                fibM = fibMMm2
                fibMMm1 = fibMMm1 - fibMMm2
                fibMMm2 = fibM - fibMMm1
            else:
                return i

        if (fibMMm1 and arr[offset+1] == x):
            return offset+1

        return -1
    else:
        return -1

# Recursive function for recursive search
def recursive_search(arr, l, r, x):
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return recursive_search(arr, l, mid-1, x)
        else:
            return recursive_search(arr, mid + 1, r, x)
    else:
        return -1

data = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

import time

# Your existing functions here...

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
    result = recursive_search(data, 0, len(data)-1, element)
    end = time.perf_counter()
    print(f"Recursive search for {element} found at index {result} in {end - start} seconds")
    
print("\n Lead Them To Paradise! - Abdulhadi")