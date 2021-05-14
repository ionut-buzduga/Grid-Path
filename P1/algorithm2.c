#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


//this is the Dynamic Programming version of the algortihm
//it uses the same principle as the recursive one regarding the printing
//the massive difference for this algorithm is that we use an adiitional matrix
//to save the minimum cost path for each location in order to reduce the amount of running time.

int FindPathDP(struct  grid_matrix matrix)
{
    int row_index,col_index; //indices of the location
    int up_location,left_location; //these are two variables in which we save the elements located above and to the left
    struct grid_matrix MinCost; //this is the newly generated matrix that will calculate the minimum path for each location
    MinCost.no_rows=matrix.no_rows; //this is the dimension of the new matrix
    MinCost.no_cols=matrix.no_cols;
    MinCost.matrix=calloc((matrix.no_rows) * (matrix.no_rows),sizeof(int)); //here we can dynammically allocate memory for our matrix
    // with this for loop we set the values of the new matrix on the first column and first row.
    //each element holds the minimum cost path required
    for(row_index=1; row_index<=MinCost.no_rows-1; row_index++)
    {
        set_value(MinCost,row_index,0,get_value(MinCost,row_index-1,0)+abso(get_value(matrix,row_index-1,0),get_value(matrix,row_index,0)));
        set_value(MinCost,0,row_index,get_value(MinCost,0,row_index-1)+abso(get_value(matrix,0,row_index-1),get_value(matrix,0,row_index)));
    }
  //here we set the rest of the matrix elements by calculating the minimum of the two elements  located before and adding the
  //absolute value of the difference between the elements of the original matrix
    for(row_index=1; row_index<=MinCost.no_rows-1; row_index++)
    {
        for(col_index=1; col_index<=MinCost.no_cols-1; col_index++)
        {
            up_location=get_value(MinCost,row_index-1,col_index)
                        +abso(get_value(matrix,row_index-1,col_index),get_value(matrix,row_index,col_index));
            left_location=get_value(MinCost,row_index,col_index-1)
                          +abso(get_value(matrix,row_index,col_index-1),get_value(matrix,row_index,col_index));
            if(up_location<left_location)
                set_value(MinCost,row_index,col_index,up_location);
            else
                set_value(MinCost,row_index,col_index,left_location);
        }
    }
 //for printing the locations of the path we use the same concept as in the other algorithm
 //the difference is that we now  use the values from the newly created matrix
 //another addition added to this part is that we limit the number of printed locations
 //by only printing the first and last 10 locations
 //the other locations that are in between will be represented by three dots(...) in order
 //to not have thousands of locations printed on the terminal
     row_index=0;
     col_index=0;
    int ok=0; //with this variable we can check if the (...) were printed already or not
    printf("THE SHORTEST PATH USING THE SECOND ALGORITHM IS:\n");
    printf("MinCost[%d][%d] ",row_index,col_index);
    while(row_index<=matrix.no_rows-1&&col_index<=matrix.no_cols-1)
    {
        if(row_index==matrix.no_rows-1&&col_index==matrix.no_cols-1)
            break;
        if(col_index==matrix.no_cols-1)
        {
            row_index++;
            if(row_index+col_index<=10||row_index+col_index>=2*matrix.no_rows-11) //this way we can print the first 10 and last 10 elements
                printf("MinCost[%d][%d] ",row_index,col_index);                  //all other elements being replaced by "..."
            else if(ok==0)                                                       //the same goes for the rest of the for loop
            {
                printf("... ");
                ok=1;
            }
        }
        else if(row_index==matrix.no_rows-1)
        {
            col_index++;
            if(row_index+col_index<=10||row_index+col_index>=2*matrix.no_rows-11)
                printf("MinCost[%d][%d] ",row_index,col_index);
            else if(ok==0)
            {
                printf("... ");
                ok=1;
            }
        }
        else  if(get_value(MinCost,row_index+1,col_index)<get_value(MinCost,row_index,col_index+1))
        {
            row_index++;
            if(row_index+col_index<=10||row_index+col_index>=2*matrix.no_rows-11)
                printf("MinCost[%d][%d] ",row_index,col_index);
            else if(ok==0)
            {
                printf("... ");
                ok=1;
            }
        }
        else
        {
            col_index++;
            if(row_index+col_index<=10||row_index+col_index>=2*matrix.no_rows-11)
                printf("MinCost[%d][%d] ",row_index,col_index);
            else if(ok==0)
            {
                printf("... ");
                ok=1;
            }
        }
    }

    printf("\n");

    return 0;

}
