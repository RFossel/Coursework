# Prompt
You and your team shall develop, test, and deliver a disassembler program for the
XE variant of the SIC/XE family of machines.

#### XE DISASSEMBLER REQUIREMENTS:

The XE disassembler program shall open an XE object file, <filename>.obj and its
accompanying symbol file, <filename>.sym, then it will disassemble the object code,
and generate an XE source file, <filename.sic> and XE listing file, <filename>.lis
using the disassembled code. The symbol file, <filename>.sym will contain the
SYMTAB and LITTAB the assembler generated when assembling the object file.
Your executable program shall be named ‘dxe’. To run your program, the user shall
provide the filename on the command line when starting/running the disassembler:

 % dxe <filename>

the disassembler will then use “filename” for the name of the source file it
generates, <filename>.sic, and the accompanying listing file, <filename>.lis.
Note, the symbol file <filename>.sym will be provided with the object code file.
If neither the <filename>.obj or <filename>.sym are present, the xed program shall
gracefully exit.

###### TEAMS:
You shall work in teams of two - three people on this project. You may choose to
use pair programming, dividing work up, or other methods for work completion, that
is up to you although I strongly encourage you to attempt pair programming!

#### ADDITIONAL REQUIREMENTS:

 ###### README file 
 - you shall create a README file; consult the instructions for README
file content on the course Blackboard. Also, your source files SHALL CONTAIN
sufficient comments for making the source easy to read. Points will be taken off
for poorly (or non) commented source or inadequate README file documentation.
Compiler and make (and Makefile) – You shall use C/C++ (gcc/g++) and use make to
compile your program for this assignment; you will need to create a Makefile for
your project, consult the example Makefile(s) on the course Blackboard. Name the
executable, ‘dxe’ (Disassembler for the XE machine).

###### Test files
– You should prepare and include test files used during the development
and test of your project.

###### Software Design Document 
- You are required to perform software design of this
system. Include a Software Design Document (SDD) and turn it in with your project.
Note, you will not be held to formal design specification/formatting or use any of
the formal methods. Turn in a file which contains your software design. You may
include a kanban (and stories), models, drawings, descriptions, diagrams or similar
tools you used for your system/software design. This is a significant part of your
grade and needs to be adequately captured in your documentation. Include a
description of how your team was organized and how effectively you worked together
and areas for improvement.

Make sure that all files (README, source files, header files, Makefile) contains
each team member’s names and RedIDs!

#### TURNING IN YOUR WORK:
The project (assignment #2) is due at 1700, Monday, 20 April 2020
A draft copy of your SDD is due at 1700, Monday, 16 March 2020
Your project shall include C/C++ source files, an include/header file, a Makefile,
and a README file. ONLY ONE MEMBER OF YOUR TEAM TURNS IN THE PROJECT. To turn in
your project, each team shall select one person, all files shall be in that
person’s class account on edoras in a directory named “a2” (~/a2). Leave any test
files in this directory as well. BE SURE ALL TEAM MEMBERS NAMES AND CLASS ACCOUNTS
ARE IN THE README FILE. Finally, the designated person turns in the project by
uploading a tarball/zip-file with all project files to Blackboard and entering any
comments in the assignment’s turnin.
