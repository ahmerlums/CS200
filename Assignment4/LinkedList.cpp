#include "LinkedList.h"
#include <iostream>
#include "stdio.h"
using namespace std;

LinkedList::LinkedList()
{
head=NULL;
}

LinkedList::LinkedList(const LinkedList& otherLinkedList)
{
//    Node * tmpNode = otherLinkedList.head;
  //  while (tmpNode != NULL) {
    //    insertAtintail(tmpNode->value);
//	tmpNode=tmpNode->next;
  //  }
	head=otherLinkedList.head;
}


LinkedList::~LinkedList()
{
    head = NULL;
}


void LinkedList::insertAtHead(int item)
{
    Node *node = new Node;
    node->value = item;
    node->prev = NULL;
    node->next = head;
    if(head!=NULL){
        head->prev = node;
    }
    head = node;
    
}


void LinkedList::insertAtintail(int item)
{
    Node * tailNode = getintail();
    
    Node * node = new Node;
    node->value = item;
    node->next = NULL;
    node->prev = tailNode;
    
    if (head!=NULL){
        tailNode->next = node;
    }
    else {
        head = node;
    }
}


void LinkedList::insertAfter(int toInsert, int afterWhat)
{
    Node * tmpNode = searchFor(afterWhat);
    if(tmpNode!=NULL){
        Node * newNode = new Node;
        newNode->value = toInsert;
        newNode->next = tmpNode->next;
        newNode->prev = tmpNode;
        tmpNode->next = newNode;
    }
    else{
        cout<<"The integer is not found";
    }
}


void LinkedList::insertSorted(int item)
{

}


Node* LinkedList::getHead()
{
    return head;
}


Node* LinkedList::getintail()
{
    Node * tmpNode = head;
    
    if (length()==0)
        return head;
    
    while(tmpNode->next != NULL){
        tmpNode = tmpNode->next;
    }
    
    return tmpNode;
}


Node* LinkedList::searchFor(int item)
{
    Node *tmpNode = head;
    
    while(tmpNode!=NULL){
        
        if(tmpNode->value==item){
            return tmpNode;
        }
        
        tmpNode = tmpNode->next;
    }
    
    return NULL;
}


void LinkedList::deleteElement(int item)
{
    Node * tmpNode = searchFor(item);
    
    if(tmpNode!=NULL){
        Node * first = tmpNode->prev;
        Node * last = tmpNode->next;
        first->next = last;
        last->prev = first;
        tmpNode = NULL;
        
    }
    else{
        cout<<"Node not found";
    }
}


void LinkedList::deleteHead()
{
    if(length()==0){
        cout<<"There are no elements in linked list";
        return;
    }
    
    Node * tmpNode = head;
    head = tmpNode->next;
    head->prev = NULL;
    tmpNode = NULL;
    
}


void LinkedList::deleteintail()
{
    if(length()==0){
        cout<<"Length of linked list is zero";
    }
    
    Node * tmpNode = getintail();
    tmpNode->prev->next=NULL;
    tmpNode = NULL;
}


int LinkedList::length()
{
    int counter=0;
    
    Node * tmpNode = head;
    
    while(tmpNode!=NULL){
        counter++;
        tmpNode = tmpNode->next;
    }
    
    return counter;
}

void LinkedList::print(){
    Node * tmpNode = head;
    while(tmpNode!=NULL){
        cout << tmpNode->value << "->";
        tmpNode = tmpNode->next;
    }
    cout<<"\n----------------------\n";
}


