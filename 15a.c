#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/*
Here we create a sparse vector element structure
*/

typedef struct SElement_for_vector
{
    int i;
    double value;
} SElement_for_vector;


/*
Here we create input function for this structure
*/



SElement_for_vector input_element_for_vector()
{
    int i1;
    double value1;
    printf("\nIndex:");
    scanf("%u", &i1);
    printf("\nValue:");
    scanf("%lf", &value1);

    SElement_for_vector s = {i1, value1};
    return s;
}

/*
Here we create output function for this structure
*/

void show_element_from_vector(SElement_for_vector a)
{
    printf("index: %u, value: %lf", a.i, a.value);
}

/*
Here we create sparse vector structure whose elements are the objects of the previous structure
*/

typedef struct SVector
{
    SElement_for_vector *vector;
    int n;
    int size_all;
} SVector;

/*
here we create function that allows us to refer to an element of vector by its index
*/

double key_to_value_in_vector(int key, SVector vect)
{
    int i;
    for (i = 0; i < vect.size_all; i ++)
    {
        if (vect.vector[i].i == key)
        {
            return vect.vector[i].value;
        }
    }
    return 0;
}

/*
here we create function input for vector
*/

void input_vector(SVector * vect)
{
    int i = 0, n1 = 0;
    int size = 0;
    bool p = true;
    vect->vector = (SElement_for_vector*)calloc(1, sizeof(SElement_for_vector));

    while (p)
    {
        SElement_for_vector s = input_element_for_vector();
        if (s.i >= n1)
            n1 = s.i + 1;
        if (s.value == 0)
            break;
        size ++;
        vect->vector[size - 1] = s;
        realloc(vect->vector, (size + 1) * sizeof(SElement_for_vector));

        show_element_from_vector(vect->vector[size - 1]);
    }
    vect->n = n1 + 1;
    vect->size_all = size;
}

/*
Here we create function that enters data from a file into a vector
*/

void input_vector_from_file(SVector * vect, int size1)
{
    FILE * file_vector = fopen("vector.txt", "r");
    vect->vector = (SElement_for_vector*)calloc(size1, sizeof(SElement_for_vector));
    vect->n = 0;
    vect->size_all = 0;
    int size = 0;
    int i;
    double j;
    while (1)
    {
        size ++;
        fscanf(file_vector, "%u", &i);
        fscanf(file_vector, "%lf", &j);
        if (j == 0 || size > size1)
        {
            break;
        }
        if (i >= vect->n)
        {
            vect->n = i + 1;
        }
        SElement_for_vector s = {i, j};
        vect->vector[size - 1] = s;
    }
    vect->size_all = size;
    fclose(file_vector);
}

/*
here we create function output for vector
*/

void show_vector(SVector vect)
{
    int i1;
    int key;
    printf("\n");
    printf("n = %u, size = %u\n", vect.n, vect.size_all);
    for (i1 = 0; i1 < vect.n; i1 ++)
    {
        key = i1;
        printf("%.0lf ", key_to_value_in_vector(key, vect));
    }
    printf("\n");
}

/*
here we create function delete vector
*/

void delete_vector(SVector vect)
{
    free(vect.vector);
    free(vect.n);
    free(vect.size_all);
}

/*
Here we create a sparse matrix element structure
*/

typedef struct SElement
{
    int i;
    int j;
    double value;
} SElement;

/*
Here we create input function for this structure
*/

SElement input_element()
{
    int i1, j1;
    double value1;
    printf("\nIndexes:");
    scanf("%u%u", &i1, &j1);
    printf("\nValue:");
    scanf("%lf", &value1);

    SElement s = {i1, j1, value1};
    return s;
}

/*
Here we create output function for this structure
*/

void show_element(SElement a)
{
    printf("indexes: (%u,%u), value: %lf", a.i, a.j, a.value);
}


typedef struct SMatrix
{
    SElement *matrix;
    int n;
    int m;
    int size_all;
} SMatrix;

/*
Here we create sparse matrix structure whose elements are the objects of the previous structure
*/

double key_to_value(int key[2], SMatrix matr)
{
    int i;
    for (i = 0; i < matr.size_all; i ++)
    {
        if (matr.matrix[i].i == key[0] & matr.matrix[i].j == key[1])
        {
            return matr.matrix[i].value;
        }
    }
    return 0;
}

