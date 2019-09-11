/**
 * Project TP1EJ2SERVIDOR
 */


#include "ManejadorCache.h"

/**
 * ManejadorCache implementation
 * 
 * Esta cache hace uso de std::map
 * mantiene una cola, con las claves mas usadas.
 * cuando se acabe la memoria, comenzara a borrar las menos usadas de la lista. hasta que pueda guardar el nuevo dato.
 */


/**
 * retorna el archivo si esta, si no esta sera null
 * 
 * @param direccionArchivo
 * @return ARCHIVO
 */
ARCHIVO ManejadorCache::consultaArchivo(string direccionArchivo) {
    perror("\nSoy ManejadorCache, siempre retorno archivos nulos, no tengo implementado mi cache LRU\n");
    
    struct ARCHIVO file;
    file.puntero=NULL;
    return file;
}

/**
 * lo mismo que en consultarArchivo, hay que ver de que forma, se implementa en memoria ram un archivo.
 * 
 * @param file
 */
void ManejadorCache::agregarArchivo(ARCHIVO file) {

}
/**
 *Constructor 
 **/
ManejadorCache::ManejadorCache() {
    cout<<"Constructor manejador cache\n";
}

/**
 * Destructor
 */
ManejadorCache::~ManejadorCache()
{
    cout<<"Destructor cache, actualmente, no borra nada\n";
}


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
 * @return bool
 */
bool ManejadorCache::liberarEspacio(int size) {
    return false;
}