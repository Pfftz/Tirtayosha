#include <stdio.h>
#include <string.h>

int main()
{
    int nilai;
    char x[10];
    printf("\nMasukkan nilai: ");
    scanf("%d", &nilai);
    if (nilai >= 60)
    {
        strcpy(x, "Lulus\n");
    }
    else
    {
        strcpy(x, "Tidak Lulus\n");
    }
    printf("\n\n %s", x);

    printf("\n Program Selesai.\n");
    return 0;
}