/*
here we create function input for matrix
*/

void input_matrix(SMatrix * matr)
{
    int i = 0, n1 = 0, m1 = 0;
    int size = 0;
    bool p = true;
    matr->matrix = (SElement*)calloc(1, sizeof(SElement));

    while (p)
    {
        SElement s = input_element();
        if (s.i > n1)
            n1 = s.i;
        if (s.j > m1)
            m1 = s.j;
        if (s.value == 0)
            break;
        size ++;
        matr->matrix[size - 1] = s;
        realloc(matr->matrix, (size + 1) * sizeof(SElement));

        show_element(matr->matrix[size - 1]);
    }
    matr->n = n1 + 1;
    matr->m = m1 + 1;
    matr->size_all = size;

}

/*
Here we create function that enters data from a file into a matrix
*/

void input_matrix_from_file(SMatrix * matr, int size1)
{
    FILE * file_matrix = fopen("matrix.txt", "r");
    matr->matrix = (SElement*)calloc(size1, sizeof(SElement));
    matr->n = 0;
    matr->m = 0;
    matr->size_all = 0;
    int size = 0;
    int i, j;
    double val;
    while (1)
    {
        size ++;
        fscanf(file_matrix, "%u", &i);
        fscanf(file_matrix, "%u", &j);
        fscanf(file_matrix, "%lf", &val);
        if (val == 0 || size > size1)
        {
            break;
        }
        if (i >= matr->n)
        {
            matr->n = i + 1;
        }
        if (j >= matr->m)
        {
            matr->m = j + 1;
        }
        SElement s = {i, j, val};
        matr->matrix[size - 1] = s;
    }
    matr->size_all = size;
    fclose(file_matrix);
}


/*
here we create function delete matrix
*/

void delete_matrix(SMatrix * mat)
{
    free(mat -> matrix);
    free(mat -> m);
    free(mat -> n);
    free(mat -> size_all);
}

/*
here we create function a function that allows to add an element to a matrix
*/

void add_element_to_matrix(SElement a, SMatrix * m)
{
    realloc(m->matrix, (m->size_all + 1) * sizeof(SElement));
    m->matrix[m->size_all] = a;

    if (a.i + 1 > m->n)
    {
        m->n = a.i + 1;
    }
    if (a.j + 1> m->m)
    {
        m->m = a.j + 1;
    }
    m->size_all ++;
}

/*
here we create function output for matrix
*/

void show_matrix(SMatrix matr)
{
    int i1, j1;
    printf("\n");
    printf("n = %u, m = %u, size = %u\n", matr.n, matr.m, matr.size_all);
    for (i1 = 0; i1 < matr.n; i1 ++)
    {
        for (j1 = 0; j1 < matr.m; j1 ++)
        {
            int key[2] = {i1, j1};
            printf("%.2lf ", key_to_value(key, matr));
        }
        printf("\n");
    }
}

/*
here we create a function that adds two matrices
*/

SMatrix sum_matrix(SMatrix m1, SMatrix m2)
{
    SMatrix sum_mat;
    if (m1.m != m2.m || m1.n != m2.n)
    {
        sum_mat.n = 0;
        sum_mat.m = 0;
        sum_mat.size_all = 0;
        return sum_mat;
    }



    sum_mat.matrix = (SElement*)calloc(1, sizeof(SElement));
    sum_mat.n = m1.n;
    sum_mat.m = m1.m;
    sum_mat.size_all = 0;

    int i1, j1, k, key[2];
    double sum;
    SElement el_for_sum_matr;

    for (i1 = 0; i1 < m1.n; i1 ++)
    {
        key[0] = i1;
        for (j1 = 0; j1 < m1.m; j1 ++)
        {
            sum = 0;
            key[1] =j1;

            el_for_sum_matr.value = key_to_value(key, m1) + key_to_value(key, m2);


            if (el_for_sum_matr.value != 0)
            {
                el_for_sum_matr.i = i1;
                el_for_sum_matr.j = j1;
                sum_mat.matrix[sum_mat.size_all] = el_for_sum_matr;
                realloc(sum_mat.matrix, (sum_mat.size_all + 2) * sizeof(SElement));
                sum_mat.size_all ++;
            }
        }
    }
    return sum_mat;
}

/*
here we create a function to multiply two matrices
*/

