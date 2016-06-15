#include "intruso.h"

#include "estacion.h"
/**
 * Constructor por defecto de mi clase intruso
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Intruso::Intruso()
 : Personaje()
{
}

/**
 * Destructor de mi clase intruso
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Intruso::~Intruso()
{
}
/**
 * Metodo mostrar (por pantalla) de mi clase intruso
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Intruso::mostrar()
{
    cout<<"estoy mostrando un intruso"<<endl;
    Personaje::mostrar();
    
}
/**
 * Constructor parametrizado de mi clase intruso
 * \param m es la marca de mi personaje de tipo intruso
 * \param n es la cadena asociada al nombre de mi personaje de tipo intruso
 * \param t es un entero asociado al turno del personaje del tipo intruso
 * \param ids es un entero asociado al identificador de la sala de mi personaje del tipo intruso
 * \param idp es un entero asociado al identificador de la planta de mi personaje del tipo intruso
 * \return No retorna ningun valor
 */
Intruso::Intruso(char m, string n, int t, int ids, int idp): Personaje (m,n,t,ids,idp)
{
    Estacion *e = Estacion :: obtenerMiEstacion();
    planta *p;
    e->obtenerPlanta(idplanta,p);
    for(int i=0;i<=p->getNLlaves();i++){
        if(i%2 == 1){
            Llave *l= new Llave(i);
            juegollaves->push(l);
        }        
    }
                
}

/**
 * Metodo que escribe la informacion correspondiente al intruso en mi registro.log
 * \param f es un flujo de entrada salida que escribe en mi fichero la informacion correspondiente al personaje de tipo intruso
 * \return No retorna ningun valor
 */
void Intruso::escribeLog(ofstream & f)
{

    f<<"(intruso:";
    Personaje::escribeLog(f);

}
/**
 * Metodo que calcula la ruta del personaje de tipo intruso y escribe en el registro.log su ruta correspondiente
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void Intruso::ruta(ofstream & f)
{
    Estacion * e = Estacion :: obtenerMiEstacion();
    planta *aux;
    
    e->obtenerPlanta(getIdPlanta(),aux);
    //movimiento de esquina inferior derecha a esquina inferior izquierda
    caminoMinimo(this->getIdSala(), ( this->getIdSala() - aux->getAnchoPlanta()+1),aux);
    
    caminoMinimo(this->getIdSala(), 0, aux);
    
    caminoMinimo(0, ( this->getIdSala() + aux->getAnchoPlanta()-1),aux);
    
    caminoMinimo(this->getIdSala(),aux->getAltoPlanta()*aux->getAnchoPlanta()-1, aux);
    escribeLogRuta(f);
    
}
/**
 * Metodo calcula el camino minimo entre 2 nodos de la planta que recibe como parametro (pl en este caso)
 * \param origen es un entero que se corresponde con el origen del grafo donde empieza mi camino
 * \param destino es un entero que se corresponde con el destino del grafo donde termina mi camino
 * \param pl es un puntero a un objeto de la clase Planta
 * \return No retorna ningun valor
 */
void Intruso::caminoMinimo(int origen, int destino, planta * pl)
{
    int i=-1;
    int aux=origen;
    
    while( i!= destino){
        pl->siguienteGrafo(aux,destino,i);
        this->setIdSala(i);
        secuencia.push(i);
        aux=i;
    }
}

/**
 * Metodo que escribe en mi registro.log la informacion correspondiente al personaje de tipo intruso
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void Intruso::escribeLogRuta(ofstream & f)
{
    Estacion *estacion = Estacion :: obtenerMiEstacion();
    planta *aux;
    estacion->obtenerPlanta(idplanta,aux);
    queue<int> aux2;
    
    int inicio=this->idsala;
    f<<"(ruta:"<<marca<<":";
    while( !secuencia.empty() ){
        if( inicio-1 == secuencia.front())
            f<<" O";
        if( inicio+1 == secuencia.front())
            f<<" E";
        if( inicio+aux->getAnchoPlanta() == secuencia.front() )
            f<<" S";
        if( inicio-aux->getAnchoPlanta() == secuencia.front() )
            f<<" N";
        inicio=secuencia.front();
        
        aux2.push(inicio);
        
        secuencia.pop();
    }
    
    while( !aux2.empty() ){
        inicio=aux2.front();
        secuencia.push(inicio);
        aux2.pop();
    }
    
    f<<")"<<endl;
}



/**
 * Metodo que realiza la accion uno del intruso 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Intruso::accionUno()
{
    sala *s;
    planta *p;
    puerta *puer;
    Estacion * e = Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);  
    if(s->getIdentificadorSala() == p->getSalaSalida()){
        //si no está ya abierta
        p->obtenerPuerta(puer);
        puer->cerrar();
    }
}
/**
 * Metodo que realiza la accion dos del intruso 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Intruso::accionDos()
{
    sala *s;
    planta *p;
    Estacion *e=Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);

    idsala=secuencia.front();
    secuencia.pop();
    secuencia.push(idsala);
}
/**
 * Metodo que realiza la accion cuatro del intruso 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Intruso::accionCuatro()
{
    sala *s;
    planta *p;
    Estacion *e=Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);

    if(!juegollaves->empty()){
        if(idsala % 2 == 0){
            s->insertarLista(juegollaves->top());
            juegollaves->pop();
        }
    }
}

/**
 * Metodo que realiza la accion tres del intruso 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Intruso::accionTres()
{
    queue <Personaje*> *aux= new queue <Personaje*>;
    Personaje *per;
    planta *p;
    bool enc=false;
    Estacion *e = Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    sala *s;
    p->obtenerCeldaVector(idsala,s);
    if(s->siHayPersonajes()){
    while( s->siHayPersonajes()){
        s->devolverPrimerPersonaje(per);
        if( typeid (Trabajador) == typeid (*per) && !enc ){
            e->insertarSalaPrisioneros(per);
            per->setIdSala(1101);
            enc=true;
            
        }
        else
            aux->push(per);
    }
    while(!aux->empty()){
        s->insertarCola(aux->front());
        aux->pop();
    }
    }
    
    delete aux;
}