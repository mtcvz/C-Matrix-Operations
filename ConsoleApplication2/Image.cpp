#include "Image.h"

Image::Image() :Matrix(255, 255) {  // Kurucu fonksiyona de?er verilmezse matris kurucu fonksiyonuna 255,255 sat?r sütun de?erleri yollan?r

}

Image::Image(int width, int height) : Matrix(width, height) {    //Matris kurucu fonksiyonuna sat?r sütun de?erleri yollan?r

}

Image::Image(string filename, string format) {

    if (format == "bin") {                                      //format bin ise dosya binary okuma modunda aç?l?r
        ifstream dosya(filename.c_str(), ios::binary);


        if (!dosya.is_open())                                //Dosya ba?ar?l? aç?lamazsa hata verilir
            cout << "Dosya okunamadi.";


        unsigned char d1, d2;
        int satir, sutun;

        dosya >> d1;
        dosya >> d2;

        satir = d1;                       // Dosyadaki ilk iki de?er okunur. Sat?r ve sütun isimleri olarak yeniden boyutland?rma yap?l?r.
        sutun = d2;

        this->resize(satir, sutun);

        for (int i = 0; i < satir; i++) {           //Di?er de?erler matrise at?l?r
            for (int j = 0; j < sutun; j++) {
                unsigned char pixel;
                dosya >> pixel;
                matris[i][j] = pixel;
            }
        }
    }
}

void Image::imwrite(string filename, string format) {

    if (format == "bin") {                  //Format bin ise binary modunda yaz?lacak dosya aç?l?r

        ofstream dosya(filename.c_str(), ios::binary);

        if (!dosya.is_open())                         //Dosya ba?ar?l? aç?lamazsa uyar? verilir
            cout << "dosya acma basarisiz." << endl;



        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {                   //Matris elemanlar? dosyaya yazd?r?l?r
                dosya << matris[i][j];
            }
        }
    }
}