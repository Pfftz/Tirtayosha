#include<iostream>

using namespace std;

void selectSort(double arr[], size_t length)
{
    // Variabel untuk menyimpan posisi elemen terbesar
    size_t max_pos;
    // Variabel sementara untuk menukar elemen
    double swap_temp;

    for (size_t i = 0; i < length - 1; i++)
    {
        // set posisi elemen terbesar ke i
        max_pos = i;
        // mencari elemen terbesar dari sisa array
        for (size_t j = i + 1; j < length; j++)
        {
            if (arr[j] > arr[max_pos])
                max_pos = j;
        }
        // menukar elemen i dengan elemen terbesar apabila memenuhi
        if (max_pos != i)
        {
            swap_temp = arr[i];
            arr[i] = arr[max_pos];
            arr[max_pos] = swap_temp;
        }
    }
}

int main(){

return 0;
}