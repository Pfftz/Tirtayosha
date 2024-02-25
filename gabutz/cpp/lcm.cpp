#include <iostream>

using namespace std;

int main()
{
    int x, y, kpk = 0;

    cout << "Masukkan Bilangan ke-1\t: ";
    cin >> x;
    cout << "Masukkan Bilangan ke-2\t: ";
    cin >> y;
    for (int r = 1; r <= y; r++)
    {
        kpk += x;
        if (kpk % y == 0)
        {
            cout << "\nKPK: " << kpk << endl;
            break;
        }
    }
    cout << "\n\tpain is never permanent but tonight is killing me\n";

    return 0;
}