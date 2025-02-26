#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "empresa.h"

/**
 * @param n Variable para iterar estructuras repetitivas
 * @param i Variable para iterar estructuras repetitivas
*/
int n,f,i;

/**
 * @brief Funcion para poner una cadena de texto en minuculas
 * @param cadena Cadena de texto a comvertir
*/
void convertir_a_minusculas(char *cadena) {
    i = 0;
    while (cadena[i] != '\0') {
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}
/**
 * @brief Funcion para llenar los datos de una empresa
 * @param e Dierccion de la empresa para ingresar datos
*/
void llenarEmpresa(Empresa *e){
  printf("\nDatos Empresa\n");
  printf("\nNombre de la empresa: ");
  scanf("%s",&e->nombre); 
  printf("\nNit de la Empresa: ");
  scanf("%d",&e->nit);
  llenarSemestre(e->semestre);
}

/**
 * @brief Funcion para llenar los datos del semestre de una empresa, se usa una variable f para solicitar el numero de factuas a ingresar en vada mes, minimo 1 maximo 5
 * @param s Arreglo de meses que funcoina como semestre
*/
void llenarSemestre(Mes s[]){
  printf("\nDatos Semestre");
  for (n=0;n<numSemestre;n++) {
    printf("\nDatos Mes %d",n+1);
    printf("\nNombre Mes: ");
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
/**
 * @brief Funcion para mostrar y sumar el valor de todas las facturas de un mes, en caso de que el mes no exista se mostrara un mensaje informando
 * @param nomMes Mes a buscar
 * @return El valor total de todas las facturas de un mes
*/

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
      if(s[pos].factura[n] > 0){
      total+=s[pos].factura[n];
      printf("\nDatos Factura %d ",n+1);
      printf("\Valor factura %d",s[pos].factura[n]);
      }
    }
  }else{
    printf("Mes no existe");
  }
  return total;
}

/**
 * @brief Calcula y muestra el recaudo obtenido por cada mes.
 * 
 * @param s Arreglo de estructuras de tipo Mes que contiene la información de los meses y sus facturas.
 */

void recaudoPorMes(Mes s[]){

 printf("\nRecaudo obtenido por cada mes:\n");
 for(int i=0; i< numSemestre; i++){
  int total=0;
  for(int j=0;j<numFacturas;j++){
   total += s[i].factura[j];
  }
  printf("Mes: %s, Total: %d\n", s[i].nombre, total);
 }
}

/**
 * @brief Calcula y muestra el recaudo total de todo el semestre.
 * 
 * @param s Arreglo de estructuras de tipo Mes que contiene la información de los meses y sus facturas.
 */

void recaudoSemestre(Mes s[]){

 int totalSemestre = 0;
 for(int i=0; i<numSemestre;i++){
  for(int j=0;j<numFacturas;j++){
   totalSemestre += s[i].factura[j];
  }
 }
 printf("\Recaudo total del semestre: %d\n", totalSemestre);
}
