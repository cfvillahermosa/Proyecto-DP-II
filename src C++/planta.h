#ifndef PLANTA_H
#define PLANTA_H
#include <vector>
#include "puerta.h"
#include "sala.h"
#include "grafo.h"
#include "genaleatorios.h"
#include <fstream>
#include <list>
#include <iostream>
using namespace std;
/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class planta{
    vector <sala*> v;
    puerta *p;
    Grafo g;
    int idplanta;
    int salaentrada;
    int salasalida;
    int nllaves;
    int anchoplanta;
    int altoplanta;
public:
    planta();
    planta(int idp,int se, int ss, int nll, int anch,int alt);
    void setIdPlanta(int n);
    int getIdPlanta();
    void setSalaEntrada(int n);
    int getSalaEntrada();
    void setSalaSalida(int n);
    int getSalaSalida();
    void setNLlaves(int n);
    int getNLlaves();
    void setAnchoPlanta(int n);
    int getAnchoPlanta();
    void setAltoPlanta(int n);
    int getAltoPlanta();
    
    void calcularPosiblesVecinos(sala *s, list < TipoArco > & larcos);
    void vecinosTodasSalas(list < TipoArco >& larcos);
    
    void insertarVector(sala *s);
    void insertarNodoGrafo(TipoNodoGrafo n);
    void obtenerCeldaVector(int i, sala *& s);
    
    void algoritmoKruskal(list <TipoArco> & l);
    void pintarEstructura(ofstream & f);
    
    void generarAtajos();
    bool AtajoNorte(sala *s);
    bool AtajoSur(sala *s);
    bool AtajoOeste(sala *s);
    bool AtajoEste(sala *s);
    bool siHayAtajo(sala *s);
    
    void generarPlanta(ofstream & f);
    void repartoLlaves(ofstream & f);
    
    void establecerCondicionApertura(int ap);
    
    void salasMasFrecuentadas(TipoNodoGrafo v,TipoCjtoNodos  visitados);
    
    void insertarPersonajeSala(Personaje *p);
    
    int totalSalas();
    
    void pintarPersonajes(ofstream & f);
    
    void siguienteGrafo(int origen, int destino, int & sig);
    
    void calcularRutaSalasPlanta(ofstream & f);
    void calcularVecinosReales(sala *s);
    void calcularVecinosRealesTodasSalas();
    
    void obtenerPuerta(puerta *&puer);
    void accionesPersonajesSalas();
    void escribeLogPlanta(ofstream & f);
    
    
    

    ~planta();

};

#endif
