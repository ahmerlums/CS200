#include <iostream>
#include <string>
#include "LinkedList.cpp"
#include <fstream>
#include <stdio.h>
#include "boiler.cpp"
#include <sstream>

using namespace std;

int CountWord(string a)
{
    int i=0;
    int c=1;
    for (i=0; i<a.length(); i++)
    {
        if(a[i] == ' ')
            c++;
    }
    return c;

}


unsigned int RSHash(const std::string& str)
{
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;

    for(int i = 0; i < str.size(); i++)
    {
        hash = hash * a + str[i];
        a    = a * b;
    }

    return hash;
}

struct Data
{
    string str;
    LinkedList list;
};

class Table
{
public:
    Data Table[1000];

};


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

    Table boy;
    LinkedList c;
    Node * tmpNode=a.getHead();
    for(int i=0; i<a.length(); i++)
    {

        string tempo="";
        string tempo1;
        int key;
       // cout << tmpNode->value2;
        for(int i=0; i<tmpNode->value2.size(); i++)
        {
            if (tmpNode->value2[i]!=' ')
            {
              tempo=tempo+tmpNode->value2[i];

            }

            if(tmpNode->value2[i]==' ')
            {

                key=RSHash(tempo);
                int ab= key%1000;

                if (ab<0)
                    ab=-ab;
                if (boy.Table[ab].str.size()==0||boy.Table[ab].str==tempo)
                {
                boy.Table[ab].str=tempo;
                boy.Table[ab].list.Insert(tmpNode->index,key);
                }

                else
                {
                    while (1)
                    {

                        if (ab<999)
                        ab++;

                        if (boy.Table[ab].str.size()==0||boy.Table[ab].str==tempo||ab>=999)
                        {

                          break;
                        }

                    }

                    boy.Table[ab].str=tempo;
                    boy.Table[ab].list.Insert(tmpNode->index,key);


                }
                tempo="";

            }

        }
        tmpNode=tmpNode->next;
    }
    for (int i=0;i<1000;i++)
    cout << boy.Table[i].str<<endl;
while (1)
{


cout << "Enter word/phrase:";
    string my ="";
    getline(cin,my);
    if (my=="q")
        break;
   LinkedList f;
    string to;

    //ifstream files("lowRank.txt");
    /*while (1)
    {
        getline(files,to);
        if (to.size()==0)
            break;
        f.insertAtHead(to);
    }*/
     startTimer();
    string arr[99];
    int i1=0;
    int cnt = CountWord(my);
    stringstream ssin(my);
    while (ssin.good() && i1 < my.size())
    {
        ssin >> arr[i1];
        i1++;
    }
LinkedList u;
    for (int i=0;i<cnt;i++)
    {

    int k=RSHash(arr[i]);
    int n=k%1000;
    if (n<0)
    n=-n;

    if (boy.Table[n].str==arr[i])
    {

        LinkedList d=boy.Table[n].list.getNode(a.getHead());
        Node* nr=d.getHead();

        while (nr!=NULL)
        {

//                int pu=f.lowRank(arr[i]);


            Node* t= u.searchForNode(nr->value2);

            if (t!=NULL)
            {
                t->rank=t->rank+1;
            }
            if (t==NULL)
                u.insertAtHead(nr->value,nr->value2,1);
            nr=nr->next;
        }



    }
    else
    {
        while (1)
        {
            if (n<999)
                n++;
             if (boy.Table[n].str==arr[i]||n>=999)
                        break;

        }
         if (boy.Table[n].str==arr[i])
         {
        LinkedList d=boy.Table[n].list.getNode(a.getHead());
        Node* nr=d.getHead();
        while (nr!=NULL)
        {
            Node* t= u.searchForNode(nr->value2);
            if (t!=NULL)
                t->rank=t->rank+1;
            if (t==NULL)
            u.insertAtHead(nr->value,nr->value2,1);
            nr=nr->next;
        }
    }
    }
    }
    if (u.length()!=0)
    u.printrank();
    double l=stopTimer();
    cout << "Time = " <<l << endl;


}
}
