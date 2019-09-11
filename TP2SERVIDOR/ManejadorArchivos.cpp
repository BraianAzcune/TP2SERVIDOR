/**
 * Project TP1EJ2SERVIDOR
 */

#include "ManejadorArchivos.h"

/**
 * ManejadorArchivos implementation
 * 
 * se encargara del acceso al directorio, en caso de que no este en cache.
 */

/**
 * Devuelve un struct ARCHIVO.
 * si el archivo no se encontro, sera NULL.
 * 
 * @param path
 * @return ARCHIVO
 */
ARCHIVO ManejadorArchivos::obtenerArchivo(string path)
{
    struct ARCHIVO file= this->me->consultaArchivo(path);
    
    if(file.puntero==NULL){//El archivo no existe en cache
        cout<<"El archivo no esta en cache\nBuscando en disco\n";
        
        Utilidades::RESPUESTA respuesta= Utilidades::esValido(path);
        
        if(respuesta==Utilidades::RESPUESTA::NO_VALIDO){//EL ARCHIVO NO EXISTE, O ES UN ARCHIVO QUE NO SE PUEDE ENVIAR.
            cout<<"Aqui hay que responder que no existe el archivo y cortar conexion";
        }else if(respuesta==Utilidades::RESPUESTA::ENCONTRADO_MENOR512M){//EL ARCHIVO EXISTE Y ES MENOR A 512 MB
            cout<<"Aqui hay que traer el archivo a ram y luego enviarlo";
        }else{//ES MAYOR A 512 MB
            cout<<"Aqui hay que solo enviarlo";
        }

    }else{//EL ARCHIVO EXISTE EN CACHE
        
    }
}

/**
 * Constructor, crea ManejadorCache
 */
ManejadorArchivos::ManejadorArchivos()
{
    cout<<"Constructor manejador archivos\n";
    this->me= new ManejadorCache();
}

/**
 * Destructor
 */
ManejadorArchivos::~ManejadorArchivos()
{
    cout<<"Eliminamos Manejador Cache\n";
    delete this->me;
}

/**
 * consulta si el archivo existe en disco.
 * (SOLO RUTAS RELATIVAS)
 * si existe devuelve su peso, si no existe, retorna -1
 * @param path
 * @return int
 */
int ManejadorArchivos::buscarArchivo(string path)
{
    return 0;
}

/**
 * carga el archivo en ram
 * @param path
 * @return ARCHIVO
 */
ARCHIVO ManejadorArchivos::cargarArchivo(string path)
{
}