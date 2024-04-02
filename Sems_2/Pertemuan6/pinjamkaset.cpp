#include <iostream>
#include <ctime>
#include <deque>
#include <sstream>
#include <iomanip>

using namespace std;

struct film
{
    string nama, kode;
    int stock, total;
};

void tambahDataAwal(deque<film> &films)
{
    film nodeBaru;
    nodeBaru.total = 0; // Initialize total to 0
    cout << " Masukkan kode film: ";
    cin >> nodeBaru.kode;
    cout << " Masukkan nama film: ";
    cin.ignore();
    getline(cin, nodeBaru.nama);
    cout << " Masukkan stock film: ";
    cin >> nodeBaru.stock;

    films.push_front(nodeBaru);
}

void tambahDataEnd(deque<film> &films)
{
    film nodeBaru;
    nodeBaru.total = 0; // Initialize total to 0
    cout << " Masukkan kode film: ";
    cin >> nodeBaru.kode;
    cout << " Masukkan nama film: ";
    cin.ignore();
    getline(cin, nodeBaru.nama);
    cout << " Masukkan stock film: ";
    cin >> nodeBaru.stock;

    films.push_back(nodeBaru);
}

void displayData(const deque<film> &films)
{
    if (films.empty())
    {
        cout << " Deque masih kosong" << endl;
        return;
    }

    for (const auto &temp : films)
    {
        cout << " Kode film: " << temp.kode << endl;
        cout << " Nama film: " << temp.nama << endl;
        cout << " Stock film: " << temp.stock << endl;
        if (temp.stock > 0)
        {
            cout << " Status film: Tersedia" << endl;
        }
        else
        {
            cout << " Status film: tidak tersedia" << endl;
        }
        if (temp.total == 0)
        {
            cout << " Biaya film: belum ada" << endl;
        }
        else
        {
            cout << " Biaya film: " << temp.total << endl;
        }

        cout << endl;
    }
}

void hapusDataAwal(deque<film> &films)
{
    if (films.empty())
    {
        cout << "Deque masih kosong" << endl;
        return;
    }

    films.pop_front();

    cout << "Node awal berhasil dihapus" << endl;
}

void hapusDataAkhir(deque<film> &films)
{
    if (films.empty())
    {
        cout << "Deque masih kosong" << endl;
        return;
    }

    films.pop_back();

    cout << "Node akhir berhasil dihapus" << endl;
}

bool isFilmAvailable(const deque<film> &films, const string &kode)
{
    for (const auto &temp : films)
    {
        if (temp.kode == kode)
        {
            return temp.stock > 0;
        }
    }
    return false;
}

std::time_t parseDate(const std::string &date)
{
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%d-%m-%Y");
    return std::mktime(&tm);
}

void transaksi(deque<film> &films)
{
    if (films.empty())
    {
        cout << " Deque masih kosong" << endl;
        return;
    }
    string tanggal_awal, tanggal_akhir, kode;

    cout << " Masukkan kode film: ";
    cin >> kode;

    if (!isFilmAvailable(films, kode))
    {
        cout << " film tidak tersedia" << endl;
        return;
    }

    for (auto &temp : films)
    {
        if (temp.kode == kode)
        {
            if (temp.stock > 0)
            {
                temp.stock--;
                cout << " Masukkan tanggal peminjaman (format: dd-mm-yyyy): ";
                cin >> tanggal_awal;
                cout << " Masukkan tanggal pengembalian (format: dd-mm-yyyy): ";
                cin >> tanggal_akhir;

                std::time_t time_awal = parseDate(tanggal_awal);
                std::time_t time_akhir = parseDate(tanggal_akhir);

                double total_days = std::difftime(time_akhir, time_awal) / (60 * 60 * 24);

                temp.total = total_days * 5000;
                cout << " Total biaya peminjaman: " << temp.total << endl;
                return;
            }
            else
            {
                cout << " film tidak tersedia" << endl;
                return;
            }
        }
    }
    cout << " Kode film tidak ditemukan" << endl;
}

int main()
{
    deque<film> films;
    int menu;
    bool isMenu = true;
    while (isMenu)
    {
        cout << "\n Peminjaman Film" << endl;
        cout << "+---------------------+" << endl;
        cout << " 1. Tambah Data Film" << endl;
        cout << " 2. Hapus Data Film" << endl;
        cout << " 3. Tampil Data Film" << endl;
        cout << " 4. Transaksi Film" << endl;
        cout << " 0. Exit" << endl;
        cout << "+---------------------+" << endl;

        cout << " Silahkan Pilih Menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:

            cout << " 1. Tambah data depan" << endl;
            cout << " 2. Tambah data belakang" << endl;
            int p;
            cout << " Masukkan menu: ";
            cin >> p;
            switch (p)
            {
            case 1:
                tambahDataAwal(films);
                break;
            case 2:
                tambahDataEnd(films);
                break;
            default:
                break;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << " 1. Hapus data depan" << endl;
            cout << " 2. Hapus data belakang" << endl;
            int p1;
            cout << " Masukkan menu: ";
            cin >> p1;
            switch (p1)
            {
            case 1:
                hapusDataAwal(films);
                break;
            case 2:
                hapusDataAkhir(films);
                break;
            default:
                break;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            displayData(films);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            transaksi(films);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 0:
            isMenu = false;
            break;
        default:
            cout << " Pilihan tdk ada !" << endl;
        }
    }
    return 0;
}