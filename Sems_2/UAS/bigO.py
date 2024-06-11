import time

def get_first_element(arr):
    return arr[0]

start_time = time.perf_counter()
print("get_first_element time complexity is O(1). The output elemento array pertama:", get_first_element([1, 2, 3]))
print("Runtime of get_first_element is", time.perf_counter() - start_time, "seconds.")

def binary_sashi(arr, target, low=None, high=None):
    if low is None:
        low = 0
    if high is None:
        high = len(arr) - 1

    if high >= low:
        mid = (high + low) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            return binary_sashi(arr, target, low, mid - 1)
        else:
            return binary_sashi(arr, target, mid + 1, high)
    else:
        return -1

start_time = time.perf_counter()
print("kompleksitas dari binary search adalah O(log n). The output is the index of the target element:", binary_sashi([1, 2, 3, 4, 5], 3))
print("Runtime of binary_search is", time.perf_counter() - start_time, "seconds.")

def linear_sashi(kocak_list, sashi_element):
    index_position = 0
    while index_position < len(kocak_list):
        if kocak_list[index_position] == sashi_element:
            return index_position
        index_position += 1
    return -1

start_time = time.perf_counter()
print("linear_search time complexity is O(n). The output is the index of the target element:", linear_sashi([1, 2, 3, 4, 5], 3))
print("Runtime of linear_search is", time.perf_counter() - start_time, "seconds.")

def merge_senbetsu(input_array):
    if len(input_array) > 1:
        middle = len(input_array) // 2
        left_half = input_array[:middle]
        right_half = input_array[middle:]
        merge_senbetsu(left_half)
        merge_senbetsu(right_half)
        left_index = right_index = merged_index = 0
        while left_index < len(left_half) and right_index < len(right_half):
            if left_half[left_index] < right_half[right_index]:
                input_array[merged_index] = left_half[left_index]
                left_index += 1
            else:
                input_array[merged_index] = right_half[right_index]
                right_index += 1
            merged_index += 1
        while left_index < len(left_half):
            input_array[merged_index] = left_half[left_index]
            left_index += 1
            merged_index += 1
        while right_index < len(right_half):
            input_array[merged_index] = right_half[right_index]
            right_index += 1
            merged_index += 1

arr = [5, 3, 1, 2, 4]
start_time = time.perf_counter()
merge_senbetsu(arr)
print("merge_sort time complexity is O(n log n). The output is the sorted array:", arr)
print("Runtime of merge_sort is", time.perf_counter() - start_time, "seconds.")

def bubble_senbetsu(kocak_list):
    list_length = len(kocak_list)
    henshin = True
    start = 0
    end = list_length - 1
    while henshin:
        henshin = False
        for current in range(start, end):
            if kocak_list[current] > kocak_list[current + 1]:
                kocak_list[current], kocak_list[current + 1] = kocak_list[current + 1], kocak_list[current]
                henshin = True
        if not henshin:
            break
        henshin = False
        end = end - 1
        for current in range(end - 1, start - 1, -1):
            if kocak_list[current] > kocak_list[current + 1]:
                kocak_list[current], kocak_list[current + 1] = kocak_list[current + 1], kocak_list[current]
                henshin = True
        start = start + 1

arr = [5, 3, 1, 2, 4]
start_time = time.perf_counter()
bubble_senbetsu(arr)
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