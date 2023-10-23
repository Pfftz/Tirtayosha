#include <iostream>

using namespace std;

string hitungbonus(int total, int goods)
{
    string bonus;
    if (total >= 1000000 && goods >= 5)
    {
        bonus = "Voucher Belanja";
    }
    else if (total >= 500000 && goods >= 3)
    {
        bonus = "Tumbler Cantik";
    }
    else if (total >= 100000 && goods >= 2)
    {
        bonus = "Piring Cantik";
    }
    else
    {
        bonus = "Tidak Ada";
    }
    return bonus;
}
int main()
{
    int total, goods;
    cout << "Total belanja: ";
    cin >> total;
    cout << "Jumlah barang: ";
    cin >> goods;
    cout << "Bonus: " << hitungbonus(total, goods) << endl;

    return 0;
}