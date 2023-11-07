#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

struct mahasiswa
{
    int nim;
    string nama;
};

struct parkir
{
    int jam, menit, detik;
    int selisih, biaya;
};

void welcome()
{
    string opening = R"(
  ________  ___________  _______   ____  ____   ______  ___________  
 /"       )("     _   ")/"      \ ("  _||_ " | /" _  "\("     _   ") 
(:   \___/  )__/  \\__/|:        ||   (  ) : |(: ( \___))__/  \\__/  
 \___  \       \\_ /   |_____/   )(:  |  | . ) \/ \        \\_ /     
  __/  \\      |.  |    //      /  \\ \__/ //  //  \ _     |.  |     
 /" \   :)     \:  |   |:  __   \  /\\ __ //\ (:   _) \    \:  |     
(_______/       \__|   |__|  \___)(__________) \_______)    \__|     
                                                                     
)";
    SetConsoleTextAttribute(h, 12);
    cout << opening << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "====================================" << endl;
    cout << " Nama: Abdulhadi Muntashir" << endl;
    cout << " NIM: 3337230041" << endl;
    cout << "====================================" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu1(int *pn)
{
    cout << " Masukkan nilai n: ";
    cin >> *pn;

    mahasiswa *data = new mahasiswa[*pn];

    int temp;
    string temp2;
    for (int i = 0; i < *pn; i++)
    {
        cout << " Masukkan data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << " NIM[0]    : ";
        cin >> data[i].nim;
        cout << " Nama[1]   : ";
        cin >> data[i].nama;
        cout << endl;
    }

    for (int i = 0; i < *pn; i++)
    {
        for (int j = i + 1; j < *pn; j++)
        {
            if (data[i].nim < data[j].nim)
            {
                temp = data[i].nim;        // nim[i]
                data[i].nim = data[j].nim; // nim[i] = nim[j]
                data[j].nim = temp;        // nim[j] = temp

                temp2 = data[i].nama;        // nama[i]
                data[i].nama = data[j].nama; // nama[i] = nama[j]
                data[j].nama = temp2;        // nama[j] = temp2
            }
        }
    }

    cout << " Hasil akhir setelah diurutkan berdasarkan NIM adalah: " << endl;
    for (int i = 0; i < *pn; i++)
    {
        cout << " (NIM: " << data[i].nim;
        cout << " Nama: " << data[i].nama << ") " << endl;
    }

    delete[] data;

    cout << endl;
    system("pause");
    system("cls");
}

void menu2()
{
    parkir arrived, departure;
    int diffJam, diffMenit, diffDetik;
    cout << " Program menghitung biaya parkir" << endl;
    cout << endl;
    cout << " +--------------------------------+" << endl;
    cout << " Input arrived time" << endl;
    cout << " Hour: ";
    cin >> arrived.jam;
    cout << " Minute: ";
    cin >> arrived.menit;
    cout << " Second: ";
    cin >> arrived.detik;
    cout << endl;
    cout << " Input departure time" << endl;
    cout << " Hour: ";
    cin >> departure.jam;
    cout << " Minute: ";
    cin >> departure.menit;
    cout << " Second: ";
    cin >> departure.detik;
    cout << " +--------------------------------+" << endl;
    cout << endl;

    cout << " Arrived time = "
         << setw(2) << setfill('0') << arrived.jam << ":"
         << setw(2) << setfill('0') << arrived.menit << ":"
         << setw(2) << setfill('0') << arrived.detik << endl;

    cout << " Departure time = "
         << setw(2) << setfill('0') << departure.jam << ":"
         << setw(2) << setfill('0') << departure.menit << ":"
         << setw(2) << setfill('0') << departure.detik << endl;

    if (departure.detik < arrived.detik)
    {
        departure.detik += 60;
        departure.menit--;
    }

    diffDetik = departure.detik - arrived.detik;

    if (departure.menit < arrived.menit)
    {
        departure.menit += 60;
        departure.jam--;
    }

    diffMenit = departure.menit - arrived.menit;

    if (departure.jam < arrived.jam)
    {
        departure.jam += 24;
    }

    diffJam = departure.jam - arrived.jam;

    cout << " Parking time  = "
         << setw(2) << setfill('0') << diffJam << ":"
         << setw(2) << setfill('0') << diffMenit << ":"
         << setw(2) << setfill('0') << diffDetik << endl;

    departure.selisih = diffJam * 3600 + diffMenit * 60 + diffDetik; // calculate the difference in seconds

    if (departure.selisih <= 3600)
    {
        departure.biaya = 3000;
    }
    else
    {
        departure.biaya = 3000;
        int extraHours = departure.selisih / 3600; // calculate the number of extra hours
        departure.biaya += extraHours * 3000;      // add 3000 for each extra hour
    }

    cout << " Parking fee   = Rp." << departure.biaya << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void menu3()
{
    cout << " Terima kasih telah menggunakan program ini" << endl;
    SetConsoleTextAttribute(h, 5);
    cout << "   ______    __          __        ______    " << endl;
    cout << "  /\" _  \"\\  |\" \\        /\"\"\\      /    \" \\   " << endl;
    cout << " (: ( \\___) ||  |      /    \\    // ____  \\  " << endl;
    cout << "  \\/ \\      |:  |     /' /\\  \\  /  /    ) :) " << endl;
    cout << "  //  \\ _   |.  |    //  __'  \\(: (____/ //  " << endl;
    cout << " (:   _) \\  /\\  |\\  /   /  \\\\  \\        /   " << endl;
    cout << "  \\_______)(__\\_|_)(___/    \\___)\"_____/    " << endl;
    exit(0);
}

int main()
{
    int pilih, n;
    bool menu = true;
    welcome();
    while (menu)
    {
        SetConsoleTextAttribute(h, 11);
        cout << "\n====================================" << endl;
        cout << " Main Menu" << endl;
        cout << " 1. Mengurutkan nim mahasiswa descending" << endl;
        cout << " 2. Menghitung biaya parkir" << endl;
        cout << " 3. Keluar" << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << " Masukkan pilihan: ";
        cin >> pilih;
        SetConsoleTextAttribute(h, 7);
        cout << endl;
        switch (pilih)
        {
        case 1:
            menu1(&n);
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        default:
            cout << " Pilihan tidak tersedia" << endl;
            break;
        }
    }
    return 0;
}
