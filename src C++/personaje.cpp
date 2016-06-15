#include "personaje.h"
#include "estacion.h"
/**
 * Constructor por defecto de mi clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Personaje::Personaje()
{
    marca='0';
    nombre=" ";
    turno=-1;
    idsala=-1;
    idplanta=-1;
    juegollaves=new stack <Llave*>;
}

/**
 * Destructor de mi clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Personaje::~Personaje()
{
    liberarMemoriaPila(this->juegollaves);
    delete juegollaves;
}
/**
 * Constructor parametrizado de mi clase Personaje
 * \param m es un parametro de entrada del tipo char asociado al atributo movimiento de mi clase Personaje
 * \param n es un parametro de entrada del tipo string asociado al atributo nombre de mi clase Personaje
 * \param t es un parametro de entrada del tipo entero asociado al atributo turno de mi clase Personaje
 * \param ids es un parametro de entrada del tipo entero asociado al atributo idsala de mi clase Personaje
 * \param idp es un parametro de entrada del tipo entero asociado al atributo idplanta de mi clase Personaje
 * \return No retorna ningun valor
 */
Personaje::Personaje(char m, string n,int t, int ids, int idp)
{
    marca=m;
    nombre=n;
    turno=t;
    idsala=ids;
    idplanta=idp;
    juegollaves=new stack <Llave*>;
}
/**
 * Metodo que muestra por pantalla que el personaje es del tipo personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Personaje::mostrar()
{
    cout<<"estoy mostrando un personaje"<<endl;
}
/**
 * Metodo que establece al atributo movimiento de mi clase personaje el valor de m
 * \param m es un parametro de entrada del tipo char 
 * \return No retorna ningun valor
 */
void Personaje::setMarca(char m)
{
    marca=m;
}
/**
 * Metodo que devuelve el caracter asociado al atributo movimiento de mi clase Personaje
 * \param "" no recibe parametros
 * \return Retorna el char correspondiente al atributo movimiento de mi clase Personaje
 */
char Personaje::getMarca()
{
    return marca;
}
/**
 * Metodo que establece el valor de mi atributo de tipo string, nombre, de mi clase Personaje
 * \param n es un parametro de entrada del tipo string asociado al atributo nombre de mi clase Personaje
 * \return No retorna ningun valor
 */
void Personaje::setNombre(string n)
{
    nombre=n;
}
/**
 * Metodo que devuelve el contenido del atributo nombre de mi clase Personaje
 * \param n es un parametro salida que devuelve el contenido de mi atributo nombre de mi clase Personaje
 * \return No retorna ningun valor
 */
void Personaje::getNombre(string & n)
{
    n=nombre;
}
/**
 * Metodo que establece el valor de mi atributo turno de mi clase Personaje
 * \param t es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
void Personaje::setTurno(int t)
{
    turno=t;
}
/**
 * Metodo que devuelve el valor del atributo turno de mi clase Personaje
 * \param "" no recibe parametros
 * \return Devuelve el entero correspondiente al valor de mi atributo turno de mi clase Personaje
 */
int Personaje::getTurno()
{
    return turno;
}
/**
 * Metodo que establece el valor de mi atributo idsala de mi clase Personaje
 * \param ids es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
void Personaje::setIdSala(int ids)
{
    idsala=ids;
}
/**
 * Metodo que devuelve el valor asociado a mi atributo idsala de mi clase Personaje
 * \param "" no recibe parametros
 * \return Retorna el valor correspondiente al atributo idsala de mi clase Personaje
 */
int Personaje::getIdSala()
{
    return idsala;
}
/**
 * Metodo que establece el valor de mi atributo idplanta de mi clase Personaje
 * \param idp es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
void Personaje::setIdPlanta(int idp)
{
    idplanta=idp;
}
/**
 * Metodo que devuelve el valor correspondiente con el atributo idplanta de mi clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
int Personaje::getIdPlanta()
{
    return idplanta;
}
/**
 * Metodo escribe en mi registro.log de mi clase Personaje
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void Personaje::escribeLog(ofstream & f)
{
    stack <Llave*> *aux;
    aux=new stack <Llave*>;
    Llave *l;
    f<<marca<<":"<<idsala<<":"<<turno<<":";
    
    if(!juegollaves->empty())
        f<<" ";
    while(!juegollaves->empty()){
        l=juegollaves->top();
        aux->push(l);
        juegollaves->pop();
        f<<l->getIdentificador();
        if(!juegollaves->empty())
            f<<" ";
    }
    f<<")"<<endl;
    while(!aux->empty()){
        l=aux->top();
        juegollaves->push(l);
        aux->pop();
    }
    liberarMemoriaPila(aux);
    delete aux;
}
/**
 * Metodo que inserta en mi atributo juegollaves del tipo pila un puntero a una instancia de mi clase Llave
 * \param l es un parametro de entrada de mi clase Llave
 * \return No retorna ningun valor
 */
