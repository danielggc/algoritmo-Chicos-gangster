
#include <cstdio>
#include <asm-generic/errno-base.h>
#include <cstddef>
#include <stdio.h> 
#include <string.h>   //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <string>
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

using namespace std;


enum Address{  Letf , Rigth };

typedef string  Elemento ;


struct Nodo{
      public:
        Elemento elemento;
        Nodo *rigth;      
        Nodo *letft;    


  };





struct Nodo *  create_new_nodo( Elemento elemento ){
    
    int size_nodo = sizeof( struct Nodo );
    Nodo *  nuevo_nodo  =  ( struct Nodo* )malloc( size_nodo );
    nuevo_nodo -> elemento = elemento;
    nuevo_nodo -> rigth =     nuevo_nodo -> letft  = NULL;
 
    return nuevo_nodo;
}

 
void  insert_to_tree( struct Nodo  *&nodo ,  Elemento elemento ){
    
    if(  nodo -> elemento < elemento ){
        
        if( nodo -> rigth == NULL ){
            nodo -> rigth = create_new_nodo( elemento );
        }
        else{
            insert_to_tree( nodo -> rigth , elemento);
        }
    }
    else{

        if( nodo -> letft == NULL ){
        
            nodo -> letft  = create_new_nodo( elemento );

        }
        else{
            insert_to_tree( nodo -> letft,  elemento );
        }
    }

 }
void print_emogis( Nodo * root_tree ){
    if( root_tree ==  NULL ){
      return;
    }
    else{
        print_emogis( root_tree->letft );
        string data = root_tree->elemento;
        cout<<data;
        if( root_tree -> rigth == NULL) 
            return;
    }
    while ( root_tree -> rigth != NULL ) {
        root_tree = root_tree->rigth;
        cout<<root_tree->elemento;
    }
    

}

void calcular_chicos_gamster( int gangster_boys ){
   

    int num_emoji_final = 0;
    int num_emoji_lateral = 0;
    int num_emoji_parcial = 0;
    const int num_emoji_completo = 1;

    if( gangster_boys > 7 ){
        num_emoji_final = 2;
    }
    int i = 1;
    int pares = 0;
    for( ; i < gangster_boys   ; i++){
        if(pares == 4 ){
            num_emoji_parcial++;
            pares =0;
        }
        else{
            num_emoji_lateral ++;
            pares++;
        }
    }
  
    num_emoji_lateral = ( gangster_boys - ( num_emoji_completo + num_emoji_final + num_emoji_parcial ) );

    printf("emoji_final = [%d], emoji_lateral = [%d] ,  emoji_parcial = [%d], emoji_completo = [%d]", num_emoji_final, num_emoji_lateral, num_emoji_parcial, num_emoji_completo );

    
    Nodo *  listEmojis =  create_new_nodo(emoji_completo);
    
    int count =1 ;
    Address following = Letf;
    const int end_race  = gangster_boys > 7 ? 2 : 0;
    Nodo * aux_letft_nodo = listEmojis;
    Nodo * auc_rigth_nodo = listEmojis;

 
 
    while( count < ( gangster_boys - end_race  ) ){
        if( following == Letf ){
            printf("\nizquierda   =>%d",count);     
            if( ( count - 1 ) % 4 == 0 & count > 1   ){
                Nodo * newEmogi = create_new_nodo( emoji_parcial_i );
                aux_letft_nodo->letft =  newEmogi;
                aux_letft_nodo = aux_letft_nodo -> letft; 
                count++;
                following = Rigth;
                printf("emoji parcial ");
            }else {
                Nodo * newEmogi = create_new_nodo( emoji_lateral_i );
                aux_letft_nodo->letft =  newEmogi;
                aux_letft_nodo = aux_letft_nodo -> letft; 
                count++;
                following = Rigth;
                printf(" emoji lateral ");
            }
        }
        else{
            printf("\nderecha   => "); 
            if( ( count - 2 ) % 4 == 0   & count > 2 ){
                Nodo * newEmogi = create_new_nodo( emoji_parcial_d );
                auc_rigth_nodo->rigth =  newEmogi;
                auc_rigth_nodo = auc_rigth_nodo->rigth;
                count++;
                following = Letf;
                printf("emoji parciar ");
            }
            else {
                Nodo * newEmogi = create_new_nodo( emoji_lateral_d );
                auc_rigth_nodo->rigth =  newEmogi;
                auc_rigth_nodo = auc_rigth_nodo->rigth;
                count++;
                following = Letf;   
                printf("emoji lateral "); 
            }  
        }
      }

      if( end_race > 0  ){
            Nodo * newEmogi_z = create_new_nodo( emoji_final_i );
            aux_letft_nodo->letft =  newEmogi_z;
            Nodo * newEmogi_r = create_new_nodo( emoji_final_d );
            auc_rigth_nodo->rigth =  newEmogi_r;     
      }

    printf("\n------------------------------------------");
    cout<<"\n\nimprimiendo emogis\n\n";
    print_emogis( listEmojis );
    
}





int main(){
    printf("\nchicos gangster: \n \n \n");
    calcular_chicos_gamster( 11);
}