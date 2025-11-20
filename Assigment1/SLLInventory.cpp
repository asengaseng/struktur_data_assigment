#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// =======================
//   STRUCT & ADT SLL
// =======================
struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct SNode {
    Product info;
    SNode* next;
    SNode(const Product& p) : info(p), next(nullptr) {}
};

struct SList {
    SNode* head;
    SList() : head(nullptr) {}
};

bool isEmpty(const SList& L) { return L.head == nullptr; }
void createList(SList& L) { L.head = nullptr; }
SNode* allocate(const Product& p) { return new SNode(p); }
void deallocate(SNode* addr) { delete addr; }

void insertFirst(SList& L, const Product& P) {
    SNode* node = allocate(P);
    node->next = L.head;
    L.head = node;
}

void insertLast(SList& L, const Product& P) {
    SNode* node = allocate(P);
    if (isEmpty(L)) { L.head = node; return; }
    SNode* cur = L.head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

void insertAfter(SList& L, SNode* Q, const Product& P) {
    if (!Q) return;
    SNode* node = allocate(P);
    node->next = Q->next;
    Q->next = node;
}

void deleteFirst(SList& L, Product& Pout) {
    if (isEmpty(L)) return;
    SNode* tmp = L.head;
    Pout = tmp->info;
    L.head = tmp->next;
    deallocate(tmp);
}

void deleteLast(SList& L, Product& Pout) {
    if (isEmpty(L)) return;
    if (!L.head->next) {
        Pout = L.head->info;
        deallocate(L.head);
        L.head = nullptr;
        return;
    }
    SNode* cur = L.head;
    while (cur->next->next) cur = cur->next;
    Pout = cur->next->info;
    deallocate(cur->next);
    cur->next = nullptr;
}

void deleteAfter(SList& L, SNode* Q, Product& Pout) {
    if (!Q || !Q->next) return;
    SNode* tmp = Q->next;
    Pout = tmp->info;
    Q->next = tmp->next;
    deallocate(tmp);
}

void updateAtPosition(SList& L, int posisi, const Product& P) {
    if (posisi <= 0) return;
    SNode* cur = L.head;
    int idx = 1;
    while (cur && idx < posisi) {
        cur = cur->next;
        idx++;
    }
    if (cur) cur->info = P;
}

float hargaAkhir(const Product& p) {
    return p.HargaSatuan * (1.0f - p.DiskonPersen / 100.0f);
}

void viewList(const SList& L) {
    cout << "SLL Inventory List:\n";
    SNode* cur = L.head;
    int idx = 1;
    while (cur) {
        const Product& p = cur->info;
        cout << idx << ". Nama: " << p.Nama << ", SKU: " << p.SKU
             << ", Jumlah: " << p.Jumlah
             << ", HargaSatuan: " << p.HargaSatuan
             << ", Diskon%: " << p.DiskonPersen
             << ", HargaAkhir: " << hargaAkhir(p) << "\n";
        cur = cur->next; idx++;
    }
    if (idx == 1) cout << "(kosong)\n";
}

void searchByFinalPriceRange(const SList& L, float minPrice, float maxPrice) {
    cout << "Search HargaAkhir in [" << minPrice << ", " << maxPrice << "]\n";
    SNode* cur = L.head;
    int idx = 1;
    bool found = false;
    while (cur) {
        float h = hargaAkhir(cur->info);
        if (h >= minPrice && h <= maxPrice) {
            found = true;
            cout << "Position " << idx << ": " << cur->info.Nama
                 << " (HargaAkhir=" << h << ")\n";
        }
        cur = cur->next; idx++;
    }
    if (!found) cout << "Tidak ada produk dalam rentang tersebut.\n";
}

void MaxHargaAkhir(const SList& L) {
    if (isEmpty(L)) {
        cout << "MaxHargaAkhir: list kosong.\n";
        return;
    }
    float maxH = -1e9f;
    SNode* cur = L.head;
    while (cur) {
        maxH = max(maxH, hargaAkhir(cur->info));
        cur = cur->next;
    }

    cout << "Produk dengan HargaAkhir maksimum = " << maxH << ":\n";
    cur = L.head;
    int idx = 1;
    while (cur) {
        if (fabs(hargaAkhir(cur->info) - maxH) <= 1e-6f) {
            cout << "Position " << idx << ": "
                 << cur->info.Nama << " SKU:" << cur->info.SKU << "\n";
        }
        cur = cur->next; idx++;
    }
}
