#include "puerta.h"
/**
 * Constructor por defecto de mi clase Puerta
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
puerta::puerta()
{
    arbolCerradura=NULL;
    arbolLlavesProbadas=NULL;
    lcs=new Lista<Llave*>;
    estadoCerradura="no_configurada";
    alturaMaxima=-1;
}

/**
 * Destructor de mi clase Puerta
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
puerta::~puerta()
{
    eliminarlista(lcs);
    delete lcs;
    liberarArbol(arbolLlavesProbadas);
    delete arbolLlavesProbadas;
    delete arbolCerradura;
}
/**
 * Constructor parametrizado de mi clase Puerta
 * \param ec es un parametro de entrada del tipo string asociado al atributo estadoCerradura de mi clase Puerta
 * \param alt es un parametro de entrada del tipo entero asociado al atributo alturaMaxima de mi clase Puerta
 * \return No retorna ningun valor
 */
puerta::puerta(string  ec, int  alt)
{
    estadoCerradura=ec;
    alturaMaxima=alt;
}
/**
 * Metodo que me devuelve el valor de mi atributo alturaMaxima de mi clase Puerta
 * \param "" no recibe parametros
 * \return Retorna el valor asociado al atributo alturaMaxima de mi clase Puerta
 */
int puerta::getAlturaMaxima()
{
    return alturaMaxima;
}
/**
 * Metodo que establece el valor a al atributo alturaMaxima de mi clase Puerta
 * \param a es un parametro de entrada del tipo entero asociado al valor del atributo alturaMaxima de mi clase Puerta
 * \return No retorna ningun valor
 */
void puerta::setAlturaMaxima(int a)
{
    alturaMaxima=a;
}
/**
 * Metodo que establece el valor del atributo estadoCerradura de mi clase Puerta
 * \param e es un parametro de entrada del tipo string asociado al atributo estadoCerradura de mi clase Puerta
 * \return No retorna ningun valor
 */
void puerta::setEstadoCerradura(string e)
{
    estadoCerradura=e;
}
/**
 * Metodo que devuelve el string asociado al valor del atributo estadoCerradura de mi clase Puerta
 * \param "" no recibe parametros
 * \return Retorna el string asociado al atributo estadoCerradura de mi clase Puerta
 */
string puerta::getEstadoCerradura()
{
    return estadoCerradura;
}
/**
 * Metodo que configura la puerta insertando todas las llaves de mi lista de llaves de forma ordenada
 * \param l es un parametro de entrada del tipo puntero a instancia de mi clase lista que contiene punteros a instancias de mi clase Llave
 * \return No retorna ningun valor
 */
void puerta::configurarPuerta(Lista < Llave * > * l)
{
    l->moverInicio();
    while(!l->finLista()){
        lcs->insertarOrdenado(l->consultar());
        l->avanzar();
    }
}
/**
 * Metodo que cierra mi puerta
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void puerta::cerrar()
{
        setEstadoCerradura("cerrada");
        liberarArbol(arbolLlavesProbadas);
        delete arbolLlavesProbadas;
        delete arbolCerradura;
        arbolLlavesProbadas=new Arbol<Llave*>();
        arbolCerradura=new Arbol<Llave*>();
        lcs->moverInicio();
        while(!lcs->finLista()){
            arbolCerradura->insertar(lcs->consultar());
            lcs->avanzar();
            
        }
        arbolCerradura=arbolCerradura->balancear();
        
}
//(arbolCerradura->numNodosNoHojas() >= arbolCerradura->numHojas())  && ( //arbolCerradura->altura() < alturaMaxima )
/**
 * Metodo booleano que se encarga de probar una llave l para comprobar si puede abrise o no mi puerta
 * \param l es un parametro de entrada del tipo puntero a instancia de mi clase Llave
 * \return Retorna true en caso de que la llave probada sea valida para abrir mi puerta y false en caso contrario
 */
bool puerta::abrir(Llave * l)
{
    if(getEstadoCerradura()!="abierta"){
        if(!arbolLlavesProbadas->insertar(l)){
            delete l;
            return false;
        }
        else{
            if(arbolCerradura->pertenece(l)){
                arbolCerradura->borrar(l);
                arbolCerradura=arbolCerradura->balancear();
                if( (arbolCerradura->numNodosNoHojas() >= arbolCerradura->numHojas())  && ( arbolCerradura->altura() < alturaMaxima ) ){
                    setEstadoCerradura("abierta");
                    return true;
                    
                }
                else
                    return false;
            
            }
            else
                return false; 
        }

    }
    return true;
}
/**
 * Metodo booleano que me indica si la llave l ha sido probada para abrir mi puerta
 * \param l es un parametro de entrada del tipo puntero a instancia de mi clase Llave
 * \return Retorna true en caso de que la llave l haya sido probada y false en caso contrario
 */
bool puerta::siEstaLlaveProbada(Llave * l)
{
    if(arbolLlavesProbadas->pertenece(l))
        return true;
    else
        return false;
}
/**
 * Metodo que se encarga de liberar la memoria de mi arbol de llaves arbol
 * \param arbol es un parametro de entrada salida del tipo puntero a instancia de la clase arbol
 * \return No retorna ningun valor
 */
void puerta:: liberarArbol (Arbol <Llave*>  *& arbol){
    Arbol<Llave*> *aux;
    if (arbol!=NULL && !arbol->vacio())
    {
        if (aux = arbol->hijoIzq())
            liberarArbol(aux);
        delete arbol->raiz();
        if (aux = arbol->hijoDer())
            liberarArbol(aux);
        
    }
}
/**
 * Metodo que elimina de la lista de llaves la llave l 
 * \param l es un parametro de entrada salida del tipo puntero a instancia de la clase llave que corresponde con la llave que se quiere eliminar de la lista
 * \return No retorna ningun valor
 */
void puerta::eliminarlista(Lista <Llave*> * & l){
    l->moverInicio();
    while(!l->finLista()){
        
        delete l->consultar();
        
        l->avanzar();
    }   
}
/**
 * Sobrecarga del operador "<<" de mi clase Puerta
 * \param f es un flujo de entrada salida
 * \param p es un parametro de entrada salida de mi clase Puerta
 * \return No retorna ningun valor
 */
ostream & operator << (ostream & f, puerta & p){
    f<<"el estado de la puerta es: "<<p.getEstadoCerradura()<<endl;
    return f;
}

/**
 * Metodo que se encarga de escribir en mi registro.log la informacion contenida en la puerta
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void puerta::escribirFichero(ofstream & f)
{
        f<<"(puerta:"<<getEstadoCerradura()<<":"<<alturaMaxima<<":";
        escribirInordenLlaves(f,arbolLlavesProbadas);
        f<<")"<<endl;
        
}
/**
 * Metodo que se encarga de escribir en mi registro.log de forma ordenada las llaves contenidas en el parametro arbol
 * \param f es un flujo de entrada salida
 * \param arbol es un parametro de entrada salida del tipo puntero a instancia de mi clase arbol que contiene las llaves de mi clase puerta
 * \return No retorna ningun valor
 */
void puerta::escribirInordenLlaves(ofstream & f,Arbol <Llave*> *& arbol)
{
    Arbol<Llave*> *aux;
    if (!arbol->vacio())
    {
        if (aux = arbol->hijoIzq())
            escribirInordenLlaves(f,aux);
        f<<" "<< arbol->raiz()->getIdentificador();
        if (aux = arbol->hijoDer())
            escribirInordenLlaves(f,aux);
    }
}





