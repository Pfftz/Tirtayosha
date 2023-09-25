#include <iostream>

using namespace std;

int main()
{
    char v;
    cout << "Masukkan sebuah huruf: " << endl;
    cin >> v;

    if (v == 'a' || v == 'i' || v == 'u' || v == 'e' || v == 'o' ||
        v == 'A' || v == 'I' || v == 'U' || v == 'E' || v == 'O')
    {
        cout << endl
             << v << " adalah salah satu huruf vokal\n"
             << "\n<<<Eternal Sunshine of the Spotless Mind>>>\n";
    }

    return 0;
}