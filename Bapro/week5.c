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

void latihan4(){
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

int main()
{
    latihan4();
    return 0;
}