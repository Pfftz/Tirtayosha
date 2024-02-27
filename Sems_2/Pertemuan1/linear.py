import random
import time


def simple_search(data_list, x):
    for i in range(len(data_list)):
        if data_list[i][0] == x:
            return i
    return -1


# List nama-nama
with open('D:\\Alprot\\Sems_2\\Pertemuan1\\databases.txt', 'r') as file:
    content = file.read().split()

nilai_list = [random.randint(1, 100) for _ in content]

# Menyusun data dengan nilai
data_nilai = list(zip(nilai_list, content))

for data in data_nilai:
    print(data)

x = int(input("Cari data = "))  # Convert input to integer

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
