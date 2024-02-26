'''problem-problem pencarian'''

def maxAverage(arr, x):
    arr.sort()
    prefix_sum = [0]
    for num in arr:
        prefix_sum.append(prefix_sum[-1] + num)

    def check(mid):
        for i in range(x, len(arr) + 1):
            if prefix_sum[i] - min(prefix_sum[j] + mid * (i - j) for j in range(i - x + 1)) >= 0:
                return True
        return False

    low, high = arr[0], prefix_sum[-1] / x
    while high - low > 1e-5:
        mid = (low + high) / 2
        if check(mid):
            low = mid
        else:
            high = mid

    return low


arr = [1, 2, 3, 4, 5]
x = 2
print(maxAverage(arr, x))  # Output: 4.5


def lower_bound(arr, k):
    arr.sort()
    low, high = 0, len(arr)
    while low < high:
        mid = (low + high) // 2
        if arr[mid] < k:
            low = mid + 1
        else:
            high = mid
    return low if low < len(arr) and arr[low] >= k else -1


arr = [1, 2, 3, 4, 5]
k = 3
print(lower_bound(arr, k))  # Output: 2


def binary_search(arr, x, search_first):
    low, high = 0, len(arr) - 1
    result = -1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            result = mid
            if search_first:
                high = mid - 1  # Go on searching towards left (lower indices)
            else:
                # Go on searching towards right (higher indices)
                low = mid + 1
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return result


def count_occurrences(arr, x):
    first = binary_search(arr, x, True)
    if first == -1:  # x is not present in the array
        return 0
    last = binary_search(arr, x, False)
    return last - first + 1


arr = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
x = 3
print(count_occurrences(arr, x))  # Output: 3
