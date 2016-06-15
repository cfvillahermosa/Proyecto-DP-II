#include "planta.h"

/**
 * Constructor por defecto de mi clase planta
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
planta::planta()
{
    p=new puerta;
    idplanta=0;
    salaentrada=0;
    salasalida=0;
    nllaves=0;
    altoplanta=0;
    anchoplanta=0;
    for(int i=0;i<altoplanta*anchoplanta;i++){
        insertarVector(new sala(i,i,0));
    }
    for(int i=0;i<anchoplanta*altoplanta;i++){
        insertarNodoGrafo(i);
    }
}
/**
 * Constructor parametrizado de mi clase planta
 * \param idp es un parametro de entrada del tipo entero asociado al atributo idplanta de mi clase Planta
 * \param se es un prametro de entrada del tipo entero asociado al atributo salaentrada de mi clase Planta
 * \param ss es un parametro de entrada del tipo entero asociado al atributo salasalida de mi clase Planta
 * \param nll es un parametro de entrada del tipo entero asociado al atributo nllaves e mi clase planta
 * \param anch es un parametro de entrada del tipo entero asociado al atributo anchoplanta de mi clase Planta
 * \param alt es un parametro de entrada del tipo entero asociado al atributo altoplanta de mi clase Planta
 * \return No retorna ningun valor
 */
planta::planta(int idp, int se, int ss, int nll, int anch, int alt)
{
    p=new puerta;
    idplanta=idp;
    salaentrada=se;
    salasalida=ss;
    nllaves=nll;
    anchoplanta=anch;
    altoplanta=alt;
    for(int i=0;i<altoplanta*anchoplanta;i++){
        insertarVector(new sala(i,i,0));
    }
    for(int i=0;i<anchoplanta*altoplanta;i++){
        insertarNodoGrafo(i);
    }
   
}

/**
 * Destructor de mi clase planta
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
planta::~planta()
{
    for(int i=0;i<v.size();i++){
        delete v[i];
    }
    delete p;
}



/**
 * Metodo que establece el valor n al atributo idplanta de mi clase planta 
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::setIdPlanta(int n)
{
    idplanta=n;
}
/**
 * Metodo que devuelve el valor de mi atributo idplanta de mi clase Planta
 * \param "" no recibe parametros
 * \return Retorna un entero correspondiente con el valor del atributo idplanta de mi clase Planta
 */
int planta::getIdPlanta()
{
    return idplanta;
}
/**
 * Metodo que establece el valor n al atributo salaentrada de mi clase planta 
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::setSalaEntrada(int n)
{
    salaentrada=n;
}
/**
 * Metodo que devuelve el entero asociado al valor del atributo salaentrada de mi clase PLanta
 * \param "" no recibe parametros
 * \return Retorna el entero correspondiente al atributo salaentrada de mi clase Planta
 */
int planta::getSalaEntrada()
{
    return salaentrada;
}
/**
 * Metodo que establece el valor n al atributo salasalida de mi clase planta 
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::setSalaSalida(int n)
{
    salasalida=n;
}
/**
 * Metodo devuelve el valor asociado a mi atributo salasalida de mi clase Planta
 * \param "" no recibe parametros
 * \return Retorna el entero correspondiente al atributo salasalida de mi clase Planta
 */
int planta::getSalaSalida()
{
    return salasalida;
    
}
/**
 * Metodo calcula los posibles vecinos de una sala 
 * \param s es un parametro de entrada (puntero) de la clase Sala
 * \param larcos es un parametro de entrada salida del tipo lista (ED STL) que almacena datos del tipo TipoArco
 * \return No retorna ningun valor
 */
