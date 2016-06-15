/**
 * \file arbol.h
 * \brief Declaración de la clase Árbol Binario de Búsqueda
 * \author
 *   \b Profesores LPII \n
 *   \b Asignatura Laboratorio de Programacion II \n
 *   \b Curso 07/08
 *   \b Revisado en: Curso 10/11
 */

#ifndef _ARBOL_H
#define _ARBOL_H

#include <iostream>

using namespace std;

/*!
   \def DEPURAR
   Variable constante utilizada para mostrar o no mensajes de depuración de programa
 */
#define DEPURAR 0

/*!
   \def DEPURAR_MSG
   Macro utilizada paa mostrar mensajes de depuración de programa y retener los mensajes en pantalla
 */
#define DEPURAR_MSG(msg) if (DEPURAR){ cout<<msg; }

/**
 * \class Arbol
 * \brief Esta clase define un Árbol Binario de Búsqueda
 *
 */
template <class T>
class Arbol
{
    T datoRaiz;
    Arbol *hIzq, *hDer;
    bool esVacio;
    Arbol *borrarOrden(T& dato);
    public:
        Arbol();
        Arbol(Arbol *hIzq,T& datoRaiz,Arbol *hDer);
        Arbol *hijoIzq();
        Arbol *hijoDer();
        T& raiz();
        bool vacio();
        bool insertar(T& dato);
        bool pertenece (T& dato); 
        void borrar (T& dato);
        int numNodos();
        int numHojas();
        int numNodosNoHojas();
        int altura();
        int maximo(int n,int m);
        ~Arbol();
};

///ÁRBOL GENÉRICO

template < class T > Arbol < T > :: Arbol(){
    DEPURAR_MSG ("Entra en Arbol::Arbol"<<endl);
    esVacio = true;
    hIzq = NULL;
    hDer = NULL;
    DEPURAR_MSG ("Sale de Arbol::Arbol"<<endl);
}

template < class T > Arbol < T > *Arbol < T > :: borrarOrden( T & dato ){
    DEPURAR_MSG ("Entra en Arbol::borrarOrden(DatoARbol&): "<<dato<<endl);
    T datoaux;
    Arbol <T>*retorno=this, *aborrar, *candidato, *antecesor;

    if (this!=NULL && !vacio() )
    {
        if (dato<datoRaiz)
            hIzq = hIzq->borrarOrden(dato);
        else
            if (dato>datoRaiz) 
                hDer = hDer->borrarOrden(dato);
        else {
            aborrar=this;
            if ((hDer==NULL)&&(hIzq==NULL))
            { /*si es hoja*/
                delete aborrar;
                retorno=NULL;
            }
            else
            {
                if (hDer==NULL)
                { /*Solo hijo izquierdo*/
                    aborrar=hIzq;
                    datoaux=datoRaiz;
                    datoRaiz=hIzq->raiz();
                    hIzq->datoRaiz = datoaux;
                    hIzq=hIzq->hijoIzq();
                    hDer=aborrar->hijoDer();

                    retorno=this;
                }
                else
                    if (hIzq==NULL)
                { /*Solo hijo derecho*/
                    aborrar=hDer;
                    datoaux=datoRaiz;
                    datoRaiz=hDer->raiz();
                    hDer->datoRaiz = datoaux;
                    hDer=hDer->hijoDer();
                    hIzq=aborrar->hijoIzq();

                    retorno=this;
                }
                else
                { /* Tiene dos hijos */
                    candidato = hijoIzq();
                    antecesor = this;
                    while (candidato->hijoDer())
                    {
                        antecesor = candidato;
                        candidato = candidato->hijoDer();
                    }

                    /*Intercambio de datos de candidato*/
                    datoaux = datoRaiz;
                    datoRaiz = candidato->raiz();
                    candidato->datoRaiz=datoaux;
                    aborrar = candidato;
                    if (antecesor==this)
                        hIzq=candidato->hijoIzq();
                    else
                        antecesor->hDer=candidato->hijoIzq();
                } //Eliminar solo ese nodo, no todo el subarbol
                aborrar->hIzq=NULL;
                aborrar->hDer=NULL;
                delete aborrar;
            }
        }
    }

    DEPURAR_MSG ("Sale de Arbol::borrarOrden(DatoARbol&)"<<endl);
    return retorno;

}

