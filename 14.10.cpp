#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    fstream file1("file1.txt", ios::in);
    string strs[100];
    int counter;

    while (getline(file1, strs[counter]))
        counter ++;



    file1.close();

    fstream file2("file1.txt", ios::out);

    for (int i = 0; i < counter; i ++)
    {
        if (i % n != 0)
        {
            file2 << strs[i] << "\n";
        }
    }

    file2.close();
}
