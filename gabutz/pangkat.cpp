#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int c = 1;

    cout << "Masukkan Bilangan\t: ";
    cin >> a;
    cout << "Masukkan Pencacah\t: ";
    cin >> b;

    for (int p = 1; p <= b; p++)
    {
        c *= a;
    }

    cout << "Hasil Pangkat\t\t: " << c << endl;
    cout << "\nBy: Sigit Rendang\n";
    return 0;
}