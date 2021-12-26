#ifndef HANDLER_H
#define HANDLER_H

#include "rover.hpp"
#include <string>
#include <vector>

class Handler
{
public:
    Handler();

    void readInput(std::vector<Rover> *rovers, std::pair<int, int> *plateauCoordinates, std::string filename);
    void printOutput(std::vector<Rover> *rovers);
};

#endif