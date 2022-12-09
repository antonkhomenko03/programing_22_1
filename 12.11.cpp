#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int Number_of_symbols(double num)
{
    int num_symbols = 0;
    if (num < 0)
    {
        num_symbols ++;
    }
    num = abs(num);
    if (num == 0)
        return 1;
    double int_part = floor(num);
    while (int_part >= 1)
    {
        int_part /= 10;
        num_symbols ++;
    }

    double frac_part = num - floor(num);
    if (frac_part > 0)
    {
        num_symbols++;
        while (fmod(frac_part, 1) < 0.99999 && fmod(frac_part, 1) > 0.000001)
        {
            frac_part *= 10;
            num_symbols++;
        }
        num_symbols *= -1;
    }

    return num_symbols;
}



int main()
{
    cout << Number_of_symbols(-1.2323) << "\n\n";
    fstream numbers_file1("file1.txt", ios::in);
    vector<double> nums;
    vector<double> length_nums;
    int max_length = 0;

    double n;
    char t;
    int counter;
    while (numbers_file1 >> n)
    {
        numbers_file1 >> t;
        nums.push_back(n);
        length_nums.push_back(Number_of_symbols(n));
        if (abs(Number_of_symbols(n)) > abs(max_length))
            max_length = Number_of_symbols(n);

    }
    numbers_file1.close();
    fstream numbers_file2("file1.txt", ios::out);

    for (int i = 0; i < nums.size(); i ++)
    {
        cout << nums[i] << '\n';
        cout << length_nums[i] << '\n';
        numbers_file2 << nums[i];
        if (length_nums[i] > 0 && nums[i] < 0)
        {
            numbers_file2 << ".";
            length_nums[i] ++;
        }
        if (nums[i] < 0)
        {
            for (int j = abs(length_nums[i]); j < abs(max_length); j ++)
            {
                numbers_file2 << "0";
            }
        }
        numbers_file2 << '\n';
    }

    numbers_file2.close();

    return 0;
}
