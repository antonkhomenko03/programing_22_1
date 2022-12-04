/* File Header.h
Realization of matrix with valarray
Done by Khomenko Anton (group computer mathematics 1)
Date 04.12.2022
Headers for matrix
*/

/* function input matrix*/

vector<valarray<double> > input_matrix(int n, int m)


/* function input matrix from file */

vector<valarray<double> > input_matrix_from_file(int n, int m)

/* function show matrix */

void show_matrix(vector<valarray<double> > &matr)

/* function input vector */

valarray<double> input_vector(int n)


/* function input vector from file */

valarray<double> input_vector_from_file(int n)


/* function show vector */

void show_vector(valarray<double> &vect)

 /* function calculate sum of two matrices */

vector<valarray<double> > plus_m(vector<valarray<double> > &matr1, vector<valarray<double> > &matr2)

/* function calculate determinante of the matrix */

double determinante(vector<valarray<double> > mat)

/* function multiply two matrices */

vector<valarray<double> > multiply_m1(vector<valarray<double> >  &matr1, vector<valarray<double> >  &matr2)

/* function calcolate invervse matrix */

vector<valarray<double> > inverse_matrix(vector<valarray<double> > mat)

/* function multiply matrix and vector */

vector<valarray<double> > multiplies_matrix_and_vector(vector<valarray<double> > mat, valarray<double > vect)

/* function swap two rows in matrix */

void swap_two_rows(vector<valarray<double> > & mat, int n1, int n2)

/* function swap two columns in matrix */

void swap_two_columns(vector<valarray<double> > & mat, int m1, int m2)
