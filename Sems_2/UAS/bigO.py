import time

def get_first_element(arr):
    return arr[0]

start_time = time.perf_counter()
print("get_first_element time complexity is O(1). The output elemento array pertama:", get_first_element([1, 2, 3]))
print("Runtime of get_first_element is", time.perf_counter() - start_time, "seconds.")

def binary_sashi(arr, targeto, rendah=None, tinggi=None):
    if rendah is None:
        rendah = 0
    if tinggi is None:
        tinggi = len(arr) - 1

    if tinggi >= rendah:
        mid = (tinggi + rendah) // 2

        if arr[mid] == targeto:
            return mid
        elif arr[mid] > targeto:
            return binary_sashi(arr, targeto, rendah, mid - 1)
        else:
            return binary_sashi(arr, targeto, mid + 1, tinggi)
    else:
        return -1

start_time = time.perf_counter()
print("binary_search time complexity is O(log n). The output is the index of the target element:", binary_sashi([1, 2, 3, 4, 5], 3))
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

def merge_senbetsu(arrayMasuk):
    if len(arrayMasuk) > 1:
        pertengahan = len(arrayMasuk) // 2
        kiri_half = arrayMasuk[:pertengahan]
        kanan_half = arrayMasuk[pertengahan:]
        merge_senbetsu(kiri_half)
        merge_senbetsu(kanan_half)
        kiri_index = kanan_index = merged_index = 0
        while kiri_index < len(kiri_half) and kanan_index < len(kanan_half):
            if kiri_half[kiri_index] < kanan_half[kanan_index]:
                arrayMasuk[merged_index] = kiri_half[kiri_index]
                kiri_index += 1
            else:
                arrayMasuk[merged_index] = kanan_half[kanan_index]
                kanan_index += 1
            merged_index += 1
        while kiri_index < len(kiri_half):
            arrayMasuk[merged_index] = kiri_half[kiri_index]
            kiri_index += 1
            merged_index += 1
        while kanan_index < len(kanan_half):
            arrayMasuk[merged_index] = kanan_half[kanan_index]
            kanan_index += 1
            merged_index += 1

arr3 = [5, 3, 1, 2, 4]
start_time = time.perf_counter()
merge_senbetsu(arr3)
print("merge_sort time complexity is O(n log n). The output is the sorted array:", arr3)
print("Runtime of merge_sort is", time.perf_counter() - start_time, "seconds.")

def bubble_senbetsu(kocak_list):
    list_length = len(kocak_list)
    henshin = True
    awal = 0
    akhir = list_length - 1
    while henshin:
        henshin = False
        for current in range(awal, akhir):
            if kocak_list[current] > kocak_list[current + 1]:
                kocak_list[current], kocak_list[current + 1] = kocak_list[current + 1], kocak_list[current]
                henshin = True
        if not henshin:
            break
        henshin = False
        akhir = akhir - 1
        for current in range(akhir - 1, awal - 1, -1):
            if kocak_list[current] > kocak_list[current + 1]:
                kocak_list[current], kocak_list[current + 1] = kocak_list[current + 1], kocak_list[current]
                henshin = True
        awal = awal + 1

arr = [5, 3, 1, 2, 4]
start_time = time.perf_counter()
bubble_senbetsu(arr)
print("bubble_sort time complexity is O(n^2). The output is the sorted array:", arr)
print("Runtime of bubble_sort is", time.perf_counter() - start_time, "seconds.")

def fibonatchi(n):
    if n <= 1:
        return n
    else:
        return fibonatchi(n-1) + fibonatchi(n-2)

start_time = time.perf_counter()
print("fibonacci time complexity is O(2^n). The output is the nth Fibonacci number:", fibonatchi(10))
print("Runtime of fibonacci is", time.perf_counter() - start_time, "seconds.")

def permutations(arr):
    if len(arr) == 0:
        return [[]]
    hasil = []
    for i in range(len(arr)):
        rest = arr[:i] + arr[i+1:]
        for perm in permutations(rest):
            hasil.append([arr[i]] + perm)
    return hasil

start_time = time.perf_counter()
print("permutations time complexity is O(n!). The output is all permutations of the array:", permutations([1, 2, 3]))
print("Runtime of permutations is", time.perf_counter() - start_time, "seconds.")

print("\n Lead Them To Paradise! - Abdulhadi")