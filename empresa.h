#ifndef EMPRESA_H
#define EMPRESA_H

#define numFacturas 5
#define numSemestre 6

typedef struct {
  char nombre[20];
  int factura[numFacturas];
}Mes;

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
