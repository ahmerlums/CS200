#include <iostream>


using namespace std;
int charreturn(char n);

int main()
{
    cout << "Welcome to TicTacMore"<< endl; 
    cout << endl;
    cout << "Author: Ahmer Ali"<<endl;
    cout << "CS 200, program #4.   Written in C++ on Mars Server."<<endl;
    cout << "The object of the game is to get either 4 in a row or" << endl; 
    cout << "3 in a row or any edge.  Player X starts and play alternates" << endl; 
    cout << "until someone wins or the board is full.  You may only move" << endl; 
    cout << "in a square adjacent to a piece already played." << endl;  

            
    int i=0;
    int arr[7][7];
    int over =0;
    int r=0;
    int col=0;
    int xturn=0;
    
    for (r=0;r<7;r++)
    {

        col=0;
        
        for (col=0;col<7;col++)
        {
            if(col==0||col==6) 
            {
                if(r==0)
                    cout << "  ";
                if(r==1)
                    cout << "A ";
                if(r==2)
                    cout << "B ";
                if (r==3)
                    cout << "C ";
                if (r==4)
                    cout << "D ";
                if (r==5)
                    cout << "E ";
                if (r==6)
                    cout << "  ";
               
           }
            else if (r==0)
                cout << col << " ";
            
           else if (r==6)
                cout << col << " ";
                
         else
           cout << ". " ;
        
   }
        cout << endl;
    } 
   
    int temp1[9999]={};
    int temp2[9999]={};
    int temp3[9999]={};
    int temp4[9999]={};
    int win1[9999]={};
    int t1=0;
    int t2=0;
    int p=0;
    int p1=0;
    int k=0;
    int k1=0;
    char q;
    int n=0;
    int ch = 0;
    int turn = 1;
    int c1=0;
    int c2=0;
    int u=0;
    int l=0;
    
       while (1)
    {
           if (over==1)
           {
               cout << "GAME OVER!";
               return 1; 
           }
    cout << "Enter your move: ";
    cin >> q ;
    if (q=='x')
    {
        cout << "You exited! ";
                break;
    }
    cin >> n;
    ch= charreturn(q);
   
 
 
    for (r=0;r<7;r++)
    {
      
        col=0;
    int count = 1;
    int count1=1;
    int count2=1;
 
        for (col=0;col<7;col++)
        {  

            k=0;
           k1=0;
            while (temp1[k]!='\0')
            { 
                if(temp1[k]==r && temp2[k]==col)
                {
                 cout << "X " ;
                
                 break;
                 
                }
                k++;
            }
            while (temp3[k1]!='\0')
            { 
                if(temp3[k1]==r && temp4[k1]==col)
                {
                 cout << "O " ;
                 
                 break;
                 
                }
                k1++;
            }
 
      if(temp1[k]==r && temp2[k]==col)
          int jl=0;
      else if (temp3[k1]==r && temp4[k1]==col)
          int yu=0;
      else
      {
           
            if(col==0||col==6) 
            {
                if(r==0)
                    cout << "  ";
                if(r==1)
                    cout << "A ";
                if(r==2)
                    cout << "B ";
                if (r==3)
                    cout << "C ";
                if (r==4)
                    cout << "D ";
                if (r==5)
                    cout << "E ";
                if (r==6)
                    cout << "  ";
               
           }
            
            else if (ch==r&&n==col) 
            {
               
               if (turn == 1)
                {       
                   l=0;
                   if (xturn==0){
                       temp1[p]=r;
                temp2[p]=col;
                cout << "X " ;
                
                win1[t1]=col;
                t1++;
                
                
                p++;
               }
            k=0;
            
            while (temp3[k]!='\0')
            { 
               if ((r==temp3[k]&&col==temp4[k]+1)||(r==temp3[k]&&col==temp4[k]-1)||(r==temp3[k]+1&&col==temp4[k])||(r==temp3[k]-1&&col==temp4[k])||(r==temp3[k]-1&&col==temp4[k]+1)||(r==temp3[k]-1&&col==temp4[k]-1)||(r==temp3[k]+1&&col==temp4[k]+1)||(r==temp3[k]+1&&col==temp4[k]-1)&&xturn>1)
                {
                    
                temp1[p]=r;
                temp2[p]=col;
                cout << "X " ;
                if ((win1[p]-win1[p-1]==1)||(win1[p-1]-win1[p-1]==1))
                {
                win1[t1]=col;
                t1++;
                }
              
                p++;
                l=1;
           break;
               }
            k++;}
            k=0;
           
           if (l==0){
           while (temp1[k]!='\0')
            {
               
               if ((r==temp1[k]&&col==temp2[k]+1)||(r==temp1[k]&&col==temp2[k]-1)||(r==temp1[k]+1&&col==temp2[k])||(r==temp1[k]-1&&col==temp2[k])||(r==temp1[k]-1&&col==temp2[k]+1)||(r==temp1[k]-1&&col==temp2[k]-1)||(r==temp1[k]+1&&col==temp2[k]+1)||(r==temp1[k]+1&&col==temp2[k]-1)&&(xturn>1)&&(l==0))
                {
                    
                temp1[p]=r;
                temp2[p]=col;
                cout << "X " ;
                if ((win1[p]-win1[p-1]==1)||(win1[p-1]-win1[p-1]==1))
                {
                win1[t1]=col;
                t1++;
                }
                p++;
                break;
                }
            k++;
            }
           }}
               
                else {
                   k=0;
                   u=0;
                      while (temp1[k]!='\0')
            { 
                          
                    if ((r==temp1[k]&&col==temp2[k]+1)||(r==temp1[k]&&col==temp2[k]-1)||(r==temp1[k]+1&&col==temp2[k])||(r==temp1[k]-1&&col==temp2[k])||(r==temp1[k]-1&&col==temp2[k]+1)||(r==temp1[k]-1&&col==temp2[k]-1)||(r==temp1[k]+1&&col==temp2[k]+1)||(r==temp1[k]+1&&col==temp2[k]-1))
                {
                       
                temp3[p1]=r;
                temp4[p1]=col;
                cout << "O ";
            
                p1++;
                u=1;
                break;
                    }
                    k++;
                      }
                   k=0;
                if (u==0)
                {
                    while (temp3[k]!='\0')
            { 
               if ((r==temp3[k]&&col==temp4[k]+1)||(r==temp3[k]&&col==temp4[k]-1)||(r==temp3[k]+1&&col==temp4[k])||(r==temp3[k]-1&&col==temp4[k])||(r==temp3[k]-1&&col==temp4[k]+1)||(r==temp3[k]-1&&col==temp4[k]-1)||(r==temp3[k]+1&&col==temp4[k]+1)||(r==temp3[k]+1&&col==temp4[k]-1))
                {
                temp3[p1]=r;
                temp4[p1]=col;
                cout << "O ";
                p1++;
                break;
               }
               k++;
                }
                }
                }
                
            }
            
            else if (r==0||r==6)
            {   if (col==0)
                cout << "  ";
            if(r==0 && col==1)
                cout << "  ";
            
            if(col>0)
                cout <<  col << " ";
            }
                
         else
           cout << ". " ;
            
             
      }
           
   }
    
        cout << endl;
        for (int i=0; i<p; i++){
     
     for (k=i+1;k<p;k++)
     {
          
         
      if (temp1[i]==temp1[k]){
      if((temp2[i] == temp2[k]-1)||((temp2[i] == temp2[k]+1))  )
      count++;}
      
      int y4=0;
      int y5=0;
      int y6=0;
      for (int rt=0; rt<p;rt++)
      {
     if (count == 3 && (temp2[rt]==1))
     {
          y4=1;
          break;
     }
     else 
         y4=0;
     }
            for (int ro=0; ro<p;ro++)
      {
     if (count == 3 && (temp2[ro]==2))
     {
          y5=1;
          break;
     }
     else 
         y5=0;
     }
        for (int rl=0; rl<p;rl++)
      {
     if (count == 3 && (temp2[rl]==3))
     {
          y6=1;
          break;
     }
     else 
         y6=0;
     }
      if (y4==1 && y5==1 && y6==1 && temp1[k]==1)
      {
          over=1;
      }
      
         if(count == 4)
      {
             over=1;
      }
         

         
  }
} 
            
         for (int i=0; i<p; i++){
             
     for (k=i+1;k<p;k++)
     { 
      if ((temp2[i]==temp2[k])) {
      if((temp1[i] == temp1[k]-1)||((temp1[i] == temp1[k]+1))  )
      count1++;
      }  
       
       int y7=0;
      int y8=0;
      int y9=0;
      for (int rt=0; rt<p;rt++)
      {
     if (count1 == 3 && (temp1[rt]==1))
     {
          y7=1;
          break;
     }
     else 
         y7=0;
     }
            for (int ro=0; ro<p;ro++)
      {
     if (count1 == 3 && (temp1[ro]==2))
     {
          y8=1;
          break;
     }
     else 
         y8=0;
     }
        for (int rl=0; rl<p;rl++)
      {
     if (count1 == 3 && (temp1[rl]==3))
     {
          y9=1;
          break;
     }
     else 
         y9=0;
     }
      if (y7==1 && y8==1 && y9==1&& temp2[k]==1)
          over=1;
      
      if(count1 == 4)
      over=1;
    
      
             }
         }
     
         for (int i=0; i<p; i++){
     
     for (k=i+1;k<p;k++)
     {
         
         if ((temp1[i]+1==temp1[k]) || (temp1[i]-1==temp1[k]) )   {
      if((temp2[i] == temp2[k]-1)||((temp2[i] == temp2[k]+1))  )
      count2++;}
         
      int y3=0;
      int y2=0;
      int y1=0;
      for (int rt=0; rt<p;rt++)
      {
     if (count2 == 3 && (temp1[rt]==1) && (temp2[rt]==1 ||temp2[rt]==2 || temp2[rt]==3))
     {        
         y3=1;
          break;
     }
     else 
         y3=0;
     }
            for (int ro=0; ro<p;ro++)
      {
     if (count2 == 3 && (temp1[ro]==2) && (temp2[ro]==1 ||temp2[ro]==2 || temp2[ro]==3))
     {
          y2=1;
          break;
     }
     else 
         y2=0;
     }
        for (int rl=0; rl<p;rl++)
      {
     if (count2 == 3 && (temp1[rl]==3) && (temp2[rl]==1 ||temp2[rl]==2 || temp2[rl]==3))
     {
          y1=1;
          break;
     }
     else 
         y1=0;
     }
      
      if (y1==1 && y2==1 && y3==1)
          over=1;
      
         if(count2 == 4)
      over=1;
         
   }}
        int cont = 1;
    int cont1=1;
    int cont2=1;
 for (int i=0; i<p1; i++){
     
     for (k=i+1;k<p1;k++)
     {
          
         
      if (temp3[i]==temp3[k]){
      if((temp4[i] == temp4[k]-1)||((temp4[i] == temp4[k]+1))  )
      cont++;}
      
      int x4=0;
      int x5=0;
      int x6=0;
      for (int rt=0; rt<p1;rt++)
      {
     if (cont == 3 && (temp4[rt]==1))
     {
          x4=1;
          break;
     }
     else 
         x4=0;
     }
            for (int ro=0; ro<p1;ro++)
      {
     if (cont == 3 && (temp4[ro]==2))
     {
          x5=1;
          break;
     }
     else 
         x5=0;
     }
        for (int rl=0; rl<p1;rl++)
      {
     if (cont == 3 && (temp4[rl]==3))
     {
          x6=1;
          break;
     }
     else 
         x6=0;
     }
      if (x4==1 && x5==1 && x6==1 && temp3[k]==1)
          over=1;
      
      
         if(cont == 4)
      over=1;
         

         
  }
} 
            
         for (int i=0; i<p1; i++){
             
     for (k=i+1;k<p1;k++)
     { 
      if ((temp4[i]==temp4[k])) {
      if((temp3[i] == temp3[k]-1)||((temp3[i] == temp3[k]+1))  )
      cont1++;
      }  
       
       int x7=0;
      int x8=0;
      int x9=0;
      for (int rt=0; rt<p1;rt++)
      {
     if (cont1 == 3 && (temp3[rt]==1))
     {
          x7=1;
          break;
     }
     else 
         x7=0;
     }
            for (int ro=0; ro<p1;ro++)
      {
     if (cont1 == 3 && (temp3[ro]==2))
     {
          x8=1;
          break;
     }
     else 
         x8=0;
     }
        for (int rl=0; rl<p1;rl++)
      {
     if (cont1 == 3 && (temp3[rl]==3))
     {
          x9=1;
          break;
     }
     else 
         x9=0;
     }
      if (x7==1 && x8==1 && x9==1&& temp4[k]==1)
          over=1;
      
      if(cont1 == 4)
      over=1;
    
      
             }
         }
     
         for (int i=0; i<p1; i++){
     
     for (k=i+1;k<p1;k++)
     {
         
         if ((temp3[i]+1==temp3[k]) || (temp3[i]-1==temp3[k]) )   {
      if((temp4[i] == temp4[k]-1)||((temp4[i] == temp4[k]+1))  )
      cont2++;}
         
      int x3=0;
      int x2=0;
      int x1=0;
      for (int rt=0; rt<p1;rt++)
      {
     if (cont2 == 3 && (temp3[rt]==1) && (temp4[rt]==1 ||temp4[rt]==2 || temp4[rt]==3))
     {
         x3=1;
          break;
     }
     else 
         x3=0;
     }
            for (int ro=0; ro<p1;ro++)
      {
     if (cont2 == 3 && (temp3[ro]==2) && (temp4[ro]==1 ||temp4[ro]==2 || temp4[ro]==3))
     {
          x2=1;
          break;
     }
     else 
         x2=0;
     }
        for (int rl=0; rl<p1;rl++)
      {
     if (cont2 == 3 && (temp3[rl]==3) && (temp4[rl]==1 ||temp4[rl]==2 || temp4[rl]==3))
     {
          x1=1;
          break;
     }
     else 
         x1=0;
     }
      if (x1==1 && x2==1 && x3==1)
          over=1;
      
         if(cont2 == 4)
      over=1;
         
         
     }}
    } 

    xturn++;
    turn=-turn;
    }
}

int charreturn(char n)
{
    if (n== 'a')
        return 1;
    if (n=='b')
        return 2;
    if (n=='c')
        return 3;
    if (n=='d')
        return 4;
    if (n=='e')
        return 5;
}