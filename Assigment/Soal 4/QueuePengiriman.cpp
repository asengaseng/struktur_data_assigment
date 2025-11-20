#include <iostream>
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

bool isEmpty(QueueEkspedisi& Q) { return Q.Head == -1; }
bool isFull(QueueEkspedisi& Q) { return Q.Tail == QUEUE_MAX - 1; }

void createQueue(QueueEkspedisi& Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi& Q, const Paket& P) {
    if (isFull(Q)) {
        cout << "Queue penuh, tidak bisa enqueue\n";
        return;
    }
    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
        Q.data[0] = P;
        return;
    }
    Q.Tail++;
    Q.data[Q.Tail] = P;
}

void deQueue(QueueEkspedisi& Q, Paket& Pout) {
    if (isEmpty(Q)) {
        cout << "Queue kosong, tidak bisa dequeue\n";
        return;
    }
    Pout = Q.data[Q.Head];

    for (int i = Q.Head; i < Q.Tail; ++i) {
        Q.data[i] = Q.data[i + 1];
    }
    Q.Tail--;

    if (Q.Tail < Q.Head)
        Q.Head = Q.Tail = -1;
}

void viewQueue(QueueEkspedisi& Q) {
    cout << "Queue Paket:\n";
    if (isEmpty(Q)) {
        cout << "(kosong)\n";
        return;
    }
    for (int i = Q.Head; i <= Q.Tail; ++i) {
        const Paket& p = Q.data[i];
        cout << (i - Q.Head + 1) << ". KodeResi: " << p.KodeResi
             << ", Pengirim: " << p.NamaPengirim
             << ", Berat: " << p.BeratBarang
             << ", Tujuan: " << p.Tujuan << "\n";
    }
}

long long TotalBiayaPengiriman(QueueEkspedisi& Q) {
    const long long biayaPerKg = 8250LL;
    long long total = 0;

    if (isEmpty(Q)) return 0;

    for (int i = Q.Head; i <= Q.Tail; ++i)
        total += (long long)Q.data[i].BeratBarang * biayaPerKg;

    return total;
}
