#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"
int main(void)
{
  Monticulo m;
  int i, n = 10;
  tipoElemento elemento;

  iniciaMonticulo(&m);

  m.tamanno = n;
  for (i = 1; i <= n; i++)
    m.elemento[i].clave = rand() % 100;

  printf("El array a partir del cual se creará el montículo es:\n");
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");

  heapsort(&m);
  
  for (i = 1; i <= m.tamanno; i++)
    printf("%d ", m.elemento[i].clave);
  printf("\n");
}
