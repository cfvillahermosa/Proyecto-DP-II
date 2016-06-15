#include "lider.h"
#include "estacion.h"
/**
 * Constructor por defecto de mi clase lider
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Lider::Lider()
 : Miembro()
{
}

/**
 * Destructor de mi clase lider 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Lider::~Lider()
{
    set <Personaje*> :: iterator it = grupo.begin();
    while( it!=grupo.end()){
        delete *it;
        it++;
    }
}
/**
 * Metodo que muestra por pantalla el tipo de personaje que se trata, en este caso , es un lider
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Lider::mostrar()
{
    cout<<"estoy mostrando un lider"<<endl;
    Miembro::mostrar();
}



/**
 * Constructor parametrizado de mi clase lider
 * \param m es un caracter correspondiente a la marca de mi personaje de tipo lider
 * \param n es una cadena correspondiente al nombre de mi personaje del tipo lider
 * \param t es un entero correspondiente al turno de mi personaje del tipo lider
 * \param ids es un entero correspondiente al identificador de la sala de mi personaje del tipo lider
 * \param idp es un entero correspondiente al identificador de la planta de mi personaje del tipo lider
 * \param sec es una cadena que se corresponde con la secuencia de orientaciones que sigue mi personaje del tipo lider
 * \param mov es un caracter que se corresponde con el movimiento asociado a mi personaje del tipo lider
 * \return No retorna ningun valor
 */
Lider::Lider(char m, string n, int t, int ids, int idp, string sec, char mov): Miembro(m,n,t,ids,idp)
{
    this->secuenciaorientaciones=sec;
    this->movimiento=mov;
}

/**
 * Metodo que escribe en mi registro.log la informacion de mi personaje de tipo lider y además escribo la informacion correspondiente a los personajes que se encuentran en el atributo grupo
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void Lider::escribeLog(ofstream & f)
{

    f<<"(lider:";
    Miembro::escribeLog(f);
    
//!    aqui hago el log de cada miembro que hay en su grupo
    set <Personaje*> :: iterator it= grupo.begin();
    Personaje *per;
    while( it != grupo.end()){
        per=*it;
        per->escribeLog(f);
        it++;
    }
    
    
    
}
/**
 * Metodo que calcula la ruta de mi personaje de tipo lider
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void Lider::ruta(ofstream & f)
{
    stack <char> secorientaciones;
    stack <int> idsalas;
    set <int> vecinos;
    planta *aux;
    Estacion * e = Estacion :: obtenerMiEstacion();
    f<<"(ruta:"<<marca<<":";
    for(int i=e->totalPlantas()-1;i>=0;i--){
        e->obtenerPlanta(i,aux);
        setIdPlanta(i);
        setIdSala(aux->getSalaEntrada());
        vecinos.clear();
        if(recorrerVecinos(idsala,secorientaciones,idsalas,vecinos))
            escribeLogRuta(f,secorientaciones, idsalas); 
    }
    f<<")"<<endl;
    
    setIdPlanta(e->totalPlantas()-1);
    
    e->obtenerPlanta(idplanta,aux);
    setIdSala(aux->getSalaEntrada());
    
    secuencia.pop();
    
}

/**
 * Metodo que establece a mi atributo movimiento el valor de m
 * \param m es un parametro de entrada del tipo caracter que establece el movimiento de mi personaje de tipo lider
 * \return No retorna ningun valor
 */
void Lider::setMovimiento(char m)
{
    movimiento=m;
}
/**
 * Metodo que devuelve el caracter correspondiente al movimiento de mi personaje de tipo lider
 * \param "" no recibe parametros
 * \return Retorna un caracter que se corresponde con el movimiento asociado a mi personaje de tipo lider
 */
char Lider::getMovimiento()
{
    return movimiento;
}

/**
 * Metodo que asigna a mi atributo secuenciaorientaciones la cadena s
 * \param s es un parametro de entrada del tipo string 
 * \return No retorna ningun valor
 */
void Lider::setSecuenciaOrientaciones(string s)
{
    secuenciaorientaciones=s;
}

/**
 * Metodo que devuelve en s la cadena correspondiente a mi atributo secuenciaorientaciones
 * \param s es un parametro de entrada salida que almacena la cadena secuenciaorientaciones
 * \return No retorna ningun valor
 */
void Lider::getSecuenciaOrientaciones(string & s)
{
    s=secuenciaorientaciones;
}
/**
 * Metodo actualiza el movimiento de mi personaje de tipo lider
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Lider::actualizarMovimiento()
{
    if(movimiento==secuenciaorientaciones[3])
        movimiento=secuenciaorientaciones[0];
    else{
        if(movimiento==secuenciaorientaciones[0])
            movimiento=secuenciaorientaciones[1];
        else{
            if(movimiento==secuenciaorientaciones[1])
                movimiento=secuenciaorientaciones[2];
            else{
                if(movimiento==secuenciaorientaciones[2])
                    movimiento=secuenciaorientaciones[3];
            }
        }
    } 
}

/**
 * Metodo booleano que calcula los vecinos de mi personaje de tipo lider 
 * \param ids es un parametro de entrada del tipo entero correspondiente al identificador de la sala
 * \param secorientaciones es un parametro de entrada salida del tipo stack (pila) que almacena los caracteres correspondiente a la posicion cardinal de los vecinos que se van obteniendo
 * \param idsalas es un parametro de entrada salida del tipo stack(pila) que almacena los enteros correspondientes a los identificadores de las salas de los vecinos donde se mueve mi personaje de tipo lider
 * \param vecinos es un parametro de entrada salida del tipo set (conjunto)  de enteros que almacena los enteros correspondientes a los identificadores de las salas de los vecinos de mi personaje de tipo lider
 
 * \return Retorna true si el personaje del tipo lider alcanza la sala de salida de la planta y false en caso contrario
 */
