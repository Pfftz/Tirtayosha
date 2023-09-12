#include <iostream>

using namespace std;

void cabang()
{
    // IF
    int nilai;

    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai >= 90)
    {
        cout << "Nilai angka: A" << endl;
    }
    if (nilai < 90)
    {
        cout << "Nilai angka: B" << endl;
    }
    else
    {
        cout << "Maaf anda tidak lulus" << endl;
    }
}

int main()
{
    cabang();
    return 0;
}