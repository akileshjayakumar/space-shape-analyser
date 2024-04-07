// Name                 : Akilesh Jayakumar
// UOW Student Number   : 7901240
// Tutorial Group Number: T06
// Assignment 2         : Enterprise-2D

// -------------------------
// File: Assn2.cpp
// -------------------------

#include <iostream>
#include <string>
#include "Cross.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "ShapeTwoD.h"

using namespace std;

ShapeTwoD * shapeArray[100];
int global_count = 0;

void startMenu();
void readShape();
void sortMenu();
void ascendingSort(vector<ShapeTwoD *> vec);
void descendingSort(vector<ShapeTwoD *> vec);
void specialSortA(vector<ShapeTwoD *> vec);
void specialSortD(vector<ShapeTwoD *> vec);
bool checkNumber(string str);


int main()
{
    string choice;
    bool flag = true;
    while (flag)
    {
        startMenu();
        cin >> choice;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        if (checkNumber(choice))
        {
            int ichoice = stoi(choice);
            // switch statement for executing different program functions
            switch (ichoice)
            {
            case 1:
                readShape();
                break;
            case 2:
                for (int i = 0; i < global_count; i++)
                {
                    shapeArray[i]->set_area();
                }
                cout << "\nComputation completed! (" << global_count << " records were updated)" << endl;
                break;
            case 3:

                cout << "\nTotal no. of records available = " << global_count << endl << endl;
                for (int i = 0; i < global_count; i++)
                {
                    cout << shapeArray[i]->toString() << endl
                         << endl;
                }
                break;
            case 4:
                sortMenu();
                break;
            case 5:
                cout << "\nThank you for using Assn2 program!" << endl << endl;
                flag = false;
                break;
            }
        }
    }
    for (auto v : shapeArray)
    {
        delete v;
    }
    return 0;
}

// function for displaying the start menu options
void startMenu()
{
    cout << "\nStudent ID  :  7901240";
	cout << "\nStudent Name:  Akilesh Jayakumar" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Welcome to Assn2 program!" << endl << endl;
	cout << "1)\tInput sensor data" << endl;
	cout << "2)\tCompute area (for all records)" << endl;
	cout << "3)\tPrint shapes report" << endl;
	cout << "4)\tSort shape data" << endl;
	cout << "5)\tQuit" << endl << endl;
	cout << "Please enter your choice: ";
}

// function for input validation for the start menu
bool checkNumber(string str) 
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

// function to read in user input (option 1)
void readShape()
{
    string shape_name;
    string spec_type;
    bool contain_warp;
    // prompt user for name of shape
    cout << "\n[ Input sensor data ]";
    cout << "\nPlease enter name of shape: ";
    cin >> shape_name;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter special type: ";
    cin >> spec_type;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    contain_warp = (spec_type == "WS") ? true : (spec_type == "NS") ? false : false;
    // create new shape based on user input
    if (shape_name == "Square")
    {
        shapeArray[global_count] = new Square(shape_name, contain_warp, global_count);
        global_count++;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nRecord successfully stored. Going back to main menu ... " << endl;
    }
    else if (shape_name == "Circle")
    {
        shapeArray[global_count] = new Circle(shape_name, contain_warp, global_count);
        global_count++;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nRecord successfully stored. Going back to main menu ... " << endl;
    }
    else if (shape_name == "Cross")
    {
        shapeArray[global_count] = new Cross(shape_name, contain_warp, global_count);
        global_count++;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nRecord successfully stored. Going back to main menu ... " << endl;
    }
    else if (shape_name == "Rectangle")
    {
        shapeArray[global_count] = new Rectangle(shape_name, contain_warp, global_count);
        global_count++;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "\nRecord successfully stored. Going back to main menu ... " << endl;
    }
    else
    {
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Invaild shape name. Going back to main menu ... " << endl << endl;
    }
}

// function for displaying the sort menu (option 4)
void sortMenu()
{
    vector<ShapeTwoD *> vec;
    for (int i = 0; i < global_count; i++)
    {
        vec.push_back(shapeArray[i]);
    }
    char choice;
    cout << endl;
    cout << "\ta)\tSort by area (ascending)" << endl;
    cout << "\tb)\tSort by area (descending)" << endl;
    cout << "\tc)\tSort by special type and area (ascending)\n";
    cout << "\td)\tSort by special type and area (ascending)" << endl;
    cout << "\nPlease select sort option ('q' to go main menu): ";

    cin >> choice;
    cout << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    switch (choice)
    {
    case 'a':
        // ascending sort
        ascendingSort(vec);
        cout << endl;
        break;
    case 'b':
        descendingSort(vec);
        cout << endl;
        // descending sort
        break;
    case 'c':
        specialSortA(vec);
        cout << endl;
        break;
    case 'd':
        specialSortD(vec);
        cout << endl;
        break;
    case 'q':
        cout << "Going back to main menu ... ";
        break;
    }
    vec.clear();
}

// function for ascending sort (option 4)
void ascendingSort(vector<ShapeTwoD *> vec)
{
    sort(vec.begin(), vec.end(), [](ShapeTwoD *lhs, ShapeTwoD *rhs) { //err squiggies
        return lhs->get_area() > rhs->get_area();
    });
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i]->toString() << endl
             << endl;
    }
}

// function for descending sort (option 4)
void descendingSort(vector<ShapeTwoD *> vec)
{
    sort(vec.begin(), vec.end(), [](ShapeTwoD *lhs, ShapeTwoD *rhs)
    {
        return lhs->get_area() < rhs->get_area();
    }
    );
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i]->toString() << endl
             << endl;
    }
}

// function for special ascending sort (option 4)
void specialSortA(vector<ShapeTwoD *> vec)
{
    vector<ShapeTwoD *> vec_NS;
    vector<ShapeTwoD *> vec_WS;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->getContainsWarpSpace() == false)
        {
            vec_NS.push_back(vec[i]);
        }
        else
        {
            vec_WS.push_back(vec[i]);
        }
    }
    ascendingSort(vec_WS);
    ascendingSort(vec_NS);
    vec_NS.clear();
    vec_WS.clear();
}

// function for special descending sort (option 4)
void specialSortD(vector<ShapeTwoD *> vec)
{
    vector<ShapeTwoD *> vec_NS;
    vector<ShapeTwoD *> vec_WS;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->getContainsWarpSpace() == false)
        {
            vec_NS.push_back(vec[i]);
        }
        else
        {
            vec_WS.push_back(vec[i]);
        }
    }
    descendingSort(vec_WS);
    descendingSort(vec_NS);
    vec_NS.clear();
    vec_WS.clear();
}
