#include "../include/lab4/matrix.hpp"

labmatrix::labmatrix(int size)
{
        vector<double>row;
        for(int j = 0; j < size; j++)
        {
            row.push_back(0);
        }
        for(int i = 0; i < size; i++)
        {
        matrix.push_back(row);
        }
}


labmatrix::labmatrix(int a, int b)
{
        vector<double>row;
        for(int j = 0; j < a; j++)
        {
            for(int i = 0; i < b; i++)
            {
                row.push_back(0);    
            }
            matrix.push_back(row);
        }
        
}

int labmatrix::col()
{
    return matrix[0].size();
}

int labmatrix::row()
{
    return matrix.size();
}

labmatrix::~labmatrix()
{

}

void labmatrix::print()
{
    cout << "-----wypisanie----" << endl;
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            cout << setw(5);
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void labmatrix::set(int n, int m, double val) noexcept(false)
{
    if (n < row() && n >= 0 && m < col() && m >= 0)
		matrix[n][m] = val;
	else
		throw My_Exception_set();
    //matrix.at(n).at(m) = val;
}

double labmatrix::get(int n, int m) noexcept(false)
{
    if (n < row() && n >= 0 && m < col() && m >= 0)
		return this->matrix[n][m];
	else  
    {
    throw My_Exception_get();
    }
    //return matrix.at(n).at(m);

}

bool labmatrix::store(string filename, string path) noexcept(false)
{
    fstream mojplik;

    int a = row();
    int b = col();
    string full_file_name = path + filename;
    cout << full_file_name;
    mojplik.open(full_file_name, ios::out);
    
    if(mojplik.is_open())
    {
        mojplik << a << " " << b;
        mojplik << endl;
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                mojplik << matrix[i][j];
                mojplik << " ";
            }
            mojplik << endl;
        }
    }
    else
    {
        throw My_Exception_save_to_file();
    }
    
    return true;

}

labmatrix::labmatrix(string filename) noexcept(false)
{
    fstream mojplik;
    int a;
    int b;
    double val;
    vector<double>row;

    mojplik.open(filename, ios::in);

    if(mojplik.is_open())
    {
        mojplik >> a;
        mojplik >> b;
        for(int j = 0; j < a; j++)
        {
            for(int i = 0; i < b; i++)
            {
                mojplik >> val;
                row.push_back(val);
            }
            matrix.push_back(row);
            row.clear();
        }

    }
    else
    {
        throw My_Exception_read_from_file();
    }
    

    cout << "a to " << a << endl;
    cout << "b to " << b << endl;
    

}

labmatrix *labmatrix::operator+(labmatrix &add)
{
    int a = this->row();
    int b = this->col();
    if( ! (a == add.col() ) && (b == add.col() ) )
    {
        throw My_Exception_mathematical_operations();
    }
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            (matrix3.matrix)[i][j] = this->matrix[i][j] + (add.matrix)[i][j];
        }
    }
    return &matrix3;
}

labmatrix *labmatrix::operator-(labmatrix &add)
{
    int a = this->row();
    int b = this->col();
    if( ! (a == add.col() ) && (b == add.col() ) )
    {
        throw My_Exception_mathematical_operations();
    }
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            (matrix3.matrix)[i][j] = this->matrix[i][j] - (add.matrix)[i][j];
        }
    }
    return &matrix3;
}

labmatrix *labmatrix::operator*(labmatrix &add)
{
    int a = row();
    int b = col();
    if(!(a == this->row()))
    {
        throw My_Exception_mathematical_operations();
    }
    double value = 0;
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            value = 0;
            for(int k = 0; k < row(); k++)
            {
               value = value + this->matrix[i][k] * (add.matrix)[k][j];
            }
            (matrix3.matrix)[i][j] = value;
        }
    }
    return &matrix3;  
}

bool labmatrix::operator==(labmatrix &second)
{
    int a = row();
    int b = col();
    if(a != second.row() || b != second.col())
    {
        throw My_Exception_mathematical_operations();
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(this->get(i, j) != second.get(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

vector<double> labmatrix::operator[](int a)
{
    if(a >= this->row() || a < 0) 
    {
        throw My_Exception_mathematical_operations();
    } 
    else
    {
        return this->matrix[a];
    }
    
}

ostream& operator << (ostream& os, labmatrix& dt)
{
    int a = dt.row();
    int b = dt.col();
    os << a << " " << b << endl;
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            os << dt[i][j];
            os << " ";
        }
        os << endl;
    }
    return os;
}

labmatrix* labmatrix::operator++()
{
    for(int i = 0; i < this->row(); i++)
    {
        for(int j = 0; j < this->col(); j++)
        {
            this->set(i, j, (1+get(i,j)));
        }
    }
}

labmatrix* labmatrix::operator--()
{
    for(int i = 0; i < this->row(); i++)
    {
        for(int j = 0; j < this->col(); j++)
        {
            this->set(i, j, (get(i,j)-1));
        }
    }
}

bool labmatrix::operator!=(labmatrix &second)
{
    int a = row();
    int b = col();
    if(a != second.row() || b != second.col())
    {
        throw My_Exception_mathematical_operations();
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(this->get(i, j) == second.get(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

/*
labmatrix labmatrix::substract(labmatrix m2) noexcept(false)
{
    int a = row();
    int b = col();

    if( ! (a == m2.col() ) && (b == m2.col() ) )
    {
        throw My_Exception_mathematical_operations();
    }

    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            (matrix3.matrix)[i][j] = matrix[i][j] - (m2.matrix)[i][j];
        }
    }
    return matrix3;    
}

labmatrix labmatrix::multiply(labmatrix m2) noexcept(false)
{
    int a = row();
    int b = col();
    if(!(a == m2.row()))
    {
        throw My_Exception_mathematical_operations();
    }
    double value = 0;
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            value = 0;
            for(int k = 0; k < row(); k++)
            {
               value = value + matrix[i][k] * (m2.matrix)[k][j];
            }
            (matrix3.matrix)[i][j] = value;
        }
    }
    return matrix3;
}
*/
/*
labmatrix labmatrix::add(labmatrix m2) noexcept(false)
{
    int a = row();
    int b = col();
    if( ! (a == m2.col() ) && (b == m2.col() ) )
    {
        throw My_Exception_mathematical_operations();
    }
    labmatrix matrix3(a, b);
    for(int i = 0; i < row(); i++)
    {
        for(int j = 0; j < col(); j++)
        {
            (matrix3.matrix)[i][j] = matrix[i][j] + (m2.matrix)[i][j];
        }
    }
    return matrix3;
}
*/