#include <iostream>
#include <vector>

using namespace std;

void bubblesort(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void menu7()
{
    int split1, split2, split3, length;
    cout << " Masukkan panjang array: ";
    cin >> length;
    cout << " Masukkan split1: ";
    cin >> split1;
    cout << " Masukkan split2: ";
    cin >> split2;
    cout << " Masukkan split3: ";
    cin >> split3;

    if (split1 >= length || split2 >= length - split1 || split3 >= length - split1 - split2)
    {
        cout << " Invalid split values. Please try again." << endl;
        return;
    }

    vector<int> arr1(length);
    for (int i = 0; i < length; i++)
    {
        cout << "Data ke-" << i + 1 << " : ";
        cin >> arr1[i];
    }

    vector<int> arr2(arr1.begin() + split1, arr1.begin() + split1 + split2);
    vector<int> arr3(arr1.begin() + split1 + split2, arr1.begin() + split1 + split2 + split3);
    vector<int> arr4(arr1.begin() + split1 + split2 + split3, arr1.end());

    cout << "\nArray 1: ";
    for (int i = 0; i < split1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (vector<int>::size_type i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Array 3: ";
    for (vector<int>::size_type i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "Array 4: ";
    for (vector<int>::size_type i = 0; i < arr4.size(); i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl;

    bubblesort(&arr1[0], split1);
    bubblesort(&arr2[0], arr2.size());
    bubblesort(&arr3[0], arr3.size());
    bubblesort(&arr4[0], arr4.size());

    cout << "\nArray 1: ";
    for (int i = 0; i < split1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (vector<int>::size_type i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Array 3: ";
    for (vector<int>::size_type i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "Array 4: ";
    for (vector<int>::size_type i = 0; i < arr4.size(); i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl;
}

int main()
{
    menu7();

    return 0;
}