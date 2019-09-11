/**
 * Project TP1EJ2SERVIDOR
 */


#ifndef _SERVIDOR_H
#define _SERVIDOR_H
#include "ARCHIVO.h"
#include <string>
#include "ManejadorArchivos.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
class Servidor {
public: 
    
/**
 * inicializamos estructuras de datos necesarias para el servidor, y se puede poner opcionalmente un puerto, sino es 44666
 * @param _puerto=44666
 */
void inicializar(int _puerto=44666);
    
/**
 * Trata de hacer el bind al puerto especificado, y pone a la escucha al server. A partir de aqui, todo se maneja internamente.
 * @param cantidadDeUsuariosEnCola default 1
 */
void arrancar(int cantidadDeUsuariosEnCola=1);


/**
 * pone al servidor a la escucha hasta que llegue una conexion
 * al entrar conexion llama a manejarPeticion
 */
void escuchar();
    
/**
 * Constructor, crea a ManejadorArchivo
 */
Servidor();

/**
 * Destructor
 */
virtual ~Servidor();

private: 
    
/**
 * Numero que identifica el descriptor de archivos, donde estara escuchando peticiones.
 */    
int socketEscucha;    
/**
 * numero que identifica el descriptor de archivos, donde se guardaran los datos para que linux los envie.
 */
int socketCliente;

/**
 * Puerto en el que escucha el servidor
 */
int puerto;
 
/**
 * Es un puntero
 *Se inicializa en el constructor.
 * se destruye en el destructor.
 */
ManejadorArchivos* ma;


    
/**
 * pregunta a CacheManager si tiene el dato solicitado, si es asi  se procede a la transmision, sino se buscara en el directorio predefindo que posee el servidor.
 */
void manejarPeticion();
    
/**
 * @param file
 */
void enviar(struct ARCHIVO &file);
    
/**
 * genera un string con el path que haya enviado el cliente.
 */
string crearSolicitud();
    
void cerrarConexion();
    
/**
 * Devuelve un .txt de archivo no encontrado.
 */
void respuestaNoEncontrado();
};

#endif //_SERVIDOR_H