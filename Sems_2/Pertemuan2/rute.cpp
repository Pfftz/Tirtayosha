#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node
{
    string data;
    Node *next;
    Node *prev;
};

class LinkedList
{
    Node *head;
    Node *tail;
    map<string, Node *> nodeMap;
    int farePerStop = 1500;

public:
    LinkedList() : head(NULL), tail(NULL) {}

    void addStop(string stop)
    {
        Node *newNode = new Node();
        newNode->data = stop;
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        nodeMap[stop] = newNode;
    }

    void printAdjacentStops(string stop)
    {
        Node *current = nodeMap[stop];
        if (current == NULL)
        {
            cout << "Stop not found." << endl;
            return;
        }

        cout << "Adjacent stops to " << stop << " are: ";
        if (current->prev != NULL)
        {
            cout << current->prev->data << ", ";
        }
        if (current->next != NULL)
        {
            cout << current->next->data;
        }
        cout << endl;
    }

    int calculateFare(string start, string end)
    {
        Node *startNode = nodeMap[start];
        Node *endNode = nodeMap[end];

        if (startNode == NULL || endNode == NULL)
        {
            cout << "Start or end stop not found." << endl;
            return -1;
        }

        int stops = 0;
        Node *current = startNode;
        while (current != NULL && current != endNode)
        {
            stops++;
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "End stop not found on the route from the start stop." << endl;
            return -1;
        }

        return stops * farePerStop;
    }
};

int main()
{
    LinkedList transJakartaRoute;
    transJakartaRoute.addStop("BKN");
    transJakartaRoute.addStop("Cawang Uki");
    transJakartaRoute.addStop("BNN");
    transJakartaRoute.addStop("Cawang Otista");
    transJakartaRoute.addStop("Gelanggang Remaja");
    transJakartaRoute.addStop("Bidara Cina");
    transJakartaRoute.addStop("Kampung Melayu");
    transJakartaRoute.addStop("Kebon Pala");
    transJakartaRoute.addStop("Slamet Riyadi");
    transJakartaRoute.addStop("Tegalan");
    transJakartaRoute.addStop("Matraman 1");
    transJakartaRoute.addStop("Salemba Carolus");
    transJakartaRoute.addStop("Salemba UI");
    transJakartaRoute.addStop("Kramat Sentiong");
    transJakartaRoute.addStop("Pal Putih");
    transJakartaRoute.addStop("Senen Sentral");
    transJakartaRoute.addStop("Budi Utomo");
    transJakartaRoute.addStop("Pasar Baru Timur");
    transJakartaRoute.addStop("Jembatan Merah");
    transJakartaRoute.addStop("Gunung Sahari");
    transJakartaRoute.addStop("Pademangan");
    transJakartaRoute.addStop("Ancol");


    transJakartaRoute.printAdjacentStops("Ancol");

    int fare = transJakartaRoute.calculateFare("BKN", "Ancol");
    if (fare != -1)
    {
        cout << "The fare from BKN to Ancol is: Rp " << fare << endl;
    }

    return 0;
}