SMatrix multiplication(SMatrix m1, SMatrix m2)
{
    SMatrix mult_mat;

    if (m1.m != m2.n)
    {
        mult_mat.n = 0;
        mult_mat.m = 0;
        mult_mat.size_all = 0;
        return mult_mat;
    }


    mult_mat.matrix = (SElement*)calloc(1, sizeof(SElement));
    mult_mat.n = m1.n;
    mult_mat.m = m2.m;
    mult_mat.size_all = 0;

    int i1, j1, k, key1[2], key2[2];
    double mult;
    SElement el_for_mult_matr;

    for (i1 = 0; i1 < m1.n; i1 ++)
    {
        key1[0] = i1;
        for (j1 = 0; j1 < m2.m; j1 ++)
        {
            mult = 0;
            key2[1] =j1;
            for (k = 0; k < m1.m; k ++)
            {
                key1[1] = k;
                key2[0] = k;
                mult += key_to_value(key1, m1) * key_to_value(key2, m2);
            }
            if (mult != 0)
            {
                el_for_mult_matr.i = i1;
                el_for_mult_matr.j = j1;
                el_for_mult_matr.value = mult;
                mult_mat.matrix[mult_mat.size_all] = el_for_mult_matr;
                realloc(mult_mat.matrix, (mult_mat.size_all + 2) * sizeof(SElement));
                mult_mat.size_all ++;
            }
        }
    }
    return mult_mat;
}

/*
here we create a function to multiply matrix and vector
*/

SMatrix multiplication_matrix_and_vector(SMatrix m1, SVector v1)
{
    SMatrix mult_mat;

    if (m1.m != v1.n)
    {
        mult_mat.n = 0;
        mult_mat.m = 0;
        mult_mat.size_all = 0;
        return mult_mat;
    }


    mult_mat.matrix = (SElement*)calloc(1, sizeof(SElement));
    mult_mat.n = m1.n;
    mult_mat.m = m1.m;
    mult_mat.size_all = 0;

    int i1, j1, k, key1[2], key2;
    SElement el_for_mult_matr;

    for (i1 = 0; i1 < m1.n; i1 ++)
    {
        key1[0] = i1;
        for (j1 = 0; j1 < m1.m; j1 ++)
        {
            key1[1] = j1;
            key2 = j1;
            if (key_to_value(key1, m1) != 0 & key_to_value_in_vector(key2, v1) != 0)
            {
                el_for_mult_matr.i = i1;
                el_for_mult_matr.j = j1;
                el_for_mult_matr.value = key_to_value(key1, m1) * key_to_value_in_vector(key2, v1);
                mult_mat.matrix[mult_mat.size_all] = el_for_mult_matr;
                realloc(mult_mat.matrix, (mult_mat.size_all + 2) * sizeof(SElement));
                mult_mat.size_all ++;
            }
        }
    }
    return mult_mat;
}

/*
here we create a function to swap to rows in matrix
*/


SMatrix swap_two_rows(SMatrix m1, int n1, int n2)
{
    SMatrix swap_mat;

    swap_mat.matrix = (SElement*)calloc(1, sizeof(SElement));
    swap_mat.n = m1.n;
    swap_mat.m = m1.m;
    swap_mat.size_all = 0;

    int i1, j1, k, key1[2];

    for (i1 = 0; i1 < m1.size_all; i1 ++)
    {
        SElement el_for_swap_mat;
        el_for_swap_mat.i = m1.matrix[i1].i;
        if (m1.matrix[i1].i == n1)
        {
            el_for_swap_mat.i = n2;
        }
        if (m1.matrix[i1].i == n2)
        {
            el_for_swap_mat.i = n1;
        }
        el_for_swap_mat.j = m1.matrix[i1].j;
        el_for_swap_mat.value = m1.matrix[i1].value;
        swap_mat.matrix[swap_mat.size_all] = el_for_swap_mat;
        realloc(swap_mat.matrix, (swap_mat.size_all + 2) * sizeof(SElement));
        swap_mat.size_all ++;
    }
    return swap_mat;
}

/*
here we create a function to swap to collumns in matrix
*/

