#ifndef PUERTA_H
#define PUERTA_H
#include "arbol.h"
#include "lista.h"
#include "llave.h"
#include <fstream>

/**
	@author Carlos Fernández Villahermosa <cfernandnv@alumnos.unex.es>
*/
class puerta{
    Arbol <Llave*> *arbolCerradura,*arbolLlavesProbadas;
    Lista <Llave*> *lcs;
    string estadoCerradura;
    int alturaMaxima;   
public:
    puerta();
    puerta(string  ec, int  alt);
    int getAlturaMaxima();
    void setAlturaMaxima(int a);
    void setEstadoCerradura(string e);
    string getEstadoCerradura();
    void configurarPuerta(Lista <Llave*> *l);
    void cerrar();
    bool abrir(Llave *l);
    bool siEstaLlaveProbada(Llave * l);
    friend ostream & operator << (ostream & f, puerta & p);
    void liberarArbol (Arbol <Llave*>  *& arbol);
    void eliminarlista(Lista <Llave*> *& l);
    void escribirFichero(ofstream & f);
    void escribirInordenLlaves(ofstream & f,Arbol <Llave*> *& a);

    ~puerta();

};

#endif
