#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include "llave.h"


using namespace std;

/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class Personaje{
    protected:
    char marca;
    string nombre;
    int turno;
    int idsala;
    int idplanta;
    queue <int> secuencia;
    stack <Llave*> *juegollaves;
    
public:
    Personaje();
    Personaje ( char m, string n,int t, int ids, int idp );
    void setMarca(char m);
    char getMarca();
    void setNombre(string n);
    void getNombre(string & n);
    void setTurno(int t);
    int getTurno();
    void setIdSala(int ids);
    int getIdSala();
    void setIdPlanta(int idp);
    int getIdPlanta();
    
    void liberarMemoriaPila(stack <Llave*> *&lis);
    void insertarPila(Llave *l);
    void cojerLlave(Llave *&l);
    bool pilaVacia ();
    
    void insertarCola(int i);
    //sobrecargas == ,<,>,<=,>=
    void TodasAcciones();
    virtual void accionUno();
    virtual void accionDos();
    virtual void accionTres();
    virtual void accionCuatro();
    
    
    virtual void ruta (ofstream & f);
    virtual void escribeLog(ofstream & f);
    virtual void mostrar();
    virtual ~Personaje();
    
    int operator == (Personaje & p);
    int operator > (Personaje & p);
    int operator < (Personaje & p);
    int operator >= (Personaje & p);
    int operator <= (Personaje & p);
    int operator != (Personaje & p);

};

#endif
