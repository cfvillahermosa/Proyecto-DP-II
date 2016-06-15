#include "miembro.h"
#include "estacion.h"
/**
 * Constructor por defecto de mi clase Miembro
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Miembro::Miembro()
 : Personaje()
{
}

/**
 * Destructor de mi clase Miembro
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Miembro::~Miembro()
{
}
/**
 * Metodo que muestra por pantalla que el personaje es de tipo miembro
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Miembro::mostrar()
{
    cout<<"estoy mostrando un miembro"<<endl;
    Personaje :: mostrar();
}
/**
 * Metodo que realiza la accion cuatro de la clase miembro (lider y trabajador)
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Miembro::accionCuatro()
{
    Llave *l;
    sala *s;
    planta *p;
    Estacion *e = Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    if(idsala!=1111){
        p->obtenerCeldaVector(idsala,s);
        if(s->siHayLlaves()){
            s->devolverPimeroLista(l);
            juegollaves->push(l);
        }
    }
        
}

/**
 * Constructor parametrizado de mi clase miembro
 * \param m es un parametro de entrada del tipo char correspondiente al atributo movimiento de mi clase Personaje
 * \param n es un parametro de entrada del tipo string correspondiente al atributo nombre de mi clase Personaje
 * \param t es un parametro de entrada del tipo entero correspondiente al atributo turno de mi clase Personaje
 * \param ids es un parametro de entrada del tipo entero correspondiente al atributo idsala de mi clase Personaje
 * \param idp es un parametro de entrada del tipo entero correspondiente al atributo idplanta de mi clase Personaje
 * \return No retorna ningun valor
 */
Miembro::Miembro(char m, string n, int t, int ids, int idp): Personaje(m,n,t,ids,idp)
{
    
}
