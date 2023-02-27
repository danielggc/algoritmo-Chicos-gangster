
#include <cstdio>
#include <asm-generic/errno-base.h>
#include <cstddef>
#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <string>
#include <strings.h>
#include <sys/select.h>
#include <unistd.h>   //close 
#include <arpa/inet.h>    //close 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h>
#include <iostream>
#include<fcntl.h>

const char * emoji_final_d       = "-)";
const char * emoji_lateral_d     = "_-)";
const char * emoji_parcial_d     = "-_-)";
const char * emoji_completo      = "(-_-)";

const char * emoji_final_i        = "(-";
const char * emoji_lateral_i      = "(-_";
const char * emoji_parcial_i      = "(-_-";
const int size_emoji_final      = 2;
const int size_emoji_lateral    = 3;
const int size_emoji_parcial    = 4;
const int size_emoji_completo   = 5;

void calcular_chicos_gamster( int catidad_chicos ){
   

    int num_emoji_final = 0;
    int num_emoji_lateral = 0;
    int num_emoji_parcial = 0;
    const int num_emoji_completo = 1;

    if( catidad_chicos > 7 ){
        num_emoji_final = 2;
    }
    int i = 1;
    int pares = 0;
    for( ; i < catidad_chicos   ; i++){
        if(pares == 4 ){
            num_emoji_parcial++;
            pares =0;
        }
        else{
            num_emoji_lateral ++;
            pares++;
        }
    }
  
    num_emoji_lateral = ( catidad_chicos - ( num_emoji_completo + num_emoji_final + num_emoji_parcial ) );

    printf("emoji_final = [%d], emoji_lateral = [%d] ,  emoji_parcial = [%d], emoji_completo = [%d]", num_emoji_final, num_emoji_lateral, num_emoji_parcial, num_emoji_completo );

    const int espacios_final  =  ( num_emoji_final  ) * size_emoji_final;
    const int espacios_lateral = num_emoji_lateral * size_emoji_lateral ;
    const int espacios_parcial = num_emoji_parcial * size_emoji_parcial ;

    const int espacios_total = espacios_lateral + size_emoji_completo + espacios_parcial;
    char  data [ espacios_total + 10] ;
    

    memset( data, '\0', espacios_total + 10 );

    int count = 0;

    if ( catidad_chicos > 7) {
        strcat(data, emoji_final_i);
        count++;
    }
    

    const int  mitad = catidad_chicos % 2 == 0 ? catidad_chicos / 2 : (catidad_chicos / 2)+ 1  ; 
    
    int izq_num_laterales = num_emoji_lateral % 2 == 0 ? num_emoji_lateral / 2  : ( num_emoji_lateral / 2 ) + 1;
    const int izq_num_parciales = num_emoji_parcial % 2 == 0 ? num_emoji_parcial / 2  : ( num_emoji_parcial / 2 ) + 1;

    if( num_emoji_parcial !=  0  ){
        while( izq_num_laterales    != ( izq_num_parciales * 2 ) ) {
            strcat(data, emoji_lateral_i);
            izq_num_laterales -= 1;
            count++;
        }    
        strcat(data, emoji_parcial_i);
        count ++;
    }
    int toletf = catidad_chicos > 7 ? 1: 0;
    int count_pares = 0;
    while ( count <( mitad -toletf) ) {
        if( count_pares  == 2 && num_emoji_parcial != 0  ){
            strcat(data, emoji_parcial_i);
            count_pares = 0;
            count ++;
        }
        else{
            strcat(data, emoji_lateral_i);
            count ++;
            count_pares++;
        }
    }

    strcat(data, emoji_completo);
    count_pares = 0;
    if ( catidad_chicos > 7) {
        
        while ( count < catidad_chicos -1 ) {
            if( count_pares  == 2 &&  num_emoji_parcial != 0  ){
                strcat(data, emoji_parcial_d);
                count_pares = 0;
                count ++;
            }
            else{
                strcat(data, emoji_lateral_d);
                count ++;
                count_pares++;
            }
        }
        strcat(data, emoji_final_d);


    }
    else {
            while ( count < catidad_chicos  -1 ) {
            if( count_pares  == 2 && num_emoji_parcial != 0  ){
                strcat(data, emoji_parcial_d);
                count_pares = 0;
                count ++;
            }
            else{
                strcat(data, emoji_lateral_d);
                count ++;
                count_pares++;
            }
        }

    }

    printf("\n\n%s",data);

    
}






int main(){
    printf("\nchicos gangster: \n \n \n");
    calcular_chicos_gamster(14);
}