template < class T > Arbol < T > :: Arbol(Arbol *hIzq,T& dato,Arbol *hDer){
    DEPURAR_MSG ("Entra en Arbol::Arbol(Arbol*,DatoARbol&,Arbol*): "<<dato<<endl);
    esVacio = false;
    this->datoRaiz=dato;
    this->hIzq = hIzq;
    this->hDer = hDer;
    DEPURAR_MSG ("Sale de Arbol::Arbol(Arbol*,DatoARbol&,Arbol*)"<<endl);
}

template < class T > Arbol < T > *Arbol < T > ::hijoIzq()
{
    return hIzq;
}

template < class T > Arbol < T > *Arbol < T > ::hijoDer(){
    return hDer;
}

template < class T > T & Arbol < T > :: raiz(){
    return datoRaiz;
}

template < class T > bool Arbol < T > :: vacio(){
    return esVacio;
}

template < class T > bool Arbol < T > :: insertar ( T & dato ){
    DEPURAR_MSG ("Entra en Arbol::Insertar(DatoARbol&): "<<dato<<endl);
    bool resultado=true;
    if (vacio()) {
        datoRaiz = dato;
        esVacio = false;
    }
    else
    {
        if (datoRaiz != dato)
        {
            Arbol *aux;
            if ((dato)<(datoRaiz))
            {
                if ((aux=hijoIzq())==NULL)
                    hIzq = aux = new Arbol();
            }
            else
            {
                if ((aux=hijoDer())==NULL)
                    hDer = aux = new Arbol();
            }
            resultado = aux->insertar(dato);
        }
        else
            resultado=false;
    }
    DEPURAR_MSG ("Sale de Arbol::Insertar(DatoARbol&)"<<endl);
    return resultado;
}

template < class T > bool Arbol < T > :: pertenece( T & dato ){
    DEPURAR_MSG ("Entra en Arbol::pertenece(DatoARbol&): "<<dato<<endl);
    Arbol *aux;
    bool encontrado=false;
    if (!vacio())
    {
        if (dato == datoRaiz)
            encontrado = true;
        else
        {
            if (dato < datoRaiz)
                aux=hijoIzq();
            else
                aux = hijoDer();
            if (aux!=NULL)
                encontrado = aux->pertenece(dato);
        }
    }

    DEPURAR_MSG ("Sale de Arbol::pertenece(DatoARbol&)"<<endl);
    return encontrado;
}

template < class T > void Arbol < T > :: borrar ( T & dato ){
    DEPURAR_MSG ("Entra en Arbol::borrar(DatoARbol&): "<<dato<<endl);
    if (this!=NULL && !vacio()  )
    {
        if (dato<datoRaiz)
            hIzq = hIzq->borrarOrden(dato);
        else
            if (dato>datoRaiz) 
                hDer = hDer->borrarOrden(dato);
        else //En este caso el dato es el datoRaiz
        {
            if (hIzq==NULL && hDer==NULL)
            {
                esVacio = true;
            }
            else
                borrarOrden(dato);
        }
    }
    DEPURAR_MSG ("Sale de Arbol::borrar(DatoARbol&)"<<endl);
}

template < class T > int Arbol < T > :: numNodos(){
    if(this!=NULL && !vacio() ){
        return (hIzq()->numNodos() + hDer()->numNodos()+1);
    }
    else
        return 0;
}

template < class T > int Arbol < T > :: numHojas(){
    if(this!=NULL && !vacio()) {
        if(hIzq==NULL && hDer==NULL)
            return (hIzq()->numHojas() + hDer()->numHojas()+1);
        else
            return (hIzq()->numHojas() + hDer()->numHojas());
            
        
    }
    else
        return 0;
}

