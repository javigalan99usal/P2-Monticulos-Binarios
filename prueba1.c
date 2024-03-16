#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"
int main(void)
{
  Monticulo m;
  tipoElemento elemento;
  int i, n = 10;
  
  elemento.informacion = 0;

  iniciaMonticulo(&m);
  printf("Monticulo iniciado correctemante. Su tamaño actual es %d\n", m.tamanno);

  printf("Monticulo => ");
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  printf("Insertando %d elementos aleatorios al monticulo:\n", n);
  for (i=0; i<n; i++){
    elemento.clave = rand()%100;
    insertar(elemento, &m);
  }

  printf("Monticulo => ");
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  printf("Decremento la clave de la posición 6 en 80 unidades:\n");
  printf("Monticulo => ");
  decrementarClave(6, 80, &m);
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  printf("Incremento la clave de la posición 3 en 120 unidades:\n");
  printf("Monticulo => ");
  incrementarClave(3, 120, &m);
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  printf("Elimino el mínimo del monticulo:\n");
  eliminarMinimo(&m, &elemento);
  printf("Elemento eliminado: %d\n", elemento.clave);
  printf("Monticulo => ");
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  printf("Comprobamos que es monticulo:");
  if (esMonticulo(m))
    printf(" El monticulo es correcto\n");
  else
    printf(" El monticulo no es correcto\n");
}
