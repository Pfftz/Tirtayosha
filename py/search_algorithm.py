'''binary search algorithm'''


def binarySearch(arr, x):
    '''binary search algorithm'''
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2

        # If x is greater, ignore left half
        if arr[mid] < x:
            low = mid + 1

        # If x is smaller, ignore right half
        elif arr[mid] > x:
            high = mid - 1

        # x is present at mid
        else:
            return mid

    # If we reach here, then the element was not present
    return -1


def linearSearch(arr, x):
    '''linear search algorithm'''
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1


# Test array
arr = [2, 3, 4, 10, 40]
arr2 = [5, 2, 4, 6, 1, 8]
x = int(input("Enter the number to search: "))

# Function call
result = binarySearch(arr, x)
result2 = linearSearch(arr2, x)

if result != -1 and result2 != -1:
    print("Element is present at index", str(result),
          'using binary search and', str(result2), 'using linear search')
elif result2 != -1 or result != -1:
    print("Element is present at index", str(result2) if result2 != -1 else str(result),
          'using linear search' if result2 != -1 else 'using binary search')
else:
    print("Element is not present in array")

