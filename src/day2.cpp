#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/// @brief Enum that contains values for the game
enum
{
    LOSS,
    ROCK,
    PAPER,
    SCISSORS,
    DRAW = SCISSORS,
    WIN = 6
};

/**
 * @brief Formats the line based on the expected outcome
 * line format 'A X'
 *
 * X = LOSS
 * Y = DRAW
 * Z = WIN
 *
 * @param line
 * @return
 */
void outcomeFromLine(string &line)
{
    switch (line[2])
    {
    case 'X':
        switch (line[0])
        {
        case 'A':
            line[2] = 'Z';
            break;
        case 'B':
            line[2] = 'X';
            break;
        case 'C':
            line[2] = 'Y';
            break;

        default:
            break;
        }
        break;
    case 'Y':
        switch (line[0])
        {
        case 'A':
            line[2] = 'X';
            break;
        case 'B':
            line[2] = 'Y';
            break;
        case 'C':
            line[2] = 'Z';
            break;

        default:
            break;
        }
        break;
    case 'Z':
        switch (line[0])
        {
        case 'A':
            line[2] = 'Y';
            break;
        case 'B':
            line[2] = 'Z';
            break;
        case 'C':
            line[2] = 'X';
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}

/**
 * @brief Determine points based on the line
 * line format 'A X'
 *
 * A, X = ROCK
 * B, Y = PAPER
 * C, Z = SCISSORS
 *
 * @param line
 * @return int
 */
int pointsFromLine(string line)
{
    switch (line[0])
    {
    case 'A':
        switch (line[2])
        {
        case 'X':
            return DRAW + ROCK;
        case 'Y':
            return WIN + PAPER;
        case 'Z':
            return LOSS + SCISSORS;

        default:
            return -1;
        }
    case 'B':
        switch (line[2])
        {
        case 'X':
            return LOSS + ROCK;
        case 'Y':
            return DRAW + PAPER;
        case 'Z':
            return WIN + SCISSORS;
        default:
            return -1;
        }
    case 'C':
        switch (line[2])
        {
        case 'X':
            return WIN + ROCK;
        case 'Y':
            return LOSS + PAPER;
        case 'Z':
            return DRAW + SCISSORS;

        default:
            return -1;
        }

    default:
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    ifstream input("input/day2.txt");
    string line;
    int points = 0;

    if (!input.is_open())
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    while (getline(input, line))
    {
        outcomeFromLine(line);
        points += pointsFromLine(line);
    }

    cout << "Points: " << points << endl;

    input.close();
    return 0;
}