void planta::calcularPosiblesVecinos(sala *s, list< TipoArco > & larcos)
{
    TipoArco A;
    if( (s->getIdentificadorSala() - anchoplanta) >=0){//norte
        A.x=s->getIdentificadorSala();
        A.y=s->getIdentificadorSala()-anchoplanta;
        larcos.push_back(A);
    }
    if( (s->getIdentificadorSala() % anchoplanta) < (anchoplanta-1) ){//este
        A.x=s->getIdentificadorSala();
        A.y=s->getIdentificadorSala()+1;
        larcos.push_back(A);
    }
    if( (s->getIdentificadorSala() + anchoplanta ) < (anchoplanta*altoplanta) ){//sur
        A.x=s->getIdentificadorSala();
        A.y=s->getIdentificadorSala()+anchoplanta;
        larcos.push_back(A);
    }
    if( (s->getIdentificadorSala() % anchoplanta) > 0 ){//oeste
        A.x=s->getIdentificadorSala();
        A.y=s->getIdentificadorSala()-1;
        larcos.push_back(A);
    }
    
}
/**
 * Metodo que calcula los vecinos de cada una de las salas de mi vector de salas de mi clase Planta
 * \param larcos es un parametro de entrada salida del tipo list (ED STL) que almacena datos del tipo TipoArco
 * \return No retorna ningun valor
 */
void planta::vecinosTodasSalas(list< TipoArco > & larcos)
{
    for(int i=0;i<altoplanta*anchoplanta;i++){
        calcularPosiblesVecinos(v[i],larcos);
    }
    
}
/**
 * Metodo que inserta en mi vector de salas de mi clase planta un puntero a una instancia de mi clase Sala
 * \param s es un parametro de entrada puntero a una instancia de la clase Sala
 * \return No retorna ningun valor
 */
void planta::insertarVector(sala * s)
{
    v.push_back(s);
}
/**
 * Metodo establece un valor al atributo nllaves de mi clase Planta
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::setNLlaves(int n)
{
    nllaves=n;
}
/**
 * Metodo que devuelve el valor del atributo nllaves de mi clase Planta
 * \param "" no recibe parametros
 * \return Devuelve el entero correspondiente a mi atributo nllaves de mi clase PLanta
 */
int planta::getNLlaves()
{
    return nllaves;
}
/**
 * Metodo que establece el valor n al atributo anchoplanta de mi clase planta 
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::setAnchoPlanta(int n)
{
    anchoplanta=n;
}
/**
 * Metodo que devuelve el valor asociado al atributo anchoplanta de mi clase Planta
 * \param "" no recibe parametros
 * \return Devuelve un valor del tipo entero correspondiente al atributo anchoplanta de mi clase PLanta
 */
int planta::getAnchoPlanta()
{
    return anchoplanta;
}
/**
 * Metodo que establece el valor n al atributo altoplanta de mi clase planta 
 * \param n es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::setAltoPlanta(int n)
{
    altoplanta=n;
}
/**
 * Metodo que devuelve el valor asociado a mi atributo altoplanta de mi clase PLanta
 * \param "" no recibe parametros
 * \return devuelve el valor correspondiente a mi atributo altoplanta de mi clase Planta
 */
int planta::getAltoPlanta()
{
    return altoplanta;
}
/**
 * Metodo que inserta un nodo nuevo en el grafo de mi clase Planta 
 * \param n es un parametro de entrada del tipo TipoNodoGrafo
 * \return No retorna ningun valor
 */
void planta::insertarNodoGrafo(TipoNodoGrafo n)
{
    g.nuevoNodo(n);
}
/**
 * Metodo me devuelve un puntero a una sala correspondiente con la posicion i 
 * \param i es un parametro de entrada del tipo entero
 * \param s es un parametro de salida del tipo instancia a la clase Sala
 * \return No retorna ningun valor
 */
void planta::obtenerCeldaVector(int i, sala *& s)
{
    s=v[i];
}
/**
 * Metodo que realiza el algoritmo de kruskal
 * \param l es un parametro de entrada salida del tipo list (ED STL) 
 * \return No retorna ningun valor
 */
