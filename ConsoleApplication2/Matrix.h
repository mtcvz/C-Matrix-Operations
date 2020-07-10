#pragma once
//#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Matrix
{
public:
    Matrix(int satir = 10, int sutun = 10, int z = 0);
    Matrix(int satir, int sutun, char harf);
    void resize(int satir, int sutun);
    void print();
    void print(string dosyaadi);
    Matrix operator+(Matrix no2);
    Matrix operator*(Matrix no2);
    Matrix operator-(Matrix no2);
    Matrix operator+(int t);
    Matrix operator-(int t);
    Matrix operator*(int t);
    Matrix operator/(int t);
    Matrix operator%(int t);
    Matrix operator^(int t);
    void T();
    void emul(Matrix temp);
    void det();
    void inv();

protected:
    int x, y;
    char p;
    vector<vector <int> > matris;

private:
};

//#endif // MATRIX_H
