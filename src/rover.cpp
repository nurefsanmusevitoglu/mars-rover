#include "rover.hpp"
#include <iostream>

using namespace std;

// default constructor
Rover::Rover() {}

// constructor
Rover::Rover(int id1, int x1, int y1, char o, string i)
{
    id = id1;
    x = x1;
    y = y1;
    orientation = o;
    instructions = i;
}

// copy constructor
Rover::Rover(const Rover &r)
{
    id = r.id;
    x = r.x;
    y = r.y;
    orientation = r.orientation;
    instructions = r.instructions;
}

// assignment operator
Rover &Rover::operator=(const Rover &r)
{
    return *this;
}

// get id
int Rover::GetId()
{
    return id;
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
void Rover::applyInstruction(char instruction, pair<int, int> plateauCoordinates)
{
    int newX = x, newY = y;

    switch (orientation)
    {
    case 'N':
        instruction == 'M' ? newY++ : (instruction == 'R' ? orientation = 'E' : orientation = 'W');
        break;

    case 'E':
        instruction == 'M' ? newX++ : (instruction == 'R' ? orientation = 'S' : orientation = 'N');
        break;

    case 'S':
        instruction == 'M' ? newY-- : (instruction == 'R' ? orientation = 'W' : orientation = 'E');
        break;

    case 'W':
        instruction == 'M' ? newX-- : (instruction == 'R' ? orientation = 'N' : orientation = 'S');
        break;
    }

    checkNewCoordinates(newX, newY, plateauCoordinates);
}

void Rover::checkNewCoordinates(int newX, int newY, pair<int, int> plateauCoordinates)
{
    if (!(newX < 0 || newX > plateauCoordinates.first ||
        newY < 0 || newY > plateauCoordinates.second))
    {
        x = newX;
        y = newY;
    }
    else
    {
        cerr << "Move instruction leads to the outside of the plateau, coordinates: ";
        cerr << x << " " << y << " " << orientation << endl;
    }
}



bool Rover::checkInstruction(char instruction)
{
    if (instruction == 'M' || instruction == 'R' || instruction == 'L')
    {
        return true;
    }
    return false;
}

bool Rover::checkOrientation()
{
    if (orientation == 'N' || orientation == 'E' ||
        orientation == 'S' || orientation == 'W')
    {
        return true;
    }
    return false;
}