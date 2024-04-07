// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: ShapeTwoD.cpp
// -------------------------

#include "ShapeTwoD.h"

using namespace std;

// accessor and mutator functions
void ShapeTwoD::setName(string name)
{
    this->name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
    this->containsWarpSpace = containsWarpSpace;
}

string ShapeTwoD::getName()
{
    return name;
}

bool ShapeTwoD::getContainsWarpSpace()
{
    return containsWarpSpace;
}
