#include "rover.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readInput(vector<Rover> *rovers)
{
    ifstream infile("input");
    int x, y;
    char orientation;
    string instructions;
    Rover rover;

    while (!infile.eof())
    {
        infile >> x >> y >> orientation;
        infile >> instructions;
        cout << x << " " << y << " " << orientation << " " << instructions << endl;
        rover = Rover(x, y, orientation, instructions);
        rovers->push_back(rover);
    }
}

void printOutput(vector<Rover> *rovers)
{
    for (int i = 0; i < (*rovers).size(); i++)
    {
        cout << (*rovers)[i].GetX() << " " << (*rovers)[i].GetY() << " " << (*rovers)[i].GetOrientation() << endl;
    }
}

int main()
{
    int x, y;
    string instructions;
    pair<int, int> plateauCoordinates;
    vector<Rover> rovers;

    // read input
    cin >> x >> y;
    plateauCoordinates = make_pair(x, y);
    cout << x << " " << y << endl;
    readInput(&rovers);

    // logic
    // TODO: handle errors such as
    //       invalid instruction
    //       moving outside of the plateauCoordinates
    for (int i = 0; i < rovers.size(); i++)
    {
        instructions = rovers[i].GetInstructions();
        cout << "instructions: " << instructions << endl;
        for (int j = 0; j < instructions.length(); j++)
        {
            rovers[i].applyInstruction(instructions[j]);
        }
    }

    // print output
    printOutput(&rovers);

    return 0;
}