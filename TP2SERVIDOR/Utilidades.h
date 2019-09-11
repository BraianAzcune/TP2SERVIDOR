/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utilidades.h
 * Author: braian
 *
 * Created on 1 de septiembre de 2019, 12:30
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include "ARCHIVO.h"


using namespace std;

class Utilidades {
public:
    //constructor
    Utilidades();
    //constructor para copiar objeto
    Utilidades(const Utilidades& orig);
    //destructor para evitar fugas de memoria ante herencia de la clase.
    virtual ~Utilidades();
    
    
    static size_t obtenerSize(string ruta);
    
    
    
    const static size_t MAX_SIZE512M=5.12e8;//ESO DICE 512 MEGABYTES, en notacion cientifica, porque esta representado en bytes.
    //1 MB son 1 millon de bytes. (el que es en base 2, es mebibyte)
    
    
    enum RESPUESTA{
        NO_VALIDO,
        ENCONTRADO_MENOR512M,
        ENCONTRADO_MAYOR512M
    };
    
    /**
     * Dado una ruta, responde si el archivo no existe, es valido para estar en ram, o no es valido.
     * @param ruta
     * @return 
     */
    static RESPUESTA esValido(string ruta);
    
private:

};

#endif /* UTILIDADES_H */

