#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void tambahDataAwal(Node **head)
{
    // membuat node baru
    Node *nodeBaru = new Node();
    cout << "Masukkan angka : ";
    cin >> nodeBaru->data;
    nodeBaru->next = NULL;
    // jika linkedlist kosong, ditambahkan ke node.
    if (*head == NULL)
    {
        (*head) = nodeBaru;
        return;
    }
    // jika linkedlist tidak kosong, tambahkan node baru ke awal linkedlist
    nodeBaru->next = (*head);
    (*head) = nodeBaru;
}

void tambahDataEnd(Node **head)
{
    // membuat node baru
    Node *nodeBaru = new Node();
    cout << "Masukkan angka : ";
    cin >> nodeBaru->data;
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
        cout << temp->data << " ";
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
        *head = NULL;
        cout << "Node terlah terhapus" << endl;
        return;
    }

    Node *temp = (*head);
    // proses menjelajah semua node, sampai dengan sebelum node TAIL / node kosong nya
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    cout << "Node berhasil dihapus" << endl;
}

void ubahData(Node **head)
{

    if (*head == NULL)
    {
        cout << "Linkedlist masih kosong" << endl;
        return;
    }

    int ubah;
    cout << "Masukkan data yang ingin diubah: ";
    cin >> ubah;

    Node *temp = (*head);
    while (temp != NULL)
    {
        if (temp->data == ubah)
        {
            cout << "Masukkan data yang baru: ";
            cin >> temp->data;
            cout << "Data telah berhasil diubah" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

int main()
{

    struct Node *HEAD = NULL;
    int menu;
    while (menu != 9)
    {
        cout << "===MENU===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Ubah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Tampil Data" << endl;
        cout << "9. Exit" << endl;

        cout << "Silahkan Pilih Menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahDataAwal(&HEAD);
            tambahDataEnd(&HEAD);
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
        case 9:
            continue;
        default:
            cout << "Pilihan tdk ada !" << endl;
        }
    }
    return 0;
}