bool Lider::recorrerVecinos(int ids, stack< char > & secorientaciones, stack< int > & idsalas, set <int> &vecinos)
{
    Estacion * e = Estacion :: obtenerMiEstacion();
    planta *aux;
    e->obtenerPlanta(this->getIdPlanta(),aux);
    sala *s1;
    sala *s2;
    aux->obtenerCeldaVector(ids,s1);
    bool fin=false;
    int i;
    idsalas.push(ids);
    
   // cout<<ids<<" ";
    
    
    if(ids==aux->getSalaSalida()){
        return true;
    }
    vecinos.insert(ids);
    for(int i=0; i<=3 && !fin;i++){
        actualizarMovimiento();
        s1->devolverCardinalVecino(movimiento,s2);
        if(s2!=NULL){
            ids=s2->getIdentificadorSala();
            if(!vecinos.count(ids) && ! fin){
                char m=movimiento;
                secorientaciones.push(movimiento);
                fin=recorrerVecinos(ids,secorientaciones,idsalas,vecinos);
                if(!fin){
              //      cout<<idsalas.top()<<" ";
                        idsalas.pop();
                        secorientaciones.pop();
                        movimiento=m;
                    }
                    
                }
                    
            }
        }
    
    return fin;
}
/**
 * Metodo que escribe en mi registro.log toda la informacion correspondiente a la ruta de mi personaje del tipo lider
 * \param f es un flujo de entrada salida
 * \param sec es un parametro de entrada salida del tipo stack(pila) de caracteres que almacena las posiciones cardinales del movimiento de mi personaje del tipo lider
 * \param idsalas es un parametro de entrada salida del tipo stack (pila) que almacena los enteros correspondientes a los identificadores de las salas donde se mueve mi personaje del tipo lider
 * \return No retorna ningun valor
 */
void Lider::escribeLogRuta(ofstream &f , stack< char > & sec,stack <int> &idsalas)
{
    
    
    stack <char> aux;
    stack <int> aux2;
    while(!idsalas.empty()){
        aux2.push(idsalas.top());
        idsalas.pop();
    }
    
    while(!aux2.empty()){
        secuencia.push(aux2.top());
        aux2.pop();
    }
    
    while(!sec.empty()){
       aux.push(sec.top());
       sec.pop();
    }
    while(!aux.empty()){
        f<<" "<<aux.top();
        aux.pop();
    }
   
}
/**
 * Metodo que realiza la accion uno del lider 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Lider::accionUno()
{
    Llave *l;
    planta *p;
    sala *s;
    puerta *puer;
    Estacion *e=Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);
    p->obtenerPuerta(puer);
    
    if(s->getIdentificadorSala() == p->getSalaSalida() && puer->getEstadoCerradura() != "abierta"){
       
        if(!pilaVacia()){
            cojerLlave(l);
            puer->abrir(l);
        }
        
        
    //! aqui pruebo con cada una de las llaves que llevan los miembros en el grupo (sólo con la 1ª de cada uno)
        set <Personaje*> :: iterator it= grupo.begin();
        Personaje *per;
        while( it!=grupo.end()){
            per=*it;
            if(!per->pilaVacia()){
                per->cojerLlave(l);
                if(puer->getEstadoCerradura() != "abierta") 
                    puer->abrir(l);
                }
            it++;
        }
        
    }
    

        
    
}
/**
 * Metodo realiza la accion dos del lider
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Lider::accionDos()
{
    sala *s;
    planta *p;
    Personaje *per;
    Estacion *e=Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    p->obtenerCeldaVector(idsala,s);
    puerta *puer;
    p->obtenerPuerta(puer);
   

    if(idsala != p->getSalaSalida()){
        idsala=secuencia.front();
        secuencia.pop();
    }
    else
    {
        if(puer->getEstadoCerradura() != "cerrada")
        {
            if(idplanta==0)
            {
                this->setIdSala(1111);
                e->insertarDesalojado(this);
                
                
         
                
                
                
            }
            else
            {
                idplanta--;
                
                idsala=secuencia.front();
                secuencia.pop();
            }
            
        }
    }
    
    
    //!Si estoy en la sala de salida y la puerta está cerrada NO me puedo mover      
    
    
}
/**
 * Metodo realiza la accion tres del lider
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Lider::accionTres()
{
    queue <Personaje*> *aux=new queue <Personaje*>;
    Personaje *per;
    planta *p;
    sala *s;
    bool enc=false;
    Estacion *e = Estacion :: obtenerMiEstacion();
    e->obtenerPlanta(idplanta,p);
    if(idsala!=1111){
        p->obtenerCeldaVector(idsala,s);
        if( s->siHayPersonajes()){
            while ( s->siHayPersonajes()){
                s->devolverPrimerPersonaje(per);
                if( typeid (Trabajador) == typeid(*per) && !enc){
                    grupo.insert(per);
                    enc=true;
                }
            else
                    aux->push(per);
            }
            while(! aux->empty()){
                s->insertarCola(aux->front());
                aux->pop();
            }
        }
    }
    
    
    
    delete aux;
    
}









