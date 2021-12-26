#include "../lib/handler.hpp"
#include "../lib/rover.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// default constructor
Handler::Handler() {}

// read input
void Handler::readInput(vector<Rover> *rovers, pair<int, int> *plateauCoordinates, string filename)
{
    int id = 1, x, y;
    char orientation;
    string instructions;
    Rover *rover;
    ifstream infile(filename);
    if (infile.fail())
    {
        throw runtime_error("Could not find file: " + filename);
    }

    infile >> x >> y;
    *plateauCoordinates = make_pair(x, y);
    while (!infile.eof())
    {
        infile >> x >> y >> orientation >> instructions;
        rover = new Rover(id++, x, y, orientation, instructions);
        rovers->push_back(*rover);
    }
}

// print output
void Handler::printOutput(vector<Rover> *rovers)
{
    for (int i = 0; i < (*rovers).size(); i++)
    {
        cout << (*rovers)[i].GetX() << " ";
        cout << (*rovers)[i].GetY() << " ";
        cout << (*rovers)[i].GetOrientation() << endl;
    }
}