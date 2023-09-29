#include <stdio.h>

void latihan2()
{
    int A, B, C, max = 0;
    printf("Input 3 buah bilangan\n");
    printf("Bilangan 1 : ");
    scanf("%i", &A);
    printf("Bilangan 2 : ");
    scanf("%i", &B);
    printf("Bilangan 3 : ");
    scanf("%i", &C);

    printf("Bilangan terbesar : ");

    if (A > max)
    {
        max = A;
    }
    if (B > max)
    {
        max = B;
    }
    if (C > max)
    {
        max = C;
    }
    printf("%i\n", max);
}

void latihan3()
{
    int A, max = 0;
    printf("Input 3 buah bilangan\n");
    printf("Bilangan 1 : ");
    scanf("%i", &A);
    max = A;
    printf("Bilangan 2 : ");
    scanf("%i", &A);
    if (A > max)
    {
        max = A;
    }
    printf("Bilangan 3 : ");
    scanf("%i", &A);
    if (A > max)
    {
        max = A;
    }
    printf("Bilangan terbesar : ");
    printf("%i\n", max);
}

void latihan4()
{
    int x;
    printf(" 1. Mau Ke Mana?\n");
    printf(" 2. Mau Apa?\n");
    printf(" Pilih 1 atau 2?\n ");
    scanf("%i", &x);
    if (x == 1)
    {
        printf(" Mau Ke Yogya\n");
    }
    else if (x == 2)
    {
        printf(" Jawir 1\n");
    }
    else
    {
        printf(" Kurang Aqua\n");
    }
}

void latihan5()
{
    int x;
    printf(" 1. Mau Ke Mana?\n");
    printf(" 2. Mau Apa?\n");
    printf(" Pilih 1 atau 2? ");
    scanf("%i", &x);
    switch (x)
    {
    case 1:
        printf("\n Anda akan Ke Yogya\n");
        printf(" 1. Wisata belanja\n");
        printf(" 2. Wisata kuliner\n");
        printf(" 3. Wisata budaya\n");
        printf(" Pilih 1, 2, atau 3? ");
        scanf("%i", &x);
        switch (x)
        {
        case 1:
            printf(" Anda akan belanja di Malioboro\n");
            break;
        case 2:
            printf(" Anda akan kuliner di Gudeg Yu Djum\n");
            break;
        case 3:
            printf(" Anda akan budaya di Candi Borobodur\n");
            break;
        }
        break;
    case 2:
        printf("\n Anda akan makan nasi gudeg \n");
        printf(" 1. Sate-satean\n");
        printf(" 2. Minuman\n");
        printf(" 3. Camilan\n");
        printf(" Pilih 1, 2, atau 3? ");
        scanf("%i", &x);
        switch (x)
        {
        case 1:
            printf(" Anda akan makan Nasi Kucing\n");
            break;
        case 2:
            printf(" Anda akan minum Kopi bara\n");
            break;
        case 3:
            printf(" Anda akan makan ampiyang cokelat\n");
            break;
        }
        break;
    default:
        printf(" Kurang Aqua\n");
        break;
    }
}

void latihan6()
{
    char grade;
    int sks;
    int angka_mutu = 0;

    printf("Masukkan grade : ");
    grade = getchar();
    printf("Masukkan sks : ");
    scanf("%i", &sks);

    switch (grade)
    {
    case 'A':
        angka_mutu = 4 * sks;
        break;
    case 'B':
        angka_mutu = 3 * sks;
        break;
    case 'C':
        angka_mutu = 2 * sks;
        break;
    case 'D':
        angka_mutu = 1 * sks;
        break;
    case 'E':
        angka_mutu = 0 * sks;
        break;
    default:
        angka_mutu = 0;
        break;
    }
    printf("\nGrade : %c\n", grade);
    printf("\nSKS : %i\n", sks);
    printf("\nAngka Mutu : %i\n", angka_mutu);
}

int main()
{
    latihan6();
    return 0;
}