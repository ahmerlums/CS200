#include <iostream>
using namespace std;


void stringCase(char (&stringinput)[9999], bool choice);
int main()
{
    char s[9999] = "";

    cout << "word = ";
    cin >> s;
    
    bool k ;
    cout << "choice = ";
    cin >> k;
    stringCase(s,k);
    int i=0;
    cout << "New word = " ;
    while (s[i] != '\0')
    {
    cout << s[i];
    i++;
    }    
    cout << endl;
}

void stringCase(char (&stringinput)[9999], bool choice)
{
    int i=0;
    
    
    while (stringinput[i]!='\0')
    {
    if (choice==1)
    {
        if(stringinput[i]>=97)
      stringinput[i]=stringinput[i]-32;  
    }
    
    if (choice==0)
    {
        if(stringinput[i]<97)
        stringinput[i]=stringinput[i]+32;  
    }
    i++;
    }
    
    
}
