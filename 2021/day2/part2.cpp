#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream file("input.txt");
    string line;

    int x = 0;
    int depth = 0;
    int aim = 0;

    while(getline(file, line))
    {
        if(line[0] == 'f')
        {
            int tmp = stoi(line.substr(7, line.size() - 7));
            x += tmp;
            depth += aim * tmp;
        }
        if(line[0] == 'd')
            aim += stoi(line.substr(4, line.size() - 4));
        if(line[0] == 'u')
            aim -= stoi(line.substr(2, line.size() - 2));
    }

    cout << x * depth;

    return 0;
}
