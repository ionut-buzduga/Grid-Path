#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <time.h>

//here we have the main function which uses a switch function for convenience

int main()
{ int choice;
    FILE *f = fopen("file.txt", "w");
    printf("TO BE ABLE TO USE THE GENERATED MATRIX IN PYTHON \nEXITING THE SWITCH FUNCTION BY PRESSING 3 AFTER CHOOSING THE OPTION 1 OR 2 IS NECESARRY!!");
    //this is very important because in case 3(where we exit the application and all the matrices that we created have been printed in
     // the file for use in getting the data sets to the python program) a "-1" is placed at the end of the file
     //The -1 is very important because it helps the python application know when the last data set has been entered.
     //Without it the python program won't correctly read the input file!!!
while( 1 > 0 )
    {   //the first choice is used for comparing the two algorithms on a small set of data
        //the second choice is used for running the Dynammic Programming algorithm on a bigger set od data.
        // !the third choice is used to exiting the program and it always needs to be selected after finishing creating the random matrices
        printf("\nPress 1 for executing both algorithms on a random matrix that has a maximum 10x10 dimension");
        printf("\nPress 2 for executing Only the second algorithm on a random matrix that has a maximum of 300x300 dimension");
        printf("\nPress 3 to exit :");


        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_matrix(10);
                break;

            case 2: create_matrix(300);
                break;

            case 3:printf("\nExit:");
            fclose(f);
    FILE *fp = fopen("file.txt", "a"); // !this part places a -1 after all the data sets which is essential
    fprintf(fp,"-1");                 //so that the python code can then run correctly(because the code checks
    fclose(fp);                       // if at the end of the file is a -1 so it can stop.

                exit(0);
                break;
            default: printf("\nYou have entered an invalid choice. Please try again");
        }
    }


    return 0;
}

