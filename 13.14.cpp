#include <iostream>
#include <string>

using namespace std;

// this function can calculate number of strings in other string and number of words in other string

int str_count(string str, string little_str)
{
    int counter = 0;
    for (int i = 0; i < str.length(); i ++)
    {
        if (str.substr(i, little_str.length()) == little_str)
        {
            counter ++;
        }
    }
    return counter;
}

int main()
{
    string s1 = "It’s over, Anakin! I have the high ground!";
    string s2 = " ";

    cout << str_count(s1, s2);
}
