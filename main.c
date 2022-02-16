#include "mcc_generated_files/mcc.h"
#include "libreria_config.h"

int i;

void main(void)
{
    SYSTEM_Initialize();


     for(i=0;i<1;i--) 
       {
         maquina();
         __delay_ms(200);
        }
    
}
    

