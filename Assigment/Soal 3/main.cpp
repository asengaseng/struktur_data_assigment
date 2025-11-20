#include <iostream>
#include "StackMahasiswa.cpp"   // memakai ADT yang sudah kamu buat
using namespace std;

int main() {

    StackMahasiswa S;
    createStack(S);   // (1) buat stack kosong

    // (2) Input 6 data mahasiswa sesuai soal
    Push(S, {"Venti",    "11111", 75.7f, 82.1f, 65.5f});
    Push(S, {"Xiao",     "22222", 87.4f, 88.9f, 81.9f});
    Push(S, {"Kazuha",   "33333", 92.3f, 88.8f, 82.4f});
    Push(S, {"Wanderer", "44444", 95.5f, 85.5f, 90.5f});
    Push(S, {"Lynette",  "55555", 77.7f, 65.4f, 79.9f});
    Push(S, {"Chasca",   "66666", 99.9f, 93.6f, 87.3f});

    cout << "\n=== (3) Stack setelah input 6 mahasiswa ===\n";
    View(S);

    // (4) Pop 1x
    Mahasiswa removed;
    Pop(S, removed);

    cout << "\n=== (4) Data terhapus (Pop 1x) ===\n";
    cout << removed.Nama << " (" << removed.NIM << ")\n";

    // (5) Tampilkan lagi stack
    cout << "\n=== (5) Stack setelah Pop 1x ===\n";
    View(S);

    // (6) Update posisi ke-3
    Mahasiswa H = {"Heizou", "77777", 99.9f, 88.8f, 77.7f};
    Update(S, 3, H);

    cout << "\n=== (7) Stack setelah Update posisi ke-3 ===\n";
    View(S);

    // (8) Searching NilaiAkhir dalam rentang [85.5, 95.5]
    cout << "\n=== (8) Searching nilai akhir dalam rentang 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5f, 95.5f);

    // Bagian B: tampilkan nilai akhir maksimum
    cout << "\n=== (Bagian B) Data dengan NilaiAkhir Maksimum ===\n";
    MaxNilaiAkhir(S);

    cout << "\nProgram selesai.\n";
    return 0;
}
