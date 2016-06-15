/**
 * \file fichero.h
 * \brief Práctica 2007-2008. Declaracion de la clase FicheroCarga
 * \author
 *   \b Profesores LPII \n
 *   \b Asignatura Laboratorio de Programación II \n
 *   \b Curso 07/08 -- Revisado en Curso 08/09
 */

#ifndef FICHERO_H
#define FICHERO_H

#include <fstream>
#include <iostream>
#include <string>


/**

* \var MAXCAMPOS
* \brief Constante con el número máximo de campos de una línea del fichero de configuración
*/

#define MAXCAMPOS 8

using namespace std;

class Cargador;

/**

* \class FicheroCarga
* \brief Esta clase carga el sistema con los elementos indicados en el fichero de configuración
*/
class FicheroCarga{

		static int trocearLinea(string linea,string vCampos[MAXCAMPOS]);//tiene una linea que es un string, vuelva ese string en un vector de string 
	public:
		static void procesarFichero(string nombre, Cargador& cargador);//le pasamos un string que es el nombre del fichero y lo que hace es que cada vez que encuentre una linea correcta trocea ese linea, llama al trocear linea y despues de trocear la linea llama a la clase cargador
};
#endif
