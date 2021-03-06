/**
* \file grafo.cpp
* \brief Implementacion de los metodos de la clase grafo
* \author
*   \b Profesores LPII \n
*   \b Asignatura Laboratorio de Programacion II \n
*   \b Curso 07/08 (revisado 08/09)
*/

#include "grafo.h"

/**
* Metodo constructor por defecto de la clase grafo
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
Grafo::Grafo()
{
    DEPURAR_MSG ("Entra en Grafo::Grafo"<<endl);
    int x,y;
    numNodos=0;

    for (x=0;x<MAXVERT;x++)
        nodos[x]= NO_VALOR;

    for (x=0;x<MAXVERT;x++)
        for (y=0;y<MAXVERT;y++)
        {
            arcos[x][y]=INFINITO;
            warshallC[x][y]=INFINITO;
            floydC[x][y]=INFINITO;
            floydP[x][y]=NO_VALOR;
        }
    // Diagonales
    for (x=0;x<MAXVERT;x++)
    {
        arcos[x][x]=0;
        warshallC[x][x]=0;
        floydC[x][x]=0;
        //floydP[x][x]=NO_VALOR;
    }
    DEPURAR_MSG ("Sale de Grafo::Grafo"<<endl);
}

/**
* Metodo que comprueba si el grafo esta vacio
* \param "" No recibe parametros
* \return Retorna un valor booleano que indica si el grafo esta o no vacio
*/
bool Grafo::esVacio (void)
{
    DEPURAR_MSG ("Entra en Grafo::esVacio()"<<endl);
    DEPURAR_MSG ("Sale de Grafo::esVacio()"<<endl);
    return bool (numNodos==0);
}

/**
* Metodo que inserta un nuevo arco en el grafo
* \param origen es el nodo de origen del arco nuevo
* \param destino es el nodo de destino del arco nuevo
* \param valor es el peso del arco nuevo 
* \return true si se pudo insertar
*/
bool Grafo::nuevoArco(TipoNodoGrafo origen, TipoNodoGrafo destino, int valor)
{
    DEPURAR_MSG ("Entra en Grafo::nuevoArco(TipoNodoGrafo origen, TipoNodoGrafo destino, int valor)"<<endl);
    bool resultado= false;
    if (((int)(origen) >= 0) && ((int)(origen) < numNodos) && 
		((int)(destino) >= 0) && ((int)(destino) < numNodos))	// Cambiado
    {
        arcos[(int)(origen)][(int)(destino)]=valor; // Cambiado
        resultado=true;
    }
    DEPURAR_MSG ("Sale de Grafo::nuevoArco(TipoNodoGrafo origen, TipoNodoGrafo destino, int valor): "<<resultado<<endl);
    return resultado;
}

/**
* Metodo que borra un arco del grafo
* \param origen es el nodo de origen del arco nuevo
* \param destino es el nodo de destino del arco nuevo
* \return true si se pudo borrar
*/
bool Grafo::borraArco(TipoNodoGrafo origen, TipoNodoGrafo destino)
{
    DEPURAR_MSG ("Entra en Grafo::borraArco(TipoNodoGrafo origen, TipoNodoGrafo destino)"<<endl);
    bool resultado= false;
    if (((int)(origen) >= 0) && ((int)(origen) < numNodos) && 
		((int)(destino) >= 0) && ((int)(destino) < numNodos)) // Cambiado
    {
        
		arcos[(int)(origen)][(int)(destino)]=INFINITO;	// Cambiado
        resultado=true;
    }
    DEPURAR_MSG ("Sale de Grafo::borraArco(TipoNodoGrafo origen, TipoNodoGrafo destino): "<<resultado<<endl);
    return resultado;
}

/**
* Metodo que comprueba si dos nodos son adyacentes
* \param origen es el primer nodo
* \param destino es el segundo nodo
* \return Retorna un valor booleano que indica si los dos nodos son adyacentes
*/
bool Grafo::adyacente(TipoNodoGrafo origen, TipoNodoGrafo destino)
{
    DEPURAR_MSG ("Entra en Grafo::adyacente (TipoNodoGrafo origen, TipoNodoGrafo destino)"<<endl);
    bool resultado= false;

    if (((int)(origen) >= 0) && ((int)(origen) < numNodos) && 
		((int)(destino) >= 0) && ((int)(destino) < numNodos)) // Cambiado
        
		resultado = (arcos[(int)(origen)][(int)(destino)]!=INFINITO); // Cambiado

    DEPURAR_MSG ("Sale de Grafo::adyacente (TipoNodoGrafo origen, TipoNodoGrafo destino): "<<resultado<<endl);
    return resultado;
}

