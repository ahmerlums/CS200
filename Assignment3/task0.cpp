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
	
        for(int x=0; x<n; x++)
        {
            for(int y=0; y<n-1; y++)
            {
                if(array[y]>array[y+1])
                {
                    int temp = array[y+1];
                    array[y+1] = array[y];
                    array[y] = temp;
                }
            }
        }

	cout << "Sorted array = ";
	for (y=0;y<n;y++)
	cout << array[y] << " " ;
}
