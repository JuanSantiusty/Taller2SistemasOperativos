#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main(){
  int opc=0;
  Empresa e;

  do{
    printf("\nElija una de las opciones");
    printf("\n1- Recopilar la informacion de la empresa");
    printf("\n2- Solicitar y procesar las fcaturas del mes de un semestre");
    printf("\n3- Carcular el recaudo obtenido por cada mes");
    printf("\n4- Calcular y mostrar el recaudo obtenido del semestre, basado en el recaudo obtenido por cada mes");
    printf("\n5- Salir\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:{
      system("cls");
      llenarEmpresa(&e);
      getchar();
      break;
    }
    
    case 2:{
      system("cls");
      getchar();
      break;
    }
    
    case 3:{
      system("cls");
      getchar();
      break;
    }
    
    case 4:{
      system("cls");
      getchar();
      break;
    }
    
  }
    
  }while(opc!=5);
  return 0;
}

