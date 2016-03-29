#include <iostream>
using namespace std;

int main()
{	
	int n=0;
	int x=0;
	int y=0;
        cout << "Enter the length of your array: ";
	cin >> n;
        int array[n];
        
        cout << "Input your array: ";
        for(y=0;y<n;y++)               //Inputting array
	        cin >> array[y];
	
	
		for(y=1;y<n;y++)
		{                                                                             
		        if (array[y]<array[y-1])    // This for loop would run until it a number
			{                           //which is lower than the previous number. 
                          int temp=array[y];        //When it finds such a number it swaps the two
                          array[y]=array[y-1];      //numbers and move the for loop in the backward
                          array[y-1]=temp;          //direction . We do y=y-2 because in the for loop
                          if(y!=1)                  //1 would be added so end result is y=y-1.Similarly
                               y=y-2;               //again if the number swapped is lower than the previous
                        }                           //one, swapping would be done again and the cycle 
                                                    //would continue until the lowest number reaches
                }                                  //the first position, and it would be compared 
                                                    //with the zeroth position and shifted again if
                                                    //it is lower. Then the for loop would proceed
                                                    //by y++ and find other smaller numbers and move
                                                    //them back!!.     
	cout << "Sorted array = ";
	for (y=0;y<n;y++)
	cout << array[y] << " " ;
}
