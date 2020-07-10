#pragma once
//#ifndef TABLO_H
#define TABLO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Matrix.h"
#include <string.h>
#include <string>
#include <iomanip>


using namespace std;

class Tablo :public Matrix
{
public:
    Tablo();
    Tablo(int, int, int);
    Tablo(int, int, char);
    void itemAt(int, int);
    void itemAt(string s);
    void itemAt(string, string);
    void setRowNames(string s[], int n);
    void setColNames(string s[], int n);
    void print();


protected:

private:
    string col[29];
    string row[100];
};
//#endif // TABLO_H