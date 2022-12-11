#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void arrayShiftIn(string& arr, char c)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[arr.size() - 1] = c;
}

bool containsDuplicate(string& arr)
{
    set<char> compareSet(arr.begin(), arr.end());
    
    if (compareSet.find('_') != compareSet.end()) { return true; }
    return compareSet.size() != 14;
}

int parseChar(ifstream& input)
{
    typedef istreambuf_iterator<char> buf_iter;
    string messageBuf = "______________";
    int markerStart = 0;

    for (buf_iter i(input), e; i != e; i++, markerStart++)
    {
        char c = *i;

        arrayShiftIn(messageBuf, c);
        if (!containsDuplicate(messageBuf))
        {
            return ++markerStart;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ifstream input("input/day6.txt");
    int output;

    if (!input.is_open())
    {
        cout << "Could not open input file." << endl;
        return 1;
    }

    output = parseChar(input);

    cout << "First marker: " << output << endl;

    input.close();
    return 0;
}