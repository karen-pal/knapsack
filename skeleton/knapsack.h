#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <stdbool.h>
#include "item.h"

/* Especificaciones en enunciado */

value_t knapsack_backtracking(item_t *items,
			      unsigned int array_length, weight_t max_weight);
/*Esta función resuelve el problema de la mochila usando backtracking. Los parámetros son: el arreglo de
items, la longitud del arreglo y la capacidad máxima de la mochila. Devuelve el valor máximo que se
puede alcanzar seleccionando items del arreglo sin sobrepasar la capacidad de la mochila.*/


value_t knapsack_dynamic(item_t *items,
			 unsigned array_length, weight_t max_weight);
/*Esta función resuelve el problema de la mochila usando programación dinámica. Los parámetros son: el
arreglo de items, la longitud del arreglo y la capacidad máxima de la mochila. Devuelve el valor máximo
que se puede alcanzar seleccionando items del arreglo sin sobrepasar la capacidad de la mochila.*/


value_t knapsack_dynamic_selection(item_t *items, bool *selected,
				   unsigned int array_length,
				   weight_t max_weight);
/*Esta función resuelve el problema de la mochila usando programación dinámica. Los parámetros son: el
arreglo de items, un arreglo de booleanos, la longitud de ambos arreglos, y la capacidad máxima de la
mochila. Devuelve el valor máximo que se puede alcanzar seleccionando items del arreglo sin sobrepasar
la capacidad de la mochila. El arreglo de booleanos se utiliza para indicar cuáles son los items del arreglo
que fueron seleccionados para colocarse en la mochila.
*/
#endif
