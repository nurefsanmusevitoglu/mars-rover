#include <iostream>
#include <vector>

using namespace std;

struct roverPosition
{
    int x;
    int y;
    char orientation;
};

struct rover
{
    roverPosition roverPosition;
    string instructions;
};

struct input
{
    pair<int, int> plateauCoordinates;
    vector<rover> rovers;
};

struct output
{
    vector<roverPosition> roversFinalPositions;
};

input readInput()
{
    int numberOfRovers;
    int x, y;
    char orientation;
    roverPosition roverPosition;
    string instructions;
    rover rover;
    input input;

    cin >> numberOfRovers;
    cin >> x >> y;

    input.plateauCoordinates = make_pair(x, y);

    for (int i = 0; i < numberOfRovers; i++)
    {
        cin >> x >> y >> orientation;
        cin >> instructions;

        roverPosition.x = x;
        roverPosition.y = y;
        roverPosition.orientation = orientation;

        rover.roverPosition = roverPosition;
        rover.instructions = instructions;

        input.rovers.push_back(rover);
    }

    return input;
}

// TODO: plateauCoordinates coordinates check should be handled
// TODO: switch case should be grouped
roverPosition applyInstructions(rover rover)
{
    roverPosition roverFinalPosition = rover.roverPosition;
    char instruction, orientation;

    for (int i = 0; i < rover.instructions.length(); i++)
    {
        instruction = rover.instructions[i];
        orientation = roverFinalPosition.orientation;
        switch (instruction)
        {
        case 'R':
        case 'L':
            switch (orientation)
            {
            case 'N':
                instruction == 'R' ? roverFinalPosition.orientation = 'E' : roverFinalPosition.orientation = 'W';
                break;
            case 'E':
                instruction == 'R' ? roverFinalPosition.orientation = 'S' : roverFinalPosition.orientation = 'N';
                break;
            case 'S':
                instruction == 'R' ? roverFinalPosition.orientation = 'W' : roverFinalPosition.orientation = 'E';
                break;
            case 'W':
                instruction == 'R' ? roverFinalPosition.orientation = 'N' : roverFinalPosition.orientation = 'S';
                break;

            // TODO: default case handle
            default:
                break;
            }
            break;

        case 'M':
            switch (orientation)
            {
            case 'N':
                roverFinalPosition.y++;
                break;
            case 'E':
                roverFinalPosition.x++;
                break;
            case 'S':
                roverFinalPosition.y--;
                break;
            case 'W':
                roverFinalPosition.x--;
                break;

            // TODO: default case handle
            default:
                break;
            }
            break;

        default:
            cout << "Invalid instruction" << endl;
            break;
        }
    }
    return roverFinalPosition;
}

void printOutput(output output)
{
    roverPosition position;
    for (int i = 0; i < output.roversFinalPositions.size(); i++)
    {
        position = output.roversFinalPositions[i];
        cout << position.x << " " << position.y << " " << position.orientation << endl;
    }
}

int main()
{
    input input;
    output output;

    // read input
    input = readInput();

    // logic
    for (int i = 0; i < input.rovers.size(); i++)
    {
        roverPosition roverFinalPosition;
        roverFinalPosition = applyInstructions(input.rovers[i]);
        output.roversFinalPositions.push_back(roverFinalPosition);
    }

    // print output
    printOutput(output);

    return 0;
}