# LangfordPairing
A langford pairing is a sequence of 2n numbers where each number between 1 to n is repeated twice, and is each pair is n spots away from each other.
This program allows you to:
# - create langford sequences of your specified n
# - check whether a langford sequence is valid 

# Use
after compiling the program (gcc -Wall -std=gnu99 -g -o langford langford.c), 
to create a langford pair,  use the "-c" option and a valid n value:
./langford -c 16
Creating a langford pairing with n=16
[12, 10, 8, 5, 3, 1, 14, 1, 3, 5, 15, 8, 10, 12, 16, 13, 11, 9, 6, 4, 2, 14, 7, 2, 4, 6, 15, 9, 11, 13, 7, 16]

to check whether a sequence is a langford sequence, input the sequence in the command line:
./langford 2 3 4 2 1 3 1 4
Your sequence: [2, 3, 4, 2, 1, 3, 1, 4]
It is a langford pairing!