void planta::algoritmoKruskal(list< TipoArco > & l)
{
    TipoArco aux;
    int naleatorio;
    for(int i=0;i<anchoplanta*altoplanta;i++){
        g.nuevoNodo(i);
    }
    list <TipoArco> ::iterator it;
    while(!l.empty()){
        naleatorio=GenAleatorios::generarNumero(l.size());
        it=l.begin();
        for(int i=0;i<naleatorio;i++)
            it++;
        aux=*it;
        sala *x=v[aux.x];
        sala *y=v[aux.y];
        sala *a;
        int marcay=y->getMarcaSala();
        if(x->getMarcaSala() != y->getMarcaSala()){
            g.nuevoArco(aux.x,aux.y,1);
            g.nuevoArco(aux.y,aux.x,1); 
            for(int i=0;i<v.size();i++){ 
                a=v[i];
                if(a->getMarcaSala()==marcay){
                    a->setMarcaSala(x->getMarcaSala());
                }
            }
        }
        
        l.erase(it);   
    }
}
/**
 * Metodo que pinta en mi registro.log la estructura de cada planta 
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::pintarEstructura(ofstream & f)
{
    sala*s;
    if(f.good()){
        f<<" ";
        for(int i=0;i<anchoplanta;i++)
            f<<"_ ";
        f<<endl;
        for(int i=0;i<anchoplanta*altoplanta;i++){
            s=v[i];
            if( (s->getIdentificadorSala()%anchoplanta)==0 ){//si estoy en el limite de la izquierda
                f<<"|";
            }
            else{
                if(g.adyacente(s->getIdentificadorSala(),s->getIdentificadorSala()-1))
                    f<<" ";
                
                else
                    f<<"|";
                    
            }
            if( (s->getIdentificadorSala()+anchoplanta)>=(anchoplanta*altoplanta) ){//si estoy en el limite de abajo
                f<<"_";
            }
            else{
                if(g.adyacente(s->getIdentificadorSala(),s->getIdentificadorSala()+anchoplanta)){
                    //aquiiiii
                        f<<" ";
                }
                
                else
                    f<<"_";
            }
            if( (s->getIdentificadorSala()%anchoplanta) == (anchoplanta-1) ){
                f<<"|"<<endl;
            }
        }
    }
}
/**
 * Metodo que genera los atajos correspondientes hasta llegar al 5% del total de salas que posee el vector de salas de mi clase PLanta 
 * \param "" no recibe parametros 
 * \return No retorna ningun valor
 */
void planta::generarAtajos()
{
    int nporcientosalas= ( (5*v.size())/100 );
    int cont=0;
    int naleatorio;
    sala *s; 
    while( cont!=nporcientosalas ){
        naleatorio=GenAleatorios::generarNumero(anchoplanta*altoplanta);
        s=v[naleatorio];
        if(siHayAtajo(s)){
            cont++;
        }
    }
    
    g.floyd();
    g.warshall();
}
/**
 * Metodo que calcula los atajos por el norte  
 * \param s es un parametro de entrada del tipo puntero a instancia de la clase Sala
 * \return Retorna true en caso de que haya atajo por el norte y false en caso contrario
 */
bool planta::AtajoNorte(sala * s)
{
    if( (s->getIdentificadorSala()-anchoplanta ) >= 0 ){
        if( !g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()-anchoplanta) ) ){
            bool condicion1=false,condicion2=false;
            if( g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()-1) ) ){
                if( g.adyacente( (s->getIdentificadorSala()-1), ((s->getIdentificadorSala()-1)-anchoplanta) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()-1)-anchoplanta), ((s->getIdentificadorSala()-1)-anchoplanta)+1) ){
                        condicion1=true;
                    }
                }
            }
            if(  g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()+1) )  ){
                if( g.adyacente( (s->getIdentificadorSala()+1), ((s->getIdentificadorSala()+1)-anchoplanta) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()+1)-anchoplanta),(((s->getIdentificadorSala()+1)-anchoplanta)-1) ) ){
                        condicion2=true;
                    }
                }
            }
            if(!condicion1 && !condicion2)
                return true;
            else
                return false;  
        }
        else
            return false;
    }
    else
        return false;  
}
/**
 * Metodo que calcula los atajos por el sur  
 * \param s es un parametro de entrada del tipo puntero a instancia de la clase Sala
 * \return Retorna true en caso de que haya atajo por el sur y false en caso contrario
 */
