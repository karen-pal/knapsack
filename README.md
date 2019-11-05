# Knapsack Problem
Knapsack Problem resolution using Backtracking and Dynamic Programming

## Uso
Clone the repo and execute as

  ```$ ./knapsack <option>```

where the available options are:

    -f <files> Run algorithms on the all the files listed. Stdin is used by default
  
    -b Enable backtracking algorithm
  
    -d Enable dynamic algorithm
  
    -s Show selected items (only in dynamic algorithm)
  
    -t Enable testing (checks VALUE field on the first line of each input file)
  
    -w <arg> Force knapsack capacity to [arg]. Reads KNAPSACK field on first line of each input file by default

*Available files to test in the /input directory*

**Example:** ```./knapsack -bds -f input/example*.in```
