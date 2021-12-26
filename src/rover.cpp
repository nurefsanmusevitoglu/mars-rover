#include "../lib/rover.hpp"
#include <iostream>

using namespace std;

enum instructionType
{
    MOVE = 'M',
    LEFT = 'L',
    RIGHT = 'R'
};

enum orientationType
{
    NORTH = 'N',
    EAST = 'E',
    SOUTH = 'S',
    WEST = 'W'
};

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
    case NORTH:
        instruction == MOVE ? newY++ : (instruction == RIGHT ? orientation = EAST : orientation = WEST);
        break;

    case EAST:
        instruction == MOVE ? newX++ : (instruction == RIGHT ? orientation = SOUTH : orientation = NORTH);
        break;

    case SOUTH:
        instruction == MOVE ? newY-- : (instruction == RIGHT ? orientation = WEST : orientation = EAST);
        break;

    case WEST:
        instruction == MOVE ? newX-- : (instruction == RIGHT ? orientation = NORTH : orientation = SOUTH);
        break;
    }

    if (instruction == MOVE)
    {
        checkNewCoordinates(newX, newY, plateauCoordinates);
    }
}

// check new coordinates
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
        cerr << x << " " << y << " " << orientation << ", ";
        cerr << "for Rover with id: " << id << endl;
    }
}

// check instruction type
bool Rover::checkInstruction(char instruction)
{
    if (instruction == MOVE || instruction == RIGHT || instruction == LEFT)
    {
        return true;
    }
    return false;
}

// check orientation type
bool Rover::checkOrientation()
{
    if (orientation == NORTH || orientation == EAST ||
        orientation == SOUTH || orientation == WEST)
    {
        return true;
    }
    return false;
}