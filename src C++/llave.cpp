#include "llave.h"
/**
 * Constructor por defecto de mi clase Llave
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Llave::Llave()
{
    identificador=-1;
}

/**
 * Destructor de mi clase Llav e
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
Llave::~Llave()
{
}
/**
 * Metodo que establece al atributo identificador de mi clase Llave el valor n
 * \param n es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
void Llave::setIdentificador(int n)
{
    identificador=n;
}
/**
 * Metodo que devuelve el valor entero de mi atributo identificador de mi clase Llave
 * \param "" no recibe parametros
 * \return Retorna el valor entero correspondiente al atributo identificador de mi clase Llave
 */
int Llave::getIdentificador()
{
    return identificador;
}
/**
 * Constructor parametrizado de mi clase Llave
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
Llave::Llave(int n)
{
    identificador=n;
}
/**
 * Sobrecarga del operador == de mi clase Llave 
 * \param l es un parametro de entrada salida de mi clase Llave
 * \return No retorna ningun valor
 */
int Llave::operator ==(Llave & l)
{
    if(identificador==l.identificador)
        return true;
    else
        return false;
}
/**
 * Sobrecarga del operador == para los identificadores de los objetos de la clase Llave
 * \param n es un parametro de entrada del tipo entero correspondiente al identificador de la llave a comparar
 * \return No retorna ningun valor
 */
int Llave::operator ==(int n)
{
    if(identificador==n)
        return true;
    else
        return false;
}
/**
 * Sobrecarga del operador << de mi clase Llave
 * \param f es un flujo de entrada salida
 * \param l es un parametro de entrada salida de la clase Llave
* \return No retorna ningun valor
 */
ostream & operator <<(ostream & f,Llave & l){
    f<<"el identificador de la llave es: "<<l.identificador<<endl;
    return f;
}
/**
 * Sobrecarga del operador "<" de mi clase Llave 
 * \param l es un parametro de entrada salida de la clase Llave
 * \return No retorna ningun valor
 */
int Llave::operator <(Llave & l)
{
    if(identificador < l.identificador)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador ">"de mi clase Llave
 * \param l es un parametro de entrada salida de la clase Llave
 * \return No retorna ningun valor
 */
int Llave::operator >(Llave & l)
{
    if(identificador > l.identificador)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador "!="de mi clase Llave
         * \param l es un parametro de entrada salida de la clase Llave
         * \return No retorna ningun valor
 */
int Llave::operator !=(Llave & l)
{
    if(identificador !=l.identificador)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador "<="de mi clase Llave
 * \param l es un parametro de entrada salida de la clase Llave
 * \return No retorna ningun valor
 */
int Llave::operator <= (Llave & l)
{
    if(identificador <=l.identificador)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador ">="de mi clase Llave
 * \param l es un parametro de entrada salida de la clase Llave
 * \return No retorna ningun valor
 */
int Llave::operator >=(Llave & l)
{
    if(identificador >= l.identificador)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador "<"de mi clase Llave
 * \param n es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
int Llave::operator <(int n)
{
    if(identificador <n)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador ">"de mi clase Llave
 * \param n es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
int Llave::operator >(int n)
{
    if(identificador > n)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador "!="de mi clase Llave
 * \param n es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
int Llave::operator !=(int n)
{
    if(identificador != n)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador "<="de mi clase Llave
 * \param n es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
int Llave::operator <=(int n)
{
    if(identificador <= n)
        return true;
    else
        return false;
}
/**
 * sobrecarga del operador ">="de mi clase Llave
 * \param n es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
int Llave::operator >=(int n)
{
    if(identificador >= n)
        return true;
    else
        return false;
}

/**
 * Constructor por copia de mi clase Llave
 * \param l  es un parametro de entrada salida de la clase Llave
 * \return No retorna ningun valor
 */
Llave::Llave(const Llave & l)
{
    identificador=l.identificador;
}




