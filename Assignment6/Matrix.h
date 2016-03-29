#include <iostream>
#include <string>
#include "LinkedList.cpp"
using namespace std;

template <class T>
class Matrix
{
public:
    //Constructors
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, const T & initvalue);
    Matrix(const Matrix & m);

    //Member Functions
    Matrix transpose();
    Matrix minor_matrix(int row, int col);
    Matrix gauss_jordan();
    int rows();
    int cols();
    void swap_rows(int r1, int r2);
    void remove_row(int row);
    void remove_column(int col);
    Matrix<T> operator+( Matrix<T> &);
    Matrix<T> operator*(const T &) ;
    T myabs(const T &) const; // A portable absolute value.
    //template <class L>
    void print(const Matrix<T> &);


    int row;
    int col;
    LinkedList<T> valuerow[999];
    LinkedList<T> valuecol[999];

};

