#include <iostream>
#include "Lexicon.h"
#include <string>
#include <fstream>
#include <cstring>

// Some of the methods have default values to allow the code to
// compile, you are expected to replace these values with actual
// implementations.

using namespace std;
//void getArrayofWords()

int wordcount(string a, string b)
{
    int d=1;
    int c=0;
    int temp;
    for (int i=0; i<a.size(); i++)
    {
        d=1;
        if(a[i]==b[0]&&((a[i-1]==' ')||i==0))
        {
            temp=i;
            for (int r=0; r<b.size(); r++)
            {
                if (r!=b.length()-1)
                {
                    if(a[temp]==b[r])
                        d=1;
                    else
                    {
                        break;
                    }
                    temp++;

                }

                else
                {
                    if(a[temp]==b[r]&&((a[temp+1]==' ')||(temp==a.size()-1 )) )

                        d=1;
                    else
                    {
                        break;
                    }

                    temp++;

                    c++ ;
                }

            }

        }
    }

    return c;
}

Lexicon::Lexicon(string &filename)
{
    ifstream file;
    //cout << filename;

    file.open((filename+".txt").c_str());
//cout << "to";
if (file.fail())
    cout << "yo";
    string text;
    while (getline(file,text))
    {

        cout << text;
        if (text.empty())
            break;
    }


    string temp="";
    string arr2[9999];
    int c=0;
    int d=0;
    bool n=1;
    int p=0;
    int i=0;
    for(i=0; i<text.size(); i++)
    {
      n=1;
//cout << "looping";
        if (text[i]!=' ')
            temp=temp+text[i];

        if ((text[i]==' '||(i==text.size()-1)))
        {

            for (p=i; p>=0; p--)
            {
                string t2=arr2[p];
                //cout <<t2<<"shit" << temp;
                if (t2==temp)
                {
                    //cout << "YO";
                    n=0;
                    break;
                }
            }
            if (n==1)
            {
            arr2[d]=temp.c_str();

            d++;
            }
            temp="";

        }

    }

cout << endl;
    for (int i=0; i<d; i++)
    {


        Map[i].c=wordcount(text,arr2[i]);
        Map[i].token=arr2[i];
    }


}




Lexicon::~Lexicon()
{
    delete []Map;
}

int Lexicon::count()
{
    int i=0;
    int temp=0;
    while (Map[i].c!='\0')
    {
        temp=temp+Map[i].c;
        i++;
    }

    return temp;
}

int Lexicon::count(string &token)
{
    int i=0;
    while (Map[i].c!='\0')
    {
        if (Map[i].token==token)
            return Map[i].c;
        i++;
    }


    return 0;
}

bool Lexicon::contains(string &token)
{
    int i=0;
    while (Map[i].c!='\0')
    {
        if (Map[i].token==token)
            return true;
        i++;
    }

    return false;
}

void Lexicon::increment(string &token)
{
    int i=0;
    while (Map[i].c!='\0')
    {
        if (Map[i].token==token)
            Map[i].c++;
    }

}
    void Lexicon::increment(string &token, int n)
    {
            int i=0;
    while (Map[i].c!='\0')
    {
        if (Map[i].token==token)
            Map[i].c=Map[i].c+n;
    }

    }

    void Lexicon::remove(string &token)
    {
    int i=0;
    while (Map[i].c!='\0')
    {
     if (Map[i].token==token)
     {
         Map[i].token="";
         Map[i].c=0;
     }
    i++;
    }
    }
    void Lexicon::printLexicographically(ostream &out)
    {
        int i=0;
    int max=0;
    int min=0;
    while (Map[i].c!='\0')
    {
        //int temp[999];
        int temp=Map[i].token[0];
        if (temp>max)
          max=temp;

        if (temp<min)
            min=temp;
        i++;

    }

    int d=0;
    for (i=min;i<=max;i++)
    {
        d=0;
    while (Map[d].c!='\0')
    {
        int temp = Map[d].token[0];
        if(temp==i)
        {
            cout << Map[d].token<<"  " << Map[d].c << endl;

        }
       d++;
    }

    }

    }
    void Lexicon::printCardinally(ostream &out)
    {


    int i=0;
    int max=0;
    while (Map[i].c!='\0')
    {
        if (Map[i].c>max)
            max=Map[i].c;
        i++;

    }

    int d=0;
    for (i=max;i>=0;i--)
    {
        d=0;
    while (Map[d].c!='\0')
    {
        if(Map[d].c==i)
        {
            cout << Map[d].token<<"  " << Map[d].c << endl;

        }
       d++;
    }

    }


    }


// Extra Credit - you do not need to modify this, but you can
// for extra credit.
    double Lexicon::distanceFrom(Lexicon &other, double (*scoringFunction)(int count1, int total1, int count2, int total2))
    {
        return 0.0;
    }


    int main()
    {
        string p="ahmer";
        Lexicon a(p);
        cout << endl << a.count();
        string cnt = "fox";
        //cout << endl << a.count(cnt);
        //a.remove(cnt);
        cout<< endl;
       a.printCardinally(cout) ;
    }
