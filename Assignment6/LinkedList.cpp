// Implementation of the LinkedList class

//#include "Stdafx.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std; //needed for cout, cin to be recognised

// Default constructor
template <class t>
LinkedList<t>::LinkedList(){
	head = NULL;
	size = 0; //Don't forget to do this!!!
}

/* Copy constructor to copy an existing list.  Note that the compile
 * will generate a copy constructor automatically.  However, this
 * constructor only creates a SHALLOW COPY (so would only copy the
 * size and head variables).  In this case this would NOT CREATE A
 * NEW LIST, just a new reference to one list.  It is therefore
 * necessary to write a constructor that makes a DEEP COPY.*/

/* Also note the parameter.  C++ functions use pass-by-value by
 * default.  This means that the functions make copies of the given
 * arguments.  This is inefficient (particularly for large objects).
 * Therefore it is normal to pass the address (using &) of the parameter,
 * but, if the parameter should not be changed, it is good practice to
 * make it const, which prevents it from being changed.*/
template <class t>
LinkedList<t>::LinkedList(const LinkedList& lst){
	if (lst.head == NULL){
		head = NULL;
		size = 0;
	}
	else{
		// Copy first node and assign head
		/* OK, what's with the '->'?  The -> operator accesses the attribute
		 * or method of the object (or struct) that is refererred to by a
		 * pointer.  So "head -> data" is the contents of the data variable
		 * of the object that head points to.  Note that this is synonomous
		 * with "(*head).data" but the latter syntax is ugly and confusing and
		 * is therefore rarely used. */
		head = new Node<t>;
		head->data = lst.head->data;
		/* Now copy the rest of the list.  To do this we'll need to create two
		 * temporary pointers, one to go through the old list, one node at a
		 * time, and one to keep pace in the new list, creating new nodes. */
		Node<t> *pNewNode = head;
		Node<t> *pOldNode = lst.head->next;
		// Repeat until the entire list is copied
		while (pOldNode != NULL){
			pNewNode->next = new Node<t>;
			pNewNode = pNewNode->next;
			pNewNode->data = pOldNode->data;;
			pOldNode = pOldNode->next;
		}
		pNewNode->next = NULL;
		size = lst.size;
	}
}

/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object.  If there is no such memory no destructor needs to
 * be created (the compiler automatically creates one).  Because this class
 * uses pointers to create new Nodes it is necessary to write a destructor.
 * Destructors are identified by the '~' preceding the class name.  There can
 * be only one destructor for a class, and it cannot have parameters. */
template <typename t>
LinkedList<t>::~LinkedList(){
	removeAll();
}

/**************************************************************************/
// LinkedList Operations

// Adds a node to the start of the list, making it the new head
template <class t>
void LinkedList<t>::add(t x){
	Node<t> *p = new Node<t>; //temporary node
	// Assign appropriate values to the new node
	p -> data = x;
	p -> next = head;
	// Make the head point to the new node
	head = p;
	size++;
}

// Inserts a new node at the given position (or index) in the list
template <class t>
void LinkedList<t>::insertAt(int pos, t x){
	Node<t> *p;
	Node<t> *newNode;

	// Check that pos is a valid index
	if (pos <= size){
		newNode = new Node<t>; //new node
		newNode->data = x;

		// Deal with case when item is to be inserted at the head of the list
		if (pos == 0){
			newNode->next = head;
			head = newNode;
		}// if(pos == 0)
		else{
			p = head;
			// Move to position BEFORE insertion point
			for(int i = 0; i < pos-1; i++){
				// Check that p points to a node
				// Note using exception handling should throw an exception here
				if(p == NULL){
					return;
				}
				p = p->next;
			}//for
			// Insert node
			newNode->next = p->next;
			p->next = newNode;
		}//else (pos != 0)
		size++;
	}//else (pos >= size) do nothing
}

