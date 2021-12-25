#ifndef ROVER_H
#define ROVER_H

#include <string>

class Rover
{
private:
    int id;
    int x;
    int y;
    char orientation;
    std::string instructions;

public:
    Rover();
    Rover(int id, int x, int y, char orientation, std::string instructions);
    Rover(const Rover& r);
    Rover& operator=(const Rover &r);

    int GetId();
    int GetX();
    int GetY();
    char GetOrientation();
    std::string GetInstructions();
    
    void applyInstruction(char instruction, std::pair<int, int> plateauCoordinates);
    void checkNewCoordinates(int x, int y, std::pair<int, int> plateauCoordinates);
    bool checkInstruction(char instruction);
    bool checkOrientation();
};

#endif