#ifndef MIEMBRO_H
#define MIEMBRO_H

#include <personaje.h>

/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class Miembro : public Personaje
{
public:
    Miembro();
    Miembro (char m, string n,int t,int ids,int idp);
    void mostrar();
    
    void accionCuatro ();
    ~Miembro();

};

#endif
