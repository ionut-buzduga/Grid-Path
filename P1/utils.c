#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int min( int a, int b) //this function is used to calculate the minimum of the two variables
{
    if(a > b)
        return b;
    return a;
}

int abso(int a,int b)  //this function is used to calculate the absolute values between two variables
{
    if(a>b)
        return a-b;
    else
        return b-a;
}


void set_value(struct grid_matrix matrix, int row_index, int column_index, int element_value) //this function is used to set the value
{                                                                                             //of the struct matrix more conviniently
    int position;

    position = row_index * matrix.no_rows + column_index;
    *(matrix.matrix + position) = element_value;
}


int get_value(struct grid_matrix matrix, int row_index, int column_index)  //with this function we get the value of the struct matrix
{
    int position;

    position = row_index * matrix.no_cols + column_index;
    return *(matrix.matrix + position);
}

void print_matrix(struct grid_matrix matrix)  //this function is used to print in the file each matrix that we randomly generate
{
    int iterator_rows;
    int iterator_columns;

    FILE *f = fopen("file.txt", "a+");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }


    fprintf(f,"%d\n", matrix.no_rows);

    for(iterator_rows = 0; iterator_rows < matrix.no_rows; iterator_rows++)
    {
        for(iterator_columns = 0; iterator_columns < matrix.no_rows; iterator_columns++)
        {
            fprintf(f,"%d ",matrix.matrix[iterator_rows * matrix.no_rows + iterator_columns]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

