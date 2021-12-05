#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int update(vector<bool> &criteria, vector<vector<int>> &binary, vector<int> &binary_sum, int value, int index)
{
    int ret = 0;
    //int n = binary.size();
    int n = 1000;

    for(int i = 0; i < n; i++)
    {
        if(binary[i][index] != value && criteria[i])
        {
            criteria[i] = false;
            ret++;

            for(int j = 0; j < n; j++)
            {
                binary_sum[j] -= binary[i][j];
            }
        }
    }

    return ret;
}

int binary_to_int(vector<int> &binary)
{
    int value = 0;
    int digit = binary.size();

    for(int i = 0; i < digit; i++)
        value += binary[digit - i - 1] << i;

    return value;
}

int main()
{
    fstream file("input.txt");
    string line;

    vector<vector<int>> binary;

    while(getline(file, line))
    {
        binary.emplace_back();
        for(auto i : line)
        {
            binary.back().push_back(i - '0');
        }
    }

    int n = binary.size(); // 1000
    int digit = binary[0].size(); // 12

    vector<int> binary_sum(n);

    for(auto value : binary)
    {
        for(int i = 0; i < digit; i++)
        {
            binary_sum[i] += value[i];
        }
    }

    int o2 = 0;
    int co2 = 0;

    int n_c = n;

    vector<bool> criteria(n, true);
    vector<int> binary_sum_(binary_sum);

    for(int i = 0; i < digit; i++)
    {
        if(binary_sum_[i] * 2 >= n_c)
        {
            n_c -= update(criteria, binary, binary_sum_, 1, i);
        }
        else
        {
            n_c -= update(criteria, binary, binary_sum_, 0, i);
        }

        if(n_c == 1)
        {
            int o2_index = distance(criteria.begin(), find(criteria.begin(), criteria.end(), true));

            o2 = binary_to_int(binary[o2_index]);

            break;
        }
    }

    n_c = n;
    criteria = vector<bool>(n, true);

    for(int i = 0; i < digit; i++)
    {
        if(binary_sum[i] * 2 >= n_c)
        {
            n_c -= update(criteria, binary, binary_sum, 0, i);
        }
        else
        {
            n_c -= update(criteria, binary, binary_sum, 1, i);
        }

        if(n_c == 1)
        {
            int co2_index = distance(criteria.begin(), find(criteria.begin(), criteria.end(), true));

            co2 = binary_to_int(binary[co2_index]);

            break;
        }
    }

    cout << o2 * co2;

    return 0;
}
