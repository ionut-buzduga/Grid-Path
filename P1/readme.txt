--This is a document which contains instructions on how the project is implemented.--
The Technical Report and all of its files are located in the AssignmentReport folder(.tex file and .pdf file).

There are a few steps to take in consideration so that all applications behave normally:
1.First we have to open the project file P1 which contains the following .c and .h files(main.c,algorithm1.c,algorithm2.c,generator.c,utils.c,utils.h)
2.Each one of those files contains comments about the functions and they do.
3.After opening the Codeblocks Project we build&run it
4.On the terminal there will appear 3 options for the user:
-to create a random matrix that has a max dimension of 10x10,on which both of the algorithms will be executed
-to create a random matrix that has a max dimension of 300x300 on which ONLY the second algorithm(DynamicProgramming one) will be executed.
-and an exit option !!!for the algorithm to create sets of data that can be used for the python implementation,the user needs to choose at least one of the 
two options from above AND also select option 3 to exit the program. 

Example of options after running the C program:
-press 1
-press 2
-press 1
-press 3

All data sets created with the randoom generator are stored in file.txt located in the same folder and are ready to be used for the python implementation.

For implementing the python programs I used Visual Studio Code(with the python extension included!)
The main.py file executes both of the algorithms which are implemented in other two .py files(algorithm1.py,algorithm2.py-their functions are also imported in main.py)
!For the main.py to execute correctly We first need to run the code in the Codeblocks project so that the same  sets of data are being used.


The Values that were used for the running time tests(for the technical report) are located in the folder Values used for testing.





  