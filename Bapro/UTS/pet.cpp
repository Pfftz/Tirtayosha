#include <iostream>
using namespace std;
int xyz;
string nama[5];
string kode[5] = {"A-1234", "B-2345", "A-3345", "D-5433", "F-3840"};
string jenis[5] = {"Kucing", "Anjing", "Ular", "Anjing", "Kucing"};
int main()
{
    cout << "\t<<<Program Penitipan Hewan>>>" << endl;
    cout << "\t <<<Pet Care Synchro>>>" << endl;
    cout << "\n\nInput Data Hewan yang Akan Dititipkan: ";
    cin >> xyz;
    for (int o = 0; o < xyz; o++)
    {
        cout << " Data " << o + 1 << endl;
        cout << "\tNama Hewan " << o + 1 << ": ";
        cin >> nama[o];
        cout << "\tKode\t : " << kode[o] << endl;
        cout << "\tJenis Hewan : " << jenis[o] << endl;
    }
    cout << endl
         << "\n\tDaftar Data Hewan Peliharaan" << endl;
    cout << "=============================================" << endl;
    cout << "No\tNama \tKode \tJenis" << endl;
    cout << "=============================================" << endl;
    for (int g = 0; g < xyz; g++)
    {
        cout << g + 1 << "\t" << nama[g] << "\t" << kode[g] << "\t" << jenis[g]
             << endl;
    }
    cout << "=============================================" << endl;
    return 0;
}
