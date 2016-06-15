/**
* \file fichero.cpp
* \brief Implementacion de la clase FicheroCarga
* \author
*   \b Profesores LPII \n
*   \b Asignatura Laboratorio de Programacion II \n
 *   \b Curso 07/08 -- Revisado en Curso 08/09
*/

#include "fichero.h"
#include "cargador.h"

/**
* Divide una cadena en los campos que la forman, token de separación '#'
* \param linea cadena orgien a dividir
* \param vCampos[MAXCAMPOS] vector que contendrá los valores de los campos
* \return Número de campos que contenía la cadena origen
*/
int FicheroCarga::trocearLinea(string linea,string vCampos[MAXCAMPOS])
{
    bool eol = false;
    int pos=0,posini = 0, numCampos=0;

    DEPURAR_MSG("Entra en Cargador::trocearLinea ("<<linea<<")");

    while (!eol)
    {
        pos = linea.find("#",posini);
        if (pos == string::npos)
        {
            eol = true;
        }
        else
        {
            vCampos[numCampos] = linea.substr(posini,pos);
            linea.erase(posini,pos+1);
            numCampos++;
        }
    }

    DEPURAR_MSG("Sale de Fichero::trocearLinea: "<<numCampos);

    return numCampos;
}

/**
* Procesa el fichero de configuración para cargar el sistema
* No procesa las líneas que comienzan por --
* \param nombre nombre del fichero de configuración a cargar
* \return No devuelve ningún valor
*/
void FicheroCarga::procesarFichero(string nombre, Cargador& cargador)
{
    string vCampos[MAXCAMPOS];
    char linea[300];
    int numCampos;

    DEPURAR_MSG("Entra en Fichero::procesarFichero ("<<nombre<<")");

    ifstream fIn(nombre.c_str());
    if (fIn.good())
    {
        while (!fIn.eof())
        {
            fIn.getline(linea,300);
            if (linea[0]!='-' && linea[1]!='-')
            {
                numCampos = trocearLinea(linea,vCampos);
                cargador.crear(vCampos[0],numCampos,vCampos);
            }
        }
    }
    //  else
    //    throw ErrorAperturaFichero ("Apertura de Fichero de Inicio");

    fIn.close();
    //   if (fIn.bad())
    //     throw ErrorFichero("Procesando el Fichero de Inicio");

    DEPURAR_MSG("Sale de Fichero::procesarFichero");
}
