#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include <fstream>
#include <stdio.h>
#include "boiler.cpp"
//#include "hash.h"
#include <sstream>

using namespace std;



int main()
{
    ifstream file("data.txt");
    LinkedList a;
    string temp;
    string temp1;
    int var;
    int idx=0;
    while (getline(file,temp))
    {
        while (1)
        {
            getline(file,temp1);
            if (temp1.size()==0)
                break;
            idx++;
            a.insertatHead(temp,temp1,idx);
        }

    }

    a.print();
    LinkedList b;
    while(1)
    {
        cout << "Select from the following options : " << endl << "1.Search\n2.reload data\n3.save data\n4.quit and save data\n5.quit without saving" << endl ;
        cin >> var;

        if (var==1)
        {


            string t="";
            cin.ignore(1000, '\n');
            cout << "Enter word/phrase:";
            getline (cin, t);

            startTimer();
            LinkedList b=a.searchFor(t);
            if (b.length()!=0)
                b.printrank();
            cout<<"Time="<<(stopTimer())<<endl;

        }
        if (var==2)
        {
            file.close();
            ifstream file("data.txt");
            while (getline(file,temp))
            {
                getline(file,temp1);
                a.insertAtHead(temp,temp1);
                getline(file,temp);
            }


        }
        if (var==3)
        {
            string t="";
            cin.ignore(1000, '\n');
            cout << "Input file Name :";
            string t1="";
            getline (cin, t1);
            t1=t1+".txt";
            cout << "Input the keyword/phrase yow wanna save:";
            getline (cin, t);
            b=a.searchFor(t);
            if(b.length()!=0)
                b.saverank(t1);

        }

        if (var==4)
        {
            string t="";
            cin.ignore(1000, '\n');
            cout << "Input file Name :";
            string t1="";
            getline (cin, t1);
            t1=t1+".txt";
            cout << "Input the keyword/phrase yow wanna save:";
            getline (cin, t);
            b=a.searchFor(t);
            if(b.length()!=0)
                b.saverank(t1);
            a.~LinkedList();
            b.~LinkedList();
            exit(1);


        }
        if (var==5)
        {
            a.~LinkedList();
            b.~LinkedList();
            exit(1);
        }
    }

}
