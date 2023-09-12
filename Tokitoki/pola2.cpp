#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "masukkan nilai n : ";
    cin >> n;
    cout << endl;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y <= x; y++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}