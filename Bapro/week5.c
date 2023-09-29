#include <stdio.h>

int main(){
    int A,B,C;
    printf("Input 3 buah bilangan\n");
    printf("Bilangan 1 : ");scanf("%i",&A);
    printf("Bilangan 2 : ");scanf("%i",&B);
    printf("Bilangan 3 : ");scanf("%i",&C);

    printf("Bilangan terbesar : ");

    if(A > B){
        if(A > C){
            printf("%i",A);
        } else {
            printf("%i",C);
        }
    } else{
        if (B > C){
            printf("%i", B);
        } else {
            printf("%i", C);
        }
    }
    return 0;

}