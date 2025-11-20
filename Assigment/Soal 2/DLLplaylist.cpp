#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating; 
};

struct DNode {
    Song info;
    DNode* prev;
    DNode* next;
    DNode(const Song& s) : info(s), prev(nullptr), next(nullptr) {}
};

struct DList {
    DNode* head;
    DNode* tail;
    DList() : head(nullptr), tail(nullptr) {}
};

bool isEmpty(const DList& L) { return L.head == nullptr && L.tail == nullptr; }
void createList(DList& L) { L.head = L.tail = nullptr; }
DNode* allocate(const Song& s) { return new DNode(s); }
void deallocate(DNode* p) { delete p; }

void insertFirst(DList& L, const Song& S) {
    DNode* node = allocate(S);
    if (isEmpty(L)) { L.head = L.tail = node; return; }
    node->next = L.head;
    L.head->prev = node;
    L.head = node;
}

void insertLast(DList& L, const Song& S) {
    DNode* node = allocate(S);
    if (isEmpty(L)) { L.head = L.tail = node; return; }
    L.tail->next = node;
    node->prev = L.tail;
    L.tail = node;
}

void insertAfter(DList& L, DNode* Q, const Song& S) {
    if (!Q) return;
    if (Q == L.tail) { insertLast(L, S); return; }
    DNode* node = allocate(S);
    node->next = Q->next;
    node->prev = Q;
    Q->next->prev = node;
    Q->next = node;
}

void insertBefore(DList& L, DNode* Q, const Song& S) {
    if (!Q) return;
    if (Q == L.head) { insertFirst(L, S); return; }
    DNode* node = allocate(S);
    node->prev = Q->prev;
    node->next = Q;
    Q->prev->next = node;
    Q->prev = node;
}

void deleteFirst(DList& L, Song& Sout) {
    if (isEmpty(L)) return;
    DNode* tmp = L.head;
    Sout = tmp->info;
    if (L.head == L.tail) { deallocate(tmp); L.head = L.tail = nullptr; return; }
    L.head = tmp->next;
    L.head->prev = nullptr;
    deallocate(tmp);
}

void deleteLast(DList& L, Song& Sout) {
    if (isEmpty(L)) return;
    DNode* tmp = L.tail;
    Sout = tmp->info;
    if (L.head == L.tail) { deallocate(tmp); L.head = L.tail = nullptr; return; }
    L.tail = tmp->prev;
    L.tail->next = nullptr;
    deallocate(tmp);
}

void deleteAfter(DList& L, DNode* Q, Song& Sout) {
    if (!Q || !Q->next) return;
    DNode* tmp = Q->next;
    Sout = tmp->info;
    Q->next = tmp->next;
    if (tmp->next) tmp->next->prev = Q;
    if (tmp == L.tail) L.tail = Q;
    deallocate(tmp);
}

void deleteBefore(DList& L, DNode* Q, Song& Sout) {
    if (!Q || !Q->prev) return;
    DNode* tmp = Q->prev;
    Sout = tmp->info;
    Q->prev = tmp->prev;
    if (tmp->prev) tmp->prev->next = Q;
    if (tmp == L.head) L.head = Q;
    deallocate(tmp);
}

void updateAtPosition(DList& L, int posisi, const Song& S) {
    if (posisi <= 0) return;
    DNode* cur = L.head;
    int idx = 1;
    while (cur && idx < posisi) { cur = cur->next; idx++; }
    if (cur) cur->info = S;
}

void updateBefore(DList& L, DNode* Q, const Song& S) {
    if (!Q || !Q->prev) return;
    Q->prev->info = S;
}

DNode* getNodeAt(DList& L, int posisi) {
    if (posisi <= 0) return nullptr;
    DNode* cur = L.head; int idx = 1;
    while (cur && idx < posisi) { cur = cur->next; idx++; }
    return cur;
}

float PopularityScore(const Song& s) {
    return 0.8f * s.PlayCount + 20.0f * s.Rating;
}

void viewList(const DList& L) {
    cout << "DLL Playlist:\n";
    DNode* cur = L.head; int idx = 1;
    if (!cur) { cout << "(kosong)\n"; return; }
    while (cur) {
        cout << idx << ". Title: " << cur->info.Title
             << ", Artist: " << cur->info.Artist
             << ", Duration: " << cur->info.DurationSec
             << ", PlayCount: " << cur->info.PlayCount
             << ", Rating: " << cur->info.Rating
             << ", PopularityScore: " << PopularityScore(cur->info)
             << "\n";
        cur = cur->next; idx++;
    }
}

void searchByPopularityRange(const DList& L, float minScore, float maxScore) {
    cout << "Search PopularityRange [" << minScore << ", " << maxScore << "]\n";
    DNode* cur = L.head; int idx = 1; bool found = false;
    while (cur) {
        float s = PopularityScore(cur->info);
        if (s >= minScore && s <= maxScore) {
            found = true;
            cout << "Position " << idx << ": " << cur->info.Title
                 << " (Popularity=" << s << ")\n";
        }
        cur = cur->next; idx++;
    }
    if (!found) cout << "Tidak ada lagu dalam rentang tersebut.\n";
}
