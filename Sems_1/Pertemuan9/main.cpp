#include <iostream>
#include <math.h>

using namespace std;

int pilih, n;
int *ppil = &pilih, *pn = &n;
bool menu = true;

void menu1()
{
    float x1, x2, y1, y2, hasil;
    float *px1 = &x1, *px2 = &x2, *py1 = &y1, *py2 = &y2, *phas = &hasil;

    cout << " Masukkan nilai x1: ";
    cin >> *px1;
    cout << " Masukkan nilai x2: ";
    cin >> *px2;
    cout << " Masukkan nilai y1: ";
    cin >> *py1;
    cout << " Masukkan nilai y2: ";
    cin >> *py2;

    *phas = sqrt(pow((*px2 - *px1), 2) + pow((*py2 - *py1), 2));
    cout << " Jarak antara dua titik adalah: " << *phas << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu2()
{
    double sum = 1;
    double *psum = &sum;
    cout << " Masukan nilai n: ";
    cin >> *pn;

    for (int i = *pn; i >= 1; i--)
    {
        if (i % 2 == 0)
        {
            *psum *= i;
            cout << i << " * ";
        }
    }
    cout << endl;
    cout << "Hasil: " << *psum << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu3()
{
    cout << " Masukkan nilai n: ";
    cin >> *pn;
    char huruf[*pn];
    int jumlah[26];
    for (int i = 0; i < 26; i++)
    {
        jumlah[i] = 0;
    }
    for (int i = 0; i < *pn; i++)
    {
        cout << " Masukkan huruf ke-" << i + 1 << ": ";
        cin >> huruf[i];
        jumlah[huruf[i] - 'a']++;
    }
    cout << endl;
    for (int i = 0; i < 26; i++)
    {
        if (jumlah[i] > 0)
        {
            cout << " Jumlah huruf " << (char)(i + 'a') << " adalah " << jumlah[i] << endl;
        }
    }
    cout << endl;
    system("pause");
    system("cls");
}

void menu4()
{
    cout << " Masukkan nilai n: ";
    cin >> *pn;
    int nim[*pn], temp;
    string nama[*pn], temp2;
    for (int i = 0; i < *pn; i++)
    {
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[" << i + 1 << "]    : ";
        cin >> nim[i];
        cout << " Nama[" << i + 1 << "]   : ";
        cin >> nama[i];
        cout << endl;
    }

    for (int i = 0; i < *pn; i++)
    {
        for (int j = i + 1; j < *pn; j++)
        {
            if (nim[i] < nim[j])
            {
                temp = nim[i];
                nim[i] = nim[j];
                nim[j] = temp;

                temp2 = nama[i];
                nama[i] = nama[j];
                nama[j] = temp2;
            }
        }
    }

    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    for (int i = 0; i < *pn; i++)
    {
        cout << " (NIM: " << nim[i];
        cout << " Nama: " << nama[i] << ") " << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

void menu5()
{
    cout << " Terima kasih telah menggunakan program ini" << endl;
    exit(0);
}

int main()
{
    while (menu)
    {
        cout << "\n====================================" << endl;
        cout << " Main Menu" << endl;
        cout << " 1. Menghitung koordinat kartesius" << endl;
        cout << " 2. Menghitung faktorial bilangan genap" << endl;
        cout << " 3. Menghitung jumlah huruf yang sama" << endl;
        cout << " 4. Mengurutkan nim mahasiswa descending" << endl;
        cout << " 5. Keluar" << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilih;
        cout << endl;
        switch (pilih)
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        case 4:
            menu4();
            break;
        case 5:
            menu5();
            break;
        default:
            cout << " Pilihan tidak tersedia" << endl;
            break;
        }
    }
    return 0;
}