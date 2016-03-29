#include <iostream>
using namespace std;

int main()
{
int grid = 0;
int rows=0;
int cols=0;
int i = 1;

cout << "Enter the dimension of square grid:";
cin >> grid;

while (i <= grid ) //Starting the loop for iteration of row addition.
 {
  i++;

  if (i>=3)    //We want this to condition to be operated after the 1st iteration so that zeroth row is taken into account.
      rows++; // Row Progression

  cols=0;      // Zeroth Column to be started after every row progression.

    while (cols<=grid-1) // Starting the loop for column addition.
      {
       if (((rows & cols)==0) && ( cols == grid-1)) // The iteration of the last column  with binary value=0
        {
          cout << "*" << endl ; // We need endl to ensure that a new
          break ; // Break so that next statements of the loop are not executed.
        }

       if (((rows & cols) !=0) && ( cols == grid-1)) // // The iteration of the last column with non-zero value
        {
          cout << " "<<endl; // We need endl to ensure that a new
          break;  // Break so that next statements of the loop are not executed.
        }

       if ((rows & cols)== 0) // Normal condition which executes every time except the last column.
           cout << "*" ;

         else
           cout << " ";

   cols++; // Column progression.

}
}
}




