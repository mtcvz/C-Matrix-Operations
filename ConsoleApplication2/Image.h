#pragma once
#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <Matrix.h>
#include <string.h>
#include <string>
#include <iomanip>

using namespace std;

class Image :public Matrix
{
public:
    Image();
    Image(int, int);
    Image(string, string);
    void imwrite(string, string);


protected:

private:
    struct rgb {
        int red;
        int green;
        int blue;
    };
};

#endif // IMAGE_H