bool planta::AtajoSur(sala * s)
{
    if( (s->getIdentificadorSala() + anchoplanta ) < (anchoplanta*altoplanta) ){
        if( !g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()+anchoplanta) ) ){
            bool condicion1=false,condicion2=false;
            if( g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()-1) ) ){
                if( g.adyacente( (s->getIdentificadorSala()-1), ((s->getIdentificadorSala()-1)+anchoplanta) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()-1)+anchoplanta),((s->getIdentificadorSala()-1)+anchoplanta)+1) ){
                        condicion1=true;
                    }
                }
            }
            if( g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()+1) ) ){
                if( g.adyacente((s->getIdentificadorSala()+1), ((s->getIdentificadorSala()+1)+anchoplanta) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()+1)+anchoplanta), ((s->getIdentificadorSala()+1)+anchoplanta)-1) ){
                        condicion2=true;
                    }
                }
            }
            if( !condicion1 && !condicion2)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
/**
 * Metodo que calcula los atajos por el oeste
 * \param s es un parametro de entrada del tipo puntero a instancia de la clase Sala
 * \return Retorna true en caso de que haya atajo por el oeste y false en caso contrario
 */
bool planta::AtajoOeste(sala * s)
{
    if( (s->getIdentificadorSala() % anchoplanta) > 0 ){
        if(!g.adyacente( s->getIdentificadorSala(),s->getIdentificadorSala()-1 ) ){
            bool condicion1=false,condicion2=false;
            if( g.adyacente( s->getIdentificadorSala(),(s->getIdentificadorSala()-anchoplanta) ) ){
                if(g.adyacente( (s->getIdentificadorSala()-altoplanta),((s->getIdentificadorSala()-anchoplanta)-1) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()-anchoplanta)-1),((s->getIdentificadorSala()-anchoplanta)-1)+anchoplanta) ){
                        condicion1=true;
                    }
                }
            }
            if( g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()+anchoplanta) ) ){
                if( g.adyacente( (s->getIdentificadorSala()+anchoplanta), ((s->getIdentificadorSala()+anchoplanta)-1) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()+anchoplanta)-1), ((s->getIdentificadorSala()+anchoplanta)-1)-anchoplanta) ){
                        condicion2=true;
                    }
                }
            }
            if( !condicion1 && !condicion2)
                return true;
            else
                return false;
        }
        else 
            return false;
    }
    else
        return false;
}
/**
 * Metodo que calcula los atajos por el este  
 * \param s es un parametro de entrada del tipo puntero a instancia de la clase Sala
 * \return Retorna true en caso de que haya atajo por el este y false en caso contrario
 */
bool planta::AtajoEste(sala * s)
{
    if( (s->getIdentificadorSala() % anchoplanta) < (anchoplanta-1) ){
        if( !g.adyacente( s->getIdentificadorSala(), s->getIdentificadorSala()+1) ){
            bool condicion1=false,condicion2=false;
            if( g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()-anchoplanta) ) ){
                if( g.adyacente( (s->getIdentificadorSala()-anchoplanta), ((s->getIdentificadorSala()-anchoplanta)+1) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()-anchoplanta)+1), (((s->getIdentificadorSala()-anchoplanta)+1)+anchoplanta) ) ){
                        condicion1=true;
                    }
                }
            }
            if( g.adyacente( s->getIdentificadorSala(), (s->getIdentificadorSala()+anchoplanta) ) ){
                if( g.adyacente( (s->getIdentificadorSala()+anchoplanta), ((s->getIdentificadorSala()+anchoplanta)+1) ) ){
                    if( g.adyacente( ((s->getIdentificadorSala()+anchoplanta)+1),((s->getIdentificadorSala()+anchoplanta)+1)-anchoplanta) ){
                        condicion2=true;
                    }
                }
            }
            if( !condicion1 && !condicion2 )
                return true;
            else
                return false;
        }
        else 
            return false;
    }
    else
        return false;
}
/**
 * Metodo booleano que me indica la existencia o no de un atajo  
 * \param s es un parametro de entrada del tipo puntero a instancia de la clase Sala
 * \return Retorna true en caso de que haya atajo y false en caso contrario
 */
