#include "Matrix.h"
#include <string>


template <class T>
Matrix<T>::Matrix(int rows, int cols) : row(rows),col(cols)
{
    for(int i=0;i<rows;i++)
    {
      for(int r=0;r<cols;r++)
      {
        valuerow[i].insertAt(r,0);
    }
    }

}

template <class T>
Matrix<T>::Matrix(int rows, int cols, const T & initvalue) : row(rows),col(cols)
{
    for(int i=0;i<rows;i++)
    {
      for(int r=0;r<cols;r++)
      {
        valuerow[i].insertAt(r,initvalue);

      }
    }

    for (int i=0;i<cols;i++)
    {
          for(int r=0;r<rows;r++)
      {
        valuecol[i].insertAt(r,initvalue);

      }

    }
}


template <class T>
Matrix<T>::Matrix(const Matrix & m):row(m.row),col(m.col)
{
    for(int i=0;i<row;i++)
    {
        valuerow[i]=m.valuerow[i];
    }

    for (int i=0;i<col;i++)
    {
        valuecol[i]=m.valuecol[i];
    }

}


template <class T>
Matrix<T> Matrix<T>::transpose()
{
    int t1=col;
    int t2=row;
    Matrix<T> res(t1,t2);


    for (int i=0;i<res.row;i++)
        res.valuerow[i]=valuecol[i];

    for (int i=0;i<res.col;i++)
        res.valuecol[i]=valuerow[i];

    return res;
}


template <class T>
int Matrix<T>::rows()
{
    return row;
}

template <class T>
int Matrix<T>::cols()
{
    return col;
}

template <class T>
Matrix<T> Matrix<T>::operator+( Matrix<T>& m)
{
    Matrix res(row,col);

    for (int i=0;i<row;i++)
    {
    res.valuerow[i]=valuerow[i]+m.valuerow[i];
    }

    for (int i=0;i<col;i++)
    {
       res.valuecol[i]=valuecol[i]+m.valuecol[i];
    }

    return res;
}

template<class T>
void Matrix<T>::swap_rows(int r1, int r2)
{
   int counter=1;
   bool a=0;
   int pos;
   LinkedList<T> temp;
    for(int i=0;i<row;i++)
    {
        if ((counter == r1||counter == r2)&&a==0)
        {
            a=1;
            temp=valuerow[i];
            valuerow[i].~LinkedList();
            pos=i;
        }

        if ((counter == r1||counter == r2)&&a==1)
        {
        valuerow[pos]=valuerow[i];
        valuerow[i]=temp;
        }
      counter++;
   }


}

template <class T>
void Matrix<T>::print(const Matrix<T> & m)
{
    for (int i=0;i<m.row;i++)
    {
     valuerow[i].printList();
     cout << endl;
    }


}


