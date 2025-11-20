#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

const int QUEUE_MAX = 5;

struct QueueEkspedisi {
    Paket data[QUEUE_MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi& Q);
bool isFull(QueueEkspedisi& Q);
void createQueue(QueueEkspedisi& Q);
void enQueue(QueueEkspedisi& Q, const Paket& P);
void deQueue(QueueEkspedisi& Q, Paket& Pout);
void viewQueue(QueueEkspedisi& Q);
long long TotalBiayaPengiriman(QueueEkspedisi& Q);

#endif
