#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int binary_to_int(vector<int> &binary, int digit)
{
    int value = 0;

    for(int i = 0; i < digit; i++)
        value += binary[digit - i - 1] << i;

    return value;
}

int main()
{
    fstream file("input.txt");
    string line;

    int n = 1000;
    int digit = 12;
    vector<int> binary(digit);

    while(getline(file, line))
    {
        // n++;
        for(int i = 0; i < digit; i++)
        {
            if(line[i] - '0' == 1)
            {
                binary[i]++;
            }
        }
    }

    for(auto &i : binary)
    {
        if(i >= n / 2)
            i = 1;
        else
            i = 0;
    }

    int gamma = binary_to_int(binary, digit);

    for(auto &i : binary)
    {
        i = abs(1 - i);
    }

    int epsilon = binary_to_int(binary, digit);

    cout << gamma * epsilon;

    return 0;
}
