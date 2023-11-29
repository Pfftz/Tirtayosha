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

void welcome()
{
    string opening = R"(
   ,--,                                                                  ,--,                                  
,---.'|                                                               ,---.'|                                  
|   | :                              ,-.                              |   | :                          ___     
:   : |     ,--,                 ,--/ /|                 ,---,        :   : |     ,--,               ,--.'|_   
|   ' :   ,--.'|         ,---, ,--. :/ |               ,---.'|        |   ' :   ,--.'|               |  | :,'  
;   ; '   |  |,      ,-+-. /  |:  : ' /                |   | :        ;   ; '   |  |,      .--.--.   :  : ' :  
'   | |__ `--'_     ,--.'|'   ||  '  /      ,---.      |   | |        '   | |__ `--'_     /  /    '.;__,'  /   
|   | :.'|,' ,'|   |   |  ,"' |'  |  :     /     \   ,--.__| |        |   | :.'|,' ,'|   |  :  /`./|  |   |    
'   :    ;'  | |   |   | /  | ||  |   \   /    /  | /   ,'   |        '   :    ;'  | |   |  :  ;_  :__,'| :    
|   |  ./ |  | :   |   | |  | |'  : |. \ .    ' / |.   '  /  |        |   |  ./ |  | :    \  \    `. '  : |__  
;   : ;   '  : |__ |   | |  |/ |  | ' \ \'   ;   /|'   ; |:  |        ;   : ;   '  : |__   `----.   \|  | '.'| 
|   ,/    |  | '.'||   | |--'  '  : |--' '   |  / ||   | '/  '        |   ,/    |  | '.'| /  /`--'  /;  :    ; 
'---'     ;  :    ;|   |/      ;  |,'    |   :    ||   :    :|        '---'     ;  :    ;'--'.     / |  ,   /  
          |  ,   / '---'       '--'       \   \  /  \   \  /                    |  ,   /   `--'---'   ---`-'   
           ---`-'                          `----'    `----'                      ---`-'                        
                                                                                                               
)";
    SetConsoleTextAttribute(h, 14);
    cout << opening << endl;
    cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        cout << "-";
    }
    cout << endl;
    cout << " Nama : Abdulhadi Muntashir" << endl;
    cout << " NIM  : 3337230041" << endl;
    cout << " ";
    for (int i = 0; i < 40; i++)
    {
        Sleep(100);
        cout << "-";
    }
    cout << endl;
    SetConsoleTextAttribute(h, 7);
    cout << endl;
    system("pause");
    system("cls");
}

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

        cout << "  Masukkan data nasabah baru : " << endl;
        cout << endl;
        cout << "    Masukkan no.rekening : ";
        cin >> nodeBaru->rekening;
        cout << "    Masukkan nama        : ";
        cin >> nodeBaru->nama;
        cout << "    Masukkan alamat      : ";
        cin >> nodeBaru->alamat;
        cout << "    Masukkan saldo       : ";
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
    cout << "  Data berhasil ditambahkan!!!" << endl;
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
}

void displayData(Node *head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "  Linkedlist masih kosong" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }
    // jelajahi sampai node terakhir
    int i = 1;
    while (temp != NULL)
    {
        cout << " Data Nasabah ke - " << i << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << "  No.rekening : " << temp->rekening << endl;
        cout << "  Nama        : " << temp->nama << endl;
        cout << "  Alamat      : " << temp->alamat << endl;
        cout << "  Saldo       : " << temp->saldo << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << endl;
        temp = temp->next;
        i++;
    }
}

