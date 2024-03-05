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
    // rute ijo
    LinkedList transJakartaRoute;
    transJakartaRoute.addStop("Kampung Rambutan");
    transJakartaRoute.addStop("Tanah Merdeka");
    transJakartaRoute.addStop("Flyover Raya Bogor");
    transJakartaRoute.addStop("RS Bunda Harapan");
    transJakartaRoute.addStop("Pasar Induk Keramat Jati");
    transJakartaRoute.addStop("Cililitan");
    transJakartaRoute.addStop("BKN");
    transJakartaRoute.addStop("Cawang Uki");
    transJakartaRoute.addStop("BNN");
    transJakartaRoute.addStop("Cawang Otista");
    transJakartaRoute.addStop("Gelanggang Remaja");
    transJakartaRoute.addStop("Bidara Cina");

    // merah
    LinkedList transJakartaRoute1;
    transJakartaRoute1.addStop("BLOK M");
    transJakartaRoute1.addStop("Masjid Agung");
    transJakartaRoute1.addStop("Bunderan Senayan");
    transJakartaRoute1.addStop("Gelora Bung Karno");
    transJakartaRoute1.addStop("Polda Metro");
    transJakartaRoute1.addStop("Bendungan Hilir");
    transJakartaRoute1.addStop("Karet");
    transJakartaRoute1.addStop("Setiabudi");
    transJakartaRoute1.addStop("Dukuh Atas");
    transJakartaRoute1.addStop("Tosari");
    transJakartaRoute1.addStop("Bunderan HI");
    transJakartaRoute1.addStop("Sarinah");
    transJakartaRoute1.addStop("Bank Indonesia");
    transJakartaRoute1.addStop("Monumen Nasional");
    transJakartaRoute1.addStop("HARMONI");
    transJakartaRoute1.addStop("Sawah Besar");
    transJakartaRoute1.addStop("Mangga Besar");
    transJakartaRoute1.addStop("Olimo");
    transJakartaRoute1.addStop("Glodok");
    transJakartaRoute1.addStop("KOTA");

    // rute kuning
    LinkedList transJakartaRoute2;
    transJakartaRoute2.addStop("Kalideres");
    transJakartaRoute2.addStop("Pesakih");
    transJakartaRoute2.addStop("Sumur Bor");
    transJakartaRoute2.addStop("Rawa Buaya");
    transJakartaRoute2.addStop("Jembatan Baru");
    transJakartaRoute2.addStop("Dispenda Samsat Barat");
    transJakartaRoute2.addStop("jembatan Gantung");
    transJakartaRoute2.addStop("Taman Kota");
    transJakartaRoute2.addStop("Indosiar");
    transJakartaRoute2.addStop("Jelambar");
    transJakartaRoute2.addStop("Grogol");
    transJakartaRoute2.addStop("RS Sumber Waras");
    transJakartaRoute2.addStop("Harmoni");
    transJakartaRoute2.addStop("Pecenongan");
    transJakartaRoute2.addStop("Pasar Baru");

    // rute abu-abu
    LinkedList transJakartaRoute3;
    transJakartaRoute3.addStop("Kampung Melayu");
    transJakartaRoute3.addStop("Kebon Pala");
    transJakartaRoute3.addStop("Slamet Riyadi");
    transJakartaRoute3.addStop("Tegalan");
    transJakartaRoute3.addStop("Matraman 1");
    transJakartaRoute3.addStop("Salemba Carolus");
    transJakartaRoute3.addStop("Salemba UI");
    transJakartaRoute3.addStop("Kramat Sentiong");
    transJakartaRoute3.addStop("Pal Putih");
    transJakartaRoute3.addStop("Senen Sentral");
    transJakartaRoute3.addStop("Budi Utomo");
    transJakartaRoute3.addStop("Pasar Baru Timur");
    transJakartaRoute3.addStop("Jembatan Merah");
    transJakartaRoute3.addStop("Gunung Sahari");
    transJakartaRoute3.addStop("Pademangan");
    transJakartaRoute3.addStop("Ancol");

    // rute hijau terang
    LinkedList transJakartaRoute4;
    transJakartaRoute4.addStop("RAGUNAN");
    transJakartaRoute4.addStop("Departemen Pertanian");
    transJakartaRoute4.addStop("SMK 57");
    transJakartaRoute4.addStop("Jatipadang");
    transJakartaRoute4.addStop("Pejaten Philips");
    transJakartaRoute4.addStop("Buncit Indah");
    transJakartaRoute4.addStop("Warung Jati");
    transJakartaRoute4.addStop("Imigrasi");
    transJakartaRoute4.addStop("Duren Tiga");
    transJakartaRoute4.addStop("Mampang Prapatan");
    transJakartaRoute4.addStop("Kuningan Timur");
    transJakartaRoute4.addStop("Patra Kuningan");
    transJakartaRoute4.addStop("DepKes");
    transJakartaRoute4.addStop("Gor Sumantri");
    transJakartaRoute4.addStop("Karet Kuningan");
    transJakartaRoute4.addStop("Kuningan Madya Aini");
    transJakartaRoute4.addStop("Setiabudi Utara");
    transJakartaRoute4.addStop("Latuharhari");
    transJakartaRoute4.addStop("Halimun");
    transJakartaRoute4.addStop("DUKUH ATAS 2");

    // rute oren
    LinkedList transJakartaRoute5;
    transJakartaRoute.addStop("Lebak Bulus");
    transJakartaRoute.addStop("Pondok Pinang");
    transJakartaRoute.addStop("Pondok Indah 1");
    transJakartaRoute.addStop("Pondok Indah 2");
    transJakartaRoute.addStop("Tamah Kusir Kodim");
    transJakartaRoute.addStop("Kebayoran Lama Bungur");
    transJakartaRoute.addStop("Pasar Kebayoran Lama");
    transJakartaRoute.addStop("Simprug");
    transJakartaRoute.addStop("Permata Hijau");
    transJakartaRoute.addStop("Permata Hijau RS Medika");
    transJakartaRoute.addStop("Pos Pengumben");
    transJakartaRoute.addStop("Kelapa Dua Sasak");
    transJakartaRoute.addStop("Kebon Jeruk");
    transJakartaRoute.addStop("Duri Kepa");
    transJakartaRoute.addStop("Kedoya Assiddiqiyah");
    transJakartaRoute.addStop("Kedoya Green Garden");
    transJakartaRoute.addStop("Indosiar");
    transJakartaRoute.addStop("Jelambar");
    transJakartaRoute.addStop("Grogol 2");
    transJakartaRoute.addStop("Tomang");
    transJakartaRoute.addStop("Tomang Mandala");
    transJakartaRoute.addStop("RS Tarakan");
    transJakartaRoute.addStop("Petojo");
    transJakartaRoute.addStop("Harmoni");

    string start, end;
    cout << "Enter start stop: ";
    getline(cin, start);
    cout << "Enter end stop: ";
    getline(cin, end);

    LinkedList *routes[] = {&transJakartaRoute, &transJakartaRoute1, &transJakartaRoute2, &transJakartaRoute3, &transJakartaRoute4, &transJakartaRoute5};
    int numRoutes = sizeof(routes) / sizeof(routes[0]);

    for (int i = 0; i < numRoutes; i++)
    {
        int fare = routes[i]->calculateFare(start, end);
        if (fare != -1)
        {
            cout << "The fare from " << start << " to " << end << " is: Rp " << fare << endl;
            routes[i]->printAdjacentStops(end);
            return 0;
        }
    }

    cout << "Wrong route." << endl;
    return 0;
}