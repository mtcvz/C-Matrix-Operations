#include "Tablo.h"
#include "Matrix.h"
using namespace std;

Tablo::Tablo() {

    Tablo::x = 10;                        //Satir ve sütun girilmezse satir ve sütun degerlerine 10 atilir
    Tablo::y = 10;

    for (int i = 0; i < x; i++) {               // Satir dizisine 0'dan ba?layarak sirayla degerler atilir
        row[i] = 48 + i;
    }

    for (int i = 0; i < y; i++) {               //Sütun dizisine A'dan baslayarak sirayla degerler atilir
        col[i] = 65 + i;
    }
}

Tablo::Tablo(int r, int c, int d) :Matrix(r, c, d) {      // Satir ve sütun için de?er girilmisse o degerler matrisin kurucu fonksiyonuna yollanir

    Tablo::x = r;
    Tablo::y = c;

    for (int i = 0; i < x; i++) {
        row[i] = 48 + i;
    }

    for (int i = 0; i < y; i++) {
        col[i] = 65 + i;
    }
}

Tablo::Tablo(int r, int c, char ch) :Matrix(r, c, ch) {

    Tablo::x = r;
    Tablo::y = c;

    for (int i = 0; i < x; i++) {
        row[i] = 48 + i;
    }

    for (int i = 0; i < y; i++) {
        col[i] = 65 + i;
    }
}

void Tablo::itemAt(int r, int c) {

    cout << Tablo::matris[r][c] << endl;            // Girilen sat?r ve sütun numaral? matris eleman? yaz?l?r
}

void Tablo::itemAt(string s) {

    int i = 0, j = 0, k = 0, sz;

    sz = s.size();                                // Girilen stringin boyutu ölçülür

    if (sz == 2) {                                  // Boyutu "A0" gibi 2 ise A ve 0 sat?r ve sütun isimleriyle k?yaslan?r
        for (i = 0; i < x; i++) {
            if (s[1] == 48 + i)
                break;
        }

        for (j = 0; j < y; j++) {
            if (s[0] == 65 + j)
                break;
        }
    }
    else {

        for (i = 0; i < x; i++) {
            int colsz = col[i].size();           //Boyutu 2'den fazlaysa
                                               //Aranan stringin sütun isimlerinin boyutlar?na kadarl?k k?sm? k?yaslan?r
            for (k = 0; k < colsz; k++) {
                if (col[i][k] != s[k])
                    break;
            }
            if (k == colsz)
                break;
        }

        int p = col[i].size();                  // Buldu?umuz sütun isminin boyutu al?n?r


        for (j = 0; j < y; j++) {
            int rowsz = row[j].size();

            for (k = 0; k < rowsz; k++) {

                if (row[j][k] != s[k + p])       // Sütun isminden itibaren kalanlar sat?r isimleriyle s?rayla k?yaslan?r
                    break;
            }
            if (k == rowsz)
                break;
        }
    }
    cout << Tablo::matris[i][j] << endl;     //Bulunan sat?r sütun de?eri ekrana yazd?r?l?r
}

void Tablo::itemAt(string rs, string cs) {

    int i = 0, j = 0;

    for (i = 0; i < x; i++) {                       //Aranan sat?r ve sütun ismi elimizdeki sat?r ve sütun isimleriyle k?yaslan?r
        if (!rs.compare(row[i]))
            break;
    }

    for (j = 0; j < y; j++) {
        if (!cs.compare(col[j]))
            break;
    }

    cout << Tablo::matris[i][j] << endl;
}

void Tablo::setRowNames(string s[], int n) {

    for (int i = 0; i < n; i++) {                //Sat?r isimlerinin bulundu?u diziye yeni isimlerin bulundu?u dizinin de?erleri at?l?r
        row[i] = s[i];
    }
}

void Tablo::setColNames(string s[], int n) {

    for (int j = 0; j < n; j++) {               //Sütun isimlerinin bulundu?u diziye yeni isimlerin bulundu?u dizinin de?erleri at?l?r
        col[j] = s[j];
    }
}

void Tablo::print() {

    cout << setw(12);

    for (int i = 0; i < y; i++) {
        cout << col[i] << setw(4);          //Sütun isimleri yazd?r?l?r
    }
    cout << endl;

    for (int i = 0; i < x; i++) {               //Sat?r isimleri ve tablonun elemanlar? s?rayla yazd?r?l?r

        cout << row[i] << setw(8);
        for (int j = 0; j < y; j++) {
            cout << matris[i][j] << " ";
        }
        cout << endl;
    }
}