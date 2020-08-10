## About

A simple implementation of sudoku solver on C Language. This example use [Backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithm to solve the problem.

## Requirement

- GCC v4 or greater (or similar app).

## Usage

- Set your sudoku problem at **matrix** section on the `solve.c`. Note that the blank spaces are replaced by **0** (zero).

- Compile the source:
```
$ gcc -o solve solve.c
```

- Run the source:
```
$ ./solve
```

- The result will be shown as like this:
```
435269781
682571493
197834562
826195347
374682915
951743628
519326874
248957136
763418259
```
