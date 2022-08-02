# quadratic_calс

As the name suggests, this program is a calculator for quadratic equations.

## Table of contents
* [Installation and setup](#installation-and-setup)
* [Usage](@usage)
* [Additional info](#additional-info)

## Installation and setup
1. Download all source files into one folder:
```
$ git clone https://github.com/tyvia/quadratic_calc
```
2. Open the subfolder with source files and build with Make:
```
$ cd quadratic_calc/
$ make all
```
This way the `test` and `quadratic` programs will automatically run(the first one should print `OK` several times).

3. You can run the `quadratic` program again from the folder, where it was built: 
```
$ ./quadratic
```
4. To remove all object files type this:
```
$ make clean
```

## Usage
After you start the program, you will see a menu with 3 options:
* s(solve): prompts the user to enter coefficients, and, if they are entered correctly, solves the equation;
* h(help): outputs a short manual on how to use a program;
* q(quit): quits the program.

To choose an option, print a letter corresponding to it, and hit `<Enter>`.

To enter coefficients, print them in `a b c` format, e.g. for solving equation like 2*x^2 - 9 = 0, print `2 0 -9` and hit `<Enter>`.

## Additional info
* Menu input processor is not sensible to register, so you can enter both lowercase and uppercase letters.
* But you can enter ***only*** letters, entering words will cause an error.
* This calculator ***does not*** support complex numbers. If solutions are complex numbers, then the program prints `No solutions.`