/**
* Metodo que retorna el peso de un arco
* \param origen es el primer nodo del arco
* \param destino es el segundo nodo del arco
* \return Retorna un valor entero que contiene el peso del arco
*/
int Grafo::getArco(TipoNodoGrafo origen, TipoNodoGrafo destino)
{
    DEPURAR_MSG ("Entra en Grafo::getArco (TipoNodoGrafo origen, TipoNodoGrafo destino)"<<endl);

    int arco=NO_VALOR;

    if (((int)(origen) >= 0) && ((int)(origen) < numNodos) && 
		((int)(destino) >= 0) && ((int)(destino) < numNodos)) 	// Cambiado
        
		arco=arcos[(int)(origen)][(int)(destino)];				// Cambiado

    DEPURAR_MSG ("Sale de Grafo::getArco (TipoNodoGrafo origen, TipoNodoGrafo destino): "<<arco<<endl);

    return arco;
}

/**
* Metodo que inserta un nuevo nodo en el grafo
* \param n es el nodo que se desea insertar
* \return true si se pudo insertar
*/
bool Grafo::nuevoNodo(TipoNodoGrafo n)
{
    DEPURAR_MSG ("Entra en Grafo::nuevoNodo(TipoNodoGrafo n)"<<endl);
    bool resultado=false;

    if (numNodos<MAXVERT)
    {
        nodos[numNodos]=n;
        numNodos++;
        resultado=true;
    }
    DEPURAR_MSG ("Sale de Grafo::nuevoNodo(TipoNodoGrafo n): "<<resultado<<endl);

    return resultado;
}

/**
* Metodo que elimina un nodo del grafo
* \param pos es la posición que ocupa el nodo que se desea eliminar
* \return true si se pudo borrar
*/
bool Grafo::borraNodo(TipoNodoGrafo nodo)
{
    DEPURAR_MSG ("Entra en Grafo::borraNodo(TipoNodoGrafo pos)"<<endl);
    bool resultado=false;
	
	int pos = (int)(nodo); // Añadido para borrar el nodo correcto

    if ((numNodos>0) && (pos <= numNodos))
    {
        int x,y;

        // Borrar el nodo
        for (x=pos; x<numNodos-1; x++){		// Añadido el -1 porque si no se salía de límites array
            nodos[x]=nodos[x+1];
			cout << nodos[x+1];
		}

        // Borrar en la Matriz de Adyacencia

        // Borra la fila
        for (x=pos; x<numNodos-1; x++)		// Añadido el -1 porque si no se salía de límites array
            for (y=0;y<numNodos; y++)
                arcos[x][y]=arcos[x+1][y];

        // Borra la columna
        for (x=0; x<numNodos; x++)
            for (y=pos;y<numNodos-1; y++)	// Añadido el -1 porque si no se salía de límites array
                arcos[x][y]=arcos[x][y+1];

        // Decrementa el numero de nodos
        numNodos--;
        resultado=true;
    }
    DEPURAR_MSG ("Sale de Grafo::borraNodo(TipoNodoGrafo pos): "<<resultado<<endl);
    return resultado;
}


