 #include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 20
#define MAX_TOKEN_LENGTH 100

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_SEPARATOR,
    TOKEN_KEYWORD
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '='||c == '<'||c == '>'||c == '&'||c == '|'||c == '%'||c == '^'||c == '!');
}

int isSeparator(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == ',' || c == ';'||c==':'||c=='.'||c=='['||c==']');
}

int isKeyword(char *token) {
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for",
                            "goto", "if", "int", "long", "register", "return", "short",
                            "signed", "sizeof", "static", "struct", "switch", "typedef",
                            "union", "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i) {
        if(strcmp(keywords[i], token) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

Token getNextToken(FILE *fp) {
    Token token;
    char currentChar, tokenValue[MAX_TOKEN_LENGTH];
    int tokenIndex = 0;
    currentChar = fgetc(fp);

    while(!feof(fp)) {
        if(isalpha(currentChar)) { // Identifier or keyword
            while(isalpha(currentChar) || isdigit(currentChar) || currentChar == '_') {
                tokenValue[tokenIndex++] = currentChar;
                currentChar = fgetc(fp);
            }
            tokenValue[tokenIndex] = '\0';
            if(isKeyword(tokenValue)) {
                token.type = TOKEN_KEYWORD;
            } else {
                token.type = TOKEN_IDENTIFIER;
            }
            strcpy(token.value, tokenValue);
            return token;
        }
        else if(isdigit(currentChar)) { // Number
            while(isdigit(currentChar)) {
                tokenValue[tokenIndex++] = currentChar;
                currentChar = fgetc(fp);
            }
            tokenValue[tokenIndex] = '\0';
            token.type = TOKEN_NUMBER;
            strcpy(token.value, tokenValue);
            return token;
        }
        else if(isOperator(currentChar)) { // Operator
            token.type = TOKEN_OPERATOR;
            token.value[0] = currentChar;
            token.value[1] = '\0';
            return token;
        }
        else if(isSeparator(currentChar)) { // Separator
            token.type = TOKEN_SEPARATOR;
            token.value[0] = currentChar;
            token.value[1] = '\0';
            return token;
        }
        currentChar = fgetc(fp);
    }

    token.type = -1;
    return token;
}

int main() {
    FILE *fp;
    Token token;
    fp = fopen("C:/Users/simra/.vscode/extensions/ms-vscode.cmake-tools-1.14.31/programs/program.txt", "r");

    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return 0;
    }

    while(1) {
        token = getNextToken(fp);
        if(token.type == -1) {
            break;
        }
        switch(token.type) {
                case TOKEN_KEYWORD:
                    printf("%s - A KEYWORD", token.value);
                    break;
                case TOKEN_IDENTIFIER:
                    printf("%s - A VALID IDENTIFIER", token.value);
                    break;
                case TOKEN_NUMBER:
                    printf("%s - A NUMBER", token.value);
                    break;
                case TOKEN_OPERATOR:
                    printf("%s - A OPERATOR", token.value);
                    break;
                case TOKEN_SEPARATOR:
                    printf("%s - A SEPARATOR", token.value);
                    break;    
        
    }
    printf("\n");
    }
    return 0;
}
 