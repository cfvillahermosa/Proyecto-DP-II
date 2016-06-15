
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <cstdlib>

using namespace std;
template <class T>
class Lista{
    typedef struct TipoNodo{
        T  dato;			//!< Dato almacenado en la lista
        TipoNodo *siguiente;	//!< Puntero al siguiente elemento de la lista
        TipoNodo *anterior;	//!< Puntero al anterior elemento de la lista

    };
    TipoNodo *inicio;	//!< Puntero al dato del principio de la lista
    TipoNodo *fin;	//!< Puntero al dato del final de la lista
    TipoNodo *pInteres; //!< Puntero a un determinado dato de la lista

    public:
        Lista ();		//!< inicializa los datos de la lista (punteros a NULL)	
        bool estaVacia(); 	//!< indica si la lista esta vacia o no
        void moverInicio();	//!< mueve el puntero de interés a la posición de inicio (= inicio)
        void moverFin();	//!< mueve el puntero de inteŕés a la posición de fin (= fin)		
        void avanzar();	//!< avanza en una posición el puntero de interés
        void retroceder();	//!< retrocede en una posición el puntero de interés
        bool enInicio();	//!< devuelve verdadero si el punto de interés está en la posición de inicio (== inicio)
        bool enFin();	//!< devuelve verdadero si el punto de interés está en la posición de fin (== fin)
        bool finLista();	//!< devuelve verdadero si el punto de interés alcanza el final de la lista por el principio o por el final (pInteres==NULL ?? )
        T consultar();//!< devuelve el dato apuntado por el puntero de interés	
        void insertar(T dato); //!< inserta un dato en la lista (delante del puntero de interés	
        void borrar();	//!< borra el dato al que apunta el puntero de interés y avanza el puntero de interés al siguiente dato
// Ejercicio para clase
        void insertarOrdenado(T dato); //!< inserta un dato en la lista de manera ordenada
        ~Lista();		//!< libera la memoria de la lista (OJO ¡NO DE LOS DATOS CONTENIDOS!)
};

  template < class T > Lista < T > :: Lista(){
      inicio=NULL;
      fin=NULL;
      pInteres=NULL;
  }
  
  template < class T > bool Lista < T > :: estaVacia(){
      if(inicio==NULL)
          return true;
      else
          return false;
  }
  
  template < class T > void Lista < T > :: moverInicio(){
    pInteres=inicio;
  }
  
  template < class T > void Lista < T > :: moverFin(){
    pInteres=fin;
  }
  
  template < class T > void Lista < T > :: avanzar(){
    pInteres=pInteres->siguiente;
  }
  
  template < class T > void Lista < T > :: retroceder(){
    pInteres=pInteres->anterior;
  }
  
  template < class T > bool Lista < T > :: enInicio(){
    if(pInteres==inicio)
        return true;
    else
        return false;
  }
  
  template < class T > bool Lista < T > :: enFin(){
    if(pInteres==fin)
        return true;
    else
        return false;
  }
  
  template < class T > bool Lista < T > :: finLista(){
    if(pInteres==NULL)
        return true;
    else
        return false;
  }
  
  template < class T > T Lista < T > :: consultar(){
    return pInteres->dato;
  }
  
  template < class T > void Lista < T > :: insertar ( T dato ){
      TipoNodo *insertado=new TipoNodo;
      insertado->dato = dato;
      insertado->anterior=NULL;
      insertado->siguiente=NULL;
	
      if(estaVacia()){
          inicio=insertado;
          fin=insertado;
          insertado->anterior=NULL;
          insertado->siguiente=NULL;
      }
      else{
          if(enInicio()){
              insertado->anterior = NULL;
              insertado->siguiente= inicio;
              inicio->anterior=insertado;
              inicio=insertado;
          }
          else{
              if(finLista()){
                  insertado->siguiente=NULL;
                  insertado->anterior=fin;
                  fin->siguiente=insertado;
                  fin=fin->siguiente;
              }
              else{
                  insertado->siguiente=pInteres;
                  insertado->anterior=pInteres->anterior;
                  pInteres->anterior->siguiente=insertado;
                  pInteres->anterior=insertado;
                        
                        
              }
          }
      }
  }
  
  template < class T > void Lista < T > :: borrar(){
      TipoNodo *borrado;
      if(!finLista()){
          if(enInicio()){
              avanzar();
              delete inicio;
              inicio=pInteres;
              if(inicio==NULL){
                  fin=NULL;
              }
              else{
                  inicio->anterior=NULL;
              }
                
          }
          else{
              if(enFin()){
                  fin=fin->anterior;
                  fin->siguiente=NULL;
                  delete pInteres;
                  avanzar();
                    
              }
              else{
                  pInteres->anterior->siguiente=pInteres->siguiente;
                  borrado=pInteres;
                  pInteres->siguiente->anterior=pInteres->anterior;
                  avanzar();
                  delete borrado;
              }
          }
      }
  }
  
  template < class T > void Lista < T > :: insertarOrdenado ( T dato ){
      bool encontrado=false;
      moverInicio();
      while(!encontrado && !finLista()){
          if(pInteres->dato >= dato){
              encontrado=true;
          }
          else
              avanzar();
      }
   
      insertar(dato);
  }
  
  template < class T > Lista < T > :: ~Lista(){
      moverInicio();
      while(!estaVacia()){
          borrar();
      }
  }
  
  
