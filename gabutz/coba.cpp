#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    float total = 1;
    cout << "Masukan bilangan prima\n";
    cin >> n;
    for (int a = 1; a < n; a++)
    {
        int bil = 0;
        for (int b = 1; b <= a; b++)
        {
            if (a % b == 0)
            {
                bil = bil + 1;
            }
        }
        if (bil == 2)
        {
            cout << "bilamgan prima nya adalah : " << a << endl;
            total *= a;
        }
    }

    cout << "Total semua bilangan prima: " << total << endl;
}
