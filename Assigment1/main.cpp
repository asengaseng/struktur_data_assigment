#include <iostream>
#include "SLLInventory.cpp"
using namespace std;

int main() {
    SList L;
    createList(L);   // 1. Buat list kosong

    // 2. insertLast 3 data
    Product P;

    // Data 1
    P.Nama = "Pulpen";
    P.SKU = "A001";
    P.Jumlah = 20;
    P.HargaSatuan = 2500;
    P.DiskonPersen = 0;
    insertLast(L, P);

    // Data 2
    P.Nama = "BukuTulis";
    P.SKU = "A002";
    P.Jumlah = 15;
    P.HargaSatuan = 5000;
    P.DiskonPersen = 10;
    insertLast(L, P);

    // Data 3
    P.Nama = "Penghapus";
    P.SKU = "A003";
    P.Jumlah = 30;
    P.HargaSatuan = 1500;
    P.DiskonPersen = 0;
    insertLast(L, P);

    // 3. Tampilkan list awal
    cout << "=== LIST AWAL ===\n";
    viewList(L);

    // 4. deleteFirst 1x
    Product removed;
    deleteFirst(L, removed);
    cout << "\nData yang dihapus (deleteFirst): " << removed.Nama << "\n";

    // 5. Tampilkan list kembali
    cout << "\n=== LIST SETELAH deleteFirst ===\n";
    viewList(L);

    // 6. Update posisi ke-2
    Product newP;
    newP.Nama = "Stabilo";
    newP.SKU = "A010";
    newP.Jumlah = 40;
    newP.HargaSatuan = 9000;
    newP.DiskonPersen = 5;
    updateAtPosition(L, 2, newP);


    cout << "\n=== LIST SETELAH UPDATE POSISI KE-2 ===\n";
    viewList(L);

    cout << "\n=== SEARCH HargaAkhir 2000 - 7000 ===\n";
    searchByFinalPriceRange(L, 2000, 7000);


    cout << "\n=== DATA DENGAN HargaAkhir MAKSIMUM ===\n";
    MaxHargaAkhir(L);

    return 0;
}
