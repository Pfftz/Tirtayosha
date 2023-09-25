#include <iostream>

using namespace std;

int main()
{
    int b; //variabel user
    int total; //variabel akhir
    cout << "Masukkan Bilangan: ";
    cin>>b;
    cout<<"Total Nilai = ";

    while(b>=1){
        total += b; /*operator penugasan untuk memberikan tugas pada variabel
        berupa pertambahan*/
        if(b!=1){ //kondisi pertama apabila variabel b tidak sama dengan satu
            cout<<b<<" + ";
        }else{ // kondisi kedua apabila variabel b = 1
            cout<<b<<" = ";
        }
        --b; //menurunkan nilai inputan user agar proses pertambahan berjalan
    }

    cout<<total<<"\n\n we work in the dark to serve the light"<<endl;
    return 0;
}