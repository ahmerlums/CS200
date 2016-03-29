#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"
#include <iostream>
#include "stdio.h"
using namespace std;

Stack::Stack()
{
  
  list=LinkedList();
    
}
    

Stack::Stack(const Stack& otherStack)
{
    LinkedList otherList = otherStack.list;
    list = otherList;
}


Stack::~Stack()
{
  list.~LinkedList();
}


void Stack::push(int item)
{
    list.insertAtintail(item);
}


int Stack::top()
{
    Node * topNode = list.getintail();
    return topNode->value;
}


int Stack::pop()
{
    if(isEmpty()){
        printf("The stack is empty");
        return -1;
    }
    
    Node * topNode = list.getintail();
    int tmpValue = topNode->value;
    list.deleteintail();
    return tmpValue;
}


int Stack::length()
{
    return list.length();
}


bool Stack::isEmpty()
{
    if (length()==0) return true;
    else return false;
}

void Stack::print(){
    Node * tmpNode = list.getHead();
    while(tmpNode!=NULL){
        cout << tmpNode->value << "->";
        tmpNode = tmpNode->next;
    }
    cout<<"\n----------------------\n";
}


#endif
