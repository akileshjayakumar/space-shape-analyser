// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: Rectangle.cpp
// -------------------------

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string name, bool containsWarpSpace, int id)
{
    this->name = name;
    this->containsWarpSpace = containsWarpSpace;
    this->id = id;
    this->set_ords();
}

// area setter
void Rectangle::set_area()
{
    this->area = computeArea();
}

void Rectangle::set_ords()
{
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
        cout << "Please enter x-ordiante of pt." << i + 1 << " : ";
        cin >> this->x_ord[i];
        cout << "Please enter y-ordiante of pt." << i + 1 << " : ";
        cin >> this->y_ord[i];
        if (i == 0)
        {
            this->x_min = this->x_ord[i];
            this->y_min = this->y_ord[i];
        }
        if (this->x_ord[i] < x_min)
            this->x_min = this->x_ord[i];
        if (this->y_ord[i] < y_min)
            this->y_min = this->y_ord[i];
        if (this->x_ord[i] > x_max)
            this->x_max = this->x_ord[i];
        if (this->y_ord[i] > y_max)
            this->y_max = this->y_ord[i];
    }
}

// function for toString
string Rectangle::toString()
{
    bool isCord = false;
    string stype = (this->containsWarpSpace) ? "WS" : "NS";
    string output;
    output += "Shape [" + to_string(this->id) + "]\n";
    output += "Name  : " + this->name + "\n" + "Special Type : " + stype + "\n";
    output += "Area : " + to_string(this->area) + " units square" + "\n" + "Vectices : \n";

    for (int i = 0; i < 4; i++)
    {
        output += "Point [" + to_string(i) + "] : (" + to_string(x_ord[i]) + ", " + to_string(y_ord[i]) + ")\n";
    }
    int iPoS_count = 0;
    output += "Points on perimeter : ";
    for (int i = x_min; i <= x_max; i++)
    {
        for (int j = y_min; j <= y_max; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (x_ord[k] == i && y_ord[k] == j)
                    isCord = true;
            }
            if (isPointOnShape(i, j) && !isCord)
            {
                output += "(" + to_string(i) + ", " + to_string(j) + "), ";
                iPoS_count++;
            }
            isCord = false;
        }
    }
    if (iPoS_count == 0)
    {
        output += "None!";
    }
    else
    {
        output += "\b\b  ";
    }

    if (this->area <= 4)
        output += "\n\nPoints within shape : None!";
    else
    {
        output += "\n\nPoints within shape : ";
        for (int i = x_min; i <= x_max; i++)
        {
            for (int j = y_min; j <= y_max; j++)
            {
                if (isPointInShape(i, j))
                {
                    output += "(" + to_string(i) + ", " + to_string(j) + "), ";
                }
            }
        }
        output += "\b\b  ";
    }

    return output;
}

bool Rectangle::isPointInShape(int x, int y)
{
    if (x < this->x_max && x > this->x_min && y < this->y_max && y > this->y_min)
    {
        return true;
    }
    else
        return false;
}

bool Rectangle::isPointOnShape(int x, int y)
{
    if (x == this->x_min && y >= this->y_min && y <= this->y_max)
    {
    	return true;
    }
    else if (y == this->y_max && x >= this->x_min && x <= this->x_max) 
    {
        return true;
    }
    else if (x == this->x_max && y >= this->y_min && y <= this->y_max)
    {
        return true;
    }
    else if (y == this->y_min && x >= this->x_min && x <= this->x_max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Rectangle::computeArea()
{
    double ar = 0;
    int j = 3;

    for (int i = 0; i < 4; i++)
    {
        ar += (x_ord[j] + x_ord[i]) * (y_ord[j] - y_ord[i]);
        j = i;
    }
    ar = ar / 2;
    ar = abs(ar);
    return ar;
}

double Rectangle::get_area()
{
    return this->area;
}
