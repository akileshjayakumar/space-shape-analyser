// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: Circle.cpp
// -------------------------

#include "Circle.h"

// circle constructor
Circle::Circle(string name, bool containsWarpSpace, int id) 
{
    this->name = name;
    this->containsWarpSpace = containsWarpSpace;
    this->id = id;
    this->set_ords(); 
}

// area setter
void Circle::set_area() 
{
    this->area = computeArea();
}

// area getter
void Circle::set_ords()
{
    cout << endl;
    cout << "Please enter x-ordiante of center : ";
    cin >> this->x_ord;
    cout << "Please enter y-ordiante of center : ";
    cin >> this->y_ord;
    cout << "Please enter radius(units) : ";
    cin >> this->radius;
}

string Circle::toString()
{

    string stype = (this->containsWarpSpace) ? "WS" : "NS";
    string output;
    stringstream stream;

    output += "Shape [" + to_string(this->id) + "]\n";
    output += "Name  : " + this->name + "\n" + "Special Type : " + stype + "\n";
    stream << fixed << setprecision(2) << this->area;
    output += "Area : " + stream.str() + " units square" + "\n" + "Vectices : \n";
    output += "Point [0] : (" + to_string(this->x_ord) + ", " + to_string(this->y_ord) + ")\n";

    output += "\nPoints on perimeter : ";
    for (int i = x_ord - radius; i <= x_ord + radius; i++)
    {
        for (int j = y_ord - radius; j <= y_ord + radius; j++)
        {
            if (isPointOnShape(i, j))
            {
                output += "(" + to_string(i) + ", " + to_string(j) + "), ";
            }
        }
    }
    output += "\b\b  ";
    if (this->radius == 1)
        output += "\n\nPoints within shape : None!";
    else
    {
        output += "\n\nPoints within shape : ";
        for (int i = x_ord - radius; i < x_ord + radius; i++) 
        {
            for (int j = y_ord - radius; j < y_ord + radius; j++)
            {
                if (i == x_ord && j == y_ord)
                {
                    continue;
                }
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

bool Circle::isPointOnShape(int x, int y)
{
    if (x == x_ord && y == y_ord + radius)
        return true;
    else if (x == x_ord + radius && y == y_ord)
        return true;
    else if (x == x_ord && y == y_ord - radius)
        return true;
    else if (x == x_ord - radius && y == y_ord)
        return true;
    else
        return false;
}

bool Circle::isPointInShape(int x, int y)
{
    if (pow((x - this->x_ord), 2) + pow((y - this->y_ord), 2) < this->radius * this->radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Circle::computeArea()
{
    return M_PI * (this->radius * this->radius);
}

double Circle::get_area() 
{
    return this->area;
}
