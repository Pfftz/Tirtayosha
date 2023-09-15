#include <stdio.h>

int main()
{
    char nim[10], nama[30];
    float nilai;
    printf(" INPUT DATA MAHASISWA\n");
    printf(" NIM :");
    scanf("%10s", nim);
    fflush(stdin);
    printf(" NAMA :");
    gets(nama);
    printf(" NILAI :");
    scanf("%f", &nilai);

    printf("\n NIM : %s", nim);
    printf("\n NAMA : %s", nama);
    printf("\n Nilai : %f", nilai);
    printf("\n NILAI (Pembulatan): %.4f", nilai);
    return 0;
}

// #include <stdio.h>

// int main()
// {
//     char nim[10], nama[30];
//     printf("INPUT DATA MAHASISWA\n");
//     printf("NIM :");
//     fgets(nim, sizeof(nim), stdin);
//     printf("NAMA :");
//     fgets(nama, sizeof(nama), stdin);

//     printf("\nNIM : %s", nim);
//     printf("\nNAMA : %s", nama);
//     return 0;
// }