template < class T > int Arbol < T > :: numNodosNoHojas(){
    return (numNodos()-numHojas());
}

template < class T > int Arbol < T > :: altura(){
    if(this!=NULL && !vacio()){
        return maximo(hIzq->altura(),hDer->altura())+1;
    }
    else{
        return 0;
    }


}



template < class T > Arbol < T > :: ~Arbol(){
    DEPURAR_MSG ("Entra en Arbol::~Arbol()"<<endl);
    Arbol *aux;
    if (!vacio())
    {
        if (aux=hijoIzq())
            delete aux;
        if (aux=hijoDer())
            delete aux;

        esVacio = true;
    }
    DEPURAR_MSG ("Sale de Arbol::~Arbol()"<<endl);
}

template < class T > int Arbol < T > :: maximo (int n, int m){
    if(n>m)
        return n;
    else
        return m;
}



///ÁRBOL GENÉRICO ESPECIALIZADO

template <class T>
        class Arbol < T* >
{
    T *datoRaiz;
    Arbol *hIzq, *hDer;
    bool esVacio;
    Arbol *borrarOrden(T * dato);
    public:
        Arbol();
        Arbol(Arbol *hIzq,T& datoRaiz,Arbol *hDer);
        Arbol *hijoIzq();
        Arbol *hijoDer();
        T*& raiz();
        Arbol *rotacionSimpleDerecha();
        Arbol *rotacionSimpleIzquierda();
        Arbol *rotacionDobleIzquierdaDerecha ();
        Arbol *rotacionDobleDerechaIzquierda();
        Arbol *balancear();
        bool vacio();
        bool insertar(T * dato);
        bool pertenece (T *& dato);
        bool pertenece (T *& dato, T *& datoaux); 
        void borrar (T * dato);
        int numNodos();
        int numHojas();
        int numNodosNoHojas();
        int altura();
        int maximo (int n, int m);
        ~Arbol();
};

template < class T > Arbol < T* > :: Arbol(){
    DEPURAR_MSG ("Entra en Arbol::Arbol"<<endl);
    esVacio = true;
    hIzq = NULL;
    hDer = NULL;
    DEPURAR_MSG ("Sale de Arbol::Arbol"<<endl);
}

template < class T > Arbol < T* > *Arbol < T* > :: borrarOrden( T * dato ){
    DEPURAR_MSG ("Entra en Arbol::borrarOrden(DatoARbol&): "<<dato<<endl);
    T* datoaux;
    Arbol *retorno=this, *aborrar, *candidato, *antecesor;

    if (this!=NULL && !vacio())
    {
        if (*dato<*datoRaiz)
            hIzq = hIzq->borrarOrden(dato);
        else
            if (*dato>*datoRaiz) 
                hDer = hDer->borrarOrden(dato);
        else {
            aborrar=this;
            if ((hDer==NULL)&&(hIzq==NULL))
            { /*si es hoja*/
                delete aborrar;
                retorno=NULL;
            }
            else
            {
                if (hDer==NULL)
                { /*Solo hijo izquierdo*/
                    aborrar=hIzq;
                    datoaux=datoRaiz;
                    datoRaiz=hIzq->raiz();
                    hIzq->datoRaiz = datoaux;
                    hIzq=hIzq->hijoIzq();
                    hDer=aborrar->hijoDer();

                    retorno=this;
                }
                else
                    if (hIzq==NULL)
                { /*Solo hijo derecho*/
                    aborrar=hDer;
                    datoaux=datoRaiz;
                    datoRaiz=hDer->raiz();
                    hDer->datoRaiz = datoaux;
                    hDer=hDer->hijoDer();
                    hIzq=aborrar->hijoIzq();

                    retorno=this;
                }
                else
                { /* Tiene dos hijos */
                    candidato = hijoIzq();
                    antecesor = this;
                    while (candidato->hijoDer())
                    {
                        antecesor = candidato;
                        candidato = candidato->hijoDer();
                    }

                    /*Intercambio de datos de candidato*/
                    datoaux = datoRaiz;
                    datoRaiz = candidato->raiz();
                    candidato->datoRaiz=datoaux;
                    aborrar = candidato;
                    if (antecesor==this)
                        hIzq=candidato->hijoIzq();
                    else
                        antecesor->hDer=candidato->hijoIzq();
                } //Eliminar solo ese nodo, no todo el subarbol
                aborrar->hIzq=NULL;
                aborrar->hDer=NULL;
                delete aborrar;
            }
        }
    }

    DEPURAR_MSG ("Sale de Arbol::borrarOrden(DatoARbol&)"<<endl);
    return retorno;

}

