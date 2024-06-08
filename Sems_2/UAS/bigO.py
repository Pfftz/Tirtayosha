import time

def get_first_element(arr):
    return arr[0]

start_time = time.perf_counter()
print("get_first_element time complexity is O(1). The output is the first element of the array:", get_first_element([1, 2, 3]))
print("Runtime of get_first_element is", time.perf_counter() - start_time, "seconds.")

def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

start_time = time.perf_counter()
print("binary_search time complexity is O(log n). The output is the index of the target element:", binary_search([1, 2, 3, 4, 5], 3))
print("Runtime of binary_search is", time.perf_counter() - start_time, "seconds.")

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

start_time = time.perf_counter()
print("linear_search time complexity is O(n). The output is the index of the target element:", linear_search([1, 2, 3, 4, 5], 3))
print("Runtime of linear_search is", time.perf_counter() - start_time, "seconds.")

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

arr = [5, 3, 1, 2, 4]
start_time = time.perf_counter()
merge_sort(arr)
print("merge_sort time complexity is O(n log n). The output is the sorted array:", arr)
print("Runtime of merge_sort is", time.perf_counter() - start_time, "seconds.")

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

arr = [5, 3, 1, 2, 4]
start_time = time.perf_counter()
bubble_sort(arr)
print("bubble_sort time complexity is O(n^2). The output is the sorted array:", arr)
print("Runtime of bubble_sort is", time.perf_counter() - start_time, "seconds.")

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

start_time = time.perf_counter()
print("fibonacci time complexity is O(2^n). The output is the nth Fibonacci number:", fibonacci(10))
print("Runtime of fibonacci is", time.perf_counter() - start_time, "seconds.")

def permutations(arr):
    if len(arr) == 0:
        return [[]]
    result = []
    for i in range(len(arr)):
        rest = arr[:i] + arr[i+1:]
        for perm in permutations(rest):
            result.append([arr[i]] + perm)
    return result

start_time = time.perf_counter()
print("permutations time complexity is O(n!). The output is all permutations of the array:", permutations([1, 2, 3]))
print("Runtime of permutations is", time.perf_counter() - start_time, "seconds.")

print("\n Lead Them To Paradise! - Abdulhadi")