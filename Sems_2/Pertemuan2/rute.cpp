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
            // If endNode was not found after startNode, try the other direction
            stops = 0;
            current = startNode;
            while (current != NULL && current != endNode)
            {
                stops++;
                current = current->prev;
            }

            if (current == NULL)
            {
                cout << "End stop not found on the route from the start stop." << endl;
                return -1;
            }
        }

        return stops * farePerStop;
    }

    void printRoute(string start, string end)
    {
        Node *startNode = nodeMap[start];
        Node *endNode = nodeMap[end];

        if (startNode == NULL || endNode == NULL)
        {
            cout << "Start or end stop not found." << endl;
            return;
        }

        Node *current = startNode;
        string route = "Route from " + start + " to " + end + ": " + start;
        while (current != NULL && current != endNode)
        {
            current = current->next;
            if (current != NULL)
            {
                route += " -> " + current->data;
            }
        }

        if (current == NULL)
        {
            // If endNode was not found after startNode, print the route in the other direction
            current = startNode;
            route = "Route from " + start + " to " + end + ": " + start;
            while (current != NULL && current != endNode)
            {
                current = current->prev;
                if (current != NULL)
                {
                    route += " -> " + current->data;
                }
            }
        }

        cout << route << endl;
    }
    bool isStopInRoute(string stop)
    {
        return nodeMap.find(stop) != nodeMap.end();
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
    transJakartaRoute2.addStop("Juanda");
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
    transJakartaRoute5.addStop("Lebak Bulus");
    transJakartaRoute5.addStop("Pondok Pinang");
    transJakartaRoute5.addStop("Pondok Indah 1");
    transJakartaRoute5.addStop("Pondok Indah 2");
    transJakartaRoute5.addStop("Tamah Kusir Kodim");
    transJakartaRoute5.addStop("Kebayoran Lama Bungur");
    transJakartaRoute5.addStop("Pasar Kebayoran Lama");
    transJakartaRoute5.addStop("Simprug");
    transJakartaRoute5.addStop("Permata Hijau");
    transJakartaRoute5.addStop("Permata Hijau RS Medika");
    transJakartaRoute5.addStop("Pos Pengumben");
    transJakartaRoute5.addStop("Kelapa Dua Sasak");
    transJakartaRoute5.addStop("Kebon Jeruk");
    transJakartaRoute5.addStop("Duri Kepa");
    transJakartaRoute5.addStop("Kedoya Assiddiqiyah");
    transJakartaRoute5.addStop("Kedoya Green Garden");
    transJakartaRoute5.addStop("Indosiar");
    transJakartaRoute5.addStop("Jelambar");
    transJakartaRoute5.addStop("Grogol 2");
    transJakartaRoute5.addStop("Tomang");
    transJakartaRoute5.addStop("Tomang Mandala");
    transJakartaRoute5.addStop("RS Tarakan");
    transJakartaRoute5.addStop("Petojo");
    transJakartaRoute5.addStop("Harmoni");

    // rute biru (DUKUH ATAS 2-HARMONI)
    LinkedList transJakartaRoute6;
    transJakartaRoute6.addStop("DUKUH ATAS 2");
    transJakartaRoute6.addStop("Pasar Rumput");
    transJakartaRoute6.addStop("MANGGARAI");
    transJakartaRoute6.addStop("Matraman");
    transJakartaRoute6.addStop("Pasar Genjing");
    transJakartaRoute6.addStop("Utan Kayu");
    transJakartaRoute6.addStop("Pramuka Lia");
    transJakartaRoute6.addStop("Pramuka BPKP");
    transJakartaRoute6.addStop("UNJ");
    transJakartaRoute6.addStop("Sunan Giri");
    transJakartaRoute6.addStop("Velodrome");
    transJakartaRoute6.addStop("Pemuda Rawamangun");
    transJakartaRoute6.addStop("Layur");
    transJakartaRoute6.addStop("TU Gas");
    transJakartaRoute6.addStop("Pasar Pulogadung");
    transJakartaRoute6.addStop("PULOGADUNG");
    transJakartaRoute6.addStop("Bermis");
    transJakartaRoute6.addStop("Pulomas");
    transJakartaRoute6.addStop("Asmi");
    transJakartaRoute6.addStop("Pedongkelan");
    transJakartaRoute6.addStop("Cempaka Timur");
    transJakartaRoute6.addStop("RS Islam");
    transJakartaRoute6.addStop("Cempaka Tengah");
    transJakartaRoute6.addStop("Pasar Cempaka Putih");
    transJakartaRoute6.addStop("Rawa Selatan");
    transJakartaRoute6.addStop("Galur");
    transJakartaRoute6.addStop("Senen");
    transJakartaRoute6.addStop("Atrium");
    transJakartaRoute6.addStop("RSPAD");
    transJakartaRoute6.addStop("DepLu");
    transJakartaRoute6.addStop("Gambir 1");
    transJakartaRoute6.addStop("Istiqlal");
    transJakartaRoute6.addStop("Juanda");
    transJakartaRoute6.addStop("Pecenongan");
    transJakartaRoute6.addStop("HARMONI");

    // rute biru (DUKUH ATAS 2-HARMONI)
    LinkedList transJakartaRoute7;
    transJakartaRoute7.addStop("DUKUH ATAS 2");
    transJakartaRoute7.addStop("Pasar Rumput");
    transJakartaRoute7.addStop("MANGGARAI");
    transJakartaRoute7.addStop("Matraman");
    transJakartaRoute7.addStop("Pasar Genjing");
    transJakartaRoute7.addStop("Utan Kayu");
    transJakartaRoute7.addStop("Pramuka Lia");
    transJakartaRoute7.addStop("Pramuka BPKP");
    transJakartaRoute7.addStop("UNJ");
    transJakartaRoute7.addStop("Sunan Giri");
    transJakartaRoute7.addStop("Velodrome");
    transJakartaRoute7.addStop("Pemuda Rawamangun");
    transJakartaRoute7.addStop("Layur");
    transJakartaRoute7.addStop("TU Gas");
    transJakartaRoute7.addStop("Pasar Pulogadung");
    transJakartaRoute7.addStop("PULOGADUNG");
    transJakartaRoute7.addStop("Bermis");
    transJakartaRoute7.addStop("Pulomas");
    transJakartaRoute7.addStop("Asmi");
    transJakartaRoute7.addStop("Pedongkelan");
    transJakartaRoute7.addStop("Cempaka Timur");
    transJakartaRoute7.addStop("RS Islam");
    transJakartaRoute7.addStop("Cempaka Tengah");
    transJakartaRoute7.addStop("Pasar Cempaka Putih");
    transJakartaRoute7.addStop("Rawa Selatan");
    transJakartaRoute7.addStop("Galur");
    transJakartaRoute7.addStop("Senen");
    transJakartaRoute7.addStop("Atrium");
    transJakartaRoute7.addStop("RSPAD");
    transJakartaRoute7.addStop("DepLu");
    transJakartaRoute7.addStop("Gambir 1");
    transJakartaRoute7.addStop("Istiqlal");
    transJakartaRoute7.addStop("Juanda");
    transJakartaRoute7.addStop("Pecenongan");
    transJakartaRoute7.addStop("HARMONI");

    string start, end;
    cout << "Enter start stop: ";
    getline(cin, start);
    cout << "Enter end stop: ";
    getline(cin, end);

    LinkedList *routes[] = {&transJakartaRoute, &transJakartaRoute1, &transJakartaRoute2, &transJakartaRoute3, &transJakartaRoute4, &transJakartaRoute5, &transJakartaRoute6, &transJakartaRoute7};
    int numRoutes = sizeof(routes) / sizeof(routes[0]);

    for (int i = 0; i < numRoutes; i++)
    {
        if (routes[i]->isStopInRoute(start) && routes[i]->isStopInRoute(end))
        {
            int fare = routes[i]->calculateFare(start, end);
            cout << "The fare from " << start << " to " << end << " is: Rp " << fare << endl;
            routes[i]->printRoute(start, end); // call printRoute here

            // Print adjacent stops for start and end stops
            cout << "Adjacent stops for " << start << ": ";
            routes[i]->printAdjacentStops(start);
            cout << "Adjacent stops for " << end << ": ";
            routes[i]->printAdjacentStops(end);

            return 0;
        }
    }

    cout << "Wrong route." << endl;
    return 0;
}