// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: Cross.cpp
// -------------------------

#include "Cross.h"

using namespace std;

Cross::Cross(string name, bool containsWarpSpace, int id)
{
    this->name = name;
    this->containsWarpSpace = containsWarpSpace;
    this->id = id;
    this->set_ords();
}

// area setter
void Cross::set_area() 
{
    this->area = computeArea(); 
}

// function for user to input coordinates 
void Cross::set_ords()
{
    for (int i = 0; i < 12; i++)
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

string Cross::toString()
{

    bool isCord = false;
    string stype = (this->containsWarpSpace) ? "WS" : "NS";
    string output;
    output += "Shape [" + to_string(this->id) + "]\n";
    output += "Name  : " + this->name + "\n" + "Special Type : " + stype + "\n";
    output += "Area : " + to_string(this->area) + " units square" + "\n" + "Vectices : \n";
    for (int i = 0; i < 12; i++)
    {
        output += "Point [" + to_string(i) + "] : (" + to_string(x_ord[i]) + ", " + to_string(y_ord[i]) + ")\n";
    }
    output += "\n\nPoints on perimeter : ";
    int iPoS_count = 0;
    for (int i = x_min; i <= x_max; i++)
    {
        for (int j = y_min; j <= y_max; j++)
        {
            if (isPointOnShape(i, j))
            {
                output += "(" + to_string(i) + ", " + to_string(j) + "), ";
                iPoS_count++;
            }
        }
    }
    if (iPoS_count == 0)
        output += "None!";
    else
        output += "\b\b  ";

    int iPiS_count = 0;
    output += "\n\nPoints within shape : ";
    for (int i = x_min + 1; i < x_max; i++)
    {
        for (int j = y_min + 1; j < y_max; j++)
        {
            if (isPointInShape(i, j) && !isPointOnShape(i, j) && !isPointaVertex(i, j))
            {
                output += "(" + to_string(i) + ", " + to_string(j) + "), ";
                iPiS_count++;
            }
        }
    }
    if (iPiS_count == 0)
        output += "None!";
    else
        output += "\b\b  ";

    return output;
}

double Cross::computeArea()
{
    double ar = 0;
    int j = 11;

    for (int i = 0; i < 12; i++)
    {
        ar += (x_ord[j] + x_ord[i]) * (y_ord[j] - y_ord[i]);
        j = i;
    }
    ar = ar / 2;
    ar = abs(ar);
    return ar;
}

bool Cross::isPointOnShape(int x, int y)
{
    for (int i = 0; i < 11; i++) 
    {

        int ux = max(x_ord[i], x_ord[i + 1]);     
        int lx = min(x_ord[i], x_ord[i + 1]);       
        int ly = min(y_ord[i], y_ord[i + 1]); 
        int uy = max(y_ord[i], y_ord[i + 1]);
        if (ux == lx && x == ux && y > ly && y < uy)
        {
            return true;
        }
        if (uy == ly && y == uy && x > lx && x < ux)
        {
            return true;
        }
    }
    int ux = max(x_ord[11], x_ord[0]);
    int lx = min(x_ord[11], x_ord[0]);
    int ly = min(y_ord[11], y_ord[0]);
    int uy = max(y_ord[11], y_ord[0]);
    if (ux == lx && x == ux && y > ly && y < uy)
    {
        return true;
    }
    if (uy == ly && y == uy && x > lx && x < ux)
    {
        return true;
    }
    return false;
}

bool Cross::isPointInShape(int x, int y) 
{
    bool flag;
    flag = pnpoly(12, this->x_ord, this->y_ord, x, y);

    return flag;
}

int Cross::pnpoly(int nvert, int *vertx, int *verty, int testx, int testy)
{
    int i, j, c = 0;
    for (i = 0, j = nvert - 1; i < nvert; j = i++) 
    {
        if (((verty[i] > testy) != (verty[j] > testy)) &&
            (testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i]))
            c = !c; 
    }
    return c;
}

bool Cross::isPointaVertex(int x, int y)
{
    for (int i = 0; i < 12; i++)
    {
        if (x == x_ord[i] && y == y_ord[i])
            return true;
    }
    return false;
}

// function for area toString
double Cross::get_area()
{
    return this->area;
}
