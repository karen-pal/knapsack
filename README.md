# Knapsack Problem
Resolución del problema de la mochila usando Backtracking y Programación dinámica.

## Uso
Para usarlo clonar el repo y ejecutar

  ```$ ./knapsack <option>```

donde las opciones disponibles son:

    -f <files> Run algorithms on the all the files listed. Stdin is used by default
  
    -b Enable backtracking algorithm
  
    -d Enable dynamic algorithm
  
    -s Show selected items (only in dynamic algorithm)
  
    -t Enable testing (checks VALUE field on the first line of each input file)
  
    -w <arg> Force knapsack capacity to [arg]. Reads KNAPSACK field on first line of each input file by default

*Hay archivos para testear en el directorio /input*

**Ejemplo:** ```./knapsack -bds -f input/example*.in```
