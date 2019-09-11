/**
 * Project TP1EJ2SERVIDOR
 */

#ifndef _MANEJADORCACHE_H
#define _MANEJADORCACHE_H
#include <string>
#include <iostream>

#include "ARCHIVO.h"
#include <map>
#include <queue>
using namespace std;

class ManejadorCache
{
public:
    /**
 * retorna el archivo si esta, si no esta sera null
 * 
 * @param direccionArchivo
 */
    struct ARCHIVO consultaArchivo(string direccionArchivo);

    /**
 * lo mismo que en consultarArchivo, hay que ver de que forma, se implementa en memoria ram un archivo.
 * 
 * @param file
 */
    void agregarArchivo(struct ARCHIVO file);
    /**
 * Constructor
 **/
    ManejadorCache();
    
    virtual ~ManejadorCache();

private:
    /**
 * estructura de datos complexidad logaritmica.
 * poseera como clave la ruta del archivo desde el directorio raiz del servidor.
 * y valor sera el ARCHIVO (falta definir como sera, al parecer los archivos pueden ser representados como un array de chars)
 */
    map<string, struct ARCHIVO> cache;
    int maxSizeCache;
    int sizeCache;
    /**
 * esta cola se utilizara para implementar la logica LRU.
 * asi los elementos mas usados se mantienen al inicio de la fila.
 * y cuando no hay espacio, se borran los ultimos.
 */
    queue<string> cola;

    /**
 * eliminara espacio hasta cumplir con la cantidad de bytes que se necesitan guardar. Si este numero es mayor a lo que deberia guardar la cache ERROR.
 * 
 * Si
 * maxSizeCache-sizeCache-size>0
 * no se hace nada.
 * en caso contrario se liberara espacio hasta cumplir.
 * 
 * 
 * @param size
 */
    bool liberarEspacio(int size);
};

#endif //_MANEJADORCACHE_H