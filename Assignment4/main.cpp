#include "LinkedList.h"
#include "LinkedList.cpp"
#include "stack.cpp"
#include "queue.cpp"

#include <iostream>
using namespace std;

LinkedList linkedList;
Stack stack;
Queue queue;

//For Linked List
/*
int main() {
//    LinkedList linkedList; 
    cout<<"1. Insert at head\n";
    cout<<"2. Insert at tail\n";
    cout<<"3. Insert after\n";
    cout<<"4. Delete head\n";
    cout<<"5. Delete tail\n";
    cout<<"6. Delete Element\n";
    cout<<"7. Exit code\n";
    cout<<"Enter a choice : ";

    int choice;
    int var,var1;
    cin >> choice;
    switch (choice) {

        case 1:
            cout << "Enter an integer to enter : ";
            cin >> var;
            linkedList.insertAtHead(var);
            linkedList.print();
            break;
        case 2:
            cout << "Enter an integer to enter : ";
            cin >> var;
            linkedList.insertAtintail(var);
            linkedList.print();
            break;
        case 3:
            cout << "Enter an integer to enter : ";
            cin >> var;
            cout << "Enter an integer to enter after :";
            cin >> var1;
            linkedList.insertAfter(var, var1);
            linkedList.print();
            break;
        case 4:
            linkedList.deleteHead();
            linkedList.print();
            break;
        case 5:
            linkedList.deleteintail();
            linkedList.print();
            break;
        case 6:
            cout << "Enter an integer to enter :";
            cin >> var;
            linkedList.deleteElement(var);
            linkedList.print();
            break;
        case 7:
            exit(1);
        default:
            cout<<"Invalid choice";
            break;
    }
    
	LinkedList b=linkedList;
	b.print();
    main();
}
 
*/

//For Stack

int main(){
    
    cout<<"1. Push\n";
    cout<<"2. Pop\n";
    cout<<"3. Top\n";
    cout<<"4. Length\n";
    cout<<"7. Exit code\n";
    cout<<"Enter a choice : ";
    
    int choice;
    int var;
    cin >> choice;
    switch (choice) {
            
        case 1:
            cout << "Enter an integer to enter : ";
            cin >> var;
            stack.push(var);
            stack.print();
            break;
        case 2:
            stack.pop();
            stack.print();
            break;
        case 3:
            printf("top is %i\n",stack.top());
            //stack.print();
            break;
        case 4:
            linkedList.deleteHead();
            linkedList.print();
            break;
        case 5:
            linkedList.deleteintail();
            linkedList.print();
            break;
        case 6:
            cout << "Enter an integer to enter :";
            cin >> var;
            linkedList.deleteElement(var);
            linkedList.print();
            break;
        case 7:
            exit(1);
        default:
            cout<<"Invalid choice";
            break;
    }
     Stack b=stack;
	b.print();
    
    main();
}


//For Queue
/*
int main(){
    
}
*/








