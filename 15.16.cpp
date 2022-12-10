#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// a * x ^ 2 + b * y + c = 0
class KvadratneRivnyannya
{
private:
    double a, b, c;
public:
    void input_a(double a)
    {
        this -> a = a;
    }
    void input_b(double b)
    {
        this -> b = b;
    }
    void input_c(double c)
    {
        this -> c = c;
    }
    double get_a()
    {
        return a;
    }
    double get_b()
    {
        return b;
    }
    double get_c()
    {
        return c;
    }
    vector<double> coreni()
    {
        vector<double> roots;
        double D = b * b - 4 * a * c;
        if (D == 0)
        {
            roots.push_back(sqrt(D) / 2 / a);
        }
        if (D > 0)
        {
            roots.push_back((-1 * b + sqrt(D)) / 2 / a);
            roots.push_back((-1 * b - sqrt(D)) / 2 / a);
        }
        return roots;
    }
    double extremum()
    {
        if (a != 0)
        {
            return -1 * b / 2 / a;
        }
        else
        {
            printf("It is not quadratic equation. No extremum points");
            return 0;
        }
    }
    void intervals()
    {
        if (a > 0)
        {
            printf("decreases on the interval (-inf; %lf], increases on the interval [%lf; inf)\n", this -> extremum(), this -> extremum());
        }
    }
};

int main()
{
    int n, j = 0;
    double a, b, c, min_root, max_root;

    cout << "how many equations?\n";
    cin >> n;

    KvadratneRivnyannya eqs[n];

    for (int i = 0; i < n; i ++)
    {
        cout << "\na = ";
        cin >> a;
        cout << "\nb = ";
        cin >> b;
        cout << "\nc = ";
        cin >> c;
        eqs[i].input_a(a);
        eqs[i].input_b(b);
        eqs[i].input_c(c);
        if (j == 0)
        {
            if (eqs[i].coreni().size() == 1)
            {
                min_root == eqs[i].coreni()[0];
                max_root = min_root;
            }
            if (eqs[i].coreni().size() == 2)
            {
                if (eqs[i].coreni()[0] > eqs[i].coreni()[1])
                {
                    min_root == eqs[i].coreni()[1];
                    max_root == eqs[i].coreni()[0];
                }
                else
                {
                    min_root == eqs[i].coreni()[0];
                    max_root == eqs[i].coreni()[1];
                }
            }
            j = 1;
        }
        if (j == 1)
        {
            if (eqs[i].coreni().size() == 1)
            {
                if (eqs[i].coreni()[0] > max_root)
                    max_root = eqs[i].coreni()[0];
                if (eqs[i].coreni()[0] < min_root)
                    min_root = eqs[i].coreni()[0];
            }
            if (eqs[i].coreni().size() == 2)
            {
                if (eqs[i].coreni()[0] > eqs[i].coreni()[1])
                {
                    if (eqs[i].coreni()[0] > max_root)
                        max_root = eqs[i].coreni()[0];
                    if (eqs[i].coreni()[1] < min_root)
                        min_root = eqs[i].coreni()[1];
                }
                else
                {
                    if (eqs[i].coreni()[1] > max_root)
                        max_root = eqs[i].coreni()[1];
                    if (eqs[i].coreni()[0] < min_root)
                        min_root = eqs[i].coreni()[0];
                }
            }
        }
    }

    cout << "\n" << min_root << " " << max_root;
}
