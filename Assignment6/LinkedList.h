// Header file for linked list class
#include <iostream>
using namespace std;

template <typename t>
class Node {
public:
    t data; //list data
    Node *next; //pointer to next item in the list
};

template <class t>
class LinkedList{
public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	LinkedList(); //default construtor
	LinkedList(const LinkedList& lst);
	LinkedList<t> operator+ ( LinkedList&); //copy constructor
	/* Every class should have a destructor, which is responsible for
	 * cleaning  up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~LinkedList();//destructor

	// PRE:
	// POST: A new node containing the given data is inserted at the front
	//       of the list
	// PARAM: data is the data to be stored
//       typename <template t>
	void add(t data);

	// PRE:
	// POST: A new node containing the given data is inserted at the given
	//       position in the list
	// PARAM: pos specifies the (index) position to insert the new node
	//        data is the data to be stored
//typename <template t>
	void insertAt(int pos, t data);
     Node<t>* getTail();
	// PRE:
	// POST: The first incidence of the given data is removed from the list.
	//       Returns true if data is found (and removed), false otherwise
	// PARAM: data specifies the data to be removed from the list
	bool remove(t data );

	// PRE:
	// POST: Empties the list, freeing up dynaically allocated memory
	// PARAM:
	void removeAll();
    int length();
	// PRE:
	// POST: Prints the contents of the list to the screen, in order
	// PARAM:

	ostream& printList();
    Node<t>* getHead();
    protected:
	Node<t> *head; //Pointer to the first node in the list
	t size; //Records the number of nodes in the list
};

template <typename T>
class Set;

template <typename T>
ofstream& operator<<(ofstream& out, const Set<T> set);

template <class T>
class Set:public LinkedList<T>{
    public:
    void insert(T item);
    friend ofstream& operator << <>(ofstream& out, const Set<T> set);
    Set<T> operator+(const Set<T> set);
    Set<T>& operator+(const T);
    bool contains(T);
};
