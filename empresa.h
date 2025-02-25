#ifndef EMPRESA_H
#define EMPRESA_H

/**
 * @param numFacturas Maximo de facturas que puede tener un mes
 * @param numSemestre Numero de meses que tiene un semestre
*/
#define numFacturas 5
#define numSemestre 6

/**
 * @brief Estructura para un mes
 * @param nombre Nombre del mes
 * @param factura Arreglo de enteros para guardar el valor de una factura
*/
typedef struct {
  char nombre[20];
  int factura[numFacturas];
}Mes;

/**
 * @brief Estructura de una empresa
 * @param nombre Nombre de la empresa
 * @param nit Identificador de la empresa
 * @param semestre Arreglo de meses que represente un semestre
*/
typedef struct {
  char nombre[20];
  int nit;
  Mes semestre[numSemestre];
}Empresa;


void convertir_a_minusculas(char *cadena);
void llenarEmpresa(Empresa *e);
void llenarSemestre(Mes s[]);

int facturasMes(Mes s[],char nomMes[]);

#endif