bool planta::siHayAtajo(sala * s)
{
    if( AtajoNorte(s) ){
        g.nuevoArco(s->getIdentificadorSala(),s->getIdentificadorSala()-anchoplanta,1);
        g.nuevoArco(s->getIdentificadorSala()-anchoplanta,s->getIdentificadorSala(),1);
        cout<<"tiro pared por el norte en: "<<s->getIdentificadorSala()<<" "<<s->getIdentificadorSala()-anchoplanta<<endl;
        return true;
    }
    else{
        if( AtajoSur(s) ){
            g.nuevoArco(s->getIdentificadorSala(),s->getIdentificadorSala()+anchoplanta,1);
            g.nuevoArco(s->getIdentificadorSala()+anchoplanta,s->getIdentificadorSala(),1);
            cout<<"tiro pared por el sur en: "<<s->getIdentificadorSala()<<" "<<s->getIdentificadorSala()+anchoplanta<<endl;
            return true;
        }
        else{
            if( AtajoOeste(s) ){
                g.nuevoArco( s->getIdentificadorSala(),s->getIdentificadorSala()-1,1);
                g.nuevoArco( s->getIdentificadorSala()-1,s->getIdentificadorSala(),1);
                cout<<"tiro pared por el oeste en: "<<s->getIdentificadorSala()<<"  "<<s->getIdentificadorSala()-1<<endl;
                return true;
            }
            else{
                if( AtajoEste(s) ){
                    g.nuevoArco( s->getIdentificadorSala(),s->getIdentificadorSala()+1,1);
                    g.nuevoArco( s->getIdentificadorSala()+1,s->getIdentificadorSala(),1);
                    cout<<"tiro pared por el este en: "<<s->getIdentificadorSala()<<" "<<s->getIdentificadorSala()+1<<endl;
                    return true;
                }
                else
                    return false;
            }
        }
    }
}
/**
 * Metodo que se encarga de generar todo lo corespondiente a la planta en el registro.log  
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::generarPlanta(ofstream & f)
{
    list <TipoArco> l;
    vecinosTodasSalas(l);
    algoritmoKruskal(l);
    pintarEstructura(f);
    f<<"(planta con ciclos)"<<endl;
    generarAtajos();
    pintarEstructura(f);
    f<<"(distribucion llaves)"<<endl;
    repartoLlaves(f);
    calcularVecinosRealesTodasSalas();
    
}
/**
 * Metodo que se encarga de repartir las llaves por las distintas salas 
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::repartoLlaves(ofstream & f)
{
    Lista <Llave*> *combinacion, *llaves_recogidas;
    combinacion=new Lista<Llave*>;
    llaves_recogidas=new Lista<Llave*>;
// Generar la combinación secreta y la lista de llaves a probar
    for (int i=0; i<nllaves; i++) {
        llaves_recogidas->insertarOrdenado(new Llave(i));
        if ((i % 2) != 0)       {
            llaves_recogidas->insertarOrdenado(new Llave(i));
            combinacion->insertarOrdenado(new Llave(i));
        }
    }
    
    sala *aux2;
    
    p->configurarPuerta(combinacion);
    p->cerrar();
    TipoCjtoNodos visitados;
    salasMasFrecuentadas(salaentrada,visitados);
    priority_queue <sala*,vector<sala*>,compararFrecuencias> c;
    for(int i=0;i<altoplanta*anchoplanta;i++){
        c.push(v[i]);
        aux2=v[i];
    }
    int contexterno=0;
    int continterno;
    sala *aux;
    Llave *l;
    llaves_recogidas->moverInicio();
    while(contexterno!=nllaves+nllaves/2){
        continterno=0;
        while (continterno!=5){
            aux=c.top();
            c.pop();
            if(aux->getIdentificadorSala()!=salaentrada && aux->getIdentificadorSala()!=salasalida)
                for(int i=0;i<5;i++){
                    l=llaves_recogidas->consultar();
                    aux->insertarLista(l);
                    llaves_recogidas->avanzar();
                    continterno++;
                }
             if(aux->getIdentificadorSala()!=salaentrada && aux->getIdentificadorSala()!=salasalida)
                    aux->escribeLog(f);
        }
        
        
        contexterno=contexterno+5;
    }
    delete combinacion;
    delete llaves_recogidas;
}
/**
 * Metodo que se encarga de aumentar las frecuencias de las salas de mi vector de salas de mi clase PLanta
 * \param f es un parametro de entrada del tipo TipoNodoGrafo
 * \param visitados es un parametro de entrada del tipo TipoCjtoNodos
 * \return No retorna ningun valor
 */