template < class T > Arbol < T* > :: Arbol(Arbol *hIzq,T& dato,Arbol *hDer){
    DEPURAR_MSG ("Entra en Arbol::Arbol(Arbol*,DatoARbol&,Arbol*): "<<dato<<endl);
    esVacio = false;
    this->datoRaiz=dato;
    this->hIzq = hIzq;
    this->hDer = hDer;
    DEPURAR_MSG ("Sale de Arbol::Arbol(Arbol*,DatoARbol&,Arbol*)"<<endl);
}

template < class T > Arbol < T* > *Arbol < T* > ::hijoIzq()
{
    return hIzq;
}

template < class T > Arbol < T* > *Arbol < T* > ::hijoDer(){
    return hDer;
}

template < class T > T* & Arbol < T* > :: raiz(){
    return datoRaiz;
}

template < class T > bool Arbol < T* > :: vacio(){
    return esVacio;
}

template < class T > bool Arbol < T* > :: insertar ( T * dato ){
    DEPURAR_MSG ("Entra en Arbol::Insertar(DatoARbol&): "<<dato<<endl);
    bool resultado=true;
    if (vacio()) {
        datoRaiz = dato;
        esVacio = false;
    }
    else
    {
        if (*datoRaiz != *dato)
        {
            Arbol *aux;
            if ((*dato)<(*datoRaiz))
            {
                if ((aux=hijoIzq())==NULL)
                    hIzq = aux = new Arbol();
            }
            else
            {
                if ((aux=hijoDer())==NULL)
                    hDer = aux = new Arbol();
            }
            resultado = aux->insertar(dato);
        }
        else
            resultado=false;
    }
    DEPURAR_MSG ("Sale de Arbol::Insertar(DatoARbol&)"<<endl);
    return resultado;
}

template < class T > bool Arbol < T* > :: pertenece( T *& dato ){
    DEPURAR_MSG ("Entra en Arbol::pertenece(DatoARbol&): "<<dato<<endl);
    Arbol *aux;
    bool encontrado=false;
    if (!vacio())
    {
        if (*dato == *datoRaiz)
            encontrado = true;
        else
        {
            if (*dato < *datoRaiz)
                aux=hijoIzq();
            else
                aux = hijoDer();
            if (aux!=NULL)
                encontrado = aux->pertenece(dato);
        }
    }

    DEPURAR_MSG ("Sale de Arbol::pertenece(DatoARbol&)"<<endl);
    return encontrado;
}

template < class T > bool Arbol < T* > :: pertenece( T *& dato,T*&datoaux ){
    DEPURAR_MSG ("Entra en Arbol::pertenece(DatoARbol&): "<<dato<<endl);
    Arbol *aux;
    bool encontrado=false;
    if (!vacio())
    {
        if (*dato == *datoRaiz){
            datoaux=datoRaiz;
            encontrado = true;
        }
        else
        {
            if (*dato < *datoRaiz)
                aux=hijoIzq();
            else
                aux = hijoDer();
            if (aux!=NULL)
                encontrado = aux->pertenece(dato);
        }
    }

    DEPURAR_MSG ("Sale de Arbol::pertenece(DatoARbol&)"<<endl);
    return encontrado;
}

