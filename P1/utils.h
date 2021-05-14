
#ifndef TESTMATRICERANDOM_MATRIX_H
#define TESTMATRICERANDOM_MATRIX_H
//this is where all the functions are declared
//here we also have the struct matrix
struct grid_matrix
{
    int no_rows;
    int no_cols;
    int *matrix;

};
void set_value(struct grid_matrix matrix, int row_index,int column_index, int element_value); //used in utils.c
void print_matrix(struct grid_matrix matrix); //used in utils.c
int get_value(struct grid_matrix matrix, int row_index, int column_index); //used in utils.x
void create_matrix(int grid_dimension); //used in generator.c
int FindPathRec(struct  grid_matrix matrix, int row_index, int col_index); //used in algorithm1.c
int FindPathDP(struct  grid_matrix matrix); //used in algorithm2.c
void printalg1(struct grid_matrix matrix); //used in algorithm1.c
int min( int a, int b); //used in utils.c
int abso(int a,int b); //used in utlis.c
#endif


