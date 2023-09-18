#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Masukkan nilai n : ";
    cin >> n;
    cout << endl;
    for (int y = 0; y <= n; y++)
    {
        // Print leading spaces
        for (int s = 0; s < n - y; s++)
        {
            cout << " ";
        }

        // Print asterisks
        for (int x = 0; x < y; x++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    // segitiga terbalik rata kanan
    for (int x = 0; x < n; x++)
    {
        // Print leading spaces
        for (int s = 0; s < x; s++)
        {
            cout << " ";
        }

        // Print asterisks
        for (int y = 0; y < n - x; y++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