//LISTA GENÉRICA ESPECIALIZADA 
  
  template <class T>
          class Lista < T* >{
      typedef struct TipoNodo{
          T  *dato;			//!< Dato almacenado en la lista
          TipoNodo *siguiente;	//!< Puntero al siguiente elemento de la lista
          TipoNodo *anterior;	//!< Puntero al anterior elemento de la lista

      };
      TipoNodo *inicio;	//!< Puntero al dato del principio de la lista
      TipoNodo *fin;	//!< Puntero al dato del final de la lista
      TipoNodo *pInteres; //!< Puntero a un determinado dato de la lista

              public:
                  Lista ();		//!< inicializa los datos de la lista (punteros a NULL)	
                  bool estaVacia(); 	//!< indica si la lista esta vacia o no
                  void moverInicio();	//!< mueve el puntero de interés a la posición de inicio (= inicio)
                  void moverFin();	//!< mueve el puntero de inteŕés a la posición de fin (= fin)		
                  void avanzar();	//!< avanza en una posición el puntero de interés
                  void retroceder();	//!< retrocede en una posición el puntero de interés
                  bool enInicio();	//!< devuelve verdadero si el punto de interés está en la posición de inicio (== inicio)
                  bool enFin();	//!< devuelve verdadero si el punto de interés está en la posición de fin (== fin)
                  bool finLista();	//!< devuelve verdadero si el punto de interés alcanza el final de la lista por el principio o por el final (pInteres==NULL ?? )
                  T*consultar();//!< devuelve el dato apuntado por el puntero de interés	
                  void insertar(T *dato); //!< inserta un dato en la lista (delante del puntero de interés	
                  void borrar();	//!< borra el dato al que apunta el puntero de interés y avanza el puntero de interés al siguiente dato
                  void insertarOrdenado(T *dato); //!< inserta un dato en la lista de manera ordenada
                  ~Lista();		//!< libera la memoria de la lista (OJO ¡NO DE LOS DATOS CONTENIDOS!)
          };

          template < class T > Lista < T* > :: Lista(){
              inicio=NULL;
              fin=NULL;
              pInteres=NULL;
          }
  
          template < class T > bool Lista < T* > :: estaVacia(){
              if(inicio==NULL)
                  return true;
              else
                  return false;
          }
  
          template < class T > void Lista < T* > :: moverInicio(){
              pInteres=inicio;
          }
  
          template < class T > void Lista < T* > :: moverFin(){
              pInteres=fin;
          }
  
          template < class T > void Lista < T* > :: avanzar(){
              pInteres=pInteres->siguiente;
          }
  
          template < class T > void Lista < T* > :: retroceder(){
              pInteres=pInteres->anterior;
          }
  
          template < class T > bool Lista < T* > :: enInicio(){
              if(pInteres==inicio)
                  return true;
              else
                  return false;
          }
  
          template < class T > bool Lista < T* > :: enFin(){
              if(pInteres==fin)
                  return true;
              else
                  return false;
          }
  
          template < class T > bool Lista < T* > :: finLista(){
              if(pInteres==NULL)
                  return true;
              else
                  return false;
          }
  
          template < class T > T* Lista < T* > :: consultar(){
              return pInteres->dato;
          }
  
          template < class T > void Lista < T* > :: insertar ( T *dato ){
              TipoNodo *insertado=new TipoNodo;
              insertado->dato = dato;
              insertado->anterior=NULL;
              insertado->siguiente=NULL;
	
              if(estaVacia()){
                  inicio=insertado;
                  fin=insertado;
                  insertado->anterior=NULL;
                  insertado->siguiente=NULL;
              }
              else{
                  if(enInicio()){
                      insertado->anterior = NULL;
                      insertado->siguiente= inicio;
                      inicio->anterior=insertado;
                      inicio=insertado;
                  }
                  else{
                      if(finLista()){
                          insertado->siguiente=NULL;
                          insertado->anterior=fin;
                          fin->siguiente=insertado;
                          fin=fin->siguiente;
                      }
                      else{
                          insertado->siguiente=pInteres;
                          insertado->anterior=pInteres->anterior;
                          pInteres->anterior->siguiente=insertado;
                          pInteres->anterior=insertado;
                        
                        
                      }
                  }
              }
              
          }
  
          template < class T > void Lista < T* > :: borrar(){
              TipoNodo *borrado;
              if(!finLista()){
                  if(enInicio()){
                      avanzar();
                      delete inicio;
                      inicio=pInteres;
                      if(inicio==NULL){
                          fin=NULL;
                      }
                      else{
                          inicio->anterior=NULL;
                      }
                
                  }
                  else{
                      if(enFin()){
                          fin=fin->anterior;
                          fin->siguiente=NULL;
                          delete pInteres;
                          avanzar();
                    
                      }
                      else{
                          pInteres->anterior->siguiente=pInteres->siguiente;
                          borrado=pInteres;
                          pInteres->siguiente->anterior=pInteres->anterior;
                          avanzar();
                          delete borrado;
                      }
                  }
              }
          }
  
          template < class T > void Lista < T* > :: insertarOrdenado ( T *dato ){
              bool encontrado=false;
              moverInicio();
              while(!encontrado && !finLista()){
                  if(*pInteres->dato >= *dato){
                      encontrado=true;
                  }
                  else
                      avanzar();
              }
   
              insertar(dato);
          }
  
          template < class T > Lista < T* > :: ~Lista(){
              moverInicio();
              while(!estaVacia()){
                  borrar();
              }
          }
          
#endif