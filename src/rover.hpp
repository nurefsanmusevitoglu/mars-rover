#ifndef ROVER_H
#define ROVER_H

#include <string>

class Rover
{
private:
    int x;
    int y;
    char orientation;
    std::string instructions;

public:
    Rover();
    Rover(int x, int y, char orientation, std::string instructions);
    Rover(const Rover& r);
    Rover& operator=(const Rover& r);
    int GetX();
    int GetY();
    char GetOrientation();
    std::string GetInstructions();
    void applyInstruction(char instruction);
};

#endif