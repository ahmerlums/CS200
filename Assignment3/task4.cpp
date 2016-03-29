#include <iostream>

using namespace std;


int compareString (char string1[], char string2[]);
int main()
{  
    int i=0;
    char s[999999] = "";
    cin.getline(s,999999);
    char t[999999] = "";
     cin.getline(t,999999);
    
    int n=compareString(s,t);
    cout << n <<endl;
    
}

int compareString(char string1[], char string2[])
{
    int i=0;
    int res=0;
    char c;
    char d;
    
       c = string1[1];
       d = string2[1];
       
  
    while (string1[i]!= '\0' || string2[i] != '\0')
    {  
       c = string1[i-1];
       d = string2[i];
        
        if (i==0)
        {
            if ((string1[0]-string2[0]==32) ||(string2[0]-string1[0]== 32) )
                    res=0;
            
        }    
        
       if (string1[i] == string2[i])
        {
        res=0;
         
        }
         
        
       if (string1[i] != string2[i] )
       {    if ((i==0)&&(string1[0]-string2[0]==32) ||(string2[0]-string1[0]== 32))
           break;
          else
          {    
           if (string1[i]>string2[i]) 
                res=1;
            if (string2[i] > string1[i])
                res=-1;
           break;
          }
        }
 

        i++;
    }
        
    return res;
}
