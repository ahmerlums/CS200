#include "StackCalculator.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

StackCalculator::StackCalculator()
{
cout << "Welcome to the Stack calculator! \n";
}

StackCalculator::~StackCalculator()
{
    int calculatorsize=a.size();
    for (int i=0;i<calculatorsize;i++)
        a.pop();
}

int main()
{
    StackCalculator cal;
    char t[]="";
    float temp;
    float temp2;
    while (1)
    {
        cout << ">";
        cin >> t;
        if (atof(t)!=0)
        {
            float i =atof(t);
            cal.a.push(i);
        }
        if (atof(t)==0 && strcmp(t,"pop")&& strcmp(t,"show")&& strcmp(t,"quit") && strcmp(t,"+")&& strcmp(t,"-")&& strcmp(t,"*")&& strcmp(t,"/"))
            cout << "Not a valid input \n";

        if (!strcmp(t,"+"))
            if (cal.a.size()>=2)
            {
                temp=cal.a.top();
                cal.a.pop();
                temp2=cal.a.top();
                cal.a.pop();
                cal.a.push(temp+temp2);
                cout << "-->"<<cal.a.top()<<endl;
            }
            else
                cout << "Sorry, there are less than 2 entries on the stack."<<endl;

        if (!strcmp(t,"-"))
            if (cal.a.size()>=2)
            {
                temp=cal.a.top();
                cal.a.pop();
                temp2=cal.a.top();
                cal.a.pop();
                cal.a.push(temp2-temp);
                cout << "-->"<<cal.a.top()<<endl;
            }
            else
                cout << "Sorry, there are less than 2 entries on the stack."<<endl;

        if (!strcmp(t,"*"))
            if (cal.a.size()>=2)
            {
                temp=cal.a.top();
                cal.a.pop();
                temp2=cal.a.top();
                cal.a.pop();
                cal.a.push(temp2*temp);
                cout << "-->"<<cal.a.top()<<endl;
            }
            else
                cout << "Sorry, there are less than 2 entries on the stack."<<endl;

        if (!strcmp(t,"/"))
            if (cal.a.size()>=2)
            {
                temp=cal.a.top();
                cal.a.pop();
                temp2=cal.a.top();
                cal.a.pop();
                cal.a.push(temp2/temp);
                cout <<"-->"<< cal.a.top()<<endl;
            }
            else
                cout << "Sorry, there are less than 2 entries on the stack."<<endl;

     if (!strcmp(t,"pop"))

          if(cal.a.size()!=0)
        cal.a.pop();
       else
            cout << "Stack is Empty! \n";

     if (!strcmp(t,"show"))
     {
        stack<float> print = cal.a;
        float y[3];
        int n=0;
        int b=print.size();

        if (b!=0)
        {
        for (int i=0;i<b;i++)
        {

            n=i;
            y[i]=print.top();
            print.pop();
        }

        for (int i=n;i>=0;i--)
            cout << y[i]<<endl;
        }
        else
            cout << "Stack is Empty! \n";
     }

     if (!strcmp(t,"quit"))
        break;

    }

}
