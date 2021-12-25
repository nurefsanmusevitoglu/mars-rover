#include "rover.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int, int> intPair;

intPair readInput(vector<Rover> *rovers, string filename)
{
    pair<int, int> plateauCoordinates;
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
    plateauCoordinates = make_pair(x, y);
    cout << "plateauCoordinates: " << x << " " << y << endl;
    while (!infile.eof())
    {
        infile >> x >> y >> orientation >> instructions;
        cout << x << " " << y << " " << orientation << " " << instructions << endl;
        rover = new Rover(id++, x, y, orientation, instructions);
        rovers->push_back(*rover);
    }

    return plateauCoordinates;
}

void printOutput(vector<Rover> *rovers)
{
    for (int i = 0; i < (*rovers).size(); i++)
    {
        cout << (*rovers)[i].GetX() << " ";
        cout << (*rovers)[i].GetY() << " ";
        cout << (*rovers)[i].GetOrientation() << endl;
    }
}

int main(int argc, char **argv)
{
    string filename = argv[1];
    string instructions;
    intPair plateauCoordinates;
    vector<Rover> rovers;

    try
    {
        // read input
        plateauCoordinates = readInput(&rovers, filename);

        // logic
        /*
         * traverse through all the rovers and apply instructions
         * if the orientation is invalid, pass the rover
         * if an instruction is invalid, skip the instruction
         * if a move instruction leads to the outside of the plateau, skip the instruction
         */
        for (int i = 0; i < rovers.size(); i++)
        {
            if (rovers[i].checkOrientation())
            {
                instructions = rovers[i].GetInstructions();
                for (int j = 0; j < instructions.length(); j++)
                {
                    if (rovers[i].checkInstruction(instructions[j]))
                    {
                        rovers[i].applyInstruction(instructions[j], plateauCoordinates);
                    }
                    else
                    {
                        cerr << "Invalid instruction: " << instructions[j] << ", ";
                        cerr << "for Rover with id: " << rovers[i].GetId() << endl;
                    }
                }
            }
            else
            {
                cerr << "Invalid orientation: " << rovers[i].GetOrientation() << ", ";
                cerr << "for Rover with id: " << rovers[i].GetId() << endl;
            }
        }

        // print output
        printOutput(&rovers);

        return EXIT_SUCCESS;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}