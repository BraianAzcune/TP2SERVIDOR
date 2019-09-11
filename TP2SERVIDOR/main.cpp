/*OBJETIVO=
abrir un archivo, si es menor de 512MB, guardarlo en ram, mostrar su contenido por consola, y guardar esa copia en disco.
*/

/* 
 * File:   main.cpp
 * Author: braian
 *
 * Created on 31 de agosto de 2019, 17:56
 */

#include <cstdlib>
#include<fstream>//la clase ifstream esta aqui
#include <iostream> //permite mostrar por consola
using namespace std;

const char* ARCHIVO="prueba.txt";//puntero constante, no se puede modificar de ninguna forma

#include "Utilidades.h"
#include "Servidor.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    
   
    
    
    //creamos un objeto del tipo ifstream, le decimos que archivo abrir, y que lo habra en modo binario.
    //std::ifstream fichero= std::ifstream(ARCHIVO,ios::binary);
    
    Servidor servidor;
    servidor.inicializar();
    servidor.arrancar();
    servidor.escuchar();

    return 0;
}

