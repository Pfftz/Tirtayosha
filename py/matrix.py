'''konversi matriks cpp ke py'''
print('Main Menu')
print(" 1. Input Nilai Matrix")
print(" 2. Matrix kali")
print(" 3. Rata-rata")
print(" 4. Hilang")
print(" 5. Keluar")

while(True):
    pilih = int(input("Pilih Menu: "))
    if pilih == 1:
        baris = int(input("Masukkan jumlah baris: "))
        kolom = int(input("Masukkan jumlah kolom: "))
        matrix = []
        for i in range(baris):
            a = []
            for j in range(kolom):
                a.append(int(input("Masukkan nilai matrix: ")))
            matrix.append(a)
        print(matrix, '\n')
    elif pilih == 2:
        result = []
        konstanta = int(input("Masukkan konstanta: "))
        for i in range(baris):
            a = []
            for j in range(kolom):
                a.append(matrix[i][j] * konstanta)
            result.append(a)
        print(result)
    elif pilih == 3:
        sum = 0
        for i in range(baris):
            for j in range(kolom):
                sum += matrix[i][j]
        print(sum/(baris*kolom))
    elif pilih == 4:
        barisHilang = int(input("Masukkan baris yang akan dihilangkan: "))
        matrix.pop(barisHilang-1)
        print(matrix)
    elif pilih == 5:
        break
    else:
        print("Menu tidak tersedia")
        