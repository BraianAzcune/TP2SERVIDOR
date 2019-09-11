/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilidades.cpp
 * Author: braian
 * 
 * Created on 1 de septiembre de 2019, 12:30
 */

#include "Utilidades.h"

Utilidades::Utilidades() {
}

Utilidades::Utilidades(const Utilidades& orig) {
}

Utilidades::~Utilidades() {
}

//METODO ESTATICO
/**
 * Metodo estatico, dado la ruta, te entrega el tamaño del archivo., si no lo encuentra o es incapaz de abrirlo -1
 * @param ruta
 * @return 
 */
size_t Utilidades::obtenerSize(string ruta){
    
    size_t rta=-1;
    struct stat64 sb;
    
    if(stat64(ruta.c_str(),&sb)==-1){
        perror("Error en lectura del archivo 'obtenerSize'");
    }else{
        if(S_ISREG(sb.st_mode)!=0){//archivo normal
            rta=sb.st_size;
        }else{
            perror("No es archivo ordinario no se puede operar con el");
        }
    }
    
    return rta;
}
    
/**
 * Dado una ruta, responde si el archivo no existe, es valido para estar en ram, o no es valido.
 * @param ruta
 * @return 
 */
Utilidades::RESPUESTA Utilidades::esValido(string ruta){
    
    RESPUESTA rta=RESPUESTA::NO_VALIDO;
    
    struct stat64 sb;
    
    if(stat64(ruta.c_str(),&sb)==-1){
        perror("Error en lectura del archivo para saber su tamaño=\n" );
    }else{//EN caso de que no haya error
        
        if(S_ISREG(sb.st_mode)!=0){//Estamos hablando de un archivo normal, no socket, no enlace simbolico o duro. etc
            
            if(sb.st_size<Utilidades::MAX_SIZE512M){//SI ES MENOR A 512 MEGABYTES, ES VALIDO
                
                rta=RESPUESTA::ENCONTRADO_MENOR512M;
                
            }else{//SI ES MAYOR ENTONCES NO ES VALIDO, SE DEBE ENVIAR DE OTRA FORMA
                rta=RESPUESTA::ENCONTRADO_MAYOR512M;
            }
            
            cout<<"Tamaño del archivo solicitado= "<<sb.st_size<<"\n";
        }else{
            perror("El archivo que se pidio, no es comun, no se puede enviar. \n");
        }
        
    }
    
    return rta;
}            

