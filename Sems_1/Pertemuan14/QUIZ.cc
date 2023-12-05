#include <iostream>

using namespace std;

struct buku
{
    string nama;
    int harga, stock, kode;
    bool status;
    buku *next;
};

void tambahDataAwal(buku **head)
{
    buku *nodeBaru = new buku();
    cout << "Masukkan kode buku: ";
    cin >> nodeBaru->kode;
    cout << "Masukkan nama buku: ";
    cin >> nodeBaru->nama;
    cout << "Masukkan harga buku: ";
    cin >> nodeBaru->harga;
    cout << "Masukkan stock buku: ";
    cin >> nodeBaru->stock;
    nodeBaru->next = NULL;

    if (*head == NULL)
    {
        (*head) = nodeBaru;
        return;
    }

    nodeBaru->next = (*head);
    (*head) = nodeBaru;
}

void tambahDataEnd(buku **head)
{
    buku *nodeBaru = new buku();
    cout << "Masukkan kode buku: ";
    cin >> nodeBaru->kode;
    cout << "Masukkan nama buku: ";
    cin >> nodeBaru->nama;
    cout << "Masukkan harga buku: ";
    cin >> nodeBaru->harga;
    cout << "Masukkan stock buku: ";
    cin >> nodeBaru->stock;
    nodeBaru->next = NULL;

    if (*head == NULL)
    {
        (*head) = nodeBaru;
        return;
    }

    buku *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void displayData(buku *head)
{
    buku *temp = head;

    if (temp == NULL)
    {
        cout << "Linkedlist masih kosong" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << "Kode buku: " << temp->kode << endl;
        cout << "Nama buku: " << temp->nama << endl;
        cout << "Harga buku: " << temp->harga << endl;
        cout << "Stock buku: " << temp->stock << endl;
        cout << endl;
        temp = temp->next;
    }
}

void ubahData(buku **head)
{
    int kode;
    cout << "Masukkan kode buku yang ingin diubah: ";
    cin >> kode;

    buku *temp = (*head);
    while (temp != NULL)
    {
        if (temp->kode == kode)
        {
            cout << "Masukkan kode buku: ";
            cin >> temp->kode;
            cout << "Masukkan nama buku: ";
            cin >> temp->nama;
            cout << "Masukkan harga buku: ";
            cin >> temp->harga;
            cout << "Masukkan stock buku: ";
            cin >> temp->stock;
            cout << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode buku tidak ditemukan" << endl;
}

void hapusData(buku **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        *head = NULL;
        cout << "Node terlah terhapus" << endl;
        return;
    }

    buku *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    cout << "Node berhasil dihapus" << endl;
}

void transaksi(buku **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }
    buku *temp = (*head);
    int kode, total;
    string tanggal_awal, tanggal_akhir;

    cout << "Masukkan kode buku: ";
    cin >> kode;

    while (temp != NULL)
    {
        if (temp->kode == kode)
        {
            if (temp->stock > 0)
            {
                temp->stock--;
                if (temp->stock == 0)
                {
                    temp->status = "Tidak tersedia";
                }
                cout << "Masukkan tanggal peminjaman (format: dd-mm-yyyy): ";
                cin >> tanggal_awal;
                cout << "Masukkan tanggal pengembalian (format: dd-mm-yyyy): ";
                cin >> tanggal_akhir;

                // Assuming the dates are in the format "dd-mm-yyyy"
                int day_awal = stoi(tanggal_awal.substr(0, 2));
                int day_akhir = stoi(tanggal_akhir.substr(0, 2));
                int total_days = day_akhir - day_awal;

                total = total_days * 5000;
                cout << "Total biaya peminjaman: " << total << endl;
                return;
            }
            else
            {
                cout << "Buku tidak tersedia" << endl;
                return;
            }
        }
        temp = temp->next;
    }
    cout << "Kode buku tidak ditemukan" << endl;
}

int main()
{
    buku *HEAD = NULL;
    int menu;
    bool isMenu = true;
    while (isMenu)
    {
        cout << "===MENU===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Ubah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Tampil Data" << endl;
        cout << "5. Transaksi" << endl;
        cout << "9. Exit" << endl;

        cout << "Silahkan Pilih Menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahDataAwal(&HEAD);
            // tambahDataEnd(&HEAD);
            break;
        case 2:
            ubahData(&HEAD);
            break;
        case 3:
            hapusData(&HEAD);
            break;
        case 4:
            displayData(HEAD);
            break;
        case 5:
            transaksi(&HEAD);
            break;
        case 9:
            isMenu = false;
            break;
        default:
            cout << "Pilihan tdk ada !" << endl;
        }
    }
    return 0;
}