# CS 442 - Compiler Construction

This is a compiler that I slowly created with guidance and assistance from the proffessor. The compiler is fully functioning with many functionalities of regular compilers such as constants, function creation, function calls, and declarables. One of the major functionalities that was not implemented was functions and function calls with parameters. Which can be worked around with less efficiency by using global variables.

Note: This last assignment is out of 60pts any additional pts are extra credit.

Current Points: 110 
60/60
50/0 extra creadit

## Semantics Part 2

This repository contains files to be added to your main project repository to include the semantic processing capabilities to compile programs of the language Y.

## The Assignment

- Step 5, 5 pts
- Step 6, 10 pts
- Step 7, 10 pts
- Step 8, 10 pts
- Step 9, 10 pts
- Step 10, 15 pts
- Step 11, 15 pts
- Step 12, 15 pts, Implement function calls for parameterless functions. (Done)
- Step 13, 15 pts, Implement function parameters.
- Step 14, 20 pts

The repository contains a selection of test programs that implement various combinations of these features. You can make your own test programs but they should actually do something.

## Extra Steps for Grading

To indicate which of these features you have implemented please add the following to your make file

    sem2test:	 feature1 feature2 etc

    feature1:    Y
                 echo "Some message identifying the feature"
                 rm -f f1-test.lst f1-test.asm
                 ./Y -l f1-test
                 cat f1-test.lst
                 cat f1-test.asm
                 spim -noexception -file f1.asm < f1.in

    feature2:    etc

Remember that the action commands must be preceeded by one or more tab characters (not spaces). To test your submission I will execute "make sem2test" and this will then run the tests for each of your features. The "f1-test.in" file is only required if the test program takes input from the terminal.

## What To Do

- Do not fork this repository on Gitlab, instead
- On your development machine, in a location different than your assignment repository, clone this project. Your assignment repository will continue to accumulate all files for the project.
- Copies the files from this repository to your assignment repository.
- Discard the clone of this repository.
- Implement the required capabilities.
- When complete, "make clean" to remove object files and executables, use git to add and commit your changes and push the project back up to your repository. Rememger to create an issue in Gitlab with me as the assignee indicating that your submission is ready for grading.
