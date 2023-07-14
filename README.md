# Simple_Shell Documentation
This is a Collaborative project with two contributors:
- Charles Okechukwu
- Abdullah Mohammed

This project is built C programming Language,  We are building of our miniature version of the Bourne Again Shell.
The code is compiled using GCC with the flag ```-Wall -Wextra -Werror -pedantic -g -std=gnu89``` flags. All the code are tested using `valgrind` and `gdb` to ensure no errors or bugs and that all allocated memories are freed properly.

## Custome Functions For String Manipulation In This Project
Very little standard functions where used in this project, we used custom functions built by us for this project, the functions are found in the files `util.c` for the first five and `util2.c` for the last four. The functions are listed in the table below with thier various uses:
| Functions | Uses |
| --------- | ---- |
| _putchar | Prints single character |
| _strlen | Checks the Length of a String |
| _puts | prints a string |
| _strcpy | copies a string |
| _strdup | duplicates a pointer string |
| _strcat | cocatenates two strings |
| _strcmp | compares two strings |
| _atoi | converts a string to an integer |
| print_num | prints an integer |
| split_str | splits a string and returns an array of each word of the string|

### Main Functions

These include the main functions used in the simple shell, the first function in the table below is located in `util2.c` file
| Function | use |
| -------- | --- |
| print_err | prints error message in shell for invalid commands |

## Files
| shell.c => main function
| shell.h => Header file

| split_string.c =>
    => split_str - A a function that splits a string and returns an array of each word of the string.
    => free_list_str -  A function that frees a 2d array of strings created by malloc.
    