void planta::salasMasFrecuentadas(TipoNodoGrafo f,TipoCjtoNodos  visitados)
{
    sala *aux;
    TipoCjtoNodos ady;
    TipoNodoGrafo w;
    TipoNodoGrafo a;
    visitados.insert(f);
    TipoCjtoNodos :: iterator it;
    if( f== salasalida){
        TipoCjtoNodos :: iterator it2=visitados.begin();
        for(it2=visitados.begin();it2!=visitados.end();it2++){
            a=*it2;
            aux=this->v[a];
            aux->setFrecuenciaSala(aux->getFrecuenciaSala()+1);
        }
    }
    g.adyacentes(f,ady);
    
    
    for(it=ady.begin(); it!=ady.end();it++){
        w=*it;
        if(!visitados.count(w)){
            salasMasFrecuentadas(w,visitados);
        }
    }
}
/**
 * Metodo que establece la condicion de apertura de la puerta de mi clase PLanta
 * \param ap es un parametro de entrada del tipo entero 
 * \return No retorna ningun valor
 */
void planta::establecerCondicionApertura(int ap)
{
    p->setAlturaMaxima(ap);
}
/**
 * Metodo que se encarga de repartir las llaves por las distintas salas 
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::insertarPersonajeSala(Personaje * p)
{
    if(p->getIdSala()!=1111)
        v[p->getIdSala()]->insertarCola(p);
    
}
/**
 * Metodo que devuelve el tamaño de mi vector de salas de mi clase PLanta ( es decir, el numero de salas de cada planta)
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
int planta::totalSalas()
{
    return v.size();
}


/**
 * Metodo que se encarga de pintar todos los personajes de cada sala en mi registro.log ( pinta un entero si hay mas de un personaje o su marca en caso de que solo haya un personaje)
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::pintarPersonajes(ofstream & f)
{
    sala*s;
    
        for(int i=0;i<anchoplanta;i++)
            f<<" _";
        f<<endl;
        for(int i=0;i<anchoplanta*altoplanta;i++){
            s=v[i];
            if( (s->getIdentificadorSala()%anchoplanta)==0 ){//si estoy en el limite de la izquierda
                f<<"|";
            }
            else{
                if(g.adyacente(s->getIdentificadorSala(),s->getIdentificadorSala()-1))
                    f<<" ";
                
                else
                    f<<"|";
                    
            }
            if(s->siHayPersonajes()){
                if(s->cuantosPersonajes() ==1){
                    Personaje *aux;
                    s->devolverFrente(aux);
                    f<<aux->getMarca();
                }
                else{
                    int cuantos=s->cuantosPersonajes();
                    f<<s->cuantosPersonajes();
                }
            }
            else{
            
            
                if( (s->getIdentificadorSala()+anchoplanta)>=(anchoplanta*altoplanta) ){//si estoy en el limite de abajo
                    f<<"_";
                }
                else{
                    if(g.adyacente(s->getIdentificadorSala(),s->getIdentificadorSala()+anchoplanta)){
                    
                            f<<" ";
                    
                    }
                
                    else
                        f<<"_";
                }
            }
            if( (s->getIdentificadorSala()%anchoplanta) == (anchoplanta-1) ){
                f<<"|"<<endl;
            }
        }
    

}
/**
 * Metodo que me devuelve el entero correspondiente al nodo siguiente entre los nodos origen y destino
 * \param origen es un parametro de entrada del tipo entero que determina donde empieza mi camino
 * \param destino es un parametro de entrada del tipo entero que determina donde termina mi camino
 * \param sig es un parametro de salida del tipo entero que me devuelve el entero correspondiente al nodo siguiente que se encuentra entre los nodos origen y destino
 * \return No retorna ningun valor
 */