SMatrix swap_two_collumns(SMatrix m1, int n1, int n2)
{
    SMatrix swap_mat;

    swap_mat.matrix = (SElement*)calloc(1, sizeof(SElement));
    swap_mat.n = m1.n;
    swap_mat.m = m1.m;
    swap_mat.size_all = 0;

    int i1, j1, k, key1[2];

    for (i1 = 0; i1 < m1.size_all; i1 ++)
    {
        SElement el_for_swap_mat;
        el_for_swap_mat.j = m1.matrix[i1].j;
        if (m1.matrix[i1].j == n1)
        {
            el_for_swap_mat.j = n2;
        }
        if (m1.matrix[i1].j == n2)
        {
            el_for_swap_mat.j = n1;
        }
        el_for_swap_mat.i = m1.matrix[i1].i;
        el_for_swap_mat.value = m1.matrix[i1].value;
        swap_mat.matrix[swap_mat.size_all] = el_for_swap_mat;
        realloc(swap_mat.matrix, (swap_mat.size_all + 2) * sizeof(SElement));
        swap_mat.size_all ++;
    }
    return swap_mat;
}

/*
here we create a function that calculates the determinant of a matrix
*/

double det(SMatrix mat, double * dett)
{
    if (mat.n == mat.m)
    {
        if (mat.n == 1)
        {
            int aa[2] = {0, 0};
            double re = key_to_value(aa, mat);
            return re;
        }
        if (mat.n == 2)
        {
            int a1[2] = {0,0};
            int a2[2] = {0,1};
            int a3[2] = {1,0};
            int a4[2] = {1,1};
            *dett = key_to_value(a1, mat) * key_to_value(a4, mat) - key_to_value(a2, mat) * key_to_value(a3, mat);
            return *dett;
        }
        int j, k, i, k11;


        for(k = 0; k < mat.n; k++)
        {
            if (k < mat.n)
            {
                k11 = k;
            }
            else
            {
                k11 = 0;
            }
            SMatrix new_det;
            new_det.matrix = (SElement*)calloc(1, sizeof(SElement));
            new_det.m = mat.m - 1;
            new_det.n = mat.n - 1;
            new_det.size_all = 0;

            for(i = 0; i < mat.size_all; i ++)
            {
                if (mat.matrix[i].i != 0 && mat.matrix[i].j != k11)
                {
                    SElement new_el = mat.matrix[i];
                    new_el.i --;
                    if (new_el.j > k11){
                        new_el.j --;}

                    realloc(new_det.matrix, (new_det.size_all + 2) * sizeof(SElement));
                    new_det.matrix[new_det.size_all] = new_el;
                    new_det.size_all ++;
                }
            }

            long double r;
            r = 0;
            r = det(new_det, &r);
            int a[2] = {0, k11};
            *dett += key_to_value(a, mat) * pow(-1, k11) * (r);
        }
        return *dett;
    }
}

/*
here we create a function that calculates inverse matrix
*/

SMatrix obernena_matricya(SMatrix m1)
{
    double det_one = 0;
    det_one = det(m1, &det_one);
    SMatrix ober_mat;
    if (m1.m != m1.n || det_one == 0)
    {
        return ober_mat;
    }
    ober_mat.matrix = (SElement*)calloc(m1.m * m1.m, sizeof(SElement));
    ober_mat.n = m1.n;
    ober_mat.m = m1.m;
    ober_mat.size_all = 0;
    int i, j, k;

    for (i = 0; i < m1.n; i ++)
    {
        for (j = 0; j < m1.n; j ++)
        {
            SMatrix matr_for_ober;
            matr_for_ober.m = m1.m - 1;
            matr_for_ober.n = m1.m - 1;
            matr_for_ober.size_all = 0;
            matr_for_ober.matrix = (SElement*)calloc((m1.m - 1) * (m1.m - 1), sizeof(SElement));
            for (k = 0; k < m1.size_all; k ++)
            {
                if (m1.matrix[k].i != i & m1.matrix[k].j != j)
                {
                    int a[2] = {m1.matrix[k].i, m1.matrix[k].j};
                    if (key_to_value(a, m1) != 0)
                    {
                        int i1 = m1.matrix[k].i;
                        int j1 = m1.matrix[k].j;
                        if (m1.matrix[k].i >= i)
                        {
                            i1 --;
                        }
                        if (m1.matrix[k].j >= j)
                        {
                            j1 --;
                        }
                        SElement s = {i1, j1, key_to_value(a, m1)};
                        matr_for_ober.matrix[matr_for_ober.size_all] = s;
                        matr_for_ober.size_all ++;
                    }
                }
            }
            double d = 0;
            d = det(matr_for_ober, &d);
            double f = pow(-1, i + j) * (d) / det_one;
            SElement s = {j, i, f};
            ober_mat.matrix[ober_mat.size_all] = s;
            ober_mat.size_all ++;
        }
    }
    return ober_mat;
}

