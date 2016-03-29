
#include <iostream>;
using namespace std;

int main()
{
    int n1 = 0;
    int n2 = 0;
    int max = 0;
    int min = 0;
    int i = 0;
    cout << "Enter the sequence of integers:" << endl ;



    while (i>=0) // This loop will execute until the user inputs -1.
    {
        i++;

        if (i==1){
        cin >> n1;


        if (n1 == -1)
            break;

        cin >> n2;

        if (n2 == -1)
            break;


        if (n2 > n1)
            max = n2;

        if (n1 > n2)
            max= n1;

        if (n2 < n1)
            min = n2;

        if (n1 < n2)
            min = n1;

        }
        cin >> n1;

        if (n1 == -1)
            break;

        cin >> n2;

        if (n2 == -1)
            break;


        if (n1>max)
            max=n1;
        if (n2>max)
            max=n2;
        if (n1<min)
            min=n1;
        if (n2<min)
            min=n2;


}
    if((n1==-1)&&(i==1))   // condition if user inputs only -1.
        cout<<"Enter at least 1 integer" ;

    if ((n2==-1)&&(i==1)){    //condition if user inputs x -1 where x is any integer
        max=n1;
        min=n1;
        cout << "As you entered only 1 integer your max is equal to your min = "<< max ;
    }
    if (i!=1)
    {
        cout << "The maximum value of your sequence is " << max << endl;
        cout << "The minimum value of your sequence is " << min << endl;
    }

}
