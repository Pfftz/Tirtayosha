import random
import time


def simple_search(data_list, x):
    for i in range(len(data_list)):
        if data_list[i][0] == x:
            return i
    return -1


# List nama-nama
with open('D:\\Alprot\\Sems_2\\Pertemuan1\\databases.txt', 'r') as file:
    content = file.read()
    names = content.replace("'", "").replace(",", "").split()

# list nilai
with open('D:\\Alprot\\Sems_2\\Pertemuan1\\random_numbers.txt', 'r') as file:
    values = file.read().split()

# Menyusun data dengan nilai
data_nilai = list(zip(names, values))

print("Pertemuan 1 - Simple Search in python\n")

x = input("Cari data = ")  # Keep input as string for name search

start_time = time.perf_counter()

hasil = simple_search(data_nilai, x)

end_time = time.perf_counter()
waktu = end_time - start_time

if hasil != -1:
    print(f"Elemen '{x}' ditemukan pada index {
          hasil} dengan nilai {data_nilai[hasil][1]}")
    print("Waktu yang dibutuhkan: {:.8f} detik".format(waktu))
else:
    print(f"Elemen '{x}' tidak ada dalam array")

'''contoh perbandingannya'''
# Elemen 'yuni' ditemukan pada index 998 dengan nilai 51,
# Waktu yang dibutuhkan: 0.00029470 detik