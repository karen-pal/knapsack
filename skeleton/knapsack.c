#include <stdlib.h>
#include <stdbool.h>
#include "knapsack.h"

value_t max_value (value_t val1, value_t val2) {
    value_t res;
    if (val1>=val2) {
    res = val1;
    } else {
    res = val2;
    }
return(res);
}

value_t knapsack_backtracking(item_t *items,                        //items es un arreglo dinamico
			      unsigned int array_length, weight_t max_weight){
    value_t res;
    if (max_weight == 0) {
        res = 0;

    } else if (max_weight>0 && array_length == 0) {
        res = 0;

    } else if ((item_weight(items[array_length-1]) > max_weight) && (array_length > 0) ) { 
        res = knapsack_backtracking(items,array_length-1,max_weight);

    } else if (max_weight >= item_weight(items[array_length-1]) && array_length>0){
        res = max_value(knapsack_backtracking(items,array_length-1,max_weight), item_value(items[array_length-1]) + knapsack_backtracking(items,array_length-1,max_weight- item_weight(items[array_length-1])));
    }

return(res);
}
static void destroy_matrix (value_t* *value_matrix,unsigned int array_length) {
    
    for (unsigned int i=0; i<=array_length; i++) {
        value_t* aux;
        aux = &value_matrix[i][0];
        free(aux);
        aux=NULL;
    }
    free(value_matrix);
}



value_t knapsack_dynamic(item_t *items,
			 unsigned int array_length, weight_t max_weight){

        value_t* *value_matrix;             
        value_matrix = calloc(array_length+1, sizeof(value_t*));      //crear matriz
        for (unsigned int k=0; k<=array_length; k++){
            value_matrix[k]=calloc(max_weight+1,sizeof(value_t));
        }
    
        for (unsigned int i=0; i<=array_length;i++) {   //poblar primera columna de la matrix
                    value_matrix[i][0]=0;
        }
        for (unsigned int j=0; j<=max_weight;j++) {      //poblar primera fila de la matrix
                    value_matrix[0][j]=0;
        }
        for (unsigned int i=1; i<=array_length;i++) {
                    for (unsigned int j=0; j<=max_weight;j++) {
                        if (item_weight(items[i-1]) > j) {
                            value_matrix[i][j] = value_matrix[i-1][j]; 
                        } else {
                            value_matrix[i][j] = max_value(value_matrix[i-1][j],item_value(items[i-1]) + value_matrix[i-1][j-item_weight(items[i-1])]); ///cuidado, están desfasados ya que items va de 0 a array_length-1, y consideramos i desde 1 a                          array_length, por eso tenés items[i-1]
                        }
                    }
        }
       value_t res = value_matrix[array_length][max_weight];
        destroy_matrix(value_matrix,array_length); 
return(res);
}


value_t knapsack_dynamic_selection(item_t *items, bool *selected,
				   unsigned int array_length,
				   weight_t max_weight){
        value_t* *value_matrix;             
        value_matrix = calloc(array_length+1, sizeof(value_t*));      //crear matriz
        for (unsigned int k=0; k<=array_length; k++){
            value_matrix[k]=calloc(max_weight+1,sizeof(value_t));
        }
    
        for (unsigned int i=0; i<=array_length;i++) {   //poblar primera columna de la matrix
                    value_matrix[i][0]=0;
        }
        for (unsigned int j=0; j<=max_weight;j++) {      //poblar primera fila de la matrix
                    value_matrix[0][j]=0;
        }
        for (unsigned int i=1; i<=array_length;i++) {
                    for (unsigned int j=0; j<=max_weight;j++) {
                        if (item_weight(items[i-1]) > j) {
                            value_matrix[i][j] = value_matrix[i-1][j];
                            selected[i-1]=false; 
                        } else {
                            if (value_matrix[i-1][j] > (item_value(items[i-1]) + value_matrix[i-1][j-item_weight(items[i-1])])){
                                value_matrix[i][j] = value_matrix[i-1][j];
                                selected[i-1]=false;
                            } else {
                                value_matrix[i][j]=item_value(items[i-1]) + value_matrix[i-1][j-item_weight(items[i-1])];
                                selected[i-1]=true;
                            }
                        }
                    }
        }
    value_t res = value_matrix[array_length][max_weight];
    destroy_matrix(value_matrix,array_length); 
return(res);

}


