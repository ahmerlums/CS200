#ifndef LinkedList_LinkedList_h
#define LinkedList_LinkedList_h
#include <string>
#include <fstream>
using namespace std;





struct Node
{
    string value;
    string value2;
    string words;
    int rank;
    int kee;
    int index;
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
    void insertAtHead(string, string);
    void insertAtHead(string, string, int);
    void insertAtHead(string, string,string, int);
    void insertAtHead(string);
    void Insert(int,int);
    void insertatHead(string,string,int);

    // Lookup Functions
    LinkedList searchFor(string& item);
    Node* searchForNode(string);
    int lowRank (string);
    Node* getHead();
    LinkedList getNode(Node*);
    // Deletion Functions
    void deleteElement(string item);

    // Utility Functions
    int length();
    void print();
    void printrank();
    void printindex();
    void saverank(string);
    int highestRank();


};



#endif
