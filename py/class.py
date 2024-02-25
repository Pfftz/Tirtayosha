'''nyoba class'''

# #using class
# class mahasiswa:
#     def __init__(self, nama, nim):
#         self.nama = nama
#         self.nim = nim

#     def tampil(self):
#         print(' Nama:', self.nama)
#         print(' NIM:', self.nim)


# batasInput = int(input(' Masukkan batas input: '))

# data = []
# for i in range(batasInput):
#     print(' Masukkan data ke-', i+1)
#     nama = input(' Masukkan nama: ')
#     nim = input(' Masukkan NIM: ')
#     mhs = mahasiswa(nama, nim)
#     data.append(mhs)

# # Sort data by nim in descending order
# data.sort(key=lambda mhs: mhs.nim, reverse=True)

# print(' Data terurut berdasarkan NIM')
# for mhs in data:
#     mhs.tampil()

#using dictionary
batasInput = int(input(' Masukkan batas input: '))

data = []
for i in range(batasInput):
    print(' Masukkan data ke-', i+1)
    nama = input(' Masukkan nama: ')
    nim = input(' Masukkan NIM: ')
    mhs = {'nama': nama, 'nim': nim}
    data.append(mhs)

# Sort data by nim in descending order
data.sort(key=lambda mhs: mhs['nim'], reverse=True)

print(' Data terurut berdasarkan NIM')
for mhs in data:
    print(' Nama:', mhs['nama'])
    print(' NIM:', mhs['nim'])
