/**
 * Project TP1EJ2SERVIDOR
 */


#include "Servidor.h"



/**
 * Servidor implementation
 * 
 * Este servidor espera a solo 1 cliente, y no atiende a nadie mas, hasta que se libera.
 */


/**
 * inicializamos estructuras de datos necesarias para el servidor, y se puede poner opcionalmente un puerto, sino es 44666
 * 
 * Nota= no es necesario especificar en el lado de implementacion cual es el puerto default ya que lo hace .h
 * @param _puerto=44666
 */
void Servidor::inicializar(int _puerto){
    this->socketEscucha=socket(PF_INET,SOCK_STREAM,0);//usaremos TCP en modo stream, el 0 indica que usaremos el protocolo por defecto TCP.
    if(this->socketEscucha==-1){
        perror("Error al abrir el socket");
        exit(EXIT_FAILURE);
    }
    this->puerto=_puerto;
}

/**
 * Trata de hacer el bind al puerto especificado, y pone a la escucha al server. A partir de aqui, todo se maneja internamente.
 * @param cantidadDeUsuariosEnCola default 1
 */
void Servidor::arrancar(int cantidadDeUsuariosEnCola) {
    //estructura para realizar el bind, se configura con el puerto especificado, y la ip que tiene la maquina.
    struct sockaddr_in name;
    name.sin_family =PF_INET;
    name.sin_port=(in_port_t)htons(this->puerto);
    name.sin_addr.s_addr=htonl(INADDR_ANY);//acepta peticiones de cualquier interfaz de red, incluso loopback
    
    //reutilizamos el puerto si ya fue usado antes.
    int reuse=1;
    if(setsockopt(this->socketEscucha,SOL_SOCKET,SO_REUSEADDR,(char*)&reuse,sizeof(int))==-1){
        perror("No es posible reusar el socket\n");
        exit(EXIT_FAILURE);
    }
    
    //realizamos el enlace
    int c= bind(this->socketEscucha,(struct sockaddr*)&name,sizeof(name));
    if(c==-1){
        perror("No se puede enlazar el puerto, direccion ya en uso");
        exit(EXIT_FAILURE);
    }
    
    //establecemos la cantidad de usuarios que pueden estar en cola.
    if(listen(this->socketEscucha,cantidadDeUsuariosEnCola)==-1){
        cout<<"Cantidad de usuarios en cola superada, cantidad maxima= "<<cantidadDeUsuariosEnCola;
        exit(EXIT_FAILURE);//return;
    }
    
    
    
    
}

/**
 * Constructor, crea a ManejadorArchivo
 */
Servidor::Servidor() {
    cout<<"Constructor servidor\n";
    this->ma= new ManejadorArchivos();
}

/**
 * Destructor
 */
Servidor::~Servidor(){
    cout<<"Eliminamos ManejadorArchivo\n";
    delete this->ma;
}


/**
 * pone al servidor a la escucha hasta que llegue una conexion
 * al entrar conexion llama a manejarPeticion
 */
void Servidor::escuchar() {
    while(1){
        struct sockaddr_storage client;
        unsigned int addres_size=sizeof(client);
        cout<<"Esperando cliente \n";
        this->socketCliente=accept(this->socketEscucha,(struct sockaddr*)&client,&addres_size);//ponemos a la escucha en el socket, esperando una nueva conexion.
        if(this->socketCliente==-1){
            cout<<"No se puede conectar socket secundario\n";
        }
        //ATENDER CLIENTE
        cout<<"LLEGO UN CLIENTE\n";
        this->manejarPeticion();
        //FINALIZAR CONEXION
        close(this->socketCliente);
    }
    
}

/**
 * pregunta a CacheManager si tiene el dato solicitado, si es asi  se procede a la transmision, sino se buscara en el directorio predefindo que posee el servidor.
 */
void Servidor::manejarPeticion() {

    string path=this->crearSolicitud();
    
    //cout<<"Soy manejarPeticion el path es= |"<<path<<"|\n";
    //cout<<"Tamaño= "<<path.length()<<"\n";
    
    struct ARCHIVO file=this->ma->obtenerArchivo(path);
    
}

/**
 * @param file
 */
void Servidor::enviar(ARCHIVO &file) {

}

/**
 * genera un string con el path que haya enviado el cliente.
 * @return string
 */
string Servidor::crearSolicitud() {
    //int buffSize=2147483647;
    int buffSize=4096;//tamaño estandar que he encontrado en muchos lados.
    //cout<<"El buffer es de = "<<buffSize<<"\n";
    
    char buff[buffSize];
    int ultimaPosicion=1;//para que entre la primera vez al bucle.
    
    string path="";//respuesta
    
    //cout<<"Tamaño maximo que puede soportar un string= "<<path.max_size()<<"\n";
    
    
    /*
     * Del lado del cliente, cuanto termina de enviar los datos usa la funcion shutdown(socketfd,SHUT_WR), para cerrar el socket, de envio por su parte.
     * Lo que hace que recv, reciba 0. Pero podremos enviarle datos todavia.
     */
    while(true){
        ultimaPosicion= recv(this->socketCliente,buff,buffSize,0);
        
        if(ultimaPosicion==0){
            break;
        }else if(ultimaPosicion==-1){
            perror("Se desconecto el cliente mientras daba su peticion\n");
            break;
        }
        
        
        //cout<<"El buffer contiene= "<<buff<<"\n";
        //cout<<"Ultima posicion= "<<ultimaPosicion<<"\n";
    
        path.append(buff,ultimaPosicion);
        
    }
    
    //cout<<"El contenido de path es= "<<path<<"\n";

    //prueba de envio.
    //char msg[]="\nsoy el servidor\n";
    //send(this->socketCliente,msg,sizeof(msg),0);
    
    
    
    return path;
}

void Servidor::cerrarConexion() {

}

/**
 * Devuelve un .txt de archivo no encontrado.
 */
void Servidor::respuestaNoEncontrado() {

}