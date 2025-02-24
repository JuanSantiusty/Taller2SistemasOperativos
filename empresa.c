#include <stdio.h>
#include "empresa.h"

int n,f,i;

void llenarEmpresa(Empresa *e){
  printf("\nDatos Empresa");
  printf("\nNombre de la empresa: ");
  scanf("%s",&e->nombre); 
  printf("\nNit de la Empresa: ");
  scanf("%d",&e->nit);
  llenarSemestre(e->semestre);
}

void llenarSemestre(Mes s[]){
  printf("\nDatos Semestre");
  for (n=0;n<numSemestre;n++) {
    printf("\nDatos Mes %d",n+1);
    printf("\nNombre Mes:");
    scanf("%s",&s[n].nombre);
    do{
      printf("\nNumero de facturas a ingresar: ");
      scanf("%d",&f);
    }while(f<1 || f>5);
    for (i=0;i<numFacturas;i++) {
      if(i<f){
	printf("Valor factura %d: ",i+1);
	scanf("%d",&s[n].factura[i]);
      }else{
	s[n].factura[i]=0;
      }
    }
    
  }
} 
