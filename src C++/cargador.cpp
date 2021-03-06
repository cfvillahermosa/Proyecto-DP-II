/**
 * \file cargador.cpp
 * \brief Práctica 2007-2008. Implementación de la Clase Cargador 
 * \author
 *   \b Profesores LPII \n
 *   \b Asignatura Laboratorio de Programación II \n
 *   \b Curso 07/08 -- Revisado en Curso 08/09
 */

#include "cargador.h"
#include "estacion.h"

//Inicialización del mapeo
Cargador::DatoMapeo Cargador::mapeo[NUMELTOSCONF] ={
            //{Nombre, Número de Campos}
            {"PLANTA",8},
            {"INTRUSO",5},
            {"LIDER",5},
            {"TRABAJADOR",4}
        };

/**
* Constructor de Cargador
* \param s Objeto sistema que se va a cargar
*/
Cargador::Cargador(Estacion* p)
{
    DEPURAR_MSG("Entra en Cargador::Constructor parametrizado");
    E=p;
    DEPURAR_MSG("Sale de Cargador::Constructor parametrizado");
}

/**
* Devuelve la posición que ocupa el elemento en el vector de mapeo
* \param elto nombre del elemento
* \return posición que ocupa el elemento en el vector de mapeo
*/
int Cargador::queElemento(string elto)
{
    int res=-1;
    bool enc=false;

    DEPURAR_MSG("Entra en Cargador::queElemento ("<<elto<<")");

    for (int i=0; i<NUMELTOSCONF && !enc; i++)
        if (strcmp(mapeo[i].nombre,elto.c_str())==0)
        {
            res=i;
            enc=true;
        }

    DEPURAR_MSG("Sale de Cargador::queElemento ("<<elto<<"): "<<res);
    return res;
}

/**
* Método que realiza comprobaciones de datos básicos (existe elemento, número campos correcto, existe localidad...)
* \param elto nombre del elemento a crear
* \param numCampos número de campos ocupados del vector vCampos
* \param vCampos[MAXCAMPOS] valores de configuración del elemento a crear
* \return No devuelve nada
*/
void Cargador::crear(string elto, int numCampos, string vCampos[MAXCAMPOS])
{
    DEPURAR_MSG("Entra en Cargador::crear ("<<elto<<","<<numCampos<<")");
    //Si existe elemento y el número de campos es correcto, procesarlo... si no, error
    int numElto = queElemento(elto);

    //Comprobación de datos básicos correctos
    if (numElto!=-1 && mapeo[numElto].numCampos==numCampos)
    {
        //procesar
        switch(queElemento(elto))
        {
        case 0:	   
            crearPlanta(numCampos,vCampos);
            break;
        case 1:
             crearIntruso(numCampos,vCampos);
            break;
        case 2:
            crearLider(numCampos,vCampos);
            break;
        case 3:
            crearTrabajador(numCampos,vCampos);
            break;
     	}
    }
    else
        cout<<"ERROR Cargador::crear: Datos de configuración incorrectos... "<<elto<<","<<numCampos<<endl;
    DEPURAR_MSG("Sale de Cargador::crear");
}

/**
* Método que crea una planta y la registra en la prisión
* \param numCampos número de campos ocupados del vector vCampos
* \param vCampos[MAXCAMPOS] valores de configuración del elemento a crear
* \return No devuelve nada
*/
void Cargador::crearPlanta(int numCampos, string vCampos[MAXCAMPOS])//creamos la planta y la insertamos en la estacion,tenemos un problema, el vector es de string y necesitamos los enteros que se consiguen asi, int id= atoi (vcampos[1].c_str())
{
    DEPURAR_MSG("Entra en Cargador::crearPlanta("<<numCampos<<")");
    cout << "Creada planta: " << vCampos[1] << endl;
    
    
    
    int idp=atoi(vCampos[1].c_str());
    int se=atoi (vCampos[4].c_str());
    int ss=atoi (vCampos[5].c_str());
    int nll= atoi(vCampos[6].c_str());
    int anch=atoi (vCampos[2].c_str());
    int alt=atoi (vCampos[3].c_str());
    
    planta *p=new planta(idp,se,ss,nll,anch,alt);
    p->establecerCondicionApertura( atoi (vCampos[7].c_str()) );
    E->insertarVector(p); 
    //Registrar la planta en la estación
    DEPURAR_MSG("Sale de Cargador::crearPlanta");
}

/**
* Método que crea un preso y lo registra en la prisión
* \param numCampos número de campos ocupados del vector vCampos
* \param vCampos[MAXCAMPOS] valores de configuración del elemento a crear
* \return No devuelve nada
*/
void Cargador::crearIntruso(int numCampos, string vCampos[MAXCAMPOS])
{
    DEPURAR_MSG("Entra en Cargador::crearIntruso ("<<numCampos<<")");
    cout << "Creado Intruso: " << vCampos[1] << endl;
    //Registrar Intruso en estación
    char m=vCampos[2][0];
    string n=vCampos[1];
    int idp=atoi(vCampos[3].c_str());
    int t=atoi(vCampos[4].c_str());
    planta *aux;
    E->obtenerPlanta(idp,aux);
    int ids=aux->totalSalas()-1;
    
    Personaje *per = new Intruso(m,n,t,ids,idp);
    E->insertarPersonajeEstacion(per);
    
    DEPURAR_MSG("Sale de Cargador::crearIntruso");
}


/**
* Método que crea un guarda y lo registra en la prisión
* \param numCampos número de campos ocupados del vector vCampos
* \param vCampos[MAXCAMPOS] valores de configuración del elemento a crear
* \return No devuelve nada
*/
void Cargador::crearLider(int numCampos, string vCampos[MAXCAMPOS])
{
    DEPURAR_MSG("Entra en Cargador::crearLider ("<<numCampos<<")");
    cout << "Creado Lider: " << vCampos[1] << endl;
    //Registrar guarda en estación
    char m=vCampos[2][0];
    string n=vCampos[1];
    int t=atoi(vCampos[4].c_str());
    string sec=vCampos[3];
    int idp=E->totalPlantas()-1;
    
    
    char mov=vCampos[3][3];
    
    planta *aux;
    E->obtenerPlanta(idp,aux);
    int ids=aux->getSalaEntrada();
    
    Personaje *per = new Lider(m,n,t,ids,idp,sec,mov);
    E->insertarPersonajeEstacion(per);
    DEPURAR_MSG("Sale de Cargador::crearLider");
}



void Cargador::crearTrabajador(int numCampos, string vCampos[])
{
    DEPURAR_MSG("Entra en Cargador::crearTrabajador ("<<numCampos<<")");
    cout << "Creado Trabajador: " << vCampos[1] << endl;
    //Registrar guarda en estación
    char m=vCampos[2][0];
    string n=vCampos[1];
    int t=atoi(vCampos[3].c_str());
    int idp=E->totalPlantas()-1;
    
    
    planta *aux;
    E->obtenerPlanta(idp,aux);
    int ids=aux->getSalaEntrada();
    
    Personaje *per = new Trabajador(m,n,t,ids,idp);
    E->insertarPersonajeEstacion(per);
    
    
    DEPURAR_MSG("Sale de Cargador::crearTrabajador");
}