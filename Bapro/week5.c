/* #include <stdio.h>

// int main()
// {
//     int A, B, C, max = 0;
//     printf("Input 3 buah bilangan\n");
//     printf("Bilangan 1 : ");
//     scanf("%i", &A);
//     printf("Bilangan 2 : ");
//     scanf("%i", &B);
//     printf("Bilangan 3 : ");
//     scanf("%i", &C);

//     printf("Bilangan terbesar : ");

//     if (A > max)
//     {
//         max = A;
//     }
//     if (B > max)
//     {
//         max = B;
//     }
//     if (C > max)
//     {
//         max = C;
//     }
//     printf("%i\n", max);
//     return 0;
// } */

#include <stdio.h>

int main()
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
    return 0;
}