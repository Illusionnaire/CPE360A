The program goes through your code and tries to find the main function, where it uses the curly braces to define the scope at that point in the program.

>int x;  //At this point the compiler makes a symbol table and adds "x" into the table. It also makes the memory size and location.
>float y; //At this point the compiler makes a new symbol "y" and it makes a memory size twice that of int and gives it a memory location.
 
1. When running code with an executable, the computer moves the program from main memory and into your RAM to run.
* It looks for continuous memory size that can fit the program.

2. When the program reaches the end of a scope. In general, the variable locations in memory are wiped and the memory is given back to the system

Pointers:
> *pal ==> gives the value of the inner contents at that location
> pal ==> gives the address of the variable