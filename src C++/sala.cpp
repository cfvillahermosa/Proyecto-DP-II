#include "sala.h"

/**
 * Constructor por defecto de mi clase sala
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
sala::sala()
{
        idsala=-1;
        marca=-1;
        frecuencia=0;
	lista=new Lista<Llave*>;
        colapersonajes= new queue <Personaje*>;
}

/**
 * Destructor de mi clase sala
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
sala::~sala()
{
    lista->moverInicio();
    while(!lista->finLista()){
        delete lista->consultar();
        lista->avanzar();
    }
delete lista;
        while(!colapersonajes->empty()){
            delete colapersonajes->front();
            colapersonajes->pop();
        }
        delete colapersonajes;                    
}

/**
 * Metodo que establece el valor de id a mi atributo idsala de mi clase sala
 * \param id es un parametro de entrada del tipo entero asociado al valor del atributo idsala de mi clase Sala
 * \return No retorna ningun valor
 */
void sala::setIdentificadorSala ( int id )
{
	idsala=id;
}
/**
 * Metodo que devuelve el valor entero de mi atributo idsala de mi clase sala
 * \param "" no recibe parametros
 * \return retorna el valor entero correspondiente al atributo idsala de mi clase sala
 */
int sala::getIdentificadorSala()
{
	return idsala;
}
/**
 * Metodo que establece el valor de m a mi atributo marca de mi clase sala
 * \param m es un parametro de entrada del tipo int asociado al valor del atributo marca de mi clase Sala
 * \return No retorna ningun valor
 */
void sala::setMarcaSala ( int m )
{
	marca=m;
}
/**
 * Metodo que devuelve el valor del atributo marca de mi clase Sala
 * \param "" no recibe parametros
 * \return Retorna el entero asociado al atributo marca de mi clase sala
 */
int sala::getMarcaSala()
{
	return marca;
}
/**
 * Metodo que establece el valor de f a mi atributo frecuencia de mi clase sala
 * \param f es un parametro de entrada del tipo entero asociado al valor del atributo frecuencia de mi clase Sala
 * \return No retorna ningun valor
 */
void sala::setFrecuenciaSala ( int f )
{
	frecuencia=f;
}
/**
 * Metodo que devuelve el valor entero asociado al atributo frecuencia de mi clase sala
 * \param "" no recibe parametros
 * \return Retorna el valor entero asociado al atributo frecuencia de mi clase sala
 */
int sala::getFrecuenciaSala()
{
	return frecuencia;
}
/**
 * Metodo que escribe en mi registro.log la informacion correspondiente a la clase Sala
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void sala::escribeLog ( ofstream & f )
{
	
		f<<"(sala:"<<getIdentificadorSala() <<": ";
		lista->moverInicio();
		while ( !lista->finLista() )
		{
			f<<lista->consultar()->getIdentificador();
			lista->avanzar();
                        if(!lista->finLista())
                            f<<" ";
		}

		f<<")"<<endl;

}
/**
 * Metodo que muestra por pantalla la informacion contenida en mi clase sala
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void sala::mostrar()
{
	cout<<"El identificador de la sala es: "<<getIdentificadorSala() <<endl<<"La marca de la sala es: "<<getMarcaSala() <<endl<<"La frecuencia de la sala es: "<<getFrecuenciaSala() <<endl<<"Las llaves de la lista de la sala son: ";
	lista->moverInicio();
	while ( !lista->finLista() )
	{
		cout<<*lista->consultar() <<" ";
		lista->avanzar();
	}

}
/**
 * Metodo que inserta en mi atributo lista de mi clase Sala un puntero a una Llave l
 * \param l es un parametro de entrada del tipo puntero a instancia de la clase Llave que corresponde con la llave a insertar en mi lista
 * \return No retorna ningun valor
 */
void sala::insertarLista ( Llave * l )
{
	lista->insertarOrdenado ( l );
}


/**
 * Constructor parametrizado de mi clase Sala
 * \param id es un parametro de entrada del tipo entero asociado al valor del atributo idsala de mi clase Sala
 * \param m es un parametro de entrada del tipo entero asociado al valor del atributo marca de mi clase sala
 * \param f es un parametro de entrada del tipo entero asociado al valor del atributo frecuencia de mi clase sala
 * \return No retorna ningun valor
 */
sala::sala(int id, int m, int f)
{
    idsala=id;
    marca=m;
    frecuencia=f;
    lista=new Lista<Llave*>;
    colapersonajes= new queue <Personaje*>;
    
}





/**
 * Metodo que inserta en mi cola de personajes un puntero a personaje
 * \param p es un parametro de entrada del tipo puntero a instancia de la clase Personaje
 * \return No retorna ningun valor
 */
void sala::insertarCola(Personaje * p)
{
    colapersonajes->push(p);
}
/**
 * Metodo booleano que me devuelve true en caso de que haya personajes en una sala y false en caso contrario
 * \param "" no recibe parametros
 * \return Devuelve true en caso de que el atributo colapersonajes no se encuentre vacio (es decir, hay personajes) y false en caso de que se encuentre vacia ( es decir , no hay personajes)
 */
