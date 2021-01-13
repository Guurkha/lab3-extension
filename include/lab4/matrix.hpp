#ifndef LAB4_HPP
#define LAB4_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <exception>

using namespace std;

class labmatrix
{
    private:
    vector< vector<double> > matrix;

    public:
    labmatrix(int size);
    labmatrix(int row, int col);
    void print();
    ~labmatrix();
    int row();
    int col();
    void set(int n, int m, double val) noexcept(false);
    double get(int n, int m) noexcept(false);
   //labmatrix add(labmatrix m2) noexcept(false);
    //labmatrix substract(labmatrix m2) noexcept(false);
    //labmatrix multiply(labmatrix m2) noexcept(false);
    bool store(string filename, string path) noexcept(false);
    labmatrix(string filename) noexcept(false);
    labmatrix operator + (labmatrix&);
    labmatrix operator - (labmatrix&);
    labmatrix operator * (labmatrix&);
    bool operator==(labmatrix&);
    vector<double> operator[](int a);
    friend ostream& operator << (ostream& os, labmatrix&);
    labmatrix* operator ++ (); //prefix incrementator
    labmatrix* operator -- (); //prefix decrementator 
    bool operator!=(labmatrix&);

};

class My_Exception_get : public exception
{
    virtual const char *what() const throw()
    {
        return "error in function get()";
    }
};

class My_Exception_set : public exception
{
    virtual const char *what() const throw()
    {
        return "error in function set()";
    }
};

class My_Exception_mathematical_operations : public exception
{
    virtual const char *what() const throw()
    {
        return "error in function with mathematical operations";
    }
};

class My_Exception_read_from_file : public exception
{
    virtual const char *what() const throw()
    {
        return "error folder doesnt exist or sth";
    }
};

class My_Exception_save_to_file : public exception
{
    virtual const char *what() const throw()
    {
        return "problem in saving";
    }
};
#endif