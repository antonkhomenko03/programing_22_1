#include<iostream>
#include<valarray>
#include<vector>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;



vector<valarray<double> > input_matrix(int n, int m)
{
    vector<valarray<double> > matr(n);
    for (int i = 0; i < n; i ++)
    {
        valarray <double> t(m);
        for (int j = 0; j < m; j ++)
        {
            double v;
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> v;
            t[j] = v;
        }
        matr[i] = t;
    }
    return matr;
}

vector<valarray<double> > input_matrix_from_file(int n, int m)
{
    ifstream file_matrix;
    file_matrix.open("matrix.txt");
    vector<valarray<double> > matr(n);
    for (int i = 0; i < n; i ++)
    {
        valarray <double> t(m);
        for (int j = 0; j < m; j ++)
        {
            double v;
            if (file_matrix.is_open())
            {
                file_matrix >> v;
            }
            t[j] = v;
        }
        matr[i] = t;
    }
    file_matrix.close();
    return matr;
}

void show_matrix(vector<valarray<double> > &matr)
{
    int n = matr.size();
    int m = matr[0].size();
    for (int i = 0; i  < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cout << matr[i][j] << " ";
        }
        cout << '\n';
    }
}

valarray<double> input_vector(int n)
{
    valarray<double> vect(n);
    for (int i = 0; i < n; i ++)
    {
        double v;
        cout << "vector[" << i << "] = ";
        cin >> v;
        vect[i] = v;
    }
    return vect;
}

valarray<double> input_vector_from_file(int n)
{
    ifstream file_vector;
    file_vector.open("vector.txt");
    valarray<double> vect(n);
    for (int i = 0; i < n; i ++)
    {
        double v;
        if (file_vector.is_open())
            {
                file_vector >> v;
            }
        vect[i] = v;
    }
    return vect;
    file_vector.close();
}

void show_vector(valarray<double> &vect)
{
    for (int i = 0; i  < vect.size(); i ++)
    {
        cout << vect[i] << " ";
    }
    cout << '\n';
}

vector<valarray<double> > plus_m(vector<valarray<double> > &matr1, vector<valarray<double> > &matr2)
{
    int n = matr1.size();
    int m = matr1[0].size();
    vector<valarray<double> > matr3(n);
    if (n != matr1.size() || m != matr1[0].size())
    {
        return matr3;
    }
    for(int i = 0; i < n; i++)
    {
        valarray<double> t(m);
        for(int j = 0; j < m; j++)
        {
            t[j] = matr1[i][j] + matr2[i][j];
        }
        matr3[i] = t;

    }
    return matr3;
}

double determinante(vector<valarray<double> > mat)
{
    double check1 = 0, check2 = 0;
    for (int i = 0; i < mat[0].size(); i ++)
    {
        for (int j = 0; j < mat[0].size(); j ++)
        {
            check1 += mat[i][j];
            check2 += mat[j][i];
        }
        if (check1 == 0 || check2 == 0)
            return 0;
        check1 = 0;
        check2 = 0;
    }
    for (int j = 0; j < mat[0].size() - 1; j ++)
    {
        for (int i = mat[0].size() - 1; i > j; i --)
        {
            mat[i] = mat[i] + (mat[j] / mat[j][j]) * (-1.0 * mat[i][j]);
        }
    }
    double k1 = 1;
    for (int i = 0; i < mat[0].size(); i ++)
    {
        k1 *= mat[i][i];
    }
    return k1;
}

vector<valarray<double> > multiply_m1(vector<valarray<double> >  &matr1, vector<valarray<double> >  &matr2)
{
    int n1 = matr1.size();
    int n2 = matr2.size();
    int m1 = matr1[0].size();
    int m2 = matr2[0].size();

    vector<valarray<double> > matr3(n1);

    for(int i = 0; i < n1; i++)
    {
        valarray<double>  t(m2);

        for(int j = 0; j < m2; j++)
        {
            double sum = 0;
            for(int k = 0; k < n2; k++)
            {
                sum = sum + matr1[i][k] * matr2[k][j];
            }
            t[j] = sum;
        }
        matr3[i] = t;
    }

    return matr3;
}


vector<valarray<double> > inverse_matrix(vector<valarray<double> > mat)
{
    int n = mat[0].size(), i, j, i1, j1, i2, j2;
    vector<valarray<double> > inv_mat(n);
    double det = determinante(mat);
    if (det == 0)
    {
        return inv_mat;
    }
    double det1;

    for (j = 0; j < n; j ++)
    {
        valarray<double> inv_row(n);
        for (i = 0; i < n; i ++)
        {
            vector<valarray<double> > for_algebraichni_dopovnennya(n - 1);
            for (i1 = 0; i1 < n; i1 ++)
            {
                valarray<double> row(n - 1);
                for (j1 = 0; j1 < n; j1 ++)
                {
                    i2 = i1;
                    if (i1 >= i)
                    {
                        i2 = i1 - 1;
                    }
                    j2 = j1;
                    if (j1 >= j)
                    {
                        j2 = j1 - 1;
                    }

                    if (i1 != i & j1 != j)
                    {
                        row[j2] = mat[i1][j1];
                    }
                }
                if (i1 != i)
                {
                    for_algebraichni_dopovnennya[i2] = row;
                }
            }
            det1 = determinante(for_algebraichni_dopovnennya);
            inv_row[i] = det1 / det * pow(-1, i + j);
        }
        inv_mat[j] = inv_row;
    }
    return inv_mat;
}

