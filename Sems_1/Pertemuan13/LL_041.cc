#include <iostream>

using namespace std;

struct Node
{
    int rekening, saldo;
    string nama, alamat;
    struct Node *next;
};

void tambahData(Node **head)
{
    // membuat node baru
    Node *nodeBaru = new Node();
    cout << "Masukkan no.rekening : ";
    cin >> nodeBaru->rekening;
    cout << "Masukkan nama : ";
    cin >> nodeBaru->nama;
    cout << "Masukkan alamat : ";
    cin >> nodeBaru->alamat;
    cout << "Masukkan saldo : ";
    cin >> nodeBaru->saldo;
    nodeBaru->next = NULL;
    // jika linkedlist kosong, ditambahkan ke node.
    if (*head == NULL)
    {
        (*head) = nodeBaru;
        return;
    }
    //
    Node *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void displayData(Node *head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Linkedlist masih kosong" << endl;
        return;
    }
    // jelajahi sampai node terakhir
    while (temp != NULL)
    {
        cout << temp->rekening << " ";
        cout << temp->nama << " ";
        cout << temp->alamat << " ";
        cout << temp->saldo << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusData(Node **head)
{

    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        Node *temp = (*head);
        (*head) = NULL;
        free(temp);
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}

void ubahData(Node **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        cout << "linked list nya hanya 1" << endl;
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Masukkan no.rekening : ";
    cin >> temp->rekening;
    cout << "Masukkan nama : ";
    cin >> temp->nama;
    cout << "Masukkan alamat : ";
    cin >> temp->alamat;
    cout << "Masukkan saldo : ";
    cin >> temp->saldo;
}

void cariData(Node **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        cout << "linked list nya hanya 1" << endl;
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Masukkan no.rekening : ";
    cin >> temp->rekening;
    cout << "Masukkan nama : ";
    cin >> temp->nama;
    cout << "Masukkan alamat : ";
    cin >> temp->alamat;
    cout << "Masukkan saldo : ";
    cin >> temp->saldo;
}

void cekSaldo(Node **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        cout << "linked list nya hanya 1" << endl;
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Masukkan no.rekening : ";
    cin >> temp->rekening;
    cout << "Masukkan nama : ";
    cin >> temp->nama;
    cout << "Masukkan alamat : ";
    cin >> temp->alamat;
    cout << "Masukkan saldo : ";
    cin >> temp->saldo;
}

void transaksi(Node **head)
{
    if (*head == NULL)
    {
        cout << "linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        cout << "linked list nya hanya 1" << endl;
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Masukkan no.rekening : ";
    cin >> temp->rekening;
    cout << "Masukkan nama : ";
    cin >> temp->nama;
    cout << "Masukkan alamat : ";
    cin >> temp->alamat;
    cout << "Masukkan saldo : ";
    cin >> temp->saldo;
}

int main()
{
    int pilih;
    bool menu = true;
    while (menu)
    {
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |                        PT. Bank Riba                        |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |Menu :                                                       |" << endl;
        cout << " |1. Input Data Nasabah(Input no.rekening, nama, alamat, saldo)|" << endl;
        cout << " |2. Hapus Data Nasabah(Hapus data berdasarkan no.rekening)    |" << endl;
        cout << " |3. Transaksi(Deposit dan tarik tunai)                        |" << endl;
        cout << " |4. Cek Saldo                                                 |" << endl;
        cout << " |5. Tampilkan Daftar Nasabah                                  |" << endl;
        cout << " |6. Cari Data Nasabah                                         |" << endl;
        cout << " |7. Keluar                                                    |" << endl;
        cout << " |Pilih Menu : ";
        cin >> pilih;
        cout << " |                                                             |" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        switch (pilih)
        {
        case 1:
            cout << "Input Data Nasabah" << endl;
            break;
        case 2:
            cout << "Hapus Data Nasabah" << endl;
            break;
        case 3:
            cout << "Transaksi" << endl;
            break;
        case 4:
            cout << "Cek Saldo" << endl;
            break;
        case 5:
            cout << "Tampilkan Daftar Nasabah" << endl;
            break;
        case 6:
            cout << "Cari Data Nasabah" << endl;
            break;
        case 7:
            cout << "Keluar" << endl;
            menu = false;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
        cout << endl;
        return 0;
    }
}