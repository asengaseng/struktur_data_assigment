#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int STACK_MAX = 6;

struct StackMahasiswa {
    Mahasiswa data[STACK_MAX];
    int Top;
};

bool isEmpty(StackMahasiswa& S) { return S.Top == -1; }
bool isFull(StackMahasiswa& S) { return S.Top == STACK_MAX - 1; }

void createStack(StackMahasiswa& S) { S.Top = -1; }

void Push(StackMahasiswa& S, const Mahasiswa& M) {
    if (isFull(S)) { cout << "Stack penuh, tidak bisa push\n"; return; }
    S.Top++;
    S.data[S.Top] = M;
}

void Pop(StackMahasiswa& S, Mahasiswa& Mout) {
    if (isEmpty(S)) { cout << "Stack kosong, tidak bisa pop\n"; return; }
    Mout = S.data[S.Top];
    S.Top--;
}

void Update(StackMahasiswa& S, int posisi, const Mahasiswa& M) {
    if (posisi <= 0 || posisi > S.Top + 1) {
        cout << "Posisi update invalid\n";
        return;
    }
    int idx = posisi - 1;
    S.data[idx] = M;
}

void View(StackMahasiswa& S) {
    cout << "StackMahasiswa (Top index = " << S.Top << ")\n";
    if (isEmpty(S)) { cout << "(kosong)\n"; return; }

    for (int i = S.Top; i >= 0; --i) {
        const Mahasiswa& m = S.data[i];
        float nilaiAkhir = 0.2f * m.NilaiTugas + 0.4f * m.NilaiUTS + 0.4f * m.NilaiUAS;

        cout << (i+1) << ". Nama: " << m.Nama
             << ", NIM: " << m.NIM
             << ", Nilai Akhir: " << nilaiAkhir << "\n";
    }
}

void SearchNilaiAkhir(StackMahasiswa& S, float minVal, float maxVal) {
    cout << "Search NilaiAkhir in [" << minVal << ", " << maxVal << "]\n";
    bool found = false;

    for (int i = S.Top; i >= 0; --i) {
        const Mahasiswa& m = S.data[i];
        float nilaiAkhir = 0.2f * m.NilaiTugas
                         + 0.4f * m.NilaiUTS
                         + 0.4f * m.NilaiUAS;

        if (nilaiAkhir >= minVal && nilaiAkhir <= maxVal) {
            found = true;
            cout << "Posisi " << (i+1)
                 << ": " << m.Nama
                 << " (Nilai Akhir = " << nilaiAkhir << ")\n";
        }
    }

    if (!found) cout << "Tidak ada mahasiswa dalam rentang tersebut.\n";
}

void MaxNilaiAkhir(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "MaxNilaiAkhir: stack kosong\n";
        return;
    }

    float maxV = -1e9;
    for (int i = 0; i <= S.Top; ++i) {
        const Mahasiswa& m = S.data[i];
        float nilaiAkhir = 0.2f * m.NilaiTugas
                         + 0.4f * m.NilaiUTS
                         + 0.4f * m.NilaiUAS;
        maxV = max(maxV, nilaiAkhir);
    }

    cout << "Mahasiswa dengan NilaiAkhir maksimum = " << maxV << ":\n";
    for (int i = 0; i <= S.Top; ++i) {
        const Mahasiswa& m = S.data[i];
        float nilaiAkhir = 0.2f * m.NilaiTugas
                         + 0.4f * m.NilaiUTS
                         + 0.4f * m.NilaiUAS;

        if (fabs(nilaiAkhir - maxV) < 1e-6) {
            cout << "Posisi " << (i+1)
                 << ": " << m.Nama
                 << " NIM: " << m.NIM << "\n";
        }
    }
}
