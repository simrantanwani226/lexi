### Lexical Analyzer
# Overview
This project implements a lexical analyzer, also known as a lexer or tokenizer, which is a fundamental component of a compiler. The lexical analyzer takes input source code as a string and breaks it down into tokens, which are the smallest units of syntax in the programming language. Each token represents a specific element of the language, such as keywords, identifiers, operators, and literals.

# Features
Tokenization: The lexical analyzer tokenizes input source code, identifying and categorizing individual tokens.
Token Types: Supports various token types including keywords, identifiers, operators, delimiters, and literals.
Error Handling: Handles lexical errors gracefully, such as invalid characters or unrecognized tokens.
Customization: Provides options for customizing token recognition rules and handling of special cases.
Efficiency: Designed for efficient tokenization of source code with minimal overhead.
# Technologies Used
Language: Implemented in C
Libraries: Utilizes regular expressions for token recognition
# Usage
Input Source Code:
Provide the source code to be analyzed as input to the lexical analyzer.
Tokenization:
Execute the lexical analyzer to tokenize the input source code and generate a list of tokens.
Token Output:
The output will consist of a list of tokens, each represented by its type and value.
# Example
Consider the following Python code snippet:

python
Copy code
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)
The lexical analyzer will tokenize this code into the following tokens:

python
Copy code
[Keyword(def), Identifier(factorial), Delimiter(()), Identifier(n), Delimiter()), 
Keyword(if), Identifier(n), Operator(==), Literal(0), Delimiter(:), 
Keyword(return), Literal(1), Keyword(else), Delimiter(:), 
Keyword(return), Identifier(n), Operator(*), Identifier(factorial), Delimiter(()), Identifier(n), Operator(-), Literal(1), Delimiter())]
# Acknowledgements
This project was inspired by the need for a robust lexical analysis tool for various programming language implementations and compilers.

# License
This project is licensed under the MIT License.
