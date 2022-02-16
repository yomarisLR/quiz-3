/*
 * File:   casosmaquina.c
 * Author: Mareus
 *
 * Created on February 15, 2022, 12:15 PM
 */


#include <xc.h>
#include "casosmaquina.h"
#include <stdio.h>

typedef enum {CERRADO=0,ABRIENDO,ABIERTO,CERRANDO,PARADO}estados;


void MAQUINA_INIT(void) {
    
    estados caso;      
    switch(caso)
{
    case CERRADO:     
        printf("cerrado\r\t");
        caso=ABRIENDO;
        break;
    case ABRIENDO:
        printf("abriendo\r\t");
        caso=ABIERTO;
        break;
    case ABIERTO:  
        printf("abierto\r\t");
        caso=CERRANDO;
        break;
    case CERRANDO:
        printf("cerrando\r\t");
        caso=PARADO;
        break;
    case PARADO:
        printf("parado\r\t");
        caso=CERRADO;
        break;
    default:
        printf("No Signal Available\n");
}
}

