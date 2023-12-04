#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    queue<string> namaTeller;
    struct Node *next;
};

void enqueue(Node **head)
{
    Node *nodeBaru = new Node();
    string nama;
    cout << "Masukkan nama teller : ";
    cin >> nama;
    nodeBaru->namaTeller.push(nama);
    nodeBaru->next = NULL;
    if (*head == NULL)
    {
        (*head) = nodeBaru;
        return;
    }
    nodeBaru->next = (*head);
    (*head) = nodeBaru;
}

void dequeue(Node **head)
{
    if (*head == NULL)
    {
        cout << "Antrian kosong" << endl;
        return;
    }
    Node *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->namaTeller.pop();
}

void clearQueue(Node **head)
{
    if (*head == NULL)
    {
        cout << "Antrian kosong" << endl;
        return;
    }
    Node *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->namaTeller.pop();
}

void view(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Antrian kosong" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->namaTeller.front() << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int pilihan;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Clear" << endl;
        cout << "4. View" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            enqueue(&head);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            clearQueue(&head);
            break;
        case 4:
            view(head);
            break;
        case 5:
            cout << "Terima kasih" << endl;
            break;
        default:
            cout << "Pilihan salah" << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}
