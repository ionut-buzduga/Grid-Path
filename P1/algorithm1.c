#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//this is the first algorithm that uses a recursive aproach to find the path with the lowest cost
//it starts from the bottom right corner and it works its way back to the first location
//checking the lowest path between the location above and the location located on the left
int FindPathRec(struct  grid_matrix matrix, int row_index, int col_index) //the parameters are a matrix of type struct grid_matrix
{                                                                         //row_index and column_index show the position of the element
    int up_location,left_location;
    if( row_index == 0 && col_index == 0 )   //if the function reaches the first position it returns 0 because there isn't a cost to
    {                                        //be added anymore
        return 0;
    }
    if( row_index == 0 )    //if the dunction reaches and element located at the first row it can only go in one direction
        return FindPathRec(matrix,row_index, col_index-1) //back to the first location(to the left)
               + abso(get_value(matrix,row_index,col_index-1),get_value(matrix,row_index,col_index));
    if( col_index == 0)  //if the dunction reaches and element located at the first column it can only go in one direction
        return FindPathRec(matrix,row_index-1, col_index) //back to the first location(up)
               + abso(get_value(matrix,row_index-1,col_index),get_value(matrix,row_index,col_index));
    //in any other cases there are always two directions ,either up or to the left.
    //here we choose the minimum value of those two locations keeping in mind that the cost of the path is calculated using the absolute
    //value between two consecutive elements
    up_location=FindPathRec(matrix,row_index-1, col_index)+abso(get_value(matrix,row_index-1,col_index),get_value(matrix,row_index,col_index));
    left_location=FindPathRec(matrix,row_index, col_index-1)+abso(get_value(matrix,row_index,col_index-1),get_value(matrix,row_index,col_index));
    if(up_location<left_location)
        return up_location;
    else
        return left_location;


}
// to print all the locations of the path we also need a print function which starts
//at the first location and calls the FindPathRec function in order to determine the
//shortest path for each consecutive element of the path
//if it reaches the last row or the last column it prints the location going in only one direction
//in any other case it computes the shortest cost path for the consecutive elements located
// either down or up and chooses the minimum value of the two
void printalg1(struct grid_matrix matrix)
{
    int row_index=0; //the starting position
    int col_index=0;

    printf("THE SHORTEST PATH ON ALG1 IS:\n"); //now we start to print the grid path in order
    printf("MinCost[%d][%d] ",row_index,col_index);
    while(row_index<=matrix.no_rows-1&&col_index<=matrix.no_cols-1)
    {
        if(row_index==matrix.no_rows-1&&col_index==matrix.no_cols-1)
            break;

        if(col_index==matrix.no_cols-1)
        {
            row_index++;

            printf("MinCost[%d][%d] ",row_index,col_index);

        }
        else if(row_index==matrix.no_rows-1)
        {
            col_index++;

            printf("MinCost[%d][%d] ",row_index,col_index);

        }
        else  if( FindPathRec(matrix,row_index+1,col_index)< FindPathRec(matrix,row_index,col_index+1))
        {
            row_index++;

            printf("MinCost[%d][%d] ",row_index,col_index);

        }
        else
        {
            col_index++;

            printf("MinCost[%d][%d] ",row_index,col_index);

        }
    }

    printf("\n");

}
