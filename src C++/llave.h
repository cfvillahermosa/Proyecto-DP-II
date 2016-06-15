#ifndef LLAVE_H
#define LLAVE_H
#include <iostream>
#include <cstdlib>
using namespace std;

/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class Llave{
    int identificador;
public:
    Llave();
    void setIdentificador(int n);
    int getIdentificador();
    Llave(int n);
    int operator == (Llave & l);
    int operator < (Llave & l);
    int operator > (Llave & l);
    int operator !=(Llave & l);
    int operator <= (Llave &l);
    int operator >= (Llave & l);
    int operator ==(int n);
    int operator < (int n);
    int operator > (int n);
    int operator != (int n);
    int operator <= (int n);
    int operator >= (int n);
    friend ostream & operator << (ostream & f, Llave & l);
    Llave (const Llave & l);

    ~Llave();

};

#endif
