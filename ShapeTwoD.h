// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: ShapeTwoD.h
// -------------------------

#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

// abstract class
class ShapeTwoD
{
protected:
    string name;
    bool containsWarpSpace;
    int id;

public:
    void setName(string name);
    void setContainsWarpSpace(bool containsWarpSpace);
    string getName();
    bool getContainsWarpSpace();
    // virtual functions
    virtual string toString() = 0;
    virtual double computeArea() = 0;
    virtual bool isPointInShape(int x, int y) = 0;
    virtual bool isPointOnShape(int x, int y) = 0;
    virtual void set_ords() = 0;
    virtual void set_area() = 0;
    virtual double get_area() = 0;
    virtual ~ShapeTwoD() = default;
};

#endif
