# About
This is a C program that consists in a series of routines that manipulate a binary tree.
It was developed as an assingment for the Algorithms and Data Structures III (CI1057) course of the Federal University of Paraná (UFPR).

# Data Structure used
There are two main data structures used in this project.  
The first one is the Type B Binary Tree, which is a simple binary tree, processed from an input string (written in nested parentheses).  
The second one is the Type A Binary Tree, which is a Binary Search Tree whose nodes are Type B trees and are sorted by their index values. Each index value is calculated by summing all the values inside the Type B tree.

# How to run the program
To run it, execute the following commands inside the project directory:
```bash
$ make
$ ./busca
```

# Routines
To add a new node, use the command *i*:
```bash
i (10(8)(30))
```
To search a node, use the command *b* (it will search a node that has the same index value, note that the Type B tree found might be different):
```bash
b (25(10(5)())())
```

To remove a node, use the command *r* (it will remove a node that has the same index value, note that the Type B tree removed might be different):
```bash
r (11(10)(17))
```

# Ending the program
To end the program, simply press Ctrl+D.

# Authors
This project was developed by [@leonokida](https://github.com/leonokida) and [@guicarboneti](https://github.com/guicarboneti).
