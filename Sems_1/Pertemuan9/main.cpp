#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

string opening = R"(

 ▄▄▄       ▄▄▄▄   ▓█████▄  █    ██  ██▓    
▒████▄    ▓█████▄ ▒██▀ ██▌ ██  ▓██▒▓██▒    
▒██  ▀█▄  ▒██▒ ▄██░██   █▌▓██  ▒██░▒██░    
░██▄▄▄▄██ ▒██░█▀  ░▓█▄   ▌▓▓█  ░██░▒██░    
 ▓█   ▓██▒░▓█  ▀█▓░▒████▓ ▒▒█████▓ ░██████▒
 ▒▒   ▓▒█░░▒▓███▀▒ ▒▒▓  ▒ ░▒▓▒ ▒ ▒ ░ ▒░▓  ░
  ▒   ▒▒ ░▒░▒   ░  ░ ▒  ▒ ░░▒░ ░ ░ ░ ░ ▒  ░
  ░   ▒    ░    ░  ░ ░  ░  ░░░ ░ ░   ░ ░   
      ░  ░ ░         ░       ░         ░  ░
                ░  ░                       
)";

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

void menu2(int *pn)
{
    double sum = 1;
    double *psum = &sum;
    cout << " Masukan nilai n: ";
    cin >> *pn;

    if (*pn % 2 == 0)
    {
        cout << " ";
        for (int i = *pn; i >= 2; i -= 2)
        {
            cout << i << " * ";
            sum *= i;
        }
        cout << endl;
        cout << " Hasil: " << *psum << endl;
    }
    else
    {
        cout << " Bukan bilangan genap" << endl;
    }

    cout << endl;
    system("pause");
    system("cls");
}

void menu3(int *pn)
{
    cout << " Masukkan nilai n: ";
    cin >> *pn;
    char *huruf = new char[*pn];
    int *jumlah = new int[26];
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
            cout << " " << (char)(i + 'a') << " = " << jumlah[i] << endl;
        }
    }
    delete[] huruf;
    delete[] jumlah;

    cout << endl;
    system("pause");
    system("cls");
}

void menu4(int *pn)
{
    cout << " Masukkan nilai n: ";
    cin >> *pn;
    int nim[*pn];
    string nama[*pn];
    for (int i = 0; i < *pn; i++)
    {
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[0]    : ";
        cin >> nim[i];
        cout << " Nama[1]   : ";
        cin >> nama[i];
        cout << endl;
    }

    // Bubble Sort in descending order
    for (int i = 0; i < *pn - 1; i++)
    {
        for (int j = 0; j < *pn - i - 1; j++)
        {
            if (nim[j] < nim[j + 1])
            {
                // Swap NIM
                int tempNim = nim[j];
                nim[j] = nim[j + 1];
                nim[j + 1] = tempNim;

                // Swap Nama
                string tempNama = nama[j];
                nama[j] = nama[j + 1];
                nama[j + 1] = tempNama;
            }
        }
    }

    cout << " Hasil akhir setelah diurutkan dan dibalik berdasarkan NIM adalah: " << endl;
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
    int pilih, n;
    int *ppil = &pilih;
    bool menu = true;
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
        cin >> *ppil;
        cout << endl;
        switch (*ppil)
        {
        case 1:
            menu1();
            break;
        case 2:
            menu2(&n);
            break;
        case 3:
            menu3(&n);
            break;
        case 4:
            menu4(&n);
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