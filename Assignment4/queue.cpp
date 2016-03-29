#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"
#include "stdio.h"
Queue::Queue()
{
   list=LinkedList();
}
    

Queue::Queue(const Queue& otherQueue)
{
    LinkedList otherList = otherQueue.list;
    list = otherList;
}


Queue::~Queue()
{
    list.~LinkedList();

}


void Queue::enqueue(int item)
{
    list.insertAtHead(item);
}


int Queue::front()
{
    Node * tmpNode = list.getintail();
    return tmpNode->value;
}


int Queue::dequeue()
{
    Node * topNode = list.getintail();
    int tmpValue = topNode->value;
    list.deleteintail();
    return tmpValue;
}


int Queue::length()
{
    return list.length();
}


bool Queue::isEmpty()
{
    if (length()==0) return true;
    else return false;

}


#endif
