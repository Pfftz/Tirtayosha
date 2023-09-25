#include <iostream>
#include <iomanip>
using namespace std;

int panjang, alas, luas, tinggi, lol;

void while_loop()
{
    cout << "\t<<Segitiga Siku Siku Terbalik>>\n\n";
    int y = 0;
    int x;
    int currentTinggi = tinggi;
    while (currentTinggi > 0)
    {
        x = currentTinggi;
        y = 0;
        while (y < lol - currentTinggi)
        {
            cout << "  ";
            y++;
        }
        while (x > 0)
        {
            cout << "*"
                 << " ";
            x--;
        }
        cout << endl;
        currentTinggi--;
    }
    cout << endl;
}

void for_loop()
{
    cout << "\t<<Segitiga Siku Siku Terbalik>>\n\n";
    for (int row = tinggi; row > 0; row--)
    {
        // Print spaces before asterisks
        for (int space = 0; space < lol - row; space++)
        {
            cout << "  ";
        }

        // Print asterisks
        for (int asterisk = 0; asterisk < row; asterisk++)
        {
            cout << "* ";
        }

        // Move to the next line
        cout << endl;
    }
}

int main()
{
    panjang = 2;
    alas = 7;
    luas = 6;
    tinggi = panjang + alas + luas;
    cout << "Masukkan nilai panjang: " << panjang << endl;
    cout << "Masukkan nilai alas: " << alas << endl;
    cout << "Masukkan nilai luas: " << luas << endl;
    cout << "====================" << endl;
    cout << "maka hasil dari tinggi: " << tinggi << endl;
    cout << "====================\n"
         << endl;

    while_loop();
    for_loop();

    return 0;
}