bool sala::siHayPersonajes()
{
    if (colapersonajes->empty()){
        return false;
    }
    else
        return true;
}
/**
 * Metodo que devuelve el tamaño de mi atributo colapersonajes
 * \param "" no recibe parametros
 * \return Retorna un valor entero correspondiente al tamaño del atributo colapersonajes de mi clase Sala
 */
int sala::cuantosPersonajes()
{
    return colapersonajes->size();
}
/**
 * Metodo que devuelve el frente de mi cola colapersonajes de mi clase Sala
 * \param p es un parametro de salida del tipo puntero a instancia de mi clase Personaje que se corresponde con el frente de la cola colapersonajes
 * \return No retorna ningun valor
 */
void sala::devolverFrente(Personaje *& p)
{
    p=colapersonajes->front();
}
/**
 * Metodo que calcula cada una de las rutas correspondientes a los personajes que se encuentran en mi atributo colapersonajes de mi clase Sala
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void sala::calcularRutaPersonajeSala(ofstream & f)
{
    Personaje *aux;
    for(int i=0;i<colapersonajes->size();i++){
        aux=colapersonajes->front();
        aux->ruta(f);
        colapersonajes->pop();
        colapersonajes->push(aux);
    }
    
    
    
}
/**
 * Metodo que vuelva el contenido de un vector v  a mi vector vecinos
 * \param v es un parametro de entrada salida del tipo puntero a ED del tipo vector de la STL en el que se encuentran las salas que quiero copiar en mi atributo vecinos de mi clase Sala
 * \return No retorna ningun valor
 */
void sala::volcarVectorVecinos(vector< sala * > & v)
{
    for(int i=0;i<v.size();i++)
        vecinos.push_back(v[i]);
}

//orden-> norte. sur, este ,oeste
/**
 * Metodo que devuelve la sala vecina v correspondiente a la posicion cardinal determinada por el caracter c
 * \param c es un parametro de entrada del tipo char en el que se encuentra la primera letra de las 4 posiciones cardinales que existen (Norte, Sur, Este,Oeste)
 * \param v es un parametro de salida del tipo puntero a instancia de mi clase Sala que va a almacenar el vecino correspondiente a la posicion cardinal c
 * \return No retorna ningun valor
 */
void sala::devolverCardinalVecino(char c, sala *& v)
{
    switch (c){
        case 'N':
            v=vecinos[0];
            break;
        case 'E':
            v=vecinos[1];
            break;
        case 'S':
            v=vecinos[2];
            break;
        case 'O':
            v=vecinos[3];
            break;
    }
}
/**
 * Metodo que desencola un personaje de mi cola colapersonajes
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void sala::borrarElementoCola()
{
    colapersonajes->pop();
}
/**
 * Metodo booleano que devuelve true en caso de que la lista no este vacia ( es decir, hay alguna llave en mi lista ) y false en caso contrario
 * \param "" no recibe parametros
 * \return Retorna un booleano ;true, en caso de que la lista no este vacia ( es decir, hay alguna llave en mi lista ) y false en caso contrario
 */
bool sala::siHayLlaves()
{
    if(lista->estaVacia())
        return false;
    else
        return true;
}
/**
 * Metodo que devuelve la primera llave de mi lista de llaves de mi clase Sala
 * \param l es un parametro de salida del tipo puntero a instancia de mi clase Llave
 * \return no retorna ningun valor
 */
void sala::devolverPimeroLista(Llave *& l)
{
    lista->moverInicio();
    if(!lista->estaVacia()){
        l=lista->consultar();
        lista->borrar();
    }
}

/**
 * Metodo que devuelve el primer personaje de mi cola de personajes de mi clase Sala
 * \param per es un parametro de salida del tipo puntero a instancia de mi clase Personaje
 * \return no retorna ningun valor
 */
void sala::devolverPrimerPersonaje(Personaje *& per)
{
    if(!colapersonajes->empty()){
        per = colapersonajes->front();
        colapersonajes->pop();
    }
}









/**
 * Metodo que realiza las acciones de los personajes incluidos en el atributo colapersonajes de mi clase Sala
 * \param "" no recibe ningun parametro
 * \return no retorna ningun valor
 */
void sala::accionesColaPersonajes()
{
    Personaje *p;
    int cont=colapersonajes->size();
    while(cont>0){
        p = colapersonajes->front();
        p->TodasAcciones();
        colapersonajes->pop();
        cont--;
    }
}
/**
 * Metodo que escribe en mi fichero.log la informacion contenida en la sala y sus llaves correspondientes
 * \param f es un flujo de entrada salida
 * \return no retorna ningun valor
 */
void sala::escribeLogConEspacio(ofstream & f)
{
    f<<"(sala:"<<getIdentificadorSala() <<": ";
    lista->moverInicio();
    while ( !lista->finLista() )
    {
        f<<lista->consultar()->getIdentificador();
        lista->avanzar();
        if(!lista->finLista())
            f<<" ";
    }

    f<<" )"<<endl;
}