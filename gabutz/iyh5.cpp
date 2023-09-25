#include <iostream>

using namespace std;

int main()
{
    int x, y, z;

    cout << "Masukkan Bilangan ke-1\t: ";
    cin >> x;
    cout << "Masukkan Bilangan ke-2\t: ";
    cin >> y;
    for (int r = 1; r <= y; r++)
    {
        z = z + x;
        if (z % y == 0)
        {
            cout << "\nKPK: " << z << endl;
            break;
        }
    }
    cout << "\n\tpain is never permanent but tonight is killing me\n";

    return 0;
}