#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    fstream file("input.txt");
    queue<int> q;
    string line;

    int cur = 0;
    int prev;
    int count = 0;

    for(int i = 0; i < 3; i++)
    {
        getline(file, line);

        int input = stoi(line);

        q.push(input);
        cur += input;
    }

    // prev = cur;

    while(getline(file, line))
    {
        prev = cur;

        cur -= q.front();
        q.pop();

        int input = stoi(line);

        cur += input;
        q.push(input);

        if(cur > prev)
            count++;
    }

    cout << count;

    return 0;
}
