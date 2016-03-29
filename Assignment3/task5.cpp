#include <iostream>
using namespace std;
int shiftString(int n, char (&stringinput)[9999]);


int main()
{  
    int c=0;
    int i=0;
    char s[9999] = "";
    cout << "n = " ;
    cin >> i ;
    cout << "input given = " ;
    cin >> s ;
    char out[9999];
    int index=0;
    shiftString(i,s);
    cout << "new string = " ;
    while (s[index] != '\0' )
    {
       cout<<s[index];
       index++;
    }
    cout << endl;
       
}

int shiftString(int n, char (&stringinput)[9999])
{
    int i=0;
    int temp=0;
    int temp1=0;
    char s[999999] = "";
    char t[999999] = "";
    char final[999999] = "";
    int p=0;
    if (n<0)
    {
        while (stringinput[i] != '\0')
            i++;
       
        
        
        int c=i;
        
        for (i=c;i>=-n;i--)
        {
           s[i+n]=stringinput[i];
        }
        
        int len=0;
        
        while(s[len]!='\0')
        len++;
        
        for(i=0;i<-n;i++)
        {
           t[p]=stringinput[i];
           p++;
        }
	p=0;
             int len1=0;
              while (t[len1]!='\0')
                   len1++;
                                  
             for(i=0;i<=c;i++)
                 {
                  if (i<len)
                   final[i]=s[i];
                                                                           
                  if (i>=len)
			{
                      final[i]=t[p];
			p++;}
                                    
                   }
                                           
      
        for (i=0;i<=c;i++)
        {
         
           stringinput[i] = final[i]  ;
        }
    }
       if (n>0)
    {
        while (stringinput[i] != '\0')
            
            i++;
       
        
      
        int c=i;
         
        
        for (i=0;i<c-n;i++)
        {
            s[i+n]=stringinput[i];
            
        }
           int len=0;
        while (s[len] != '\0')
           len++;
        
      for (i>=c-n;i<=c;i++)
        {
          t[p]=stringinput[i];
                p++;
        }
        int len1=0;
        while (t[len1]!='\0')
              len1++;
        
        for(i=0;i<=c;i++)
        {
             if (i<len1)
             final[i]=t[i];
             
             else
             final[i]=s[i];       
        
        }
                          
        
        for (i=0;i<=c;i++)
        {
         stringinput[i]=final[i];
           
        }
      
       		
        
        }    
 }

