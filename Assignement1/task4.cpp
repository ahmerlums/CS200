#include <iostream>
#include <cmath>
using namespace std;

int WhitePawn(char m, int n);
int BlackPawn(char q ,int w);
int King(char a, int b);
int Queen(char e, int r);
int Rook(char q, int w);
int Bishop(char v, int b);
int Knight(char o, int p);
int CheckPos(char yi, int y1); //This function will be used as it tells if the chess board can take the inputted position.

int main()
{
    int reset=1;

    while (reset==1)
    {
        char piece;
        char n;
        char pawn;
        int x=0;
        int p=0;
        char res;

        cout << "Enter your piece (P,K,Q,R,B,N(Knight)):";
        cin >> piece ;

        if (piece == 'P') // THE PAWN
        {
            cout << "The Pawn is White(W) or Black(B)?:"; // Remember there are 2 types of pawns with different moves !
            cin >> pawn;

            if (pawn == 'W') // White Pawn
            {
                cout << "Input the initial position for White Pawn:";
                cin >> n >> x;
                p = CheckPos(n,x);

                if (x==1 && p==1)
                {
                    cout << "White Pawn can't take this initial position" << endl;
                    p=0;
                }

                if (p==1)
                   WhitePawn(n,x); // Calling White Pawn Function
            }

            if (pawn == 'B')// Black Pawn
            {
                cout << "Input the initial position for the Black Pawn:";
                cin >> n >> x;
                p = CheckPos(n,x);

                if (x==8 && p==1)
                {
                    cout << "Black Pawn can't take this initial position" << endl;
                    p=0;
                }

                if (p==1)
                   BlackPawn(n,x); // Calling Black Pawn Function
            }
        }

        if (piece == 'K') {   // THE KING
            cout << "Input the initial position for King:";
            cin >> n >> x;
            p = CheckPos(n,x);

            if (p==1)
               King(n,x); // Calling King Function
        }

        if (piece == 'Q') // THE QUEEN
        {
            cout << "Input the initial position for Queen:";
            cin >> n >> x;
            p = CheckPos(n,x);

            if (p==1)
               Queen(n,x) ; // Calling Queen Function
        }

        if (piece == 'R') // THE ROOK
        {
            cout << "Input the initial position for Rook:";
            cin >> n >> x;
            p = CheckPos(n,x);

            if (p==1)
               Rook(n,x); // Calling Rook Function
        }

        if (piece == 'B')  // THE BISHOP
        {
            cout << "Input the initial position for Bishop:";
            cin >> n >> x;

            p = CheckPos(n,x);
            if (p==1)
               Bishop(n,x); //Calling Bishop Function
        }

        if (piece == 'N') // THE KNIGHT
        {
            cout << "Input the initial position for Knight:";
            cin >> n >> x;

            p = CheckPos(n,x);
            if (p==1)
               Knight(n,x); // Calling Knight Function
        }

        cout << "Try again ? (Enter Y/y for yes or any other key for No! )"; // Now this asks the user if he wants to try again.
        cin >> res ;

        if (res =='Y'||res == 'y'){
           reset = 1;
           cout << endl; }  // A new line for clarity!
        else
           reset = 0;
    }
}

int WhitePawn(char m, int n)
{
    char d;
    int c=0;
    int p=0;

    cout << "Enter the final position:" ;
    cin >> d >> c;
    p = CheckPos(d,c);
    if (p==1)
    {
        if(n==2)    // Condition if the Pawn takes its default initial position as the game starts.
        {
            if (d==m && c==(n+1)|| c==(n+2))
               cout << "The move is legal" << endl;
            else
               cout << "The move is illegal" << endl;
        }

        if (n!=2) // Condition when the Pawn is not on its starting position.
        {
            if (d==m && c==(n+1))
               cout << "The move is legal" << endl;
            else
               cout << "The move is illegal" << endl;
        }
    }
}

int BlackPawn(char q, int w)
{
    char d;
    int c=0;
    int p=0;

    cout << "Enter the final position:";
    cin >> d >> c;
    p = CheckPos(d,c);
    if (p==1)
    {
        if (w==7)     // Condition if the Pawn takes its default initial position as the game starts.
        {
            if ((d==q) && (c==w-1||c==w-2))
               cout << "The move is legal" << endl;
            else
               cout << "The move is illegal" << endl;
        }

        if (w!=7)    // Condition when the Pawn is not on its starting position.
        {
            if (d==q && c==w-1)
               cout << "The move is legal" << endl ;
            else
               cout << "The move is illegal" << endl;
        }
    }
}

int King(char a, int b)
{
    char d;
    int c=0;
    int p=0;

    cout << "Enter the final position:";
    cin >> d >> c;
    p = CheckPos(d,c);
    if (p==1)
    {
        if ((d==a&&c==b+1)||(d==a&&c==b-1)||(d==a+1&&c==b)||(d==a-1&&c==b)||(d==a+1&&c==b+1)||(d==a-1&&c==b+1)||(d==a+1&&c==b-1)||(d==a-1&&c==b-1))
           cout << "The move is legal" << endl;

        else
           cout << "The move is illegal" << endl;

    }
}

int Queen(char e, int r)
{
    char d;
    int c=0;
    int x1=0;
    int x2=0;
    int p=0;

    cout << "Enter the final position:";
    cin >> d >> c;
    p = CheckPos(d,c);
    if (p==1)
    {
        // Taking abs values of differences so that the result can always be compared
        x1=abs(e-d);
        x2=abs(r-c);

        if (x1==x2)
           cout << "The move is legal"<< endl;

           else if (e==d)
              cout << "The move is legal" << endl;

           else if (r==c)
              cout << "The move is legal" << endl;

           else
              cout << "The move is illegal" << endl;
    }
}

int Rook(char q, int w)
{
    char d;
    int c=0;
    int p=0;

    cout << "Enter the final position:";
    cin >> d >> c;
    p = CheckPos(d,c);
    if (p==1)
    {
        if ((q==d)||(w==c))
           cout << "The move is legal" << endl;
        else
           cout << "The move is illegal" << endl;
    }
}
int Bishop(char v, int b)
{
    char d;
    int c=0;
    int x1=0;
    int x2=0;
    int p=0;

    cout << "Enter the final position:";
    cin >> d >> c;
    p = CheckPos(d,c);
    if (p==1)
    {
        // Taking abs values of difrences so that the result can always be compared
        x1=abs(v-d);
        x2=abs(b-c);

        if (x1==x2)
           cout << "The move is legal" << endl;
        else
           cout << "The move is illegal"<< endl;
    }
}

int Knight(char o, int p)
{
    char d;
    int c=0;
    int e=0;

    cout << "Enter the final position:";
    cin >> d >> c;
    e = CheckPos(d,c);
    if (e==1)
    {
        if ((d==o+1||d==o-1) && (c==p+2||c==p-2))  // The 2.5 move conditions !!
              cout << "The move is legal" << endl;
           else if ((d==o+2||d==o-2) && (c==p+1||c==p-1))
              cout << "The move is legal" << endl;
           else
              cout << "The move is illegal" << endl;
    }
}

int CheckPos(char yi,int y1)   // Suppose if you enter j4 or a9 then this function will return 0 in which the user will prompt you.
{                              // If you enter a correct position like a6 or g3 then 1 will be returned and the condition of p=1 will hold true.
    if ((yi=='a'|| yi =='b'|| yi =='c'|| yi =='d'|| yi =='e'|| yi =='f'|| yi =='g'|| yi =='h')&&(y1 >=1 && y1 <=8))
       return 1;
    else
    {   cout << "Invalid position" << endl;
        return 0;
    }
}