vector<valarray<double> > multiplies_matrix_and_vector(vector<valarray<double> > mat, valarray<double > vect)
{
    int m = mat[0].size();
    int n = mat.size();
    vector<valarray<double> > new_mat(n);
    if (m != vect.size())
    {
        return new_mat;
    }
    for (int i = 0; i < n; i ++)
    {
        valarray<double> row = mat[i] * vect;
        new_mat[i] = row;
    }
    return new_mat;
}

void swap_two_rows(vector<valarray<double> > & mat, int n1, int n2)
{
    valarray<double> row = mat[n1];
    mat[n1] = mat[n2];
    mat[n2] = row;
}

void swap_two_columns(vector<valarray<double> > & mat, int m1, int m2)
{
    for (int i = 0; i < mat.size(); i ++)
    {
        double k = mat[i][m1];
        mat[i][m1] = mat[i][m2];
        mat[i][m2] = k;
    }
}

int main()
{
    float s = clock();
    cout << s;
    int n;

    printf("choose program mode:\n input and show matrix - 1\n input and show vector - 2\n");
    printf(" input two matrices and multiple - 3\n input two matrices and add(plus) - 4\n");
    printf(" input matrix and vector and multiple - 5\n input matrix and calculate determinate - 6\n");
    printf(" input matrix and calculate inverse matrix - 7\n input matrix and swap two rows - 8\n input matrix and swap two columns - 9\n");
    printf(" input from file and show matrix - 10\n input from file and show vector - 11\n");

    cin >> n;

    switch(n)
    {
    case 1:{
        cout << "What is size of matrix?\n";
        int n1, m1;
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        break;}
    case 2:{
        int n1;
        cout << "What is size of vector?\n";
        cin >> n1;
        valarray<double> vect1 = input_vector(n1);
        show_vector(vect1);
        break;}
    case 3:{
        cout << "What is size of matrix1?\n";
        int n1, m1, n2, m2;
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        cout << "What is size of matrix2?\n";
        cin >> n2 >> m2;
        vector<valarray<double> > matr2 = input_matrix(n2, m2);
        show_matrix(matr2);
        vector<valarray<double> > matr3 = multiply_m1(matr1, matr2);
        cout << '\n' << "Multiplication:" << '\n';
        show_matrix(matr3);
        break;}
    case 4:{
        int n1, m1, m2, n2;
        cout << "What is size of matrix1?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        cout << "What is size of matrix2?\n";
        cin >> n2 >> m2;
        vector<valarray<double> > matr2 = input_matrix(n2, m2);
        show_matrix(matr2);
        vector<valarray<double> > matr3 = plus_m(matr1, matr2);
        cout << '\n' << "Sum:" << '\n';
        show_matrix(matr3);
        break;}
    case 5:{
        int n1, m1, n2, m2;
        cout << "What is size of matrix?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        cout << "What is size of vector?\n";
        cin >> n2;
        valarray<double> vect1 = input_vector(n2);
        show_vector(vect1);
        vector<valarray<double> > matr3 = multiplies_matrix_and_vector(matr1, vect1);
        cout << '\n' << "Multiplication of matrix and vector:" << '\n';
        show_matrix(matr3);
        break;}
    case 6:{
        int n1, m1;
        cout << "What is size of matrix?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        double det = determinante(matr1);
        cout << "Determinant is " << det;
        break;}
    case 7:{
        int n1, m1;
        cout << "What is size of matrix?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        vector<valarray<double> > matr2;
        for (int i = 0; i < 100000; i ++){
                matr2 = inverse_matrix(matr1);}
        cout << '\n' << "Inverse matrix:" << '\n';
        show_matrix(matr2);
        break;}
    case 8:{
        int n1, m1, n2, m2;
        cout << "What is size of matrix?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        cout << "What rows do you want to swap?\n";
        cin >> n2 >> m2;
        swap_two_rows(matr1, n2, m2);
        show_matrix(matr1);
        break;}
    case 9:{
        int n1, m1, n2, m2;
        cout << "What is size of matrix?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        cout << "What columns do you want to swap?\n";
        cin >> n2 >> m2;
        swap_two_columns(matr1, n2, m2);
        show_matrix(matr1);
        break;}
    case 10:{
        cout << "What is size of matrix?\n";
        int n1, m1;
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix_from_file(n1, m1);
        show_matrix(matr1);
        break;}
    case 11:{
        int n1;
        cout << "What is size of vector?\n";
        cin >> n1;
        valarray<double> vect1 = input_vector_from_file(n1);
        show_vector(vect1);
        break;}
    default:{
        int n1, m1;
        cout << "What is size of matrix?\n";
        cin >> n1 >> m1;
        vector<valarray<double> > matr1 = input_matrix(n1, m1);
        show_matrix(matr1);
        break;}
    }
}
