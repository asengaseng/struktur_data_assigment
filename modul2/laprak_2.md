# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Jeky Sebayang - 1031124301160</p>

## Dasar Teori
Kebutuhan perangkat lunak merupakan dasar utama dalam pengembangan sistem, yang mendefinisikan semua fungsi, fitur, serta batasan yang harus dipenuhi oleh perangkat lunak tersebut. Kebutuhan ini umumnya terbagi menjadi dua kategori utama. Pertama, Kebutuhan Fungsional, yang secara jelas menjelaskan apa saja tugas yang harus dijalankan oleh sistem, seperti kemampuan untuk mencetak dokumen, memutar musik, atau menghitung langkah pengguna. Kedua, Kebutuhan Non-Fungsional, yang sering dikenal sebagai aspek kualitas atau batasan, menjelaskan bagaimana sistem tersebut harus beroperasi atau tingkat performa yang harus dicapai. Contoh kebutuhan non-fungsional meliputi kecepatan respons, keamanan, kemudahan penggunaan, serta batasan teknologi yang harus diterapkan.

Dalam konteks sistem operasi, proses adalah sebuah program yang sedang berjalan atau dieksekusi, dan merupakan unit kerja yang diatur oleh sistem operasi. Untuk mengelola proses ini, sistem operasi menggunakan sebuah struktur data penting yang disebut Process Control Block (PCB). PCB berisi informasi lengkap tentang status proses, isi register, dan kontrol terkait proses tersebut. Proses melewati beberapa tahap dalam siklus hidupnya: mulai dari status New (baru dibuat), kemudian Ready (siap menunggu giliran untuk mendapatkan CPU), berlanjut ke Running (sedang dieksekusi), bisa beralih ke Blocked (menunggu operasi I/O atau kejadian lain), dan akhirnya Exit (proses telah selesai). Untuk menjalankan beberapa proses secara bersamaan (multitasking), sistem operasi memanfaatkan teknik seperti Context Switching, yaitu pergantian cepat antar proses, serta Swapping, yakni pemindahan proses ke penyimpanan sekunder (disk) jika memori utama penuh.

### 1. ...

```C++
#include <iostream>
using namespace std;

const int SIZE = 3;

void inputMatriks(int mat[SIZE][SIZE]) {
    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void tampilkanMatriks(int mat[SIZE][SIZE]) {
    cout << "Matriks:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void penjumlahan(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

void pengurangan(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalian(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriksA[SIZE][SIZE], matriksB[SIZE][SIZE], hasil[SIZE][SIZE];
    int pilihan;

    cout << "=== Program Operasi Matriks 3x3 ===\n";
    inputMatriks(matriksA);
    cout << "\nMatriks A:\n";
    tampilkanMatriks(matriksA);

    inputMatriks(matriksB);
    cout << "\nMatriks B:\n";
    tampilkanMatriks(matriksB);

    cout << "\nPilih operasi:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            penjumlahan(matriksA, matriksB, hasil);
            cout << "\nHasil Penjumlahan:\n";
            tampilkanMatriks(hasil);
            break;
        case 2:
            pengurangan(matriksA, matriksB, hasil);
            cout << "\nHasil Pengurangan:\n";
            tampilkanMatriks(hasil);
            break;
        case 3:
            perkalian(matriksA, matriksB, hasil);
            cout << "\nHasil Perkalian:\n";
            tampilkanMatriks(hasil);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }

    return 0;
}


```
penjelasan singkat 1
Kode ini merupakan program sederhana untuk melakukan operasi matriks 3x3, yaitu penjumlahan, pengurangan, dan perkalian antara dua matriks yang dimasukkan oleh pengguna. Program meminta pengguna untuk mengisi elemen-elemen dari dua matriks 3x3, kemudian menampilkan kedua matriks tersebut. Selanjutnya, pengguna diminta memilih operasi yang ingin dilakukan: penjumlahan, pengurangan, atau perkalian. Berdasarkan pilihan tersebut, program akan menjalankan fungsi yang sesuai untuk menghitung hasil operasi matriks dan menampilkan matriks hasilnya ke layar. Setiap fungsi operasi menggunakan loop bersarang untuk mengakses dan memproses elemen-elemen matriks sesuai dengan aturan operasi matriks. Program ini juga menangani input pengguna dan memastikan hasil operasi dapat dilihat secara jelas, sehingga memberikan gambaran dasar tentang manipulasi matriks dalam bahasa C++.

