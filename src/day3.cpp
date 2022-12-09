#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int getPriority(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1 + (c - 'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return 27 + (c - 'A');
    }
    else
    {
        cout << "Something has gone wrong" << endl;
        return -1;
    }
}

void taskOne(ifstream &input)
{
    string line;
    set<char> leftSet;
    string leftString, rightString;
    int halfLineLength, prioritySum = 0;
    char repeat;

    while (getline(input, line))
    {
        repeat = -1;
        halfLineLength = line.length() / 2;

        leftString = line.substr(0, halfLineLength);
        leftSet = set<char>(begin(leftString), end(leftString));

        rightString = line.substr(halfLineLength, halfLineLength);
        for (const char c : rightString)
        {
            if (leftSet.find(c) != leftSet.end())
            {
                repeat = c;
                break;
            }
        }
        prioritySum += getPriority(repeat);
    }

    cout << "Sum: " << prioritySum << endl;
}

void taskTwo(ifstream &input)
{
    string line1, line2, line3;
    set<char> set2, set3;
    char repeat;
    int prioritySum = 0;

    while (getline(input, line1))
    {
        repeat = -1;

        getline(input, line2);
        set2 = set<char>(begin(line2), end(line2));

        getline(input, line3);
        set3 = set<char>(begin(line3), end(line3));

        for (const char c : line1)
        {
            if (set2.find(c) != set2.end() && set3.find(c) != set3.end())
            {
                repeat = c;
                break;
            }
        }
        prioritySum += getPriority(repeat);
    }

    cout << "Sum: " << prioritySum << endl;
}

int main(int argc, char const *argv[])
{
    ifstream input ("input/day3.txt");

    if (!input.is_open())
    {
        cout << "Unable to open input file." << endl;
        return 1;
    }

    /* taskOne(input) */
    taskTwo(input);

    input.close();
    return 0;
}
