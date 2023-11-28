#include <iostream>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

struct Node
{
    int rekening, saldo;
    string nama, alamat;
    struct Node *next;
};

void tambahData(Node **head, int *ptrN)
{
    Node *temp = *head;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }

    for (int i = 0; i < *ptrN; i++)
    {
        // membuat node baru
        Node *nodeBaru = new Node();

        cout << " Masukkan data nasabah baru : " << endl;
        cout << endl;
        cout << "   Masukkan no.rekening : ";
        cin >> nodeBaru->rekening;
        cout << "   Masukkan nama        : ";
        cin >> nodeBaru->nama;
        cout << "   Masukkan alamat      : ";
        cin >> nodeBaru->alamat;
        cout << "   Masukkan saldo       : ";
        cin >> nodeBaru->saldo;
        cout << endl;
        nodeBaru->next = NULL;

        if (temp == NULL)
        {
            *head = nodeBaru;
        }
        else
        {
            temp->next = nodeBaru;
        }

        temp = nodeBaru;
    }
    cout << " Data berhasil ditambahkan!!!" << endl;
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void displayData(Node *head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << " Linkedlist masih kosong" << endl;
        cout << endl;
        system("pause");
        system("cls");
        return;
    }
    // jelajahi sampai node terakhir
    int i = 1;
    while (temp != NULL)
    {
        cout << " Data Nasabah ke - " << i << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " | No.rekening : " << temp->rekening << "                      |" << endl;
        cout << " | Nama        : " << temp->nama << "                          |" << endl;
        cout << " | Alamat      : " << temp->alamat << "                        |" << endl;
        cout << " | Saldo       : " << temp->saldo << "                         |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << endl;
        temp = temp->next;
        i++;
    }
    cout << endl;
    system("pause");
    system("cls");
}

auto hapusData = [](Node **head)
{
    if (*head == NULL)
    {
        cout << " Linked list nya masih kosong" << endl;
        cout << endl;
        system("pause");
        system("cls");
        return;
    }

    if ((*head)->next == NULL)
    {
        Node *temp = (*head);
        (*head) = NULL;
        free(temp);
        cout << " Node telah terhapus" << endl;
        cout << endl;
        system("pause");
        system("cls");
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
};

void ubahData(Node **head)
{
    if (*head == NULL)
    {
        cout << " Linked list nya masih kosong" << endl;
        return;
    }

    if ((*head)->next == NULL)
    {
        cout << " Linked list nya hanya 1" << endl;
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    cout << " Masukkan no.rekening : ";
    cin >> temp->rekening;
    cout << " Masukkan nama : ";
    cin >> temp->nama;
    cout << " Masukkan alamat : ";
    cin >> temp->alamat;
    cout << " Masukkan saldo : ";
    cin >> temp->saldo;
}

void cariData(Node **head)
{
    if (*head == NULL)
    {
        cout << " Linked list nya masih kosong" << endl;
        return;
    }

    int cariRekening;
    cout << " Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->rekening == cariRekening)
        {
            cout << " Data ditemukan!!!" << endl;
            cout << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << " | No.rekening : " << temp->rekening << "                      |" << endl;
            cout << " | Nama        : " << temp->nama << "                          |" << endl;
            cout << " | Alamat      : " << temp->alamat << "                        |" << endl;
            cout << " | Saldo       : " << temp->saldo << "                         |" << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << endl;
            return;
        }
        temp = temp->next;
    }

    cout << " Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
}

void cekSaldo(Node **head)
{
    if (*head == NULL)
    {
        cout << " Linked list nya masih kosong" << endl;
        return;
    }

    int cariRekening;
    cout << " Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->rekening == cariRekening)
        {
            cout << " Saldo untuk no.rekening " << cariRekening << " adalah: " << temp->saldo << endl;
            return;
        }
        temp = temp->next;
    }

    cout << " Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
}

void transaksi(Node **head)
{
    if (*head == NULL)
    {
        cout << "Linked list nya masih kosong" << endl;
        return;
    }

    int cariRekening, pilih, transaksi;
    cout << "Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->rekening == cariRekening)
        {
            cout << " 1. Tarik Tunai" << endl;
            cout << " 2. Deposit" << endl;
            cout << " Pilih transaksi: ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                cout << "Masukkan jumlah transaksi: ";
                cin >> transaksi;
                if (transaksi > temp->saldo)
                {
                    cout << "Saldo tidak cukup untuk transaksi ini." << endl;
                    return;
                }
                temp->saldo -= transaksi; // subtract the transaction amount from the balance
                cout << "Transaksi berhasil! Saldo sekarang: " << temp->saldo << endl;
                return;
            case 2:
                cout << "Masukkan jumlah transaksi: ";
                cin >> transaksi;
                temp->saldo += transaksi; // add the transaction amount to the balance
                cout << "Transaksi berhasil! Saldo sekarang: " << temp->saldo << endl;
                return;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                return;
            }
        }
        temp = temp->next;
    }

    cout << "Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
}

auto input = [](int *ptrN)
{
    cout << " Masukkan jumlah data yang ingin diinput : ";
    cin >> *ptrN;
    cout << endl;
    return ptrN;
};

int main()
{
    Node *head = NULL;
    int pilih, n;
    bool loop = true;
    while (loop)
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
        cout << " +-------------------------------------------------------------+" << endl;
        cout << "  Pilih Menu : ";
        cin >> pilih;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << endl;
        switch (pilih)
        {
        case 1:
            input(&n);
            tambahData(&head, &n);
            break;
        case 2:
            hapusData(&head);
            break;
        case 3:
            transaksi(&head);
            break;
        case 4:
            cekSaldo(&head);
            break;
        case 5:
            displayData(head);
            break;
        case 6:
            cariData(&head);
            break;
        case 7:
            cout << endl;
            SetConsoleTextAttribute(h, 5);
            cout << "   ______    __          __        ______    " << endl;
            cout << "  /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
            cout << " (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
            cout << "  \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
            cout << "  //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
            cout << " (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
            cout << "  \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
            loop = false;
            break;
        default:
            cout << " Menu tidak tersedia" << endl;
            break;
        }
    }
    cout << endl;
    return 0;
}