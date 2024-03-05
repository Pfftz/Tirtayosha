#include <iostream>
#include <string>
using namespace std;

struct merah
{
    string stasiun[21]; // Mengubah ukuran array menjadi 21 untuk menampung stasiun tambahan
};

struct biru
{
    string stasiun[14]; // Tetap menggunakan ukuran array 14 seperti sebelumnya
};

struct pink
{
    string stasiun[4]; // Ukuran array 4 untuk jalur pink (KampungBandan, Ancol, TanjongPriok)
};

struct hijauTua
{
    string stasiun[12]; // Ukuran array 12 untuk jalur hijau tua
};

struct coklat
{
    string stasiun[12];
};

struct hijauMuda
{
    string stasiun[19];
};

struct ungu
{
    string stasiun[4];
};

int main()
{
    merah dataMerah;

    // Menginisialisasi nilai array jalur merah
    dataMerah.stasiun[0] = "Tebet";
    dataMerah.stasiun[1] = "Cawang";
    dataMerah.stasiun[2] = "DurenKalibata";
    dataMerah.stasiun[3] = "PasarMingguBaru";
    dataMerah.stasiun[4] = "PasarMinggu";
    dataMerah.stasiun[5] = "TanjungBarat";
    dataMerah.stasiun[6] = "LentengAgung";
    dataMerah.stasiun[7] = "UnivPancasila";
    dataMerah.stasiun[8] = "UnivIndonesia";
    dataMerah.stasiun[9] = "PondokCina";
    dataMerah.stasiun[10] = "DepokBaru";
    dataMerah.stasiun[11] = "Depok";
    dataMerah.stasiun[12] = "Manggarai";
    dataMerah.stasiun[13] = "Cikini";        // Menambahkan stasiun Cikini
    dataMerah.stasiun[14] = "Gondangdia";    // Menambahkan stasiun Gondangdia
    dataMerah.stasiun[15] = "Juanda";        // Menambahkan stasiun Juanda
    dataMerah.stasiun[16] = "SawahBesar";    // Menambahkan stasiun SawahBesar
    dataMerah.stasiun[17] = "ManggaBesar";   // Menambahkan stasiun ManggaBesar
    dataMerah.stasiun[18] = "Jayakarta";     // Menambahkan stasiun Jayakarta
    dataMerah.stasiun[19] = "JakartaKota";   // Menambahkan stasiun JakartaKota
    dataMerah.stasiun[20] = "KampungBandan"; // Menambahkan stasiun KampungBandan

    biru dataBiru;
    // Menginisialisasi nilai array jalur biru
    dataBiru.stasiun[0] = "Cikarang";
    dataBiru.stasiun[1] = "Metland";
    dataBiru.stasiun[2] = "Cibitung";
    dataBiru.stasiun[3] = "Tambun";
    dataBiru.stasiun[4] = "BekasiTimur";
    dataBiru.stasiun[5] = "Bekasi";
    dataBiru.stasiun[6] = "Kranji";
    dataBiru.stasiun[7] = "Cakung";
    dataBiru.stasiun[8] = "KlenderBaru";
    dataBiru.stasiun[9] = "Buaran";
    dataBiru.stasiun[10] = "Klender";
    dataBiru.stasiun[11] = "JatiNegara";
    dataBiru.stasiun[12] = "Manggarai";
    dataBiru.stasiun[13] = "Matraman"; // Menambahkan stasiun Matraman

    pink dataPink;
    // Menginisialisasi nilai array jalur pink
    dataPink.stasiun[0] = "KampungBandan"; // Menambahkan stasiun KampungBandan
    dataPink.stasiun[1] = "Ancol";         // Menambahkan stasiun Ancol
    dataPink.stasiun[2] = "TanjongPriok";  // Menambahkan stasiun TanjongPriok

    hijauTua dataHijauTua;
    // Menginisialisasi nilai array jalur hijau tua
    dataHijauTua.stasiun[0] = "JambuBaru";
    dataHijauTua.stasiun[1] = "Catang";
    dataHijauTua.stasiun[2] = "Cikeusal";
    dataHijauTua.stasiun[3] = "Walantaka";
    dataHijauTua.stasiun[4] = "Serang";
    dataHijauTua.stasiun[5] = "KarangAntu";
    dataHijauTua.stasiun[6] = "TonjongBaru";
    dataHijauTua.stasiun[7] = "Cilegon";
    dataHijauTua.stasiun[8] = "Krenceng";
    dataHijauTua.stasiun[9] = "Merak";

    coklat dataCoklat;
    // Menginisialisasi nilai array jalur coklaf
    dataCoklat.stasiun[0] = "Tangerang";
    dataCoklat.stasiun[1] = "TanahTinggi";
    dataCoklat.stasiun[2] = "BatuCeper";
    dataCoklat.stasiun[3] = "Poris";
    dataCoklat.stasiun[4] = "KaliDeres";
    dataCoklat.stasiun[5] = "RawaBuaya";
    dataCoklat.stasiun[6] = "BojongIndah";
    dataCoklat.stasiun[7] = "TamanKota";
    dataCoklat.stasiun[8] = "Pesing";
    dataCoklat.stasiun[9] = "Grogol";
    dataCoklat.stasiun[10] = "Duri"; // Menambahkan stasiun Duri

    hijauMuda dataHijauMuda;
    // Initialize values for the new route "Hijau Muda"
    dataHijauMuda.stasiun[0] = "TanahAbang";
    dataHijauMuda.stasiun[1] = "Palmerah";
    dataHijauMuda.stasiun[2] = "Kebayoran";
    dataHijauMuda.stasiun[3] = "PondokRanji";
    dataHijauMuda.stasiun[4] = "JurangMangu";
    dataHijauMuda.stasiun[5] = "Sudimara";
    dataHijauMuda.stasiun[6] = "RawaBuntu";
    dataHijauMuda.stasiun[7] = "Serpong";
    dataHijauMuda.stasiun[8] = "Cisauk";
    dataHijauMuda.stasiun[9] = "Cicayur";
    dataHijauMuda.stasiun[10] = "ParungPanjang";
    dataHijauMuda.stasiun[11] = "Cilejit";
    dataHijauMuda.stasiun[12] = "Daru";
    dataHijauMuda.stasiun[13] = "Tenjo";
    dataHijauMuda.stasiun[14] = "Tigaraksa";
    dataHijauMuda.stasiun[15] = "Cikoya";
    dataHijauMuda.stasiun[16] = "Maja";
    dataHijauMuda.stasiun[17] = "Citeras";
    dataHijauMuda.stasiun[18] = "RangkasBitung";

    ungu dataUngu;
    // Initialize values for the new route "Hijau Muda"
    dataUngu.stasiun[0] = "BatuCeper";
    dataUngu.stasiun[1] = "Duri";
    dataUngu.stasiun[2] = "BniCity";
    dataUngu.stasiun[3] = "Manggarai";

    string stasiunInput;
    cout << "Masukkan nama stasiun: ";
    getline(cin, stasiunInput);

    if (stasiunInput == "JakartaKota")
    {
        cout << "Jika anda ingin rute merah, Maka stasiun sebelumnya : Jayakarta." << endl;
        cout << "Jika anda ingin rute pink, Maka Stasiun setelahnya : Kampung Bandan." << endl;
    }
    else if (stasiunInput == "KampungBandan")
    {
        cout << "Jika rute biru, Maka stasiun setelahnya : Rajawali, dan stasiun sebelumnya : Angke." << endl;
        cout << "Jika rute pink, maka Stasiun setelahnya : Ancol, dan stasiun sebelumnya : JakartaKota." << endl;
    }
    else if (stasiunInput == "Manggarai")
    {
        cout << "Jika anda ingin rute merah, Maka Stasiun setelahnya : Cikini dan Stasiun Sebelumnya : Tebet." << endl
             << "Jika anda ingin rute ungu Maka Stasiun sebelumnya: Bni City" << endl;
        cout << "Jika anda ingin rute biru, Maka Stasiun setelahnya: Matraman dan Stasiun Sebelumnya:Sudirman." << endl;
    }
    else if (stasiunInput == "Cilegon")
    {
        cout << "Stasiun setelahnya adalah Krenceng, dan stasiun sebelumnya adalah TonjongBaru." << endl;
    }
    else if (stasiunInput == "Duri")
    {
        cout << "Jika rute Ungu, Maka stasiun sebelumnya : BatuCeper, dan stasiun setelahnya : BniCity." << endl;
        cout << "Jika rute Biru, maka Stasiun setelahnya : Ange, dan stasiun sebelumnya : TanahAbang" << endl;
    }
    else
    {
        int indexMerah = -1;         // Inisialisasi indeks jalur merah sebagai -1, menandakan stasiun tidak ditemukan
        int indexBiru = -1;          // Inisialisasi indeks jalur biru sebagai -1, menandakan stasiun tidak ditemukan
        int indexPink = -1;          // Inisialisasi indeks jalur pink sebagai -1, menandakan stasiun tidak ditemukan
        int indexHijauTua = -1;      // Inisialisasi indeks jalur hijau tua sebagai -1, menandakan stasiun tidak ditemukan
        int indexCoklat = -1;        // Inisialisasi indeks jalur hijau tua sebagai -1, menandakan stasiun tidak ditemukan
        int indexHijauMuda = -1;     // Inisialisasi indeks jalur hijau tua sebagai -1, menandakan stasiun tidak ditemukan
        int indexUngu = -1;          // Inisialisasi indeks jalur hijau tua sebagai -1, menandakan stasiun tidak ditemukan
        for (int i = 0; i < 21; ++i) // Mengubah iterasi menjadi 21 karena tambahan stasiun di jalur merah
        {
            if (dataMerah.stasiun[i] == stasiunInput)
            {
                indexMerah = i;
                break;
            }
        }
        for (int i = 0; i < 14; ++i)
        {
            if (dataBiru.stasiun[i] == stasiunInput)
            {
                indexBiru = i;
                break;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            if (dataPink.stasiun[i] == stasiunInput)
            {
                indexPink = i;
                break;
            }
        }
        for (int i = 0; i < 12; ++i)
        {
            if (dataHijauTua.stasiun[i] == stasiunInput)
            {
                indexHijauTua = i;
                break;
            }
        }

        for (int i = 0; i < 12; ++i)
        {
            if (dataCoklat.stasiun[i] == stasiunInput)
            {
                indexCoklat = i;
                break;
            }
        }

        for (int i = 0; i < 19; ++i)
        {
            if (dataHijauMuda.stasiun[i] == stasiunInput)
            {
                indexHijauMuda = i;
                break;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            if (dataUngu.stasiun[i] == stasiunInput)
            {
                indexUngu = i;
                break;
            }
        }

        if (indexMerah != -1)
        {
            cout << "Jalur: Merah" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexMerah > 0)
            {
                cout << dataMerah.stasiun[indexMerah - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataMerah.stasiun[indexMerah] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexMerah < 20)
            {
                cout << dataMerah.stasiun[indexMerah + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 20, tidak ada stasiun setelahnya
            }
            cout << endl;
        }
        else if (indexBiru != -1)
        {
            cout << "Jalur: Biru" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexBiru > 0)
            {
                cout << dataBiru.stasiun[indexBiru - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataBiru.stasiun[indexBiru] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexBiru < 13)
            {
                cout << dataBiru.stasiun[indexBiru + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 13, tidak ada stasiun setelahnya
            }
            cout << endl;
        }
        else if (indexPink != -1)
        {
            cout << "Jalur: Pink" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexPink > 0)
            {
                cout << dataPink.stasiun[indexPink - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataPink.stasiun[indexPink] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexPink < 3)
            {
                cout << dataPink.stasiun[indexPink + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 3, tidak ada stasiun setelahnya
            }
            cout << endl;
        }
        else if (indexHijauTua != -1)
        {
            cout << "Jalur: Hijau Tua" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexHijauTua > 0)
            {
                cout << dataHijauTua.stasiun[indexHijauTua - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataHijauTua.stasiun[indexHijauTua] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexHijauTua < 11)
            {
                cout << dataHijauTua.stasiun[indexHijauTua + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 11, tidak ada stasiun setelahnya
            }
            cout << endl;
        }
        else if (indexCoklat != -1)
        {
            cout << "Jalur: Coklaf" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexCoklat > 0)
            {
                cout << dataCoklat.stasiun[indexCoklat - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataCoklat.stasiun[indexCoklat] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexCoklat < 11)
            {
                cout << dataCoklat.stasiun[indexCoklat + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 11, tidak ada stasiun setelahnya
            }
            cout << endl;
        }
        else if (indexHijauMuda != -1)
        {
            cout << "Jalur: Hijau Muda" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexHijauMuda > 0)
            {
                cout << dataHijauMuda.stasiun[indexHijauMuda - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataHijauMuda.stasiun[indexHijauMuda] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexHijauMuda < 19)
            {
                cout << dataHijauMuda.stasiun[indexHijauMuda + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 11, tidak ada stasiun setelahnya
            }
            cout << endl;
        }

        else if (indexUngu != -1)
        {
            cout << "Jalur: Ungu" << endl;
            cout << "Stasiun sebelumnya: ";
            if (indexUngu > 0)
            {
                cout << dataUngu.stasiun[indexUngu - 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 0, tidak ada stasiun sebelumnya
            }
            cout << endl;

            cout << "Stasiun yang dimasukkan: " << dataUngu.stasiun[indexUngu] << endl;

            cout << "Stasiun setelahnya: ";
            if (indexUngu < 4)
            {
                cout << dataUngu.stasiun[indexUngu + 1];
            }
            else
            {
                cout << "Tidak ada"; // Jika indeks adalah 11, tidak ada stasiun setelahnya
            }
            cout << endl;
        }
        else
        {
            cout << "Stasiun tidak ditemukan." << endl;
        }
    }

    return 0;
}