/**
* Metodo que muestra el vector de nodos del grafo
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
void Grafo::mostrarNodos(void)
{
    DEPURAR_MSG ("Entra en Grafo::mostrarNodos()"<<endl);
    int x;

    cout << "NODOS:" << endl;
    for (x=0;x<numNodos;x++)
        cout << nodos[x] << " ";
    cout << endl;
    DEPURAR_MSG ("Sale de Grafo::mostrarNodos()"<<endl);
}

/**
* Metodo que muestra los arcos del grafo (la matriz de adyacencia)
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
void Grafo::mostrarArcos(void)
{
    DEPURAR_MSG ("Entra en Grafo::mostrarArcos()"<<endl);
    int x,y;

    cout << "ARCOS:" << endl;
    for (x=0;x<numNodos;x++)
    {
        for (y=0;y<numNodos;y++)
        {
            cout.width(3);
            if (arcos[x][y]!=INFINITO)
                cout << arcos[x][y] << " ";
            else
                cout << "#" <<" ";
        }
        cout << endl;
    }
    DEPURAR_MSG ("Sale de Grafo::mostrarArcos()"<<endl);
}

/**
* Metodo que muestra la matriz de Warshall
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
void Grafo::mostrarPW(void)
{
    DEPURAR_MSG ("Entra en Grafo::mostrarPW()"<<endl);
    int x,y;

    cout << "warshallC:" << endl;
    for (x=0;x<numNodos;x++)
    {
        for (y=0;y<numNodos;y++){
            cout.width(3);
            cout << warshallC[x][y] << " ";
        }
        cout << endl;
    }
    DEPURAR_MSG ("Sale de Grafo::mostrarPW()"<<endl);
}

/**
* Metodo que muestra las matrices de coste y camino de Floyd
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
void Grafo::mostrarFloydC(void)
{
    DEPURAR_MSG ("Entra en Grafo::mostrarFloydC()"<<endl);
    int x,y;

    cout << "floydC:" << endl;

    for (y=0;y<numNodos;y++)
    {
        for (x=0;x<numNodos;x++)
        {
            cout.width(3);
            cout << floydC[x][y] << " ";
        }
        cout << endl;
    }

    cout << "floydP:" << endl;
    for (x=0;x<numNodos;x++)
    {
        for (y=0;y<numNodos;y++)
        {
            cout.width(3);
            cout << floydP[x][y] << " " ;
        }
        cout << endl;
    }
    DEPURAR_MSG ("Sale de Grafo::mostrarFloydC()"<<endl);
}

/**
* Metodo que realiza el algoritmo de Warshall sobre el grafo
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
void Grafo::warshall (void)
{
    DEPURAR_MSG ("Entra en Grafo::Warshall()"<<endl);
    int i,j,k;
    for(i=0;i<numNodos;i++)
        for(j=0;j<numNodos;j++){
        if(arcos[i][j]!=0 && arcos[i][j]!='#')
                warshallC[i][j]=1;
        else
            warshallC[i][j]=arcos[i][j];
        }  
    for(k=0;k < numNodos; k++)
        for(j=0;j < numNodos;j++)
            for(i=0;i < numNodos;i++)
                if(!warshallC[i][j])
                    warshallC[i][j] = warshallC[i][k] && warshallC[k][j];
	
	// Implementar este algoritmo

    DEPURAR_MSG ("Sale de Grafo::Warshall()"<<endl);
}


/**
* Metodo que realiza el algoritmo de Floyd sobre el grafo
* \param "" No recibe parametros
* \return No retorna ningun valor
*/
void Grafo::floyd (void)
{
    DEPURAR_MSG ("Entra en Grafo::Floyd()"<<endl);
    int i,j,k;
    for(i=0;i<numNodos;i++)
        for(j=0;j<numNodos;j++)
            floydC[i][j]=arcos[i][j];
    for(k=0;k<numNodos;k++)
        for(j=0;j<numNodos;j++)
            for(i=0;i<numNodos;i++)
                if((floydC[i][k]+floydC[k][j])<floydC[i][j]){
                    floydC[i][j]=floydC[i][k]+floydC[k][j];
                    floydP[i][j]=k;
                }
                


	// Implementar este algoritmo

    DEPURAR_MSG ("Sale de Grafo::Floyd()"<<endl);
}

