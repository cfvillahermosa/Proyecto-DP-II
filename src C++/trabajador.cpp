#include "trabajador.h"
#include "estacion.h"
/**
 * Constructor por defecto de mi clase trabajador
 * \param "" no recibe parametros
 * \return no retorna ningun valor
 */
Trabajador::Trabajador()
 : Miembro()
{
}

/**
 * Destructor de mi clase Trabajador
 * \param "" no recibe parametros
 * \return no retorna ningun valor
 */
Trabajador::~Trabajador()
{
}
/**
 * Metodo que muestra por pantalla el tipo de personaje del cual se trata, en este caso, trabajador
 * \param "" no recibe parametros
 * \return no retorna ningun valor
 */
void Trabajador::mostrar()
{
    cout<<"estoy mostrando un trabajador"<<endl;
    Miembro::mostrar();
}



/**
 * Constructor parametrizado de mi clase Trabajador
 * \param m es un parametro de entrada del tipo char asociado al atributo marca de mi clase Personaje
 * \param n es un parametro de entrada del tipo string asociado al atributo Nombre de mi clase Personaje
 * \param t es un parametro de entrada del tipo entero asociado al atributo turno de mi clase Personaje
 * \param ids es un parametro de entrada del tipo entero asociado al atributo idsala de mi clase Personaje
 * \param idp es un parametro de entrada del tipo entero asociado al atributo idplanta de mi clase Personaje
 * \return no retorna ningun valor
 */
Trabajador::Trabajador(char m, string n, int t, int ids, int idp): Miembro(m,n,t,ids,idp)
{
    
}
/**
 * Metodo que escribe en mi registro.log la informacion correspondiente al trabajador
 * \param f es un flujo de entrada salida
 * \return no retorna ningun valor
 */
void Trabajador::escribeLog(ofstream & f)
{
    f<<"(trabajador:";
    Miembro::escribeLog(f);
}
/**
 * Metodo que escribe en mi registro.log la informacion correspondiente a la ruta del trabajador
 * \param f es un flujo de entrada salida
 * \return no retorna ningun valor
 */
void Trabajador::escribeLogRuta(ofstream & f)
{
    f<<"(ruta:"<<getMarca()<<":)"<<endl;
}
/**
 * Metodo que llama al escribelogRuta de mi clase Trabajador
 * \param f es un flujo de entrada salida
 * \return no retorna ningun valor
 */
void Trabajador::ruta(ofstream & f)
{
    escribeLogRuta(f);
}
/**
 * Metodo realiza la accion uno correspondiente al trabajador
 * \param "" no recibe parametros
 * \return no retorna ningun valor
 */
void Trabajador::accionUno()
{
    Llave *l;
    planta *p;
    sala *s;
    puerta *puer;
    Estacion *e=Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);
    if(s->getIdentificadorSala() == p->getSalaSalida()){
        l=juegollaves->top();
        p->obtenerPuerta(puer);
        puer->abrir(l);
        juegollaves->pop();
    }
}
/**
 * Metodo realiza la accion dos correspondiente al trabajador
 * \param "" no recibe parametros
 * \return no retorna ningun valor
 */
void Trabajador::accionDos()
{
    planta *p;
    sala *s;
    sala *aux=NULL;
    Estacion * e = Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);
    bool puede=false;
    while(!puede){
        
        char c;
        int naleatorio = GenAleatorios::generarNumero(4);
        if(naleatorio == 0)
            c='N';
        if(naleatorio == 1)
            c='E';
        if(naleatorio == 2)
            c='S';
        if(naleatorio == 3)
            c='O';
        s->devolverCardinalVecino(c,aux);
        if( aux != NULL)
            puede= true;
    }
    
    idsala=aux->getIdentificadorSala();
}

/**
 * Metodo realiza la accion tres correspondiente al trabajador
 * \param "" no recibe parametros
 * \return no retorna ningun valor
 */
void Trabajador::accionTres()
{
    queue <Personaje*> *aux=new queue <Personaje*>;
    Personaje *per;
    planta *p;
    sala *s;
    Llave *l;
    bool enc=false;
    Estacion *e = Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);
    if( s->siHayPersonajes() ){
        while ( s->siHayPersonajes() ){
            s->devolverPrimerPersonaje(per);
            if(typeid (Intruso) == typeid (*per) && !enc){
                enc=true;
                if(!per->pilaVacia()){
                    per->cojerLlave(l);
                    juegollaves->push(l);
                }
            }
            
            aux->push(per);
        }
        while( !aux->empty() ){
            s->insertarCola(aux->front());
            aux->pop();
        }
    }
    delete aux;
    
}