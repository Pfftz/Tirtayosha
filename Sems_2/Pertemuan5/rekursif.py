'''fibonacci search dan rekursif search'''
# Import library
import time
from datetime import datetime
import pandas as pd

# Function to get the minimum of two values
def min_val(x, y):
    return x if x <= y else y

# Recursive function for fibonacci search
def fibonacci_search(arr, x, n):
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


# Read data from CSV file
df = pd.read_csv('D:\\Alprot\\Sems_2\\Pertemuan5\\Amazon 2_Raw.csv')

# Convert columns to lists
product_names = df['Product Name'].tolist()
sales = [int(i) for i in df['Sales'].tolist()]
order_dates = [datetime.strptime(i, '%m/%d/%Y')
               for i in df['Order Date'].tolist()]

# Combine lists into one list of tuples
data = list(zip(product_names, sales, order_dates))

# Sort data by each column for searching
product_data = sorted(data, key=lambda x: x[0])
sales_data = sorted(data, key=lambda x: x[1])
date_data = sorted(data, key=lambda x: x[2])

# Get list of each column for searching
product_names = [i[0] for i in product_data]
sales = [i[1] for i in sales_data]
order_dates = [i[2] for i in date_data]

# Get input from user
search_product = input("Enter product name to search: ")
search_sale = int(input("Enter sale to search: "))
search_date = datetime.strptime(
    input("Enter date to search (mm/dd/yyyy): "), '%m/%d/%Y')

# Search for a product name using fibonacci search
start = time.perf_counter()
result = fibonacci_search(product_names, search_product, len(product_names))
end = time.perf_counter()
if result != -1:
    print('\n', 'Found at index:', result)
    print('Data:', product_data[result])
print('Fibonacci search time for product:', "{:.16f}".format(end - start))

# Search for a sale using fibonacci search
start = time.perf_counter()
result = fibonacci_search(sales, search_sale, len(sales))
end = time.perf_counter()
if result != -1:
    print('\n', 'Found at index:', result)
    print('Data:', sales_data[result])
print('Fibonacci search time for sale:', "{:.16f}".format(end - start))

# Search for a date using fibonacci search
start = time.perf_counter()
result = fibonacci_search(order_dates, search_date, len(order_dates))
end = time.perf_counter()
if result != -1:
    print('\n', 'Found at index:', result)
    print('Data:', date_data[result])
print('Fibonacci search time for date:', "{:.16f}".format(end - start), "\n")

# Search for a product name using recursive search
start = time.perf_counter()
result = recursive_search(product_names, 0, len(
    product_names)-1, search_product)
end = time.perf_counter()
if result != -1:
    print('\n', 'Found at index:', result)
    print('Data:', product_data[result])
print('Recursive search time for product:', "{:.16f}".format(end - start), "\n")

# Search for a sale using recursive search
start = time.perf_counter()
result = recursive_search(sales, 0, len(sales)-1, search_sale)
end = time.perf_counter()
if result != -1:
    print('\n', 'Found at index:', result)
    print('Data:', sales_data[result])
print('Recursive search time for sale:', "{:.16f}".format(end - start), "\n")

# Search for a date using recursive search
start = time.perf_counter()
result = recursive_search(order_dates, 0, len(order_dates)-1, search_date)
end = time.perf_counter()
if result != -1:
    print("\n", 'Found at index:', result)
    print('Data:', date_data[result])
print('Recursive search time for date:', "{:.16f}".format(end - start), "\n")
