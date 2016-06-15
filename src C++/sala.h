#ifndef SALA_H
#define SALA_H
#include <fstream>
#include "lista.h"
#include "llave.h"
#include "personaje.h"


/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class sala{
    int idsala;
    int marca;
    int frecuencia;
    Lista <Llave*> *lista;
    friend class compararFrecuencias;
    queue <Personaje*> *colapersonajes;
    vector <sala*> vecinos;
public:
    sala();
    sala(int id,int m,int f);
    void setIdentificadorSala(int id);
    int getIdentificadorSala();
    void setMarcaSala(int m);
    int getMarcaSala();
    void setFrecuenciaSala(int f);
    int getFrecuenciaSala();
    void escribeLog(ofstream & f);
    void mostrar();
    void insertarLista(Llave *l);
    void insertarCola(Personaje *p);
    void devolverPrimerPersonaje (Personaje *& per);
    void borrarElementoCola();
    bool siHayPersonajes();
    bool siHayLlaves();
    void escribeLogConEspacio(ofstream & f);
   
    int cuantosPersonajes();
    void devolverFrente(Personaje *& p);
    void calcularRutaPersonajeSala(ofstream & f);
    void volcarVectorVecinos (vector <sala*>  &v);
    //orden-> norte, sur, este, oeste
    void devolverCardinalVecino(char c, sala *& v);
    void devolverPimeroLista(Llave *& l);
    void accionesColaPersonajes();
     ~sala();

};

class compararFrecuencias{
    public:
    bool operator() (sala*s1,sala *s2){
        if( s1->getFrecuenciaSala() < s2->getFrecuenciaSala())
            return true;
        else{
            if( s1->getFrecuenciaSala() == s2->getFrecuenciaSala() ){
                if( s1->getIdentificadorSala() < s2->getIdentificadorSala()){
                    return false;
                }
                else
                    return true;
            }
            else
                return false;
                
        }
        
        
    }
};

#endif
