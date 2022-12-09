#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int isContained(int a, int b, int x, int y)
{
    if ((a <= x && b >= y)
        || (x <= a && y >= b))
    {
        return 1;
    }
    return 0;
}

int isOverlapping(int a, int b, int x, int y)
{
    if ((a <= x && b >= x)
        || (a <= y && b >= y))
    {
        return 1;
    }
    return 0;
}

int numberContained(ifstream &input, bool overlap)
{
    string segment, lower, upper;
    vector<string> seglist;
    /* 
     * fLower - first lower limit 
     * fUpper - first upper limit
     * sLower - second lower limit
     * sUpper - second upper limit
     */
    int fLower, fUpper, sLower, sUpper;
    int numberOverlapping = 0;

    while (getline(input, segment, ','))
    {
        /* First elf */
        stringstream first(segment);

        getline(first, lower, '-');
        fLower = stoi(lower);
        getline(first, upper);
        fUpper = stoi(upper);


        /* Second elf */
        getline(input, segment);
        stringstream second(segment);

        getline(second, lower, '-');
        sLower = stoi(lower);
        getline(second, upper);
        sUpper = stoi(upper);

        if (!overlap)
        {
            numberOverlapping += isContained(fLower, fUpper, sLower, sUpper);
        }
        else
        {
            numberOverlapping += (isContained(fLower, fUpper, sLower, sUpper)
                                  | isOverlapping(fLower, fUpper, sLower, sUpper));
        }
    }

    return numberOverlapping;
}

int main(int argc, char const *argv[])
{
    ifstream input ("input/day4.txt");

    if (!input.is_open())
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    cout << "Number overlapping: " << numberContained(input, true) << endl;

    input.close();
    return 0;
}
