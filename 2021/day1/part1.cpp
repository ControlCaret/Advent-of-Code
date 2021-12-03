#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream file("input.txt");
    string line;

    getline(file, line);

    int cur = stoi(line);
    int prev = cur;
    int count = 0;

    while(getline(file, line))
    {
        prev = cur;
        cur = stoi(line);

        if(cur > prev)
            count++;
    }

    cout << count;

    return 0;
}
