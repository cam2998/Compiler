# CS 442 - Compiler Construction
## IOMngr Repository

This repository contains files to be added to your main project repository to include the IOMngr capabilities. The repository contains

- IOMngrDriver.c
    - This is the test driver for the assignment. This driver opens the source and listing files and repeatedly requests the next character from the source file. When specific types of characters are seen it posts messages indicating the type of character. 

- IOMngr.h
    - The include file defining the functions implemented by the IOMngr. 

- IOMngr.c
	- A stub for the implementation file. 
	
- IOMngrSource
    - A file containing an excerpt of a C source file for testing.

- IOMngrListing1-out, IOMngrListing2-out
    - The listing files produced from the given source file for the two modes of operation. 

- Makefile
    - An extended Makefile containing the rules required for building and testing the project. 

## The Assignment

Complete the IOMngr.c file by implementing the functions defined in SymTab.h. The implementation will need to buffer source lines and also buffer posted messages for printing at the appropriate time. Two test targets are provided in the makefile. The first ("make iotest1") tests the form where both source and listing filenames are provided. The second ("make iotest2") tests the form where only a source filename is provided. 

## What to Do

- DO NOT FORK this repository on Gitlab, instead
- On your development machine, in a location different than your assignment repository, clone this project. Your original Project repository will continue to accumulate all files for the project. 
- Copy the files from this repository to your Project repository. The new Makefile will replace the existing copy.
- Discard the clone of this repository.
- Complete the IOMngr.c file by implementing the required functionality.
- When complete, 
    - "make clean" to remove object files and executables
    - use git to add and commit your changes to your local repository
    - use git to push the project back up to your GitLab account
    - I should already be a member of your project repository
    - create an issue on your project repository, listing me as assignee, with a title of "Submit for grading"
