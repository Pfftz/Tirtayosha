'''pertemuan 4 sorting'''
import time
import pandas as pd
# Fungsi untuk selection sort

def selection_sort(data):
    for i in range(len(data)):
        min_idx = i
        for j in range(i+1, len(data)):
            if data[min_idx] > data[j]:
                min_idx = j
        data[i], data[min_idx] = data[min_idx], data[i]

# Fungsi untuk insertion sort


def insertion_sort(data):
    for i in range(1, len(data)):
        key = data[i]
        j = i-1
        while j >= 0 and key < data[j]:
            data[j+1] = data[j]
            j -= 1
        data[j+1] = key

# Fungsi untuk quick sort


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


# Membuat data acak
# Read data from CSV file
df = pd.read_csv('D:\\Alprot\\Sems_2\\Pertemuan4\\tinggi_badannew.csv')

# Convert height and weight columns to lists
heights = df['Height(Inches)'].tolist()
weights = df['Weight(Pounds)'].tolist()

# Sort heights and weights using selection sort and measure the time
start = time.time()
selection_sort(heights)
selection_sort(weights)
end = time.time()
print(f"Selection sort time: {end - start}")

# Read data from CSV file again to get unsorted data
df = pd.read_csv('D:\\Alprot\\Sems_2\\Pertemuan4\\tinggi_badannew.csv')
heights = df['Height(Inches)'].tolist()
weights = df['Weight(Pounds)'].tolist()

# Sort heights and weights using insertion sort and measure the time
start = time.time()
insertion_sort(heights)
insertion_sort(weights)
end = time.time()
print(f"Insertion sort time: {end - start}")

# Read data from CSV file again to get unsorted data
df = pd.read_csv('D:\\Alprot\\Sems_2\\Pertemuan4\\tinggi_badannew.csv')
heights = df['Height(Inches)'].tolist()
weights = df['Weight(Pounds)'].tolist()

# Sort heights and weights using quick sort and measure the time
start = time.time()
quick_sort(heights, 0, len(heights)-1)
quick_sort(weights, 0, len(weights)-1)
end = time.time()
print(f"Quick sort time: {end - start}", '\n')
print("Heights after sort: ", heights, '\n\n\n')
print("Weights after sort: ", weights, '\n')
