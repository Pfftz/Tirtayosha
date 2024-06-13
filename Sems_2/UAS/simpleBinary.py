def unique_binary_search(kensaku_list, kensaku_item):
    batasTerbawah = 0
    batasTeratas = len(kensaku_list) - 1

    while batasTerbawah <= batasTeratas:
        middle_point = (batasTerbawah + batasTeratas) // 2
        if kensaku_list[middle_point] == kensaku_item:
            return middle_point  # Returns the index of the found element
        elif kensaku_list[middle_point] < kensaku_item:
            batasTerbawah = middle_point + 1  # Searching in the right half
        else:
            batasTeratas = middle_point - 1  # Searching in the left half

    return -1  # Returns a value indicating the element was not found

def unique_simple_search(kensaku_list, kensaku_item):
    index_position = 0
    while index_position < len(kensaku_list):
        if kensaku_list[index_position] == kensaku_item:
            return index_position
        index_position += 1

    return -1  # Returns a value indicating the element was not found


my_array1 = [1, 2, 5, 7, 69]
value_binary = 69
result1 = unique_binary_search(my_array1, value_binary)
my_array2 = [5, 777, 9, 1, 7]
value_simple = 777
result2 = unique_simple_search(my_array2, value_simple)
print(' Nilai yang ingin dicari: \n untuk binary search', value_binary, 'dan untuk simple search', value_simple)
print(' Simple Search: \n di index ke', result2)
print(' Binary Search: \n di index ke', result1)
print("\n Lead Them To Paradise!")
