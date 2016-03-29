#include "LinkedList.h"
#include <iostream>
#include "stdio.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;
int wordcount(string a, string b)
{
    int d=1;
    int c=0;
    int temp;
    for (int i=0; i<a.size(); i++)
    {
        d=1;
        if(a[i]==b[0]&&((a[i-1]==' ')||i==0))
        {
            temp=i;
            for (int r=0; r<b.size(); r++)
            {
                if (r!=b.length()-1)
                {
                    if(a[temp]==b[r])
                        d=1;
                    else
                    {
                        break;
                    }
                    temp++;

                }

                else
                {
                    if(a[temp]==b[r]&&((a[temp+1]==' ')||(temp==a.size()-1 )) )

                        d=1;
                    else
                    {
                        break;
                    }

                    temp++;

                    c++ ;
                }

            }

        }
    }

    return c;
}



int CountWords(string a)
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





LinkedList::LinkedList()
{
    head=NULL;
}

LinkedList::LinkedList(const LinkedList& otherLinkedList)
{
    head=otherLinkedList.head;

}


LinkedList::~LinkedList() {
head=NULL;
/*    Node* node = head;
    Node* tmpNode = NULL;

    if (head!=NULL)
    {
        if (head->next==NULL)
            delete head;
        else
        {
            while (node->next)
            {
                tmpNode=node;
                node=node->next;
                delete tmpNode;
            }
        }
        delete node;
    }
*/
}
void LinkedList::Insert(int item, int item2)
{
    Node *node=new Node;
    node->index = item;
    node->kee = item2;
    node->prev = NULL;
    node->next = head;;
    if(head!=NULL)
    {
        head->prev = node;
    }
    head = node;

}
 LinkedList LinkedList::getNode(Node* a)
 {
     LinkedList b;
    Node* tmpNode=head;
    while (tmpNode!=NULL)
    {
        Node* tmp=a;

       while (tmp!=NULL)
        {
            if(tmpNode->index==tmp->index)
                b.insertAtHead(tmp->value2,tmp->value);
           tmp=tmp->next;
        }

        tmpNode=tmpNode->next;
    }

return b;
 }
void LinkedList::insertAtHead(string item, string item2)
{
    Node *node=new Node;
    node->value = item;
    node->value2 = item2;
    node->prev = NULL;
    node->next = head;;
    if(head!=NULL)
    {
        head->prev = node;
    }
    head = node;

}
void LinkedList::insertatHead(string item, string item2, int idx)
{
    Node *node=new Node;
    node->value = item;
    node->value2 = item2;
    node->index=idx;
    node->prev = NULL;
    node->next = head;;
    if(head!=NULL)
    {
        head->prev = node;
    }
    head = node;

}
void LinkedList::insertAtHead(string item, string item2, int rnk)
{
    Node *node=new Node;
    node->value = item;
    node->value2 = item2;
    node->rank=rnk;
    node->prev = NULL;
    node->next = head;;
    if(head!=NULL)
    {
        head->prev = node;
    }
    head = node;

}
void LinkedList::insertAtHead(string item, string item2, string item3, int rnk)
{
    Node *node=new Node;
    node->value = item;
    node->value2 = item2;
    node->words = item3;
    node->rank=rnk;
    node->prev = NULL;
    node->next = head;
    if(head!=NULL)
    {
        head->prev = node;
    }
    head = node;

}

void LinkedList::insertAtHead(string item)
{
    Node *node=new Node;
    node->words = item;
    node->prev = NULL;
    node->next = head;;
    if(head!=NULL)
    {
        head->prev = node;
    }
    head = node;

}

