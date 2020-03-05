/*************************************************************
 Name: Raul Fosselman
 Username: cssc1900
 Class: CS530 Spring 2020
 Project: CS-530 Assignment 1
 File: README.txt
 *************************************************************/

 What This Program Does:
    Opens and reads every byte in a regular file (specified by the user when
    launching the program) and writes both the ASCII hex value for that
    byte as well as it’s printable (human-readable) character. The user may also choose to have the program print in binary     instead of hex.

 File Mainifest:
    dbx.cpp
    Makefile
    README.txt

To Compile:
    1.Run the Makefile. How: from the directory where the files are located enter 'make', and the Makefile will compile         dbx.cpp

Operating instructions:
    1. To run enter './dbx <YourFileHere>' or './dbx -b <YourFileHere>'
    2. Use of the '-b' option will make the program yield a binary output as opposed to hexadecimal

Design Decisions:
    The decision to use C++ over C was made purely based on a desire to better learn streams and the C++ language. Another       conscious decision was to keep the entire program in one file (dbx.cpp) instead of separating the code into multiple         .cpp files. Due to the simplicity of the program and short length it struck me as cleaner to have only one file.

Extra features:
    Erroneous user input handling in the form of printed instructions was added in order to make the program easier to use.

Known Defeciencies/Bugs:
    The program is only designed to handle regular file types. There is no error handling for other file types.

Lessons Learned:
    This is my first program using the C++ language, as such I gained a great deal of familiarity with the syntax. This was     also my first introduction to Makefiles, which I can imagine would be very useful on projects much larger than this one.     One of my most notable takeaways is new knowledge of getopt(), I did not previously know this function existed and I         believe it will be very useful for me in the future to handle options.