void planta::siguienteGrafo(int origen, int destino, int & sig)
{
    g.siguiente(origen,destino,sig);
}
/**
 * Metodo que calcula las rutas de todos los personajes que estan incluidos dentro de cada sala de mi vector de salas de mi clase PLanta
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::calcularRutaSalasPlanta(ofstream & f)
{
    for(int i=0;i<v.size();i++){
        v[i]->calcularRutaPersonajeSala(f);
    }
}
/**
 * Metodo que calcula los vecinos reales correspondientes a la sala s 
 * \param s es un parametro de entrada del tipo puntero a instancia de la clase Sala que es mi sala de referencia para calcular sus vecinos reales
 * \return No retorna ningun valor
 */
void planta::calcularVecinosReales(sala * s)
{
    vector <sala*> aux;
    if( (s->getIdentificadorSala() - anchoplanta) >=0){//norte
        if( g.adyacente(s->getIdentificadorSala(), s->getIdentificadorSala()-anchoplanta) ){
            aux.push_back(v[s->getIdentificadorSala()-anchoplanta]);
        }
        else{
            aux.push_back(NULL);
        }
    }
    else{
        aux.push_back(NULL);
    }
    
    if( (s->getIdentificadorSala() % anchoplanta) < (anchoplanta-1) ){//este
        if( g.adyacente(s->getIdentificadorSala(), s->getIdentificadorSala()+1) ){
            aux.push_back(v[s->getIdentificadorSala()+1]);
        }
        else{
            aux.push_back(NULL);
        }
    }
    else{
        aux.push_back(NULL);
    }
    
    if( (s->getIdentificadorSala() + anchoplanta ) < (anchoplanta*altoplanta) ){//sur
        if( g.adyacente(s->getIdentificadorSala(), s->getIdentificadorSala()+anchoplanta) ){
            aux.push_back(v[s->getIdentificadorSala()+anchoplanta]);
        }
        else{
            aux.push_back(NULL);
        }
    }
    else{
        aux.push_back(NULL);
    }
    if( (s->getIdentificadorSala() % anchoplanta) > 0 ){//oeste
        if( g.adyacente(s->getIdentificadorSala(), s->getIdentificadorSala()-1) ){
            aux.push_back(v[s->getIdentificadorSala()-1]);
        }
        else{
            aux.push_back(NULL);
        }
    }
    else{
        aux.push_back(NULL);
    }
    s->volcarVectorVecinos(aux);
}
/**
 * Metodo que repite la funcion anterior para cada una de mis salas de mi vector de salas de mi clase PLanta 
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void planta::calcularVecinosRealesTodasSalas()
{
    for(int i=0;i<v.size();i++)
        calcularVecinosReales(v[i]);
}

/**
 * Metodo que me copia en puer el atributo p de mi clase planta
 * \param puer es un parametro de salida del tipo puntero a instancia de la clase Puerta
 * \return No retorna ningun valor
 */
void planta::obtenerPuerta(puerta *& puer)
{
    puer=p;
}
/**
 * Metodo que se encarga de realizar las acciones correspondientes a los personajes de cada sala de mi vector de salas
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void planta::accionesPersonajesSalas()
{
    for(int i=0; i<v.size();i++){
        v[i]->accionesColaPersonajes();
    }
}
/**
    * Metodo que se encarga escribir en mi registro.log la informacion correspondiente a Planta
 * \param f es un flujo de entrada salida
 * \return No retorna ningun valor
 */
void planta::escribeLogPlanta(ofstream & f)
{
    f<<"(planta:"<<idplanta<<":"<<salaentrada<<":"<<salasalida<<":"<<nllaves<<")"<<endl;
    p->escribirFichero(f);
    queue <Personaje*> *aux= new queue <Personaje*>;
    Personaje *per;
    pintarPersonajes(f);
    for(int i=0;i<v.size();i++){
        if(v[i]->siHayLlaves()){
            v[i]->escribeLogConEspacio(f);
        }
        
    }
    for(int i=0;i<v.size();i++){
        if(v[i]->siHayPersonajes()){
            while(v[i]->siHayPersonajes()){
                v[i]->devolverPrimerPersonaje(per);
                per->escribeLog(f);
                aux->push(per);
            }
            while(!aux->empty()){
                v[i]->insertarCola(aux->front());
                aux->pop();
            }
        }
    }
    delete aux;
     //   f<<endl;
    
    
    
}