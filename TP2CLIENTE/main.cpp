#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#define ELPUERTO 44666

using namespace std;


int main(int argc, char *argv[])
{

    char *dirserver= argv[1];
    char *msg=argv[2];
    int sockfd;




    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servidor_addr;

    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_port = htons(ELPUERTO);
    servidor_addr.sin_addr.s_addr = inet_addr(dirserver);
    memset(&(servidor_addr.sin_zero), '\0',8);


    if (connect(sockfd, (struct sockaddr *)&servidor_addr,sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }
    
    //ENVIAR DATOS
    int contador=0;
    while(contador<=strlen(msg)){//menor igual, por el caracter \0       
        contador+=send(sockfd,msg,strlen(msg)+1,0);//ENVIA EL CARACTER \0, PARA INDICAR FIN DE STRING. por eso el +1
        cout<<"Contador= "<<contador<<"\n";
    }
    cout<<"Strlen msg= "<<strlen(msg)<<"\n";

    if(shutdown(sockfd,SHUT_WR)!=0){
        perror("No se pudo cerrar el socket");
        exit(1);
    }
    
    
    //RECIBIR DATOS
    char recibir[4000];
    
    string ruta=msg;
    
    string nombreArchivo = ruta.substr(ruta.find_last_of("/\\") + 1);//SI RUTA ES /HOME/BRAIAN/queseyo.txt | nombreArchivo=queseyo.txt
    
    ofstream manejadorArchivosGuardar(nombreArchivo,ofstream::binary);
    
    int datosRecibidos=1;
    while(datosRecibidos!=0){
        datosRecibidos=recv(sockfd,recibir,sizeof(recibir),0);
        
        manejadorArchivosGuardar.write(recibir,datosRecibidos);
        
    }
    
    manejadorArchivosGuardar.close();

    printf("recibimos del servidor: %s",recibir);


    close(sockfd);

    return(0);
}
