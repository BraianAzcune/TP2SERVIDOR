/**
 * Project TP1EJ2SERVIDOR
 */

#ifndef _MANEJADORARCHIVOS_H
#define _MANEJADORARCHIVOS_H
#include <iostream>
#include <string>

#include "ARCHIVO.h"
#include "ManejadorCache.h"
#include "Utilidades.h"
using namespace std;
class ManejadorArchivos
{
public:
    /**
     * Devuelve un struct ARCHIVO.
     * si el archivo no se encontro, sera NULL.
     * 
     * @param path
     */
    struct ARCHIVO obtenerArchivo(string path);

    /**
    * Constructor, crea ManejadorCache
    */
    ManejadorArchivos();
    
    /**
     * Destructor
     */
    virtual ~ManejadorArchivos();

private:
    
    /**
     * Es un puntero
     *Se incializa en el constructor 
     * Se elimina en el destructor
     */
    ManejadorCache* me;
    
    /**
    * consulta si el archivo existe en disco.
    * (SOLO RUTAS RELATIVAS)
    * si existe devuelve su peso, si no existe, retorna -1
    * @param path
    */
    int buscarArchivo(string path);

    /**
    * carga el archivo en ram
    * @param path
    */
    struct ARCHIVO cargarArchivo(string path);
};

#endif //_MANEJADORARCHIVOS_H