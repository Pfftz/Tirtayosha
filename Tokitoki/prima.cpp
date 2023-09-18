#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    bool isPrime = true;
    cout << "Masukkan nilai n : ";
    cin >> n;
    cout << endl;
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << n << " adalah bilangan prima" << endl;
    }
    else
    {
        cout << n << " bukan bilangan prima" << endl;
    }
    return 0;
}