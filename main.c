/**
 * @brief Program para la gestion finenciera de una empresa
*/

#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main(){
  /**
   * @param opc Variable para eleguir una opcion del menu
   * @param nomMes variable para guardar el nombre de un mes
   * @param e Structura empresa para trabajar
  */
  int opc=0;
  char nomMes[20];
  Empresa e;

  do{
    printf("\nElija una de las opciones");
    printf("\n1- Recopilar la informacion de la empresa");
    printf("\n2- Solicitar y procesar las facturas del mes de un semestre");
    printf("\n3- Carcular el recaudo obtenido por cada mes");
    printf("\n4- Calcular y mostrar el recaudo obtenido del semestre, basado en el recaudo obtenido por cada mes");
    printf("\n5- Salir\n");
    scanf("%d",&opc);
    switch(opc){
    case 1:{
      system("clear");
      llenarEmpresa(&e);
      getchar();
      break;
    }
    
    case 2:{
      system("clear");
      printf("\nIngres el nombre de un Mes:");
      scanf("%s",nomMes);
      printf("\nRecaudo completo del Mes: %d",facturasMes(e.semestre,nomMes));
      getchar();
      break;
    }
    
    case 3:{
      system("clear");
      recaudoPorMes(e.semestre);
      getchar();
      break;
    }
    
    case 4:{
      system("clear");
      recaudoSemestre(e.semestre);
      getchar();
      break;
    }
    
  }
    
  }while(opc!=5);
  return 0;
}

