#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

/* This is the generic List class */

class LinkedList
{
    Node * head;
    
public:
    
    // Constructor
    LinkedList();
    
    // Copy Constructor
    LinkedList(const LinkedList& otherList);
    
    // Destructor
    ~LinkedList();
    
    // Insertion Functions
    void insertAtHead(int item);
    void insertAtintail(int item);
    void insertAfter(int toInsert, int afterWhat);
    void insertSorted(int item);
    
    // Lookup Functions
    Node *getHead();
    Node *getintail();
    Node *searchFor(int item);
    
    // Deletion Functions
    void deleteElement(int item);
    void deleteHead();
    void deleteintail();
    
    // Utility Functions
    int length();
    void print();
};

#endif
