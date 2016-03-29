#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    int i=0;
    int r=0;
    int c=0;
    int n=0;
   
   char re='y';
   int temp1=0;
   int temp2=0;
   int const1=0;
   int const2=0;
   
    
    char arr1[999][999]={};
    char word[256];


    ifstream file("puzzle.txt");

      for (c=0;c<999;c++)
    {
        file >> arr1[0][c];
        if (arr1[0][c]=='\0')
            break;
    }
    
    n = sqrt(c);
   
    char arr[n][n];
    
    ifstream file1("puzzle.txt");
    for (r=0;r<n;r++)
    {
        c=0;
        for(c=0;c<n;c++)
        {
          file1 >> arr[r][c];
          
          }
                
        }

    
    while (re=='y'||re=='Y')
    {
    cout << "Enter the word you want to find: ";
    cin >> word;
    int len=0;
    int p=0;
    int t=0;
    int res=0;
    int up=0;
    int down=0;
    int left =0;
    int right=0;
    
    while (word[len] != '\0' )
        len++;
    
    for (i=0;i<n;i++)
    {
        c=0;
        
        for(c=0;c<n;c++)
        {
	 
            if (arr[i][c] == word[0])
            {
		 temp1 = i;
		 temp2 = c;
	
                for (t=0;t<len;t++)
                {    
                    if (arr[i][c] == word[t])
                    {     
                        res=1;}
  
                    
                    else 
		{
                        res=0;
			
			break;
			}

			i++;
                }
                 if(res==1)
                 {
                     up=1;
                     break;
                 }
                 i=temp1;
                 c=temp2;
                           for (t=0;t<len;t++)
                {
                    if (arr[i][c] == word[t])
                    {     
                        res=1;}
  
                    
                    else 
		{
                        res=0;
			
			break;
			}

			i--;
                }
                 if(res==1)
                 {
                     down=1;
                     break;
                 }
                     
                 
                 i=temp1;
                 c=temp2;
                
                for (t=0;t<len;t++)
                {
                    if (arr[i][c] == word[t])
                    {     
                        res=1;}
  
                    
                    else 
		{
                        res=0;
			
			break;
			}

			c++;
                }
                 if(res==1)
                 {  
                     right=1;
                     break;
                 }
                 i=temp1;
                 c=temp2;
                for (t=0;t<len;t++)
                {
                    if (arr[i][c] == word[t])
                    {     
                        res=1;}
  
                    
                    else 
		{
                        res=0;
			
			break;
			}

			c--;
                }
                 if(res==1)
                 {
                     left=1;
                     break;
                 }
                 i=temp1;
                 c=temp2;
                }
			if (res==1)
			break;
		
              	}
		
		
		if (res==1)
			break;
            }
		
		
		if (res == 1)
               {
                if (up==1)
                    cout << "Found at location " << temp1 << "," << temp2 << " at downward direction" << endl;            
                if(down==1)
                    cout << "Found at location " << temp1 << "," << temp2 << " at upward direction" << endl;
                if(right==1)
                    cout << "Found at location " << temp1 << "," << temp2 << " at rightward direction" << endl;
                if(left==1)
                    cout << "Found at location " << temp1 << "," << temp2 << " at leftward direction" << endl;

                }  
                    else 
                    cout << "Word not found"<<endl; 
                    
                cout << "Do you want to continue searching: ";
                cin >> re;
                
                if (re== 'n' || re=='N')
                    cout << "Good Bye";
}
                        
}    


