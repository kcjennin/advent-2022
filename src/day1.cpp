#include <iostream>
#include <fstream>
#include <string>

long first, second, third;

void updateTopThree(long newNumber)
{
    if (newNumber >= first)
    {
        third = second;
        second = first;
        first = newNumber;
    }
    else if (newNumber >= second)
    {
        third = second;
        second = newNumber;
    }
    else if (newNumber >= third)
    {
        third = newNumber;
    }
    else { /* No update */}
}

using namespace std;

int main()
{
    ifstream input ("input/day1.txt");
    string line;
    long calorieSum;

    first = second = third = -1;
    
    if (input.is_open())
    {
        while (getline(input, line))
        {
            calorieSum = 0;

            while (line != "")
            {
                calorieSum += stoi(line);
                if (!getline(input, line)) { break; }
            }
            updateTopThree(calorieSum);
        }

        cout << "Top Elf: " << first << endl;
        cout << "Top Three Elves: " << first + second + third << endl;
        input.close();
    }
    else { cout << "Unable to open file." << endl; }

    return 0;
}