#include <stdlib.h>
#include <stdio.h>
#include "monticulo.h"
int main(void)
{
  Monticulo m;
  tipoElemento elemento;
  int i, n = 10;

  iniciaMonticulo(&m);
  elemento.clave = 12;
  elemento.informacion = 0;
  printf("Monticulo iniciado correctemante. Su tamaño actual es %d\n", m.tamanno);

  i = insertar(elemento, &m);

  printf("Elemento insertado correctamente. Su tamaño actual es %d\n", m.tamanno);
  printf("Monticulo => ");
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  printf("Insertando %d elementos aleatorios al monticulo:\n", n - 1);
  while (m.tamanno < n)
  {
    elemento.clave = rand() % 100;
    i = insertar(elemento, &m);
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
