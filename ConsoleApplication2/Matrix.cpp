#include "Matrix.h"

using namespace std;


Matrix::Matrix(int satir, int sutun, int z) {

    Matrix::x = satir;                             //Satýr ve sütun deðerleri saklanýr
    Matrix::y = sutun;

    for (int i = 0; i < x; i++) {                       //Matris vektörü tanýmlanýr
        matris.push_back(vector <int>(y));
    }

    for (int i = 0; i < Matrix::x; i++) {
        for (int j = 0; j < Matrix::y; j++) {
            Matrix::matris[i][j] = z;             //Matrisin içine deðerler atanýr
        }
    }
}

Matrix::Matrix(int satir, int sutun, char harf) {

    Matrix::x = satir;
    Matrix::y = sutun;
    Matrix::p = harf;

    if (Matrix::p == 'e' || Matrix::p == 'r') {                       //p veya e harfi girilmiþse matris oluþturulur
        for (int i = 0; i < x; i++) {
            matris.push_back(vector <int>(y));
        }
    }

    if (Matrix::p == 'e') {                                         //Matrise deðerler birim matris olacak þekilde atýlýr
        for (int i = 0; i < Matrix::x; i++) {
            for (int j = 0; j < Matrix::y; j++) {

                if (i == j)
                    Matrix::matris[i][j] = 1;

                else
                    Matrix::matris[i][j] = 0;
            }
        }
    }

    if (Matrix::p == 'r') {                                        //Matrise deðerler random atýlýr
        for (int i = 0; i < Matrix::x; i++) {
            for (int j = 0; j < Matrix::y; j++) {
                Matrix::matris[i][j] = rand() % (256 - 0);
            }
        }
    }
}

void Matrix::resize(int satir, int sutun) {

    Matrix::x = satir;                                        //Yeni satýr ve sütun deðerleri saklanýr
    Matrix::y = sutun;

    Matrix::matris.resize(x);                               //Matris yeniden boyutlandýrýlýr
    for (int i = 0; i < x; i++) {
        Matrix::matris[i].resize(y);
    }
}

void Matrix::print() {                                       //Matris ekrana yazdýrýlýr

    for (int i = 0; i < Matrix::x; i++) {
        for (int j = 0; j < Matrix::y; j++) {
            cout << Matrix::matris[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::print(string dosyaadi) {                    //Matris belirtilen dosyaya yazdýrýlýr

    ofstream dosya;
    dosya.open(dosyaadi.c_str());

    for (int i = 0; i < Matrix::x; i++) {
        for (int j = 0; j < Matrix::y; j++) {
            dosya << Matrix::matris[i][j] << " ";
        }
        dosya << endl;
    }
}

Matrix Matrix::operator+(Matrix no2) {

    Matrix temp(this->x, this->y, 0);                         //Ayný boyutlarda geçici matris oluþturulur

    if (this->x == no2.x && this->y == no2.y) {                     //Ýki matrisin boyutlarýnýn eþitliði kontrol edilir

        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < this->y; j++) {
                temp.matris[i][j] = this->matris[i][j] + no2.matris[i][j];   //Geçici matrise iki matrisin elemanlarý toplamý atýlýr
            }
        }
    }
    else
        cout << "Matrisler cikarilamaz." << endl;

    return temp;
}

Matrix Matrix::operator-(Matrix no2) {

    Matrix temp(this->x, this->y, 0);                         //Ayný boyutlarda geçici matris oluþturulur

    if (this->x == no2.x && this->y == no2.y) {

        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < this->y; j++) {
                temp.matris[i][j] = this->matris[i][j] - no2.matris[i][j];      //Geçici matrise iki matrisin elemanlarý farký atýlýr
            }
        }
    }
    else
        cout << "Matrisler cikarilamaz." << endl;

    return temp;
}


Matrix Matrix::operator*(Matrix no2) {

    Matrix temp(this->x, no2.y, 0);                           //Çarpýmýn atýlacaðý geçici matris oluþturulur

    if (this->y == no2.x) {                                     //Ýlk matrisin sütunu ile ikincisinin satýrýnýn eþitliði kontrol edilir

        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < no2.y; j++) {
                for (int k = 0; k < no2.y; k++) {
                    temp.matris[i][j] += (this->matris[i][k]) * (no2.matris[k][j]);      //Çarpým geçici matrise atýlýr
                }
            }
        }
    }

    else
        cout << "Matrisler carpilamaz." << endl;

    return temp;
}


