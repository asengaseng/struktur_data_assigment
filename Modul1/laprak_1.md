# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (1)</h1>
<p align="center">Jeky Sebayang - 103112430160</p>

## Dasar Teori
Materi ini menjelaskan tentang penggunaan Code::Blocks, yaitu sebuah lingkungan pengembangan terintegrasi (IDE) yang bersifat gratis dan digunakan untuk menulis program menggunakan bahasa C++. Dalam pembelajaran ini, Anda akan mempelajari cara menginstal Code::Blocks, membuat proyek baru, menulis kode program, serta menjalankan hasilnya. Selain itu, dijelaskan pula bagaimana cara mengatasi berbagai masalah yang sering muncul, seperti program yang tidak dapat dijalankan, dengan menggunakan fitur Clean Project, serta memahami pesan kesalahan (error message) yang muncul akibat kesalahan dalam penulisan kode.

Pada bagian dasar pemrograman, materi ini membahas konsep-konsep utama dalam bahasa C++, seperti struktur dasar program, penggunaan tipe data (seperti int untuk bilangan bulat dan float untuk angka desimal), serta variabel sebagai tempat penyimpanan nilai. Anda juga akan belajar mengenai operator yang digunakan dalam operasi aritmetika dan logika, serta struktur pengendali alur program seperti percabangan (if-else, switch) untuk membuat keputusan, dan perulangan (for, while, do-while) untuk menjalankan proses yang berulang.


### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nPenjumlahan : " << a + b << endl;
    cout << "Pengurangan : " << a - b << endl;
    cout << "Perkalian   : " << a * b << endl;
    cout << "Pembagian   : " << a / b << endl;

    return 0;
}

```
Penjelasan singkat 1
Program C++ ini merupakan kalkulator sederhana yang dapat melakukan empat operasi aritmetika dasar. Program akan meminta pengguna untuk memasukkan dua buah angka, yang dapat berupa bilangan desimal. Setelah kedua angka dimasukkan, program akan menghitung dan menampilkan hasil dari operasi penjumlahan, pengurangan, perkalian, serta pembagian dari kedua bilangan tersebut.



### 2. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100 ) {
        cout << "Angka di luar jangkauan" << endl;

        return 0;
    }

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam",  "tujuh", "delapan", "sembilan"};
    string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
    string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

    if (angka == 0) {
        cout << "Nol" << endl;
    } else if (angka == 100) {
        cout << "Seratus" << endl;
    } else if (angka >= 10 && angka < 20) {
        cout << belasan[angka - 10] << endl;
    } else {
        int puluh = angka / 10;
        int satu = angka % 10;

        if (puluh > 0) cout << puluhan[puluh];
        if (puluh > 0 && satu > 0) cout << " ";
        if (satu >  0) cout << satuan[satu];
        cout << endl;
    }
    return 0;
}

```
penjelasan singkat 2
Program C++ ini berfungsi sebagai alat konversi yang mengubah bilangan bulat menjadi bentuk teks dalam Bahasa Indonesia, dengan batasan antara 0 hingga 100. Program akan meminta pengguna untuk memasukkan sebuah angka, kemudian memeriksa apakah nilai yang dimasukkan berada dalam rentang tersebut. Jika input valid, program akan memprosesnya: angka-angka khusus seperti 0, 100, dan bilangan belasan (10–19) akan langsung diterjemahkan. Untuk angka lainnya, program akan memisahkan nilai menjadi bagian puluhan dan satuan, kemudian menggabungkan keduanya untuk menghasilkan tampilan akhir berupa representasi kata dari angka yang dimasukkan.


### 3. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j < i) cout << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}



```
penjelasan singkat  3
Program C++ ini dibuat untuk menampilkan pola angka simetris (mirrored pattern) yang menurun berdasarkan input dari pengguna. Setelah pengguna memasukkan sebuah bilangan bulat, program akan menampilkan beberapa baris angka. Setiap baris terdiri dari dua bagian angka yang dipisahkan oleh tanda bintang (*): bagian pertama menampilkan urutan angka menurun dari nilai baris ke 1, sedangkan bagian kedua menampilkan urutan angka menaik dari 1 kembali ke nilai baris tersebut. Pola ini akan berkurang pada setiap baris berikutnya hingga tersisa angka 1, dan diakhiri dengan satu simbol * pada baris terakhir.


##### Output 1
![Screenshot Output 1](https://github.com/asengaseng/struktur_data_assigment/blob/main/Modul1/output1.png)

##### Output 2
![Screenshot Output 2](https://github.com/asengaseng/struktur_data_assigment/blob/main/Modul1/output2.png)

##### Output 3
![Screenshot Output 3](https://github.com/asengaseng/struktur_data_assigment/blob/main/Modul1/output3.png)


## Kesimpulan
...

## Referensi
[1]
<br>jukani. Moh. 2009. Struktur Data(Algoritma & Struktur Data 2) Dengan C, C++ .Edisi 3. Jakarta : Mitra Wacana Media


<br>
