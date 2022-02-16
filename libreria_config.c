#include <xc.h>
#include "libreria_config.h"
#include <stdio.h>
#include "mcc_generated_files/device_config.h"

void maquina(void)
{
  static estados caso;      
    switch(caso)
    {
    case CERRADO:     
        printf("cerrado\r\t");
        x=1;x2=1;
        PORTB=0x0;
        rgbverde=1;
        dato2 = pulsador2;
        if(dato2==1 && datoant2==0)
        {        
        rgbverde=0;
        rgbrojo=1;__delay_ms(500);
        rgbrojo=0;__delay_ms(500);
           caso=ABRIENDO;
        
        }
        datoant2=dato2; 
        __delay_ms(20);
//        else
//        {caso=CERRADO;}
        break;
    case ABRIENDO:
            led1=1;
            led2=0;
           
                for(cont=x;cont<=10;cont++){
                    printf("%d\r\t",cont);__delay_ms(1000);
                  
               dato3 = pulsador3;  
              if(datoant3==1 && dato3==0)
               {
                 caso = PARADO;
                 x=cont;
                 cont=11;
               }
               datoant3=dato3;
                __delay_ms(20);
                }
           
             if(caso==ABRIENDO)
             {
                 x = 10;
                 caso=ABIERTO;
             }
            
        break;
    case ABIERTO:  
        printf("abierto\r\t");
        led1=0;
        
        dato4 = pulsador4;
        if(dato4==1 && datoant4==0)
        {        
        rgbrojo=1;__delay_ms(500);
        rgbrojo=0;__delay_ms(500);
           caso=CERRANDO;        
        }
        datoant4=dato4; 
        __delay_ms(20);

        break;
    case CERRANDO:
        
        printf("cerrando\r\t");
        led2=0;
        led3=1;
            for(cont2=x;cont2>=0;cont2--){
            printf("%d\r\t",cont2);__delay_ms(1000);
            dato3 = pulsador3;  
              if(datoant3==1 && dato3==0)
               {
                 caso = PARADO;
                 x=cont2;
                 cont2=-1;
               }
               datoant3=dato3;
                __delay_ms(20);
                
            dato1 = pulsador1;  
              if(datoant1==1 && dato1==0)
               {
                 caso = PARADO;
                 x=cont2;
                 cont2=-1;
               }
               datoant1=dato1;
                __delay_ms(20);
                }
           
             if(caso==CERRANDO)
             {
                 caso=CERRADO;
             }
            
        led3=0;

        break;
    case PARADO:
        
        printf("parado\r\t");
               led1=0;
               led2=1;       
               led3=0;
        dato2 = pulsador2;       
        if(dato2==1 && datoant2==0)
        {        
           caso=ABRIENDO;
        }
        datoant2=dato2; 
        __delay_ms(20);
        
        dato4=pulsador4;
        if(dato4==1 && datoant4==0)
        {        
        rgbrojo=1;__delay_ms(500);
        rgbrojo=0;__delay_ms(500);
           caso=CERRANDO;        
        }
        datoant4=dato4; 
        __delay_ms(20);
               
                     
//               caso=PARADO;
        break;
    default:
        printf("No Available\n");
    } 
}