LinkedList LinkedList::searchFor(string& item)
{
    int cnt=CountWords(item);


    int i1=0;
    string arr[9999];

    stringstream ssin(item);
    while (ssin.good() && i1 < item.size())
    {
        ssin >> arr[i1];
        i1++;
    }
    LinkedList d;
    string t;

    ifstream file("lowRank.txt");
    while (1)
    {
        getline(file,t);
        if (t.size()==0)
            break;
        d.insertAtHead(t);
    }

    LinkedList b;
    int p;
    Node *tmpNode = head;

    int counter=0;
    while(tmpNode!=NULL)
    {
        p=0;
        p=wordcount(tmpNode->value2,item);

        if (p>0)
        {
            if (cnt>1)
            p=10;

            b.insertAtHead(item,tmpNode->value,p);
        }

        tmpNode = tmpNode->next;
    }


    int u=0;
    if (cnt > 1)
    {

        for (i1=0; i1<cnt; i1++)
        {

            tmpNode=head;
            while(tmpNode!=NULL)
            {

                p=wordcount(tmpNode->value2,arr[i1]);
                if(p>0)
                {
                    u=d.lowRank(arr[i1]);
                    if (u==1)
                        p=1;
                     Node* t= b.searchForNode(tmpNode->value);
                     if (t!=NULL&&t->rank!=10)
                     {
                    t->rank=p+t->rank;
                     t->value=t->value+" 'and' "+arr[i1];
                     }
                    if (t==NULL)
                    b.insertAtHead(arr[i1],tmpNode->value,tmpNode->value2,p);
                }
                tmpNode = tmpNode->next;
            }

        }
    }

    if (cnt>1)
        return b;
}



int LinkedList::length()
{
    int counter=0;

    Node * tmpNode = head;

    while(tmpNode!=NULL)
    {
        counter++;
        tmpNode = tmpNode->next;
    }

    return counter;
}

void LinkedList::print()
{
    Node * tmpNode = head;
    while(tmpNode!=NULL)
    {
        cout << tmpNode->value2 << endl;
        tmpNode = tmpNode->next;
    }
    cout << "\n----------------------\n";
}
void LinkedList::printindex()
{
    Node * tmpNode = head;
    while(tmpNode!=NULL)
    {
        cout << tmpNode->index << endl;
        tmpNode = tmpNode->next;
    }
    cout << "\n----------------------\n";
}

int LinkedList::lowRank(string a)
{
    Node * tmpNode=head;
    while(tmpNode!=NULL)
    {

        if(a==tmpNode->words)
            return 1;
        tmpNode=tmpNode->next;
    }
    return 0;

}

int LinkedList::highestRank()
{
    Node * tmpNode=head;
    int u=tmpNode->rank;
    while(tmpNode!=NULL)
    {
        if (tmpNode->rank > u)
            u=tmpNode->rank;
        tmpNode=tmpNode->next;
    }

    return u;

}

Node* LinkedList::searchForNode(string item)
{
    Node *tmpNode = head;

    while(tmpNode!=NULL)
    {

        if(tmpNode->value2==item)
        {
            return tmpNode;
        }

        tmpNode = tmpNode->next;
    }

    return NULL;
}

void LinkedList::printrank()
{
    Node*tmpNode = head;
    //cout << highestRank()<<endl << end;
    int c=highestRank();
    int p=0;
    for (c=c; c>0; c--)
    {
        tmpNode =head;
        while (tmpNode!=NULL)
        {
            if (tmpNode-> rank == c)
            {    p++;
         //        cout << p << endl;
                cout << "URL = "<<tmpNode->value2 << endl;
                cout << "Words Found = " <<tmpNode->value << endl;
                cout << "Rank = " <<tmpNode->rank<<endl;
                cout << "Data= " <<tmpNode->words<<endl;
                cout << endl;
                tmpNode->rank=-5;
            }
            tmpNode = tmpNode->next;
        }
    }

}

void LinkedList::saverank(string a)
{

    ofstream file(a.c_str());
    Node*tmpNode = head;
    //cout << highestRank()<<endl << end;
    int c=highestRank();
    int p=0;
    for (c=c; c>0; c--)
    {
        tmpNode =head;
        while (tmpNode!=NULL)
        {
            if (tmpNode-> rank == c)
            {    p++;
                file << "URL = "<<tmpNode->value2 << endl;
                file << "Words Found = " <<tmpNode->value << endl;
                file << "Rank = "<<tmpNode->rank<<endl;
               file<< "Data= " <<tmpNode->words<<endl;
                tmpNode->rank=-5;
            }
            tmpNode = tmpNode->next;
        }
    }

}
Node* LinkedList::getHead()
{
    return head;
}
