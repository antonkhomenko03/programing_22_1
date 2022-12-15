// 17.3.cpp
// homework 20
// if I remember correctly, you said, in 20s homework we can do any exersize after paragraph 16, so I did 17.3
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// числр а в системі зчислення за основою b переводиться в систему числення за соновою 10
int funk(char a, int b)
{
    string s;
    s = "0123456789ABCDEF";
    int k = s.find(a);
    assert(k < b && "uncorrect number in counting system based on b");
    return k;
}

int funk2(string a, int b)
{
    int c = 0;
    while (a.size() > 0)
    {
        c = c * b + funk(a[0], b);
        string s = "";
        for (int i = 1; i < a.size(); i ++)
        {
            s = s + a[i];
        }
        a = s;
    }
    return c;
}

int main()
{
    string a;
    int b;
    cout << "Input number:\n";
    cin >> a;
    cout << "Input number counting system based on:\n";
    cin >> b;
    cout << "your number in counting system based on 10 is " << (funk2(a, b));
}