/**
* Metodo que devuelve el siguiente nodo en la ruta entre un origen y un destino
* \param origen es el primer nodo
* \param destino es el segundo nodo
* \param sig parametro de entrada salida que devuelve el siguiente nodo en la ruta entre origen y destino
* \return No retorna ningun valor
*/
void Grafo::siguiente(TipoNodoGrafo origen, TipoNodoGrafo destino, TipoNodoGrafo &sig)
{
    DEPURAR_MSG ("Entra en Grafo::siguiente(TipoNodoGrafo origen, TipoNodoGrafo destino, TipoNodoGrafo &sig)"<<endl);
    bool enc=false;
    int j=destino;
    while(!enc){
        if(floydP[origen][j]==-1){
            enc=true;
            sig=j;
        }
        else
            j=floydP[origen][j];
    }

	// Implementar este algoritmo
    DEPURAR_MSG ("Sale de Grafo::siguiente(TipoNodoGrafo origen, TipoNodoGrafo destino, TipoNodoGrafo &sig)"<<endl);
}



/**
* Metodo que devuelve el conjunto (en una cola) de nodos adyacentes al nodo actual
* \param origen es el nodo actual
* \param sig parametro de entrada salida que devuelve el conjunto de nodos adyacentes (en una cola)
* \return No retorna ningun valor
*/
void Grafo::adyacentes(TipoNodoGrafo origen, TipoCjtoNodos &ady)
{
   DEPURAR_MSG ("Entra en Grafo::adyacentes(TipoNodoGrafo origen, TipoCjtoNodos &ady)"<<endl);
   int j;
   ady.begin();
   for(j=0;j<numNodos;j++){
       if(arcos[origen][j]!=INFINITO && arcos[origen][j]!=0){
                ady.insert(j);
        }
   }


	// Implementar este algoritmo

   DEPURAR_MSG ("Sale de Grafo::adyacentes(TipoNodoGrafo origen, TipoCjtoNodos &ady)"<<endl);  
}



//RECORRIDOS DEL GRAFO
// void anchura(Grafo &g, TipoNodoGrafo v,TipoCjtoNodos & visitados){
//     TipoCjtoNodos ady;
//     TipoNodoGrafo w;
//     queue <TipoNodoGrafo> c;
//     c.push(v);
//     visitados.insert(v);
//     while(!c.empty()){
//         v=c.front();
//         c.pop();
//         cout<<v<<endl;
//         g.adyacentes(v,ady);
//         TipoCjtoNodos :: iterator it;
//         for(it=ady.begin();it!=ady.end();it++){
//             w=*it;
//             if(!visitados.count(w)){
//         
//                 visitados.insert(w);
//                 c.push(w);
//             }
//         }
//     }
// 
// }
// void prof(Grafo &g, TipoNodoGrafo v,TipoCjtoNodos & visitados){
//     TipoCjtoNodos ady;
//     TipoNodoGrafo w;
//     visitados.insert(v);
//     cout<<v<<endl;
//     g.adyacentes(v,ady);
//     TipoCjtoNodos :: iterator it;
//     it=ady.begin();
//     while(!ady.empty()){
//         w=*it;
//         it++;
//         ady.erase(w);
// 
//         if(!visitados.count(w)){
//             prof(g,w,visitados);
//         }
//     }
// }
// void profundidad(Grafo &g, TipoNodoGrafo v,TipoCjtoNodos & visitados){
//     prof(g,v,visitados);
// }
// bool vueltaAtras(Grafo &g, TipoNodoGrafo o,TipoNodoGrafo d,TipoCjtoNodos & visitados)
// {
//     bool fin=false;
//     visitados.insert(o);
//     if(o==d)
//         fin=true;
//     cout << o << endl;
//     TipoCjtoNodos ady;
//     g.adyacentes(o, ady);
//     TipoCjtoNodos::iterator it = ady.begin();
// 
//     if (!ady.empty())
//     {
//         while(!ady.empty() && !fin)
//         {
//             TipoNodoGrafo w = *it;
//             it++;
//             ady.erase(w);
// 
//             if(!visitados.count(w)){
//                 fin=vueltaAtras(g, w,d, visitados);
//                 if(!fin)
//                     cout << o << endl;
//                 
//                 
//             }
//         }
//     }
//     return fin;
// }
// 
// void caminoMinimoEntero(Grafo &g,TipoNodoGrafo origen, TipoNodoGrafo destino)
// {
//     int i=-1;
//     int aux=origen;
//     cout<<origen<<" --> ";
//     while(i!=destino){
//         g.siguiente(aux,destino,i);
//         cout<<i;
//         aux=i;
//         if(i!=destino)
//             cout<<" --> ";
//     }
// }









