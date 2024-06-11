# Import library
import time

# Function for selection sort
def selection_senbetsu(BEDUNG):
    for i in range(len(BEDUNG)):
        min_idx = i
        for j in range(i+1, len(BEDUNG)):
            if BEDUNG[min_idx] > BEDUNG[j]:
                min_idx = j
        BEDUNG[i], BEDUNG[min_idx] = BEDUNG[min_idx], BEDUNG[i]

# Function for insertion sort
def insertion_senbetsu(BEDUNG):
    for i in range(1, len(BEDUNG)):
        key = BEDUNG[i]
        j = i-1
        while j >= 0 and key < BEDUNG[j]:
            BEDUNG[j+1] = BEDUNG[j]
            j -= 1
        BEDUNG[j+1] = key


def partition(BEDUNG, bawah, atas):
    i = (bawah-1)
    pivot = BEDUNG[atas]
    for j in range(bawah, atas):
        if BEDUNG[j] <= pivot:
            i = i+1
            BEDUNG[i], BEDUNG[j] = BEDUNG[j], BEDUNG[i]
    BEDUNG[i+1], BEDUNG[atas] = BEDUNG[atas], BEDUNG[i+1]
    return (i+1)

def quick_senbetsu(BEDUNG, bawah, atas):
    if len(BEDUNG) == 1:
        return BEDUNG
    if bawah < atas:
        pi = partition(BEDUNG, bawah, atas)
        quick_senbetsu(BEDUNG, bawah, pi-1)
        quick_senbetsu(BEDUNG, pi+1, atas)


BEDUNG = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
# Sort BEDUNG using selection sort and measure the time
start = time.perf_counter()
selection_senbetsu(BEDUNG)
end = time.perf_counter()
print(f"Selection sort time: {end - start}")
print("BEDUNG after selection sort: ", BEDUNG)

# Reset BEDUNG to the unsorted array
BEDUNG = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

# Sort BEDUNG using insertion sort and measure the time
start = time.perf_counter()
insertion_senbetsu(BEDUNG)
end = time.perf_counter()
print(f"Insertion sort time: {end - start}")
print("BEDUNG after insertion sort: ", BEDUNG)

# Reset BEDUNG to the unsorted array
BEDUNG = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

# Sort BEDUNG using quick sort and measure the time
start = time.perf_counter()
quick_senbetsu(BEDUNG, 0, len(BEDUNG)-1)
end = time.perf_counter()
print(f"Quick sort time: {end - start}")
print("BEDUNG after quick sort: ", BEDUNG)

print("\n Lead Them To Paradise! - Abdulhadi")