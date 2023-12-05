#include <iostream>

using namespace std;

struct item
{
    string nama;
    int harga, stock, kode;
    item *next;
};

void tambahDataAwal(item **head)
{
    item *nodeBaru = new item();
    cout << "Masukkan kode barang: ";
    cin >> nodeBaru->kode;
    cout << "Masukkan nama barang: ";
    cin >> nodeBaru->nama;
    cout << "Masukkan harga barang: ";
    cin >> nodeBaru->harga;
    cout << "Masukkan stock barang: ";
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

void tambahDataEnd(item **head)
{
    item *nodeBaru = new item();
    cout << "Masukkan kode barang: ";
    cin >> nodeBaru->kode;
    cout << "Masukkan nama barang: ";
    cin >> nodeBaru->nama;
    cout << "Masukkan harga barang: ";
    cin >> nodeBaru->harga;
    cout << "Masukkan stock barang: ";
    cin >> nodeBaru->stock;
    nodeBaru->next = NULL;

    if (*head == NULL)
    {
        (*head) = nodeBaru;
        return;
    }

    item *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void displayData(item *head)
{
    item *temp = head;

    if (temp == NULL)
    {
        cout << "Linkedlist masih kosong" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << "Kode barang: " << temp->kode << endl;
        cout << "Nama barang: " << temp->nama << endl;
        cout << "Harga barang: " << temp->harga << endl;
        cout << "Stock barang: " << temp->stock << endl;
        cout << endl;
        temp = temp->next;
    }
}

void ubahData(item **head)
{
    int kode;
    cout << "Masukkan kode barang yang ingin diubah: ";
    cin >> kode;

    item *temp = (*head);
    while (temp != NULL)
    {
        if (temp->kode == kode)
        {
            cout << "Masukkan kode barang: ";
            cin >> temp->kode;
            cout << "Masukkan nama barang: ";
            cin >> temp->nama;
            cout << "Masukkan harga barang: ";
            cin >> temp->harga;
            cout << "Masukkan stock barang: ";
            cin >> temp->stock;
            cout << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode barang tidak ditemukan" << endl;
}

void hapusData(item **head)
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

    item *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    cout << "Node berhasil dihapus" << endl;
}

void transaksi(item **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }
    item *temp = (*head);
    int kode, jumlah, total;
    cout << "Masukkan kode barang: ";
    cin >> kode;
    cout << "Masukkan jumlah barang: ";
    cin >> jumlah;
    while (temp != NULL)
    {
        if (temp->kode == kode)
        {
            if (temp->stock >= jumlah)
            {
                total = temp->harga * jumlah;
                temp->stock -= jumlah;
                cout << "Total harga: " << total << endl;
                return;
            }
            else
            {
                cout << "Stock barang tidak cukup" << endl;
                return;
            }
        }
        temp = temp->next;
    }
    cout << "Kode barang tidak ditemukan" << endl;
}

int main()
{
    item *HEAD = NULL;
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