### 2. ...

```C++

#include <iostream>
using namespace std;

void swapPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void swapReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "=== Swap Menggunakan Pointer ===\n";
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    swapPointer(&x, &y, &z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;

    x = 10; y = 20; z = 30;

    cout << "\n=== Swap Menggunakan Reference ===\n";
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    swapReference(x, y, z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;

    return 0;
}

```
Kode ini memperlihatkan dua cara berbeda untuk menukar nilai tiga variabel (x, y, dan z) dalam bahasa C++. Pertama, menggunakan pointer melalui fungsi swapPointer, yang menerima alamat memori dari variabel-variabel tersebut dan menukar nilainya dengan mengakses langsung memori menggunakan dereferensi pointer. Kedua, menggunakan reference melalui fungsi swapReference, yang menerima variabel secara referensi sehingga perubahan di dalam fungsi langsung mempengaruhi variabel asli tanpa perlu dereferensi. Kedua metode ini berhasil melakukan pertukaran nilai dengan efektif, namun penggunaan reference lebih sederhana dan aman karena tidak memerlukan operasi dereferensi secara eksplisit, sementara pointer memberikan kontrol yang lebih eksplisit terhadap alamat memori. Secara keseluruhan, kode ini menggambarkan konsep penting dalam C++ tentang bagaimana variabel dapat dimanipulasi melalui alamat memori (pointer) maupun alias (reference).

### 3. ...

```C++

#include <iostream>
using namespace std;

const int UKURAN = 10;
int arrA[UKURAN] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

int cariMinimum() {
    int min = arrA[0];
    for (int i = 1; i < UKURAN; i++) {
        if (arrA[i] < min) {
            min = arrA[i];
        }
    }
    return min;
}

int cariMaksimum() {
    int max = arrA[0];
    for (int i = 1; i < UKURAN; i++) {
        if (arrA[i] > max) {
            max = arrA[i];
        }
    }
    return max;
}

void hitungRataRata() {
    float sum = 0;
    for (int i = 0; i < UKURAN; i++) {
        sum += arrA[i];
    }
    float rataRata = sum / UKURAN;
    cout << "Rata-rata: " << rataRata << endl;
}

void tampilkanArray() {
    cout << "Isi array: ";
    for (int i = 0; i < UKURAN; i++) {
        cout << arrA[i] << " ";
    }
    cout << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray();
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum() << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum() << endl;
                break;
            case 4:
                hitungRataRata();
                break;
            case 0:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
```
penjelasan singkat  3
Program C++ ini adalah alat bantu sederhana berbasis menu interaktif yang dirancang untuk menganalisis data angka yang tersimpan dalam array berisi 10 elemen. Fungsi utamanya adalah menyediakan empat operasi dasar: menampilkan keseluruhan isi array, mencari nilai maksimum (cariMaksimum), mencari nilai minimum (cariMinimum), dan menghitung rata-rata (hitungRataRata) semua elemen. Pengguna dapat berinteraksi dengan program untuk memilih operasi yang diinginkan, dan program akan terus berjalan hingga pengguna memilih opsi untuk keluar.

##### Output 1
![Screenshot Output 1](https://github.com/asengaseng/struktur-data-assigment/blob/main/Modul 2/output1.png)

##### Output 2
![Screenshot Output 2](https://github.com/asengaseng/struktur-data-assigment/blob/main/Modul 2/output2.png)

##### Output 3
![Screenshot Output 3](https://github.com/asengaseng/struktur-data-assigment/blob/main/Modul 2/output-3.png)


## Kesimpulan
...

## Referensi
[1]
<br>jukani. Moh. 2009. Struktur Data(Algoritma & Struktur Data 2) Dengan C, C++ .Edisi 3. Jakarta : Mitra Wacana Media

<br>
