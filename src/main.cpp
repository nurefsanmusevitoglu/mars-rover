#include "../lib/rover.hpp"
#include "../lib/handler.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    string filename = argv[1];
    string instructions;
    pair<int, int> plateauCoordinates;
    vector<Rover> rovers;
    Handler handler;

    try
    {
        // read input
        handler.readInput(&rovers, &plateauCoordinates, filename);

        /*
         * traverse through all the rovers and apply instructions
         * if the orientation is invalid, pass the rover
         * if an instruction is invalid, skip the instruction
         * if a move instruction leads to the outside of the plateau, skip the instruction
         */
        // logic
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
        handler.printOutput(&rovers);

        return EXIT_SUCCESS;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}