Matrix Matrix::operator+(int t) {

    Matrix temp(this->x, this->y, 0);                     //Ayný boyutlarda geçici matris oluþturulur

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = this->matris[i][j] + t;    //Matrisin elemanlarýyla t deðerinin toplamý geçici matrise atýlýr
        }
    }
    return temp;
}

Matrix Matrix::operator-(int t) {

    Matrix temp(this->x, this->y, 0);

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = this->matris[i][j] - t;
        }
    }
    return temp;
}

Matrix Matrix::operator*(int t) {

    Matrix temp(this->x, this->y, 0);

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = this->matris[i][j] * t;
        }
    }
    return temp;
}

Matrix Matrix::operator/(int t) {

    Matrix temp(this->x, this->y, 0);

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = this->matris[i][j] / t;
        }
    }
    return temp;
}

Matrix Matrix::operator%(int t) {

    Matrix temp(this->x, this->y, 0);

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = this->matris[i][j] % t;
        }
    }
    return temp;
}

Matrix Matrix::operator^(int t) {

    Matrix temp(this->x, this->y, 0);                 //Ayný boyutlarda geçici matris oluþturulur

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = matris[i][j];         //Matrisin elemanlarý geçici matrise atýlýr
        }
    }

    for (int i = 1; i < t; i++) {                           //t deðeri kadar matris çarpýmý yapýlýr
        temp = temp * temp;
    }
    return temp;
}

void Matrix::T() {

    Matrix temp(this->x, this->y, 0);                 //Ayný boyutlarda geçici matris açýlýr ve içine elemanlar atýlýr

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            temp.matris[i][j] = this->matris[i][j];
        }
    }

    this->resize(this->y, this->x);                  //Matris satýr ve sütunu yer deðiþtirerek yeniden boyutlandýrýlýr

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            this->matris[i][j] = temp.matris[j][i];               // Yeniden boyutlandýrýlmýþ matrise geçici matristeki
        }                                                       // deðerler satýr ile sütunu yer deðiþtirerek atýlýr
    }
}

void Matrix::emul(Matrix temp) {

    for (int i = 0; i < this->x; i++) {                                 //Matrisin elemanlarý diðer matrisin ayný satýr ve sütuna denk düþen elemanlarýyla çarpýlýr
        for (int j = 0; j < this->y; j++) {
            this->matris[i][j] *= temp.matris[i][j];
        }
    }
}

/*void Matrix::det() {

    float rat, det;
    float matris[x][y];       // ondalýk deðerler oluþabileceði için float matris açýlýr



    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            matris[i][j] = this->matris[i][j];               //Matrisin elemanlarý float matrise atýlýr
        }
    }

    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->x; j++) {
            if (j > i) {
                rat = (matris[j][i]) / (matris[i][i]);

                for (int k = 0; k < this->x; k++) {
                    matris[j][k] -= rat * (matris[i][k]);
                }
            }
        }
    }
    det = 1;

    for (int i = 0; i < this->x; i++) {
        det *= matris[i][i];
    }
    cout << det << endl;
}

*/
void Matrix::inv() {

    Matrix temp(this->x, this->y, 'e');               //Geçici bir birim matris oluþturulur

    float d, k;

    for (int i = 0; i < this->x; i++) {                    //Asýl matris iþlemlerle birim matrise dönüþtürülmeye çalýþýlýr
        d = this->matris[i][i];                      //Ayný iþlemler birim matrise de uygulanýr
        for (int j = 0; j < this->x; j++) {                //Asýl matris birim matrise dönüþtüðünde geçici matristeki deðerler matrisin tersi olur
            this->matris[i][j] /= d;
            temp.matris[i][j] /= d;
        }
        for (int c = 0; c < this->x; c++) {
            if (c != i) {
                k = this->matris[c][i];
                for (int j = 0; j < this->x; j++) {
                    this->matris[c][j] -= (this->matris[i][j] * k);
                    temp.matris[c][j] -= (temp.matris[i][j] * k);
                }
            }
        }
    }

    for (int i = 0; i < this->x; i++) {                     //Geçici matristeki deðerler asýl matrise atýlýr
        for (int j = 0; j < this->y; j++) {
            this->matris[i][j] = temp.matris[i][j];
        }
    }
}