auto hapusData = [](Node **head)
{
    if (*head == NULL)
    {
        cout << "  Linked list nya masih kosong" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    int cariRekening;
    cout << "  Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    if ((*head)->rekening == cariRekening)
    {
        Node *temp = (*head);
        (*head) = (*head)->next;
        delete temp;
        cout << "  Node telah terhapus" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    Node *temp = (*head);
    while (temp->next != NULL && temp->next->rekening != cariRekening)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "  Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
    cout << "  Node telah terhapus" << endl;
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
};

void ubahData(Node **head)
{
    if (*head == NULL)
    {
        cout << "  Linked list nya masih kosong" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    int pos;
    cout << "  Masukkan posisi node yang ingin diubah: ";
    cin >> pos;

    Node *temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "  Posisi tidak valid" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    int pilih;
    cout << "  1. Ubah no.rekening" << endl;
    cout << "  2. Ubah nama" << endl;
    cout << "  3. Ubah alamat" << endl;
    cout << "  4. Ubah saldo" << endl;
    cout << "  5. Ubah semua data" << endl;
    cout << "  Pilih opsi: ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        cout << "  Masukkan no.rekening baru: ";
        cin >> temp->rekening;
        break;
    case 2:
        cout << "  Masukkan nama baru: ";
        cin >> temp->nama;
        break;
    case 3:
        cout << "  Masukkan alamat baru: ";
        cin >> temp->alamat;
        break;
    case 4:
        cout << "  Masukkan saldo baru: ";
        cin >> temp->saldo;
        break;
    case 5:
        cout << "  Masukkan no.rekening baru: ";
        cin >> temp->rekening;
        cout << "  Masukkan nama baru: ";
        cin >> temp->nama;
        cout << "  Masukkan alamat baru: ";
        cin >> temp->alamat;
        cout << "  Masukkan saldo baru: ";
        cin >> temp->saldo;
        break;
    default:
        cout << "  Pilihan tidak valid" << endl;
        break;
    }
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
}

void cariData(Node **head)
{
    if (*head == NULL)
    {
        cout << "  Linked list nya masih kosong" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    int cariRekening;
    cout << "  Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->rekening == cariRekening)
        {
            cout << endl;
            cout << " Data ditemukan!!!" << endl;
            cout << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << "  No.rekening : " << temp->rekening << endl;
            cout << "  Nama        : " << temp->nama << endl;
            cout << "  Alamat      : " << temp->alamat << endl;
            cout << "  Saldo       : " << temp->saldo << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            cout << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "  Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
}

void cekSaldo(Node **head)
{
    if (*head == NULL)
    {
        cout << "  Linked list nya masih kosong" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    int cariRekening;
    cout << "  Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->rekening == cariRekening)
        {
            cout << "  Saldo untuk no.rekening " << cariRekening << " adalah: " << temp->saldo << endl;
            cout << endl;
            cout << " +-------------------------------------------------------------+" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "  Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
}

void transaksi(Node **head)
{
    if (*head == NULL)
    {
        cout << "  Linked list nya masih kosong" << endl;
        cout << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        return;
    }

    int cariRekening, pilih, transaksi;
    cout << "  Masukkan no.rekening yang dicari: ";
    cin >> cariRekening;

    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->rekening == cariRekening)
        {
            cout << "  1. Tarik Tunai" << endl;
            cout << "  2. Deposit" << endl;
            cout << "  Pilih transaksi: ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                cout << "  Masukkan jumlah transaksi: ";
                cin >> transaksi;
                if (transaksi > temp->saldo)
                {
                    cout << "  Saldo tidak cukup untuk transaksi ini." << endl;
                    return;
                }
                temp->saldo -= transaksi; // subtract the transaction amount from the balance
                cout << "  Transaksi berhasil! Saldo sekarang: " << temp->saldo << endl;
                break;
            case 2:
                cout << "  Masukkan jumlah transaksi: ";
                cin >> transaksi;
                temp->saldo += transaksi; // add the transaction amount to the balance
                cout << "  Transaksi berhasil! Saldo sekarang: " << temp->saldo << endl;
                break;
            default:
                cout << "  Pilihan tidak tersedia" << endl;
                break;
            }
            cout << endl;
            cout << " +-------------------------------------------------------------+" << endl;
        }
        temp = temp->next;
    }

    cout << "  Data dengan no.rekening " << cariRekening << " tidak ditemukan." << endl;
    cout << endl;
    cout << " +-------------------------------------------------------------+" << endl;
}

auto input = [](int *ptrN)
{
    cout << "  Masukkan jumlah data yang ingin diinput : ";
    cin >> *ptrN;
    cout << endl;
    return ptrN;
};

int main()
{
    Node *head = NULL;
    int pilih, n;
    bool loop = true;
    welcome();
    SetConsoleTextAttribute(h, 13);
    while (loop)
    {
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |                      PT. Bank Riba                          |" << endl;
        cout << " +-------------------------------------------------------------+" << endl;
        cout << " |Menu :                                                       |" << endl;
        cout << " |1. Input Data Nasabah(Input no.rekening, nama, alamat, saldo)|" << endl;
        cout << " |2. Hapus Data Nasabah(Hapus data berdasarkan no.rekening)    |" << endl;
        cout << " |3. Update Data Nasabah                                       |" << endl;
        cout << " |4. Transaksi(Deposit dan tarik tunai)                        |" << endl;
        cout << " |5. Tampilkan Daftar Nasabah                                  |" << endl;
        cout << " |6. Cek Saldo                                                 |" << endl;
        cout << " |7. Cari Data Nasabah                                         |" << endl;
        cout << " |8. Keluar                                                    |" << endl;
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
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            hapusData(&head);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            ubahData(&head);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            transaksi(&head);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            displayData(head);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 6:
            cekSaldo(&head);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 7:
            cariData(&head);
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 8:
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