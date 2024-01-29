# LangfordPairing

Langford Pairing is a mathematical concept involving sequences where each number between 1 to n is repeated twice, with each pair spaced n units apart. This program enables users to create and validate Langford sequences, providing an interactive way to explore this interesting mathematical puzzle.

## Features
- **Create Langford sequences** for a specified value of n.
- **Validate Langford sequences** to check their correctness.

## Requirements
- GCC compiler (GNU99 standard or later)

## Installation
Clone this repository and compile the program using the following command:
gcc -Wall -std=gnu99 -g -o langford langford.c


## Usage

**Creating a Langford Pairing:**
./langford -c 16
Example output for `n=16`:
Creating a Langford pairing with n=16
[12, 10, 8, 5, 3, 1, 14, 1, 3, 5, 15, 8, 10, 12, 16, 13, 11, 9, 6, 4, 2, 14, 7, 2, 4, 6, 15, 9, 11, 13, 7, 16]

**Validating a Langford Sequence:**

Certainly! Below is the content for your README file, formatted in Markdown, which is the format used by GitHub for README files. You can copy and paste this directly into your README.md file on GitHub.

markdown
Copy code
# LangfordPairing

Langford Pairing is a mathematical concept involving sequences where each number between 1 to n is repeated twice, with each pair spaced n units apart. This program enables users to create and validate Langford sequences, providing an interactive way to explore this interesting mathematical puzzle.

## Features
- **Create Langford sequences** for a specified value of n.
- **Validate Langford sequences** to check their correctness.

## Requirements
- GCC compiler (GNU99 standard or later)

## Installation
Clone this repository and compile the program using the following command:
gcc -Wall -std=gnu99 -g -o langford langford.c

markdown
Copy code

## Usage

**Creating a Langford Pairing:**
./langford -c 16

go
Copy code
Example output for `n=16`:
Creating a Langford pairing with n=16
[12, 10, 8, 5, 3, 1, 14, 1, 3, 5, 15, 8, 10, 12, 16, 13, 11, 9, 6, 4, 2, 14, 7, 2, 4, 6, 15, 9, 11, 13, 7, 16]


**Validating a Langford Sequence:**
./langford 2 3 4 2 1 3 1 4
Example output:
Your sequence: [2, 3, 4, 2, 1, 3, 1, 4]
It is a Langford pairing!

## Troubleshooting
- Ensure you're using the correct GCC version.
- If you encounter any errors, please check the syntax and command-line arguments.

## Contributing
Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