template < class T > void Arbol < T* > :: borrar ( T * dato ){
    DEPURAR_MSG ("Entra en Arbol::borrar(DatoARbol&): "<<dato<<endl);
    if (this!=NULL && !vacio()  )
    {
        if (*dato<*datoRaiz)
            hIzq = hIzq->borrarOrden(dato);
        else
            if (*dato>*datoRaiz) 
                hDer = hDer->borrarOrden(dato);
        else //En este caso el dato es el datoRaiz
        {
            if (hIzq==NULL && hDer==NULL)
            {
                esVacio = true;
            }
            else
                borrarOrden(dato);
        }
    }
    DEPURAR_MSG ("Sale de Arbol::borrar(DatoARbol&)"<<endl);
}

template < class T > int Arbol < T* > :: numNodos(){
    if(this!=NULL && !vacio() ){
        return (hijoIzq()->numNodos() + hijoDer()->numNodos()+1);
    }
    else
        return 0;
}

template < class T > int Arbol < T* > :: numHojas(){
    if(this!=NULL && !vacio()) {
        if(hIzq==NULL && hDer==NULL)
            return (1);
        else
            return (hijoIzq()->numHojas() + hijoDer()->numHojas());
            
        
    }
    else
        return 0;
}

template < class T > int Arbol < T* > :: numNodosNoHojas(){
    return (numNodos()-numHojas());
}

template < class T > int Arbol < T* > :: altura(){
    if(this!=NULL && !vacio()){
        return maximo(hIzq->altura(),hDer->altura())+1;
    }
    else{
        return 0;
    }


}

template <class T> Arbol<T*>* Arbol<T*>::rotacionSimpleDerecha() {
    Arbol< T * > *p;

    p = hIzq;
    hIzq = p->hDer;
    p->hDer = this;
    return p;
}

template <class T> Arbol<T*>* Arbol<T*>::rotacionSimpleIzquierda() {
    Arbol< T * > *p;

    p = hDer;
    hDer = p->hIzq;
    p->hIzq = this;
    return p;
}

template <class T> Arbol<T*>* Arbol<T*>::rotacionDobleIzquierdaDerecha () {
    Arbol< T * > *p;

    hIzq=hIzq->rotacionSimpleIzquierda();
    p=rotacionSimpleDerecha();
    return p;
}

template <class T> Arbol<T*>* Arbol<T*>::rotacionDobleDerechaIzquierda () {
    Arbol< T * > *p;

    hDer=hDer->rotacionSimpleDerecha();
    p=rotacionSimpleIzquierda();
    return p;
}

template <class T>  Arbol<T*>* Arbol<T*>::balancear()
{
    int n;
    Arbol< T * > * b=this;
    if (this!=NULL)
    {
        if (hIzq!=NULL)
            hIzq=hIzq->balancear();
		
        if (hDer!=NULL)
            hDer=hDer->balancear();
		
        n=hIzq->altura()- hDer->altura();
        if (n>1)//hizquierda es mayor que el hijoderecha
        {
            if (hIzq->hijoIzq()->altura() >= hIzq->hijoDer()->altura())
                b=rotacionSimpleDerecha();
            else 
                b=rotacionDobleIzquierdaDerecha();
        }
        else
        {
            if (n<-1)//hderecho mayor que el hijo izquierdo
            {
                if (hDer->hijoDer()->altura() >= hDer->hijoIzq()->altura())
                    b=rotacionSimpleIzquierda();
                else 
                    b=rotacionDobleDerechaIzquierda();
            }
        }
        if(b!=NULL){
            if (b->hIzq!=NULL)
                b->hIzq=b->hIzq->balancear();
            if (b->hDer!=NULL)
                b->hDer=b->hDer->balancear();
        }
    }
    return b;
}

template < class T > Arbol < T* > :: ~Arbol(){
    DEPURAR_MSG ("Entra en Arbol::~Arbol()"<<endl);
    Arbol *aux;
    if (!vacio())
    {
        if (aux=hijoIzq())
            delete aux;
        if (aux=hijoDer())
            delete aux;

        esVacio = true;
    }
    DEPURAR_MSG ("Sale de Arbol::~Arbol()"<<endl);
}
template < class T > int Arbol < T* > :: maximo (int n, int m){
    if(n>m)
        return n;
    else
        return m;
}





#endif
