#include <iostream>
using namespace std;


int StringLen(char stringinput[]);
int main()
{
    char s[999999] = "";
    
    cout << "Input string : ";
    cin.getline(s,999999);
    
    int n=StringLen(s);
    
    cout << "String Length = ";
    cout << n;
    cout << endl;
}

int StringLen(char stringinput[])
{
    int i=0;
    int res=0;
    while (1)
    {   
        if (stringinput[i] == '\0')
            break;
        else
            res++;
        
            i++;
        
        
    }
    
    return res;
}
