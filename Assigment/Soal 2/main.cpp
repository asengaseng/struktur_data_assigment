#include <iostream>
#include "DLLPlaylist.cpp"
using namespace std;

int main() {

    DList L;
    createList(L);   // (1) Buat list kosong

    // =============================
    // (2) insertLast 3 lagu
    // =============================
    Song S;

    // Lagu 1
    S.Title = "Senja di Kota";
    S.Artist = "Nona Band";
    S.DurationSec = 210;
    S.PlayCount = 150;
    S.Rating = 4.2;
    insertLast(L, S);

    // Lagu 2
    S.Title = "Langkahmu";
    S.Artist = "Delta";
    S.DurationSec = 185;
    S.PlayCount = 320;
    S.Rating = 4.8;
    insertLast(L, S);

    // Lagu 3
    S.Title = "Hujan Minggu";
    S.Artist = "Arka";
    S.DurationSec = 240;
    S.PlayCount = 90;
    S.Rating = 3.9;
    insertLast(L, S);

    // =============================
    // (3) Tampilkan list
    // =============================
    cout << "\n=== LIST AWAL ===\n";
    viewList(L);

    // =============================
    // (4) deleteLast 1x
    // =============================
    Song removed;
    deleteLast(L, removed);
    cout << "\nDeleteLast -> Terhapus: " << removed.Title << "\n";

    cout << "\n=== LIST SETELAH deleteLast ===\n";
    viewList(L);

    // =============================
    // (5) Update node pada posisi ke-2
    // =============================
    Song updateS;
    updateS.Title = "Pelita";
    updateS.Artist = "Luna";
    updateS.DurationSec = 200;
    updateS.PlayCount = 260;
    updateS.Rating = 4.5;

    updateAtPosition(L, 2, updateS);

    cout << "\n=== LIST SETELAH UPDATE POSISI 2 ===\n";
    viewList(L);

    // =============================
    // (7a) insertBefore node posisi 2
    // =============================
    DNode* pos2 = getNodeAt(L, 2);
    Song newB;

    newB.Title = "Senandung";
    newB.Artist = "Mira";
    newB.DurationSec = 175;
    newB.PlayCount = 120;
    newB.Rating = 4.0;

    insertBefore(L, pos2, newB);

    cout << "\n=== LIST SETELAH insertBefore(posisi 2) ===\n";
    viewList(L);

    // =============================
    // (7b) updateBefore node posisi 2
    // =============================
    DNode* pos2_again = getNodeAt(L, 2);
    Song bebas;
    bebas.Title = "Melodi Baru";
    bebas.Artist = "Sora";
    bebas.DurationSec = 190;
    bebas.PlayCount = 200;
    bebas.Rating = 4.3;

    updateBefore(L, pos2_again, bebas);

    cout << "\n=== LIST SETELAH updateBefore(posisi 2) ===\n";
    viewList(L);

    // =============================
    // (7c) deleteBefore node posisi 3
    // =============================
    DNode* pos3 = getNodeAt(L, 3);
    Song removed2;
    deleteBefore(L, pos3, removed2);

    cout << "\nDeleteBefore(posisi 3) -> Terhapus: " << removed2.Title << "\n";

    cout << "\n=== LIST SETELAH deleteBefore(posisi 3) ===\n";
    viewList(L);

    // =============================
    // (8) Searching PopularityScore (150 - 300)
    // =============================
    cout << "\n=== SEARCH PopularityScore 150.0 - 300.0 ===\n";
    searchByPopularityRange(L, 150.0f, 300.0f);

    cout << "\nPROGRAM SELESAI.\n";
    return 0;
}
