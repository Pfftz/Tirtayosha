#include <iostream>
using namespace std;

int main()
{
    double alas, tinggi, luasSegitiga, panjang, lebar, luasPersegiPanjang;
    int pilihan, n;
    bool menu = true;

    cout << "\n====================================" << endl;
    cout << " Main Menu" << endl;
    cout << " 1. Menghitung Bilangan Prima" << endl;
    cout << " 2. Menghitung faktorial" << endl;
    cout << " 3. Menghitung luas persegi panjang" << endl;
    cout << " 4. Menghitung luas segitiga" << endl;
    cout << " 5. Nested Loop" << endl;
    cout << " 6. Nested Loop Terbalik" << endl;
    cout << " 7. Prima Checker" << endl;
    cout << " 8. Keluar" << endl;
    cout << "====================================" << endl;

    while (menu)
    {
        cout << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan)
        {
        case 1:
            
            cout << endl;
            break;
        case 2:
        {
           
            cout << endl;
            break;
        }
        case 3:
            
            cout << endl;
            break;
        case 4:
            
            cout << endl;
            break;
        case 5:
            
            cout << endl;
            break;
        case 6:
        {
            
            cout << endl;
            break;
        }
        case 7:
        {
            
            cout << endl;
            break;
        }
        case 8:
            cout << " <<program selesai>>" << endl;
            exit(0);
        default:
            cout << " Pilihan tidak valid" << endl;
            break;
        }
    }
    return 0;
}