#include <iostream>

using namespace std;

struct buku
{
    string nama, kode;
    int stock, total;
    buku *next;
};

void tambahDataAwal(buku **head)
{
    buku *nodeBaru = new buku();
    cout << " Masukkan kode buku: ";
    cin >> nodeBaru->kode;
    cout << " Masukkan nama buku: ";
    cin.ignore();
    getline(cin, nodeBaru->nama);
    cout << " Masukkan stock buku: ";
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
    cout << " Masukkan kode buku: ";
    cin >> nodeBaru->kode;
    cout << " Masukkan nama buku: ";
    cin.ignore();
    getline(cin, nodeBaru->nama);
    cout << " Masukkan stock buku: ";
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
        cout << " Linkedlist masih kosong" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << " Kode buku: " << temp->kode << endl;
        cout << " Nama buku: " << temp->nama << endl;
        cout << " Stock buku: " << temp->stock << endl;
        if (temp->stock > 0)
        {
            cout << " Status buku: Tersedia" << endl;
        }
        else
        {
            cout << " Status buku: tidak tersedia" << endl;
        }
        if (temp->total == 0)
        {
            cout << " Biaya buku: belum ada" << endl;
        }
        else
        {
            cout << " Biaya buku: " << temp->total << endl;
        }

        cout << endl;
        temp = temp->next;
    }
}

void hapusData(buku **head)
{
    if (*head == NULL)
    {
        cout << " linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        *head = NULL;
        cout << " Node terlah terhapus" << endl;
        return;
    }

    buku *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    cout << " Node berhasil dihapus" << endl;
}

bool isBookAvailable(buku **head, string kode)
{
    buku *temp = *head;
    while (temp != NULL)
    {
        if (temp->kode == kode)
        {
            return temp->stock > 0;
        }
        temp = temp->next;
    }
    return false;
}

void transaksi(buku **head)
{
    if (*head == NULL)
    {
        cout << " linked list nya masih kosong" << endl;
        return;
    }
    buku *temp = (*head);
    string tanggal_awal, tanggal_akhir, kode;

    cout << " Masukkan kode buku: ";
    cin >> kode;

    if (!isBookAvailable(head, kode))
    {
        cout << " Buku tidak tersedia" << endl;
        return;
    }

    while (temp != NULL)
    {
        if (temp->kode == kode)
        {
            if (temp->stock > 0)
            {
                temp->stock--;
                cout << " Masukkan tanggal peminjaman (format: dd-mm-yyyy): ";
                cin >> tanggal_awal;
                cout << " Masukkan tanggal pengembalian (format: dd-mm-yyyy): ";
                cin >> tanggal_akhir;

                // Assuming the dates are in the format "dd-mm-yyyy"
                int day_awal = stoi(tanggal_awal.substr(0, 2));
                int day_akhir = stoi(tanggal_akhir.substr(0, 2));
                int total_days = day_akhir - day_awal;

                temp->total = total_days * 5000;
                cout << " Total biaya peminjaman: " << temp->total << endl;
                return;
            }
            else
            {
                cout << " Buku tidak tersedia" << endl;
                return;
            }
        }
        temp = temp->next;
    }
    cout << " Kode buku tidak ditemukan" << endl;
}

int main()
{
    buku *HEAD = NULL;
    int menu;
    bool isMenu = true;
    while (isMenu)
    {
        cout << "\n Peminjaman Buku" << endl;
        cout << "+---------------------+" << endl;
        cout << " 1. Tambah Data" << endl;
        cout << " 2. Hapus Data" << endl;
        cout << " 3. Tampil Data" << endl;
        cout << " 4. Transaksi" << endl;
        cout << " 0. Exit" << endl;
        cout << "+---------------------+" << endl;

        cout << " Silahkan Pilih Menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahDataAwal(&HEAD);
            // tambahDataEnd(&HEAD);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            hapusData(&HEAD);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            displayData(HEAD);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            transaksi(&HEAD);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 0:
            isMenu = false;
            cout << "   ______    __          __        ______    " << endl;
            cout << "  /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
            cout << " (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
            cout << "  \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
            cout << "  //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
            cout << " (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
            cout << "  \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
            break;
        default:
            cout << " Pilihan tdk ada !" << endl;
        }
    }
    return 0;
}