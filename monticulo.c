#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "monticulo.h"

//
//  Fución que inicializa un montículo vacío.
//
void iniciaMonticulo(Monticulo *m)
{
    m->tamanno = 0; // Inicializa el tamaño del montículo a 0
}
//
//  Función que indica si el montículo está o no vacío
//
int vacioMonticulo(Monticulo m)
{
    if (m.tamanno == 0)
    {
        return 1; // Montículo vacío
    }
    else
    {
        return 0; // Montículo no vacío
    }
}
//
//  Función que inserta un elemento en el montículo
//
int insertar(tipoElemento x, Monticulo *m)
{
    if (m->tamanno < MAXIMO) // Si el montículo no está lleno
    {
        m->tamanno++;                          // Incrementa el tamaño del montículo
        m->elemento[m->tamanno] = x;           // Inserta el elemento en la última posición
        filtradoAscendente(m, m->tamanno - 1); // Filtra el elemento hacia arriba
        return 0;                              // Inserción correcta
    }
    else
    {
        return 1; // Montículo lleno (no se pudo insertar el elemento)
    }
}
//
//  Función que elimina el mínimo del montículo
//
int eliminarMinimo(Monticulo *m, tipoElemento *minimo)
{
    if (m->tamanno > 0) // Si el montículo no está vacío
    {
        *minimo = m->elemento[1];                     // Devuelve el mínimo por parámetro
        m->elemento[1] = m->elemento[m->tamanno]; // El último elemento ocupa el lugar del mínimo
        m->tamanno--;                                 // Decrementa el tamaño del montículo
        filtradoDescendente(m, 1);                    // Filtra el elemento hacia abajo
        return 0;                                     // Eliminación correcta
    }
    else
    {
        return 1; // Montículo vacío (no se pudo eliminar el mínimo)
    }
}
//
//  Función que decrementa la clave de un elemento del montículo
//
void decrementarClave(int pos, tipoClave cantidad, Monticulo *m)
{
    if (pos > 0 && pos < m->tamanno)
    {                                       // Si la posición es válida
        m->elemento[pos].clave -= cantidad; // Decrementa la clave del elemento
        filtradoAscendente(m, pos);         // Filtra el elemento hacia arriba
    }
    else
    {
        printf("Posición no válida, no se ha podido decrementar la clave\n");
    }
}
//
//  Función que incrementa la clave de un elemento del montículo
//
void incrementarClave(int pos, tipoClave cantidad, Monticulo *m)
{
    if (pos > 0 && pos < m->tamanno)
    {                                       // Si la posición es válida
        m->elemento[pos].clave += cantidad; // Incrementa la clave del elemento
        filtradoDescendente(m, pos);        // Filtra el elemento hacia abajo
    }
    else
    {
        printf("Posición no válida, no se ha podido incrementar la clave\n");
    }
}
//
//  Función que indica si un montículo es o no montículo
//
int esMonticulo(Monticulo m)
{
    int nodosInternos = m.tamanno / 2; // Número de nodos internos del montículo
    int clavePadre;
    for (int i; i < nodosInternos; i++) // Recorro los nodos internos comparando el padre con sus hijos, excepto el último
    {
        clavePadre = m.elemento[i].clave;
        if (clavePadre > m.elemento[2 * i].clave || clavePadre > m.elemento[2 * i + 1].clave)
        {             // Si el padre es mayor que alguno de sus hijos
            return 0; // No es montículo
        }
    }
    clavePadre = m.elemento[nodosInternos].clave;         // Compruebo el último nodo interno, que puede tener solo un hijo
    if (clavePadre > m.elemento[2 * nodosInternos].clave) // Si el padre es mayor que el hijo izquierdo
    {
        return 0; // No es montículo
    }
    if (2 * nodosInternos + 1 < m.tamanno) // Si existe el hijo derecho
    {
        if (clavePadre > m.elemento[2 * nodosInternos + 1].clave) // Si el padre es mayor que el hijo derecho
        {
            return 0; // No es montículo
        }
    }
    return 1; // Es montículo
}
//
//  Función que crea un montículo a partir de un vector de elementos
//
void crearMonticulo(Monticulo *m)
{
    int i;
    for (i = m->tamanno / 2; i >= 1; i--) // Recorro los nodos internos desde el último hasta el primero
    {
        filtradoDescendente(m, i); // Filtra el elemento hacia abajo
    }
}

//
//  Función auxiliar: Filtrado Ascendente
//
void filtradoAscendente(Monticulo *m, int i)
{
    tipoElemento x = m->elemento[i]; // Guarda el elemento a filtrar
    while (m->elemento[i / 2].clave > m->elemento[i].clave && i != 1)
    {                                        // Mientras el padre sea mayor que el hijo
        m->elemento[i] = m->elemento[i / 2]; // El padre ocupa el lugar del hijo
        i = i / 2;                           // El hueco se traslada al lugar del padre
    }
    m->elemento[i] = x; // El elemento a filtrar ocupa el hueco que queda
}
//
//  Función auxiliar: Filtrado Descendente
//
void filtradoDescendente(Monticulo *m, int i)
{
    tipoElemento x = m->elemento[i]; // Guarda el elemento a filtrar
    tipoElemento hijo;
    bool finFiltrado = false;
    while ((2 * i) <= m->tamanno && finFiltrado != true)
    { // Mientras tenga al menos un hijo
        if ((2 * i) == m->tamanno)
        {                              // Si solo tiene un hijo
            hijo = m->elemento[2 * i]; // Guardo el hijo izquierdo (único hijo)
        }
        else
        { // Si tiene dos hijos
            if (m->elemento[2 * i].clave < m->elemento[2 * i + 1].clave)
            {                              // Si el hijo izquierdo es menor que el derecho
                hijo = m->elemento[2 * i]; // Guardo el hijo izquierdo
            }
            else
            {
                hijo = m->elemento[2 * i + 1]; // Guardo el hijo derecho
            }
        }
        if (hijo.clave < x.clave) // Si el hijo es menor que el padre
        {
            m->elemento[i] = hijo; // El hijo ocupa el lugar del padre
            i = 2 * i;             // El hueco se traslada al lugar del hijo
        }
        else
        {
            finFiltrado = true; // Si el padre es menor que el hijo, termina el filtrado
        }
    }
    m->elemento[i] = x; // El elemento a filtrar ocupa el hueco que queda
}