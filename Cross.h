// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: Cross.h
// -------------------------

#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"

using namespace std;

class Cross : public ShapeTwoD
{
private:
    int x_ord[12];
    int y_ord[12];
    int area = 0;
    int x_min = INT8_MAX;
    int y_min = INT8_MAX;
    int x_max = 0;
    int y_max = 0;

public:
    Cross(string name, bool containsWarpSpace, int id);
    void set_area();
    void set_ords();
    string toString();
    double computeArea();
    bool isPointOnShape(int x, int y);
    bool isPointInShape(int x, int y);
    int pnpoly(int nvert, int *vertx, int *verty, int testx, int testy);
    bool isPointaVertex(int x, int y);
    double get_area();
};

#endif
