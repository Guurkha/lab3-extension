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
    //------------------------------


    cout << "macierz 1:" << endl;
    macierz.print();
    cout << "macierz 2:" << endl;
    macierz2.print();
    cout << "macierz 3:" << endl;
    macierz3.print();
 


    //----------------------add, subtract, multiply-------//

        //matrix dodawanie - test operatora
    try{
    cout << "---------" << endl;
    cout << "dodawanie" << endl;
    labmatrix added = macierz2 + macierz3;
    added.print();
    //-------------------------------
        //matrix odejmowanie - test operatora
    cout << "---------" << endl;
    cout << "odejmowanie" << endl;
    labmatrix subbed = macierz2 - macierz3;
    subbed.print();
    //---------------------------------
        //matrix mnozenie - test operatora
    cout << "---------" << endl;
    cout << "mnozenie" << endl;
    labmatrix multiplied = macierz2 * macierz3;
    multiplied.print();
    //---------
    

        //test operatora ==
    if(macierz == macierz2)
        //----------------
        cout << "macierze sa takie same" << endl;
        //test operatora !=
    if(macierz != macierz2)
        //----------------
        cout << "macierze nie sa takie same" << endl;
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    //-------------------------
    

    //--------operator []
    try
    {
    vector<double> temp;
    temp = macierz2[1];
    for(int i = 0; i < macierz2.col(); i++)
    {
        cout << temp[i] << "  ";
    }
    cout << endl;
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    //--------proba operatora << -------------
    cout << "wypisanie macierzy 2 z operatorem" << endl;
    cout << macierz2;
    //-------------------------------------
    //--------proba operatora ++ ----------
    cout << "proba ++" << endl;
    ++macierz2;
    macierz2.print();
    //-------------------------------------
    //--------proba operatora -- ----------
    cout << "proba --" << endl;
    --macierz2;
    macierz2.print();
    //-------------------------------------


    return 0;
}



    /*
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
    cout << "proba" << endl;

        //--------test  funkcji store-------//
    try
    {
    macierz2.store("plik.txt", "C:\\Users\\proco\\cppprojects\\lab3\\");
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

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

*/