#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
struct reversion_wrapper
{
    T &iterable;
};

template <typename T>
auto begin(reversion_wrapper<T> w) { return rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse(T &&iterable) { return {iterable}; }

vector<string> getStacks(ifstream &input)
{
    string line;
    vector<string> diagramLines;
    int numberStacks;

    while (getline(input, line))
    {
        diagramLines.push_back(line);

        if (isdigit(line[1]))
        {
            getline(input, line);
            break;
        }
    }

    numberStacks = (diagramLines[0].length() + 1) / 4;
    vector<string> stacks(numberStacks, "");

    for (auto &elem : reverse(diagramLines))
    {
        if (&elem == &diagramLines.back())
        {
            continue;
        }

        for (int i = 0; i < numberStacks; i++)
        {
            int idx = (i * 4) + 1;

            if (isalpha(elem[idx]))
            {
                stacks[i].push_back(elem[idx]);
            }
        }
    }

    return stacks;
}

void executeInstructions(ifstream &input, vector<string> &stacks)
{
    string line;
    string output("");
    int amountToMove, src, dest;

    while (getline(input, line, ' '))
    {
        getline(input, line, ' ');
        amountToMove = stoi(line);

        getline(input, line, ' ');
        getline(input, line, ' ');
        src = stoi(line) - 1;

        getline(input, line, ' ');
        getline(input, line);
        dest = stoi(line) - 1;

        for (int i = 0; i < amountToMove; i++)
        {
            stacks[dest].push_back(stacks[src].back());
            stacks[src].pop_back();
        }
    }
}

void executeInstructionsMultiMove(ifstream &input, vector<string> &stacks)
{
    string line, temp("");
    string output("");
    int amountToMove, src, dest;

    while (getline(input, line, ' '))
    {
        getline(input, line, ' ');
        amountToMove = stoi(line);

        getline(input, line, ' ');
        getline(input, line, ' ');
        src = stoi(line) - 1;

        getline(input, line, ' ');
        getline(input, line);
        dest = stoi(line) - 1;

        for (; amountToMove > 0; amountToMove--)
        {
            temp.push_back(stacks[src].back());
            stacks[src].pop_back();
        }

        while (temp.size() > 0)
        {
            stacks[dest].push_back(temp.back());
            temp.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    ifstream input("input/day5.txt");
    string output("");

    if (!input.is_open())
    {
        cout << "Could not open input." << endl;
        return 1;
    }

    auto stacks = getStacks(input);

    // executeInstructions(input, stacks);
    executeInstructionsMultiMove(input, stacks);

    for (auto stack : stacks)
    {
        output.push_back(stack.back());
    }

    cout << "Tops: " << output << endl;

    input.close();
    return 0;
}
