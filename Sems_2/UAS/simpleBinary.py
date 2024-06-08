def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid  # Returns the index of the found element
        elif arr[mid] < target:
            left = mid + 1  # Searching in the right half
        else:
            right = mid - 1  # Searching in the left half

    return -1  # Returns a value indicating the element was not found

def simple_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Returns the index of the found element

    return -1  # Returns a value indicating the element was not found


my_array1 = [1, 2, 5, 7, 69]
value_binary = 69
result1 = binary_search(my_array1, value_binary)
my_array2 = [5, 777, 9, 1, 7]
value_simple = 777
result2 = simple_search(my_array2, value_simple)
print(' Nilai yang ingin dicari: \n untuk binary search', value_binary, 'dan untuk simple search', value_simple)
print(' Simple Search: \n di index ke', result2)
print(' Binary Search: \n di index ke', result1)
print("\n Lead Them To Paradise!")
