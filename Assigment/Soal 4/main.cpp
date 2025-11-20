#include <iostream>
#include <string>
using namespace std;

#include "QueuePengiriman.cpp"   // berisi fungsi queue

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    cout << "--- Komaniya Ekspress ---\n";
    cout << "Memasukkan 5 data paket otomatis...\n\n";

    // 5 paket otomatis
    Paket p1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket p2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket p3 = {"345678", "Bennet", 7, "Natlan"};
    Paket p4 = {"456789", "Furina", 16, "Liyue"};
    Paket p5 = {"567890", "Nefer", 6, "Inazuma"};

    // Enqueue otomatis
    enQueue(Q, p1);
    enQueue(Q, p2);
    enQueue(Q, p3);
    enQueue(Q, p4);
    enQueue(Q, p5);

    // Tampilkan queue awal
    cout << "Queue setelah input 5 paket: \n";
    viewQueue(Q);

    // Dequeue 1x
    Paket removed;
    deQueue(Q, removed);
    cout << "\nPaket yang dikeluarkan (1x dequeue): " << removed.KodeResi << "\n";

    // Tampilkan queue setelah dequeue
    cout << "\nQueue setelah 1x dequeue:\n";
    viewQueue(Q);

    // Total biaya
    long long total = TotalBiayaPengiriman(Q);
    cout << "\nTotal biaya pengiriman = Rp " << total << "\n";

    cout << "\nProgram otomatis selesai.\n";
    return 0;
}