// Removes the first node containing the given data, returns true
// iff data is found (and deleted).
template <class t>
bool LinkedList<t>::remove(t x){
	Node<t> *p = head;
	Node<t> *temp;
	// Check to see if the list exists
	if (head == NULL){
		return false;
	}
	// Check to see if target is at the head of the list
	else if (head->data == x){
		head = head->next;
		delete p; //currently assigned head
		size--;
		return true;
	}
	// Otherwise iterate through list
	else{
		while(p->next != NULL){
			// Check next node for target
			if(p->next->data == x){
				temp = p->next;
				p->next = p->next->next;
				size--;
				delete temp;
				return true;
			}
			p = p->next;
		}
	}
	return false;
}

// Empties the list by deleting each node, starting at the head
template <class t>
void LinkedList<t>::removeAll(){
	Node<t> *p = head;
	// Traverse the list deleting nodes
	while (p!= NULL){
		head = head->next; // Mustn't "lose" the next node
		delete p; // De-allocate memory
		p = head; // Go to next node
	}
	head = NULL;
	size = 0;
}

// Prints the entire list (head first) to the screen.
/* Note that there is some debate about whether or not this type of
 * method belongs in a class.  The argument (briefly) is that a class
 * shouldn't be responsible for its own display as it cannot foresee
 * how it is to be displayed. */
template <class t>
ostream& LinkedList<t>::printList(){
	Node<t> *p = head;
//	ostream& out;
	cout << "["; //Nice format!
	// Traverse the list
	while (p != NULL){
		cout << p -> data; // Print data
		p = p -> next; // Go to next node
		if (p != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "]"; // Don't print a newline - it might not be wanted
    //return out;
}



 template <class t>
 Node<t>* LinkedList<t>::getHead()
{
    return head;
}

template <class t>
int LinkedList<t>::length()
{
    int counter=0;

    Node<t> * tmpNode = head;

    while(tmpNode!=NULL){
        counter++;
        tmpNode = tmpNode->next;
    }

    return counter;
}

template <class t>
Node<t>* LinkedList<t>::getTail()
{
    Node<t>* temp = this->head;
    if (length()==0)
        return this->head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

      return temp;
}



template <typename T>
void Set<T>::insert(T item) {
    Node<T>* temp = this->head;
    bool contains = false;

    while (temp != NULL) {
        if (temp->data == item) {
            contains = true;
        }
        temp  = temp->next;
    }

    if (contains == false) {
    Node<T>* tailNode=this->getTail();
    Node<T>* node = new Node<T>;
    node->data=item;
    node->next=NULL;

    if (this->head!=NULL)
        tailNode->next=node;

    else
        this->head = node;


    }

}

template <typename T>
ofstream& operator<<(ofstream& out, const Set<T> set) {
    Node<T>* temp = set.head;

    cout << "{ ";
    while (temp != NULL) {

        out << temp->data ;
        temp = temp->next;
    }
    cout << " }" << endl;

    return out;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T> set) {
    Set<T> result;
    result.head = this->head;

    Node<T>* temp = this->head;
    Node<T>* temp1 = set.head;

    while (temp != NULL || temp1 != NULL) {
        if (temp != NULL) {
            result.insert(temp->data);

        }

        if (temp1 != NULL) {
            result.insert(temp1->data);

        }
        temp=temp->next;
        temp1=temp1->next;
    }

    return result;
}

template <typename T>
Set<T>& Set<T>::operator+(const T a)
{
    this->insert(a);
    return *this;
}

 template <class T>
 bool Set<T>::contains(T a)
 {
     Node<T>* temp = this->head;
     while (temp!=NULL)
     {
         if(temp->data == a)
            return 1;
         temp=temp->next;
     }

     return 0;
 }

 template <class t>
LinkedList<t> LinkedList<t>::operator+( LinkedList& l)
{
    LinkedList res;
    Node<t>* tmp = getHead();
    Node<t>* tmp1 = l.getHead();
    t arr[222];
    int pos=0;

    while(tmp!=NULL)
    {
    arr[pos]=tmp->data;
    tmp=tmp->next;
    pos++;
    }
    pos=0;

    while(tmp1!=NULL)
    {
    arr[pos]=tmp1->data+arr[pos];
    tmp1=tmp1->next;
    pos++;
    }
    for (int i=0;i<pos;i++)
        res.insertAt(i,arr[i]);
    return res;


}

