#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int x, y, m, n;
    cout << "masukkan nilai m dan n : ";
    cin >> m >> n;
    cout << endl;
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < m; y++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}