int main()
{

    /*
    SVector vect;
    int i = 0, n1 = 0;
    int size = 0;
    bool p = true;
    vect.vector = (SElement_for_vector*)calloc(1, sizeof(SElement_for_vector));
    FILE * file_vector = fopen("vector.txt", "r");

    while (p)
    {
        SElement_for_vector s;
        int i1;
        double v1;
        fscanf(file_vector, "%1u", &s.i);
        fscanf(file_vector, "%1d", &s.value);
        printf(" %u ", s.i);
        if (s.i > n1)
            n1 = s.i;
        if (s.value == 0)
            break;
        size ++;
        vect.vector[size - 1] = s;
        realloc(vect.vector, (size + 1) * sizeof(SElement_for_vector));

        show_element_from_vector(vect.vector[size - 1]);
    }
    vect.n = n1 + 1;
    vect.size_all = size;

    show_vector(vect);
    fclose(file_vector);
*/
    int n;

    printf("choose program mode:\n input and show matrix - 1\n input and show vector - 2\n");
    printf(" input two matrices and multiple - 3\n input two matrices and add - 4\n");
    printf(" input matrix and vector and multiple - 5\n input matrix and calculate determinate - 6\n");
    printf(" input matrix and calculate inverse matrix - 7\n input matrix and swap two rows - 8\n input matrix and swap two columns - 9\n");
    printf(" input vector from file and show - 10\n input matrix from file and show - 11\n");

    scanf("%u", &n);

    switch(n)
    {
    case 1:;
        SMatrix mat1;
        input_matrix(&mat1);
        show_matrix(mat1);
        break;
    case 2:;
        SVector vect;
        input_vector(&vect);
        show_vector(vect);
        break;
    case 3:;
        input_matrix(&mat1);
        show_matrix(mat1);
        SMatrix mat2;
        input_matrix(&mat2);
        show_matrix(mat2);
        SMatrix mat3 = multiplication(mat1, mat2);
        show_matrix(mat3);
        break;
    case 4:;
        input_matrix(&mat1);
        show_matrix(mat1);
        input_matrix(&mat2);
        show_matrix(mat2);
        mat3 = sum_matrix(mat1, mat2);
        show_matrix(mat3);
        break;
    case 5:;
        input_matrix(&mat1);
        show_matrix(mat1);
        input_vector(&vect);
        show_vector(vect);
        mat3 = multiplication_matrix_and_vector(mat1,vect);
        show_matrix(mat3);
        break;
    case 6:;
        SMatrix mat;
        input_matrix(&mat);
        show_matrix(mat);
        double determinate = 0;
        determinate = det(mat, &determinate);
        printf("Determinate is %lf\n", determinate);
        break;
    case 7:;
        input_matrix(&mat);
        show_matrix(mat);
        int i;
        SMatrix inv;
        show_matrix(inv);
        break;
    case 8:;
        input_matrix(&mat);
        show_matrix(mat);
        int n1, n2;
        printf("Which two rows do you want to swap?(starting from 0)\n");
        scanf("%u%u", &n1, &n2);
        SMatrix swap = swap_two_rows(mat, n1, n2);
        show_matrix(swap);
        break;
    case 9:;{
        input_matrix(&mat);
        show_matrix(mat);
        int m1, m2;
        printf("Which two columns do you want to swap?(starting from 0)\n");
        scanf("%u%u", &m1, &m2);
        swap = swap_two_collumns(mat, m1, m2);
        show_matrix(swap);
        break;}
    case 10:;{
        printf("How many non-zero elements are in vector?\n");
        scanf("%u", &n1);
        input_vector_from_file(&vect, n1);
        show_vector(vect);
        break;}
    case 11:;{
        printf("How many non-zero elements are in matrix?\n");
        scanf("%u", &n1);
        input_matrix_from_file(&mat, n1);
        show_matrix(mat);
        break;}
    default:;
        input_matrix(&mat);
        show_matrix(mat);
        break;
    }
}
