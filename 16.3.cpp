// 16.3, homework19
// describe class Pasenger based on class Person. Class contains data about place of departure, place of arrival, place in train.
// create class cash register that allows to add and show informatuin about pasengers, find pasengers with name, place of departure, place of arrival or place in train
// and find minimal free place in train

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Person
{
public:
    string name;
    unsigned byear;
    int input()
    {
        cin >> name >> byear;
    }

    void show()
    {
        cout << name << " " << byear << endl;
    }
};

class Pasenger : public Person
{

public:
    string misce_posadky;
    string misce_vysadky;
    unsigned misce;
    using Person::name;
    using Person::byear;
};

class Kassa : public Pasenger
{
    string f;

public:
    void change_name(string name1)
    {
        name = name1;
    }
    void change_byear(unsigned year)
    {
        byear = year;
    }
    void change_misce_posadky(string misce_posadky1)
    {
        misce_posadky = misce_posadky1;
    }
    void change_misce_vysadky(string misce_vysadky1)
    {
        misce_vysadky = misce_vysadky1;
    }
    void change_misce(unsigned misce1)
    {
        misce = misce1;
    }
    void show_name()
    {
        cout << "name is " << name << "\n";
    }
    void show_byear()
    {
        cout << "byear is " << byear << "\n";
    }
    void show_misce_posadky()
    {
        cout << "misce posadky is " << misce_posadky << "\n";
    }
    void show_misce_vysadky()
    {
        cout << "misce vysadky is " << misce_vysadky << "\n";
    }
    void show_misce()
    {
        cout << "misce is " << misce << "\n";
    }
    void change_pasenger(string name1, unsigned year, string misce_posadky1, string misce_vysadky1, unsigned misce1)
    {
        change_name(name1);
        change_byear(year);
        change_misce_posadky(misce_posadky1);
        change_misce_vysadky(misce_vysadky1);
        change_misce(misce1);
    }
    void show_pasenger()
    {
        show_name();
        show_byear();
        show_misce_posadky();
        show_misce_vysadky();
        show_misce();
    }
    Kassa find_pasenger_by_name(Kassa pasengers[], string name1, int n)
    {
        Kassa new_pasengers[n];
        int k = 0;
        for (int i = 0; i < n; i ++)
        {
            if (pasengers[i].name == name1)
            {
                return pasengers[i];
            }
        }
    }
    Kassa find_pasenger_by_misce_posadky(Kassa pasengers[], string misce_posadky1, int n)
    {
        Kassa new_pasengers[n];
        for (int i = 0; i < n; i ++)
        {
            if (pasengers[i].misce_posadky == misce_posadky1)
            {
                return pasengers[i];
            }
        }
    }
    Kassa find_pasenger_by_misce_vysadky(Kassa pasengers[], string misce_vysadky1, int n)
    {
        Kassa new_pasengers[n];
        int k = 0;
        for (int i = 0; i < n; i ++)
        {
            if (pasengers[i].misce_vysadky == misce_vysadky1)
            {
                return pasengers[i];
            }
        }
    }
    Kassa find_pasenger_by_misce(Kassa pasengers[], int misce1, int n)
    {
        Kassa new_pasengers[n];
        int k = 0;
        for (int i = 0; i < n; i ++)
        {
            if (pasengers[i].misce == misce1)
            {
                return pasengers[i];
            }
        }
    }
    int vilni_miscya(Kassa pasengers[], int n, int number_of_places)
    {
        int miscya[number_of_places];
        for (int i = 0; i < number_of_places; i ++)
            miscya[i] = i + 1;
        int k = 0;
        for (int i = 0; i < number_of_places; i ++)
        {
            if (pasengers[i].misce == i + 1)
            {
                miscya[i] = 0;
            }
        }
        vector <int> vector_vilnyh_misc;
        for (int i = 0; i < number_of_places; i ++)
        {
            if (miscya[i] != 0)
                vector_vilnyh_misc.push_back(miscya[i]);
        }
        int min1 = number_of_places;
        for (int i = 0; i < vector_vilnyh_misc.size(); i ++)
        {
            if (vector_vilnyh_misc[i] < min1)
            {
                min1 = vector_vilnyh_misc[i];
            }
        }
        return min1;
    }

};

int main()
{
    string myStr = "Sergiy 1987 Kyiv Lviv 2\nStephan 1993 Uzhgorod Mykolaiv 7\nMykyta Herson Zaporizzhya 5\nMykola Chernivci Chercasy 1\nPavlo Ivano-Frankivsk Zhytomyr 4\n";
    Kassa pasengers[20];
    int p = 1, i = 0, misce, max_mise;
    unsigned byear;
    string name, misce_posadky, misce_vysadky;
    while (p)
    {
        cout << "What is the name of pasenger?\n";
        cin >> name;
        cout << "What is the byear of pasenger?\n";
        cin >> byear;
        cout << "What is the place of departure of pasenger?\n";
        cin >> misce_posadky;
        cout << "What is the place of arrival of pasenger?\n";
        cin >> misce_vysadky;
        cout << "What is the place in train of pasenger?\n";
        cin >> misce;
        if (misce > max_mise)
            max_mise = misce + 1;
        pasengers[i].change_pasenger(name, byear, misce_posadky, misce_vysadky, misce);
        i ++;
        cout << "Do you want add one more pasenger? Write 1 if yes, write 0 if no\n";
        cin >> p;
    }

    for (int j = 0; j <= i; j ++)
        pasengers[j].show_pasenger();

    int p1 = 1;
    while (p1)
    {
        cout << "choose mod:\nfind pasenger by name - 1\nfind pasenger by place of departure - 2\nfind pasenger by place of arrival - 3\nfind pasenger by place in train - 4\n find free place in train - 5\n";
        cin >> p;
        switch (p)
        {
        case 1:
            cout << "What is the name?\n";
            cin >> name;
            pasengers[0].find_pasenger_by_name(pasengers, name, i).show_pasenger();

        case 2:
            cout << "What is the place of departure?\n";
            cin >> misce_posadky;
            pasengers[0].find_pasenger_by_misce_posadky(pasengers, misce_posadky, i).show_pasenger();

        case 3:
            cout << "What is the place of arrival?\n";
            cin >> misce_vysadky;
            pasengers[0].find_pasenger_by_misce_vysadky(pasengers, misce_vysadky, i).show_pasenger();

        case 4:
            cout << "What is the place in train?\n";
            cin >> misce;
            pasengers[0].find_pasenger_by_misce(pasengers, misce, i).show_pasenger();
        case 5:
            cout << pasengers[0].vilni_miscya(pasengers, i, max_mise);
        }
        cout << "Do you want continue? 1 - yes, 0 - no\n";
        cin >> p1;
    }
}
