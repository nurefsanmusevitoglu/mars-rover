#include "rover.hpp"
#include <iostream>

using namespace std;

// default constructor
Rover::Rover() {}

// constructor
Rover::Rover(int x1, int y1, char o, string i)
{
    x = x1;
    y = y1;
    orientation = o;
    instructions = i;
}

// copy constructor
Rover::Rover(const Rover& r)
{
    cout << "Copy constructor called " << endl;
}

// assignment operator
Rover& Rover::operator=(const Rover& r)
{
    cout << "Assignment operator called " << endl;
    return *this;
}

// get x
int Rover::GetX()
{
    return x;
}

// get y
int Rover::GetY()
{
    return y;
}

// get orientation
char Rover::GetOrientation()
{
    return orientation;
}

// get instructions
string Rover::GetInstructions()
{
    return instructions;
}

// applyInstruction function
void Rover::applyInstruction(char instruction)
{
    // cout << "In apply function..." << endl;
    // cout << "instruction: " << instruction << endl;
    switch (orientation)
    {
    case 'N':
        instruction == 'M' ? y++ : (instruction == 'R' ? orientation = 'E' : orientation = 'W');
        break;

    case 'E':
        instruction == 'M' ? x++ : (instruction == 'R' ? orientation = 'S' : orientation = 'N');
        break;

    case 'S':
        instruction == 'M' ? y-- : (instruction == 'R' ? orientation = 'W' : orientation = 'E');
        break;

    case 'W':
        instruction == 'M' ? x-- : (instruction == 'R' ? orientation = 'N' : orientation = 'S');
        break;

    default:
        cout << "Invalid orientation: " << orientation << endl;
        break;
    }
    // cout << "Out from apply function..." << endl;
}