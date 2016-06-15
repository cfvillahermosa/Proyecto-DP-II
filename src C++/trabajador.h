#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <miembro.h>
#include <typeinfo>

/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class Trabajador : public Miembro
{
public:
    Trabajador();
    Trabajador(char m, string n,int t,int ids,int idp);
    void mostrar();
    void escribeLog(ofstream & f);
    void ruta(ofstream & f);
    void escribeLogRuta(ofstream & f);
    void accionUno();
    void accionDos();
    void accionTres();
    

    ~Trabajador();

};

#endif
