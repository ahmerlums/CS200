#include <iostream>;
using namespace std;

int main()
{
    int quantity = 0;
    int price = 0;
    int total = 0;
    int x = 1;
    int d=0;
    int discount=0;
    int disctotal=0;



    while (x==1)
    {
        d++;
        cout << "Quantity of item " << d <<":";
        cin >> quantity;


        cout << "Price of item " << d << ":";
        cin >> price;

        total = total + (quantity*price);
        cout << "Total price of item " << d << " is " << quantity*price << " Rs. " << endl;
        cout << "Your total is " << total << " Rs." << endl;

          if (total > 5000) // 10 % Discount Condition
    {
        disctotal = total;
        discount = 0.1 * disctotal;
        disctotal = disctotal - discount ;
        cout << "Discount is " << discount << " Rs." << endl;
        cout << "Your discounted total is " << disctotal << " Rs." << endl;
    }


        cout << "Do you want to buy more items?(Enter 1 if yes, 0 if no!" << endl;
        cin >> x;

            while ((x!=0)&&(x!=1)){   // A loop which ensures that only 0 or 1 are entered.
                cout <<"Enter either 0 or 1:";
                cin >> x;
            }
        cout << endl ;  //A new line for clarity

    }



}
