#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "empresa.h"

int n,f,i;

void convertir_a_minusculas(char *cadena) {
    i = 0;
    while (cadena[i] != '\0') {
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}

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


int facturasMes(Mes s[],char nomMes[]){
  int pos=-1;
  convertir_a_minusculas(nomMes);
  for(n=0;n<numSemestre;n++){
    convertir_a_minusculas(s[n].nombre);
    if(strcmp(nomMes,s[n].nombre)==0){
      pos=n;
    }
  }
  int total=0;
  if(pos!=-1){
    for(n=0;n<numFacturas;n++){
      total+=s[pos].factura[n];
      printf("\nDatos Factura %d",n+1);
      printf("\Valor factura %d",s[pos].factura[n]);
    }
  }else{
    printf("Mes no existe");
  }
  return total;
}
