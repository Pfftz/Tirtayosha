# Import library
import time

# Function for selection sort
def selection_sort(data):
    for i in range(len(data)):
        min_idx = i
        for j in range(i+1, len(data)):
            if data[min_idx] > data[j]:
                min_idx = j
        data[i], data[min_idx] = data[min_idx], data[i]

# Function for insertion sort
def insertion_sort(data):
    for i in range(1, len(data)):
        key = data[i]
        j = i-1
        while j >= 0 and key < data[j]:
            data[j+1] = data[j]
            j -= 1
        data[j+1] = key

# Function for quick sort
def partition(data, low, high):
    i = (low-1)
    pivot = data[high]
    for j in range(low, high):
        if data[j] <= pivot:
            i = i+1
            data[i], data[j] = data[j], data[i]
    data[i+1], data[high] = data[high], data[i+1]
    return (i+1)

def quick_sort(data, low, high):
    if len(data) == 1:
        return data
    if low < high:
        pi = partition(data, low, high)
        quick_sort(data, low, pi-1)
        quick_sort(data, pi+1, high)


data = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
# Sort data using selection sort and measure the time
start = time.perf_counter()
selection_sort(data)
end = time.perf_counter()
print(f"Selection sort time: {end - start}")
print("Data after selection sort: ", data)

# Reset data to the unsorted array
data = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

# Sort data using insertion sort and measure the time
start = time.perf_counter()
insertion_sort(data)
end = time.perf_counter()
print(f"Insertion sort time: {end - start}")
print("Data after insertion sort: ", data)

# Reset data to the unsorted array
data = [50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

# Sort data using quick sort and measure the time
start = time.perf_counter()
quick_sort(data, 0, len(data)-1)
end = time.perf_counter()
print(f"Quick sort time: {end - start}")
print("Data after quick sort: ", data)

print("\n Lead Them To Paradise! - Abdulhadi")