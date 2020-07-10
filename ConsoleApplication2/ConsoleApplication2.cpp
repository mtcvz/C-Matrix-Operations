#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Tablo.h"

using namespace std;

int main()
{
    Matrix m1(2, 2, 2);
    Matrix m2(3, 3, 'e');
    Matrix m3(2, 2, 'r');
    m1.print();
    m2.print();
    m1.resize(3, 3);
    m2 = m2 + m1;
    m2.print();
    m2 = m2 - 5;
    m2.T();
    m2.emul(m1);
    m3.inv();
   

    Tablo m51(3, 3, 'r');
    m51.itemAt("A0");
    string s[] = { "0.satir","1.satir","2.satir" };
    m51.setRowNames(s, 3);
    string m[] = { "ABC","CDE","EFG" };
    m51.setColNames(m, 3);

}
