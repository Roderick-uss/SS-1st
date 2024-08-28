<div align="center"> 

# Square Solvatar

It can solve **square equation** with arbitrary quotienst.

It checks all possible variants of this task and gives answer in each case

</div>

## Using

> before using go to the program directory in terminal
> to do it enter `cd **path**` 
> implace of **path** wright path to directory

Program has two variants of usage:

### 1. Main

This solves square equation in standart form without any limitetion to qutienst.<br>
ax^2 + bx + c = 0

<details>
<summary>How to build and run</summary>

- build ***MAIN.exe***:
    > ```sh
    > make
    > ```

- run ***MAIN.exe***:
    > ```sh
    > ./MAIN
    > ```

</details>

<details>
<summary>What it does</summary>

- enter 3 numbers separated with **' '** or **'\n'** they will be a b c quotients
- if you entered not a number, program will ask you to repeat
- program solve equation with entered quotients and gives answers

> 

> If you change program files(any __*.c__ or __*.h,__ except test.c) rebuild ***MAIN.exe***.

</details>

<div align="center">

#### jpg

</div>

### 2. Test

This run program for all given tests<br>
and prints error if test answer and receiver answer not equal.

<details>
<summary>How to build and run</summary>

- build ***TEST.exe***:
    > ```sh
    > make test
    > ```

- run ***TEST.exe***:
    > ```sh
    > ./TEST
    > ```

</details>

<details>
<summary>What it does</summary>

- it has two testers with different realisatoins
- if all is good program ends without error message
- if program finds different solvation to test's, it prints error message<br>
this message contains test and program answers comparison

<details>
<summary>tester1</summary>

- enter test's data in ***tester.txt***
- input order a b c x1 x2 n_roots
- separate with **' '**  between parameters
- separate with **'\n'** between tests

> you don't need to rebuild ***TEST.exe*** if you have changed ***tester.txt***.

</details>

<details>
<summary>tester2</summary>

- enter test's data in ***test.c*** in tester2 functoin
- input order a b c x1 x2 n_roots
- separate with **', '**  between parameters
- separate with **'\n'** between tests
- surround tests with **'\{'** and **'\},'**

</details>

> If you change program files(any __*.c__ or __*.h,__ except ***main.c***) rebuild ***MAIN.exe***.

</details>

<div align="center">

#### jpg

</div>

## Installation

"Install"

## Documentation

"Doxygen"