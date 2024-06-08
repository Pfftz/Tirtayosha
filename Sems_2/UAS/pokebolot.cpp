//WATERMARK ADMIN Hd
#include <iostream>
#include <ctime>
#include <deque>
#include <sstream>
#include <iomanip>

using namespace std;

struct pokeball
{
    string nama, kode;
    int stock, total;
};

void tambahDataAwal(deque<pokeball> &pokeballs)
{
    pokeball nodeBaru;
    nodeBaru.total = 0; // Initialize total to 0
    cout << " Masukkan kode pokeball: ";
    cin >> nodeBaru.kode;
    cout << " Masukkan nama pokeball: ";
    cin.ignore();
    getline(cin, nodeBaru.nama);
    cout << " Masukkan stock pokeball: ";
    cin >> nodeBaru.stock;

    pokeballs.push_front(nodeBaru);
}

void tambahDataEnd(deque<pokeball> &pokeballs)
{
    pokeball nodeBaru;
    nodeBaru.total = 0; // Initialize total to 0
    cout << " Masukkan kode pokeball: ";
    cin >> nodeBaru.kode;
    cout << " Masukkan nama pokeball: ";
    cin.ignore();
    getline(cin, nodeBaru.nama);
    cout << " Masukkan stock pokeball: ";
    cin >> nodeBaru.stock;

    pokeballs.push_back(nodeBaru);
}

void displayData(const deque<pokeball> &pokeballs)
{
    if (pokeballs.empty())
    {
        cout << " Deque masih kosong" << endl;
        return;
    }

    for (const auto &temp : pokeballs)
    {
        cout << " Kode pokeball: " << temp.kode << endl;
        cout << " Nama pokeball: " << temp.nama << endl;
        cout << " Stock pokeball: " << temp.stock << endl;
        if (temp.stock > 0)
        {
            cout << " Status pokeball: Tersedia" << endl;
        }
        else
        {
            cout << " Status pokeball: tidak tersedia" << endl;
        }
        if (temp.total == 0)
        {
            cout << " Biaya pokeball: belum ada" << endl;
        }
        else
        {
            cout << " Biaya pokeball: " << temp.total << endl;
        }

        cout << endl;
    }
}

void hapusDataAwal(deque<pokeball> &pokeballs)
{
    if (pokeballs.empty())
    {
        cout << "Deque masih kosong" << endl;
        return;
    }

    pokeballs.pop_front();

    cout << "Node awal berhasil dihapus" << endl;
}

void hapusDataAkhir(deque<pokeball> &pokeballs)
{
    if (pokeballs.empty())
    {
        cout << "Deque masih kosong" << endl;
        return;
    }

    pokeballs.pop_back();

    cout << "Node akhir berhasil dihapus" << endl;
}

bool ispokeballAvailable(const deque<pokeball> &pokeballs, const string &kode)
{
    for (const auto &temp : pokeballs)
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

void transaksi(deque<pokeball> &pokeballs)
{
    if (pokeballs.empty())
    {
        cout << " Deque masih kosong" << endl;
        return;
    }
    string tanggal_awal, tanggal_akhir, kode;

    cout << " Masukkan kode pokeball: ";
    cin >> kode;

    if (!ispokeballAvailable(pokeballs, kode))
    {
        cout << " pokeball tidak tersedia" << endl;
        return;
    }

    for (auto &temp : pokeballs)
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
                cout << " pokeball tidak tersedia" << endl;
                return;
            }
        }
    }
    cout << " Kode pokeball tidak ditemukan" << endl;
}

int main()
{
    deque<pokeball> pokeballs;
    int menu;
    bool isMenu = true;
    while (isMenu)
    {
        cout << "\n Peminjaman pokeball" << endl;
        cout << "+---------------------+" << endl;
        cout << " 1. Tambah Data pokeball" << endl;
        cout << " 2. Hapus Data pokeball" << endl;
        cout << " 3. Tampil Data pokeball" << endl;
        cout << " 4. Transaksi pokeball" << endl;
        cout << " 0. Exit" << endl;
        cout << " WATERMARK ADMIN Hd" << endl;
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
                tambahDataAwal(pokeballs);
                break;
            case 2:
                tambahDataEnd(pokeballs);
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
                hapusDataAwal(pokeballs);
                break;
            case 2:
                hapusDataAkhir(pokeballs);
                break;
            default:
                break;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            displayData(pokeballs);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            transaksi(pokeballs);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 0:
            isMenu = false;
            break;
        default:
            cout << "\n Lead Them To Paradise! - Abdulhadi" << endl;
        }
    }
    return 0;
}