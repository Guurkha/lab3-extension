#include "../include/lab4/matrix.hpp"

int main()
{
    srand((unsigned) time(0));
    //wczytanie i cdwyswietlenie rowów i columnusów
    int row;
    int col;

    cout << "podaj liczbe wierszy" << endl;
    cin >> row;
    cout << "podaj liczbe kolumn" << endl;
    cin >> col;
    //---------------proba konstruktorow----------------//

    //tworzenie matrixa z konstruktorem jedoargumentowym
    labmatrix macierz(row);
    //tworzenie matrixa z drugim konstruktorem
    labmatrix macierz2(row, col);
    labmatrix macierz3(row, col);


    
    //-----proba funkcji cols i rows-----------//
    cout << "kolumny to" << macierz2.col() << endl;
    cout << "wiersze to" << macierz2.row() << endl;

    //-------proba funkcji set i get---------//
    try
    {
    macierz2.set(1, 1, 3);
    macierz2.set(1, 0, 5);
    macierz2.set(0, 0, 2);
    macierz3.set(1, 1, 5);
    macierz3.set(1, 0, 3);
    macierz3.set(0, 0, 7);
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    try
    {
    int get = macierz2.get(1, 1);
    cout << "test funkcji get: " << get << endl;
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    

    //--------proba funkcji print----------//
    cout << "macierz 1:" << endl;
    macierz.print();
    cout << "macierz 2:" << endl;
    macierz2.print(); 
    cout << "macierz 3:" << endl;
    macierz3.print(); 

    //--------wypelnienie macierzy----//
    try{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < row; j++)
        {
        int result = 1 + (rand() % 30);
        macierz.set(i, j, result);
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
        int result = 1 + (rand() % 30);
        macierz2.set(i, j, result);
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
        int result = 1 + (rand() % 30);
        macierz3.set(i, j, result);
        }
    }
    }

    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    

    macierz.print();
    macierz2.print();
    macierz3.print();
        //z pliku
    try
    {
    labmatrix macierz4("C:\\Users\\proco\\cppprojects\\lab3\\plik.txt");
    macierz4.print(); 
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }


    //------add, subtract, multiply-------//
        //matrix dodawanie
    try{
    cout << "---------" << endl;
    cout << "dodawanie" << endl;
    macierz2 = macierz2.add(macierz3);
    macierz2.print();
        //matrix odejmowanie
    cout << "---------" << endl;
    cout << "odejmowanie" << endl;
    macierz2 = macierz2.substract(macierz3);
    macierz2.print();
        //matrix mnozenie
    cout << "---------" << endl;
    cout << "mnozenie" << endl;
    macierz2 = macierz2.multiply(macierz3);
    macierz2.print();
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    

    //--------test  funkcji store-------//
    try
    {
    macierz2.store("plik.txt", "C:\\Users\\proco\\cppprojects\\lab3\\");
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    
    return 0;
}
