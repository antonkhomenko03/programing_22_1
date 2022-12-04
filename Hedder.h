/* File Header.h
Realization of matrix with using memory allocation pointers
Done by Khomenko Anton (group computer mathematics 1)
Date 04.12.2022
Headers for matrix
*/

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


/*
Here we create output function for this structure
*/

void show_element_from_vector(SElement_for_vector a)


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


/*
here we create function input for vector
*/

void input_vector(SVector * vect)


/*
Here we create function that enters data from a file into a vector
*/

void input_vector_from_file(SVector * vect, int size1)


/*
here we create function output for vector
*/

void show_vector(SVector vect)



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
input function for this structure
*/

SElement input_element()


/*
output function for this structure
*/

void show_element(SElement a)


/* Matrix struct*/
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


/*
here we create function input for matrix
*/

void input_matrix(SMatrix * matr)

/*
Here we create function that enters data from a file into a matrix
*/

void input_matrix_from_file(SMatrix * matr, int size1)



/*
a function a function that allows to add an element to a matrix
*/

void add_element_to_matrix(SElement a, SMatrix * m)


/*
a function output for matrix
*/

void show_matrix(SMatrix matr)

/*
a function that adds two matrices
*/

SMatrix sum_matrix(SMatrix m1, SMatrix m2)

/*
a function to multiply two matrices
*/

SMatrix multiplication(SMatrix m1, SMatrix m2)


/*
a function to multiply matrix and vector
*/

SMatrix multiplication_matrix_and_vector(SMatrix m1, SVector v1)


/*
a function to swap to rows in matrix
*/


SMatrix swap_two_rows(SMatrix m1, int n1, int n2)


/*
a function to swap to collumns in matrix
*/

SMatrix swap_two_collumns(SMatrix m1, int n1, int n2)

/*
a function that calculates the determinant of a matrix
*/

double det(SMatrix mat, double * dett)


/*
a function that calculates inverse matrix
*/

SMatrix obernena_matricya(SMatrix m1)

