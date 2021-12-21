#include <iostream>
#include <vector>

using namespace std;

struct roverCoordinate
{
    int x;
    int y;
    char c;
};

int main()
{
    int numberOfRovers;
    pair<int, int> plateauCoordinates;
    vector<roverCoordinate> roversCoordinates;
    vector<string> instructions;

    int x, y;
    char c;
    roverCoordinate rc;
    string s;

    // read input
    cin >> numberOfRovers;
    cin >> x >> y;
    plateauCoordinates.first = x;
    plateauCoordinates.second = y;
    for (int i = 0; i < numberOfRovers; i++)
    {
        cin >> x >> y >> c;
        rc.x = x;
        rc.y = y;
        rc.c = c;
        roversCoordinates.push_back(rc);
        cin >> s;
        instructions.push_back(s);
    }

    // print input
    for (int i = 0; i < numberOfRovers; i++)
    {
        cout << roversCoordinates[i].x << roversCoordinates[i].y << roversCoordinates[i].c << endl;
        cout << instructions[i] << endl;
    }

    // logic
    for (int i = 0; i < numberOfRovers; i++)
    {
        for (int j = 0; j < instructions[i].length(); j++)
        {
            switch (instructions[i][j])
            {
            case 'R':
            case 'L':
                switch (roversCoordinates[i].c)
                {
                case 'N':
                    instructions[i][j] == 'R' ? roversCoordinates[i].c = 'E' : roversCoordinates[i].c = 'W';
                    break;
                case 'E':
                    instructions[i][j] == 'R' ? roversCoordinates[i].c = 'S' : roversCoordinates[i].c = 'N';
                    break;
                case 'S':
                    instructions[i][j] == 'R' ? roversCoordinates[i].c = 'W' : roversCoordinates[i].c = 'E';
                    break;
                case 'W':
                    instructions[i][j] == 'R' ? roversCoordinates[i].c = 'N' : roversCoordinates[i].c = 'S';
                    break;

                default:
                    break;
                }
                break;

            case 'M':
                switch (roversCoordinates[i].c)
                {
                case 'N':
                    roversCoordinates[i].y++;
                    break;
                case 'E':
                    roversCoordinates[i].x++;
                    break;
                case 'S':
                    roversCoordinates[i].y--;
                    break;
                case 'W':
                    roversCoordinates[i].x--;
                    break;

                default:
                    break;
                }
                break;

            default:
                cout << "Invalid instruction" << endl;
                break;
            }
        }
    }

    // print output
    for (int i = 0; i < numberOfRovers; i++)
    {
        cout << roversCoordinates[i].x << " " << roversCoordinates[i].y << " " << roversCoordinates[i].c << endl;
    }

    return 0;
}