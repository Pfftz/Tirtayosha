#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;
    //n = bilangan yang akan dicetak 
    //m = bilangan yang akan dilewati (kelipatan)
    cout << "masukkan nilai n dan m: ";
    cin >> n >> m;
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        if (i % m == 0)
        {
            continue;
        }
        cout << i << endl;
    }
    cout << "selesai" << endl;
    return 0;
}