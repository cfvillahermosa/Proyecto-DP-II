/**
* \file grafo.h
* \brief Declaracion de la clase grafo
* \author
*   \b Profesores LPII \n
*   \b Asignatura Laboratorio de Programacion II \n
*   \b Curso 07/08 (revisado 08/09)
*/

#ifndef GRAFO_H
#define GRAFO_H

#define MAXVERT 200 
#define INFINITO 9999
#define NO_VALOR -1

#include <iostream>
#include <cstdlib>
#include <queue>
//MAXVERT  es el numero maximo de vertices que puede tener el grafo
using namespace std;

/*!
   \def DEPURAR
   Variable constante utilizada para mostrar o no mensajes de depuracion de programa
 */
#define DEPURAR 0

/*!
   \def DEPURAR_MSG
   Macro utilizada para mostrar mensajes de depuracion de programa y retener los mensajes en pantalla
 */
#define DEPURAR_MSG(msg) if (DEPURAR){ cout<<msg; cin.get();}

typedef int TipoNodoGrafo;
typedef int TipoArcoGrafo;
typedef TipoArcoGrafo TipoMatrizAdyacencia [MAXVERT][MAXVERT];
typedef TipoNodoGrafo TipoVectorNodos[MAXVERT];

// ---------------------------------------------------------

// Para calcular los adyacentes a un nodo
#include <set>
typedef set<TipoNodoGrafo> TipoCjtoNodos;


struct TipoArco{
	TipoArcoGrafo x;
	TipoArcoGrafo y;
};



/**
* \class Grafo
* \brief Esta clase define un grafo
*
*/
class Grafo
{
    int numNodos;              //!< Numero de nodos del grafo
    TipoVectorNodos nodos;          //!< Vector que almacena los nodos del grafo
    TipoMatrizAdyacencia arcos;    //!< Matriz de adyacencia, para almacenar los arcos del grafo

    TipoMatrizAdyacencia warshallC;    //!< Matriz de Camino (Warshall - Path)
    TipoMatrizAdyacencia floydC;//!< Matriz de Costes (Floyd - Cost)
    TipoMatrizAdyacencia floydP;//!< Matriz de Camino (Floyd - Path)

public:

    Grafo(void);
    inline int getNumNodos(void){ return numNodos; }
    bool esVacio(void);
    bool nuevoArco(TipoNodoGrafo origen, TipoNodoGrafo destino, int valor);
    bool borraArco(TipoNodoGrafo origen, TipoNodoGrafo destino);
    bool adyacente (TipoNodoGrafo origen, TipoNodoGrafo destino);
    int  getArco  (TipoNodoGrafo origen, TipoNodoGrafo destino);
    bool nuevoNodo(TipoNodoGrafo n);
    bool borraNodo(TipoNodoGrafo nodo);

    // ------- Metodos para mostrar
    void mostrarArcos(void);
    void mostrarNodos(void);
    void mostrarPW(void);
    void mostrarFloydC(void);
    
    // ------- Algoritmos sobre Grafos
    void warshall (void);
    void floyd (void);
    void siguiente(TipoNodoGrafo origen, TipoNodoGrafo destino, TipoNodoGrafo &sig);//
    void adyacentes(TipoNodoGrafo origen, TipoCjtoNodos &ady);//inserta en un conjunto todos sus adyacentes, para insertar en un conjunto la funcion "insert(dato)" y por si queremos borrar "erase(dato)"  también tenemos la funcion empty() que nos dice si esta vacia o no y la funcion size() que nos dice cuantos elementos tiene y la funcion count(dato) que nos dice si el elemento que le metemos por parentesis pertenece al conjunto
    
    //------- Métodos para recorrer el grafo
    void anchura(Grafo g, TipoNodoGrafo v,TipoCjtoNodos & visitados);
    void profundidad(Grafo g, TipoNodoGrafo v,TipoCjtoNodos & visitados);
    void prof(Grafo g, TipoNodoGrafo v,TipoCjtoNodos & visitados);
    void caminoMinimoEntero(TipoNodoGrafo origen,TipoNodoGrafo destino);
    bool vueltaAtras(Grafo g, TipoNodoGrafo v, TipoCjtoNodos & visitados);

    
};

#endif