void Personaje::insertarPila(Llave * l)
{
    juegollaves->push(l);
}
/**
 * Metodo que libera la memoria de cada Llave contenida en mi estructura pila pil
 * \param pil es un parametro de entrada salida (puntero) que almacena punteros a instancias de mi clase Llave
 * \return No retorna ningun valor
 */
void Personaje::liberarMemoriaPila(stack< Llave * > *& pil)
{
    while(!pil->empty()){
        delete pil->top();
        pil->pop();
    }
}
/**
 * Metodo que realiza la ruta de mi clase Personaje
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void Personaje::ruta(ofstream & f)
{
    
}
/**
 * Metodo que inserta en mi cola secuencia un valor entero
 * \param i es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
void Personaje::insertarCola(int i)
{
    secuencia.push(i);
}
/**
 * Metodo que realiza todas las acciones (uno,dos,tres y cuatro) de la clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Personaje::TodasAcciones()
{
    Estacion *e = Estacion :: obtenerMiEstacion();
    if (turno==e->getTurnoSimulacion()){
        
        turno++;
        
        accionUno();
        accionDos();
        accionTres();
        accionCuatro();
    }
    
    e->insertarPersonajeEstacion(this);
}
/**
 * Metodo que realiza la accion uno de la clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Personaje::accionUno()
{
}
/**
 * Metodo que realiza la accion dos de la clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Personaje::accionDos()
{
}
/**
 * Metodo que realiza la accion tres de la clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Personaje::accionTres()
{
}
/**
 * Metodo que realiza la accion cuatro de la clase Personaje
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Personaje::accionCuatro()
{
}
/**
 * Sobrecarga del operador "==" de mi clase Personaje
 * \param p es un parametro de entrada salida de mi clase Personaje
 * \return No retorna ningun valor
 */
int Personaje::operator ==(Personaje & p)
{
    if(marca == p.marca)
        return true;
    else
        return false;
}


/**
 * Sobrecarga del operador ">" de mi clase Personaje
 * \param p es un parametro de entrada salida de mi clase Personaje
 * \return No retorna ningun valor
 */
int Personaje::operator >(Personaje & p)
{
    if(marca > p.marca)
        return true;
    else
        return false;
}

/**
 * Sobrecarga del operador "<" de mi clase Personaje
 * \param p es un parametro de entrada salida de mi clase Personaje
 * \return No retorna ningun valor
 */
int Personaje::operator <(Personaje & p)
{
    if(marca < p.marca)
        return true;
    else
        return false;
}

/**
 * Sobrecarga del operador ">=" de mi clase Personaje
 * \param p es un parametro de entrada salida de mi clase Personaje
 * \return No retorna ningun valor
 */
int Personaje::operator >=(Personaje & p)
{
    if(marca >= p.marca)
        return true;
    else
        return false;
}

/**
 * Sobrecarga del operador "<=" de mi clase Personaje
 * \param p es un parametro de entrada salida de mi clase Personaje
 * \return No retorna ningun valor
 */
int Personaje::operator <=(Personaje & p)
{
    if(marca <= p.marca)
        return true;
    else
        return false;
}

/**
 * Sobrecarga del operador "!=" de mi clase Personaje
 * \param p es un parametro de entrada salida de mi clase Personaje
 * \return No retorna ningun valor
 */
int Personaje::operator !=(Personaje & p)
{
    if(marca != p.marca)
        return true;
    else
        return false;
}

/**
 * Metodo que devuelve la primera llave de mi atributo del tipo pila juegollaves si la cola no esta vacia y ademas ,desapila esa llave
 * \param l es un parametro de entrada salida de mi clase Llave
 * \return No retorna ningun valor
 */
void Personaje::cojerLlave(Llave * &l)
{
    if(!juegollaves->empty()){
        l=juegollaves->top();
        juegollaves->pop();
    }
}

/**
 * Metodo booleano que me indica si mi atributo del tipo pila juegollaves se encuentra vacia o no
 * \param "" no recibe parametros
 * \return Retorna true si la pila esta vacia y false en caso contrario
 */
bool Personaje::pilaVacia()
{
    return juegollaves->empty();
}