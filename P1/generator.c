#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <time.h>


//here we create the randmly generated matrix
void create_matrix(int grid_dimension)
{
    struct grid_matrix matrix;

    int i,j;
clock_t  tic;  //with these variables we can measure the time for our functions
clock_t  toc;
double elapsed;
    FILE *f = fopen("file.txt", "a+"); //here we open the file in which we are going to write out generated matrix
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }


    srand(time(NULL)); //we initialize the seed
    matrix.no_rows=1+rand()%grid_dimension; //matrix.no_rows gets a random value between 1 and grid_dimension value

    matrix.no_cols=matrix.no_rows;
    matrix.matrix = calloc((matrix.no_rows) * (matrix.no_rows),sizeof(int)); //here we allocate the memory for the matrix

    for(i=0; i<matrix.no_rows; i++)
        for(j=0; j<matrix.no_rows; j++)
            set_value(matrix,i,j,rand()%10000);  //the matrix's element have random values between 0 and 10000
    print_matrix(matrix);

    printf("\n");
     tic=clock();

    if(grid_dimension<=11)      //here we call the first algorithm function
        {printalg1(matrix);     //it has a restriction so we can observe how the algorithm behaves at lower  dimensions of the matrix
    toc =clock();                //if it was higher than 11 the algorithm would take too long as it has an exponential running time
    elapsed=(double)(toc-tic)/CLOCKS_PER_SEC;
    printf("Algorithm 1 elapsed: %lf seconds\n",elapsed);}

    tic=clock();
    FindPathDP(matrix);  //here we can see that the call for the second algorithm doesn't have a restriction because it runs much faster
    toc =clock();
    elapsed=(double)(toc-tic)/CLOCKS_PER_SEC;
    printf("Algorithm 2 elapsed: %lf seconds\n",elapsed);
    free(matrix.matrix);
    fclose(f);
}

