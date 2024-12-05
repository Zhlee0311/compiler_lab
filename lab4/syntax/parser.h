#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "color.h"

extern int yylineno;
extern char* yytext;
extern int yylex();

typedef enum { TEXT, INT_P, FLOAT_P } TYPE;

void yyerror(const char* msg) {
    printf(RED "%s at line %d: " RESET "%s\n", msg, yylineno, yytext);
}

int OCT2DEC(char* text) {
    int sum = 0;
    int start = 0;
    int sign = 1;

    // 处理正负号
    if (text[0] == '-') {
        sign = -1;
        start = 1;
    } else if (text[0] == '+') {
        start = 1;
    }

    for (int i = start + 1; i < strlen(text); i++) {
        sum = sum * 8 + (text[i] - '0');
    }
    return sign * sum;
}

int HEX2DEC(char* text) {
    int sum = 0;
    int start = 0;
    int sign = 1;

    // 处理正负号
    if (text[0] == '-') {
        sign = -1;
        start = 1;
    } else if (text[0] == '+') {
        start = 1;
    }

    for (int i = start + 2; i < strlen(text); i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            sum = sum * 16 + (text[i] - '0');
        } else if (text[i] >= 'A' && text[i] <= 'F') {
            sum = sum * 16 + (text[i] - 'A' + 10);
        } else if (text[i] >= 'a' && text[i] <= 'f') {
            sum = sum * 16 + (text[i] - 'a' + 10);
        }
    }
    return sign * sum;
}

typedef struct ASTnode {
    TYPE type;
    int   num1;  // 整数值
    float num2;  // 浮点数值
    char* text;
    struct ASTnode* next; // Sibling
    struct ASTnode* child; // Child
}ASTnode;

ASTnode* ASThead = NULL;

// new node
ASTnode* newASTnode(TYPE type, char* text, float num, ASTnode* next, ASTnode* child) {
    ASTnode* node = (ASTnode*)malloc(sizeof(ASTnode));
    node->type = type;
    if (type == INT_P) {
        node->num1 = (int)num;
    } else if (type == FLOAT_P) {
        node->num2 = num;
    } else {
        node->text = strdup(text);
    }
    node->next = next;
    node->child = child;
    return node;
}

// connect
void connectASTnode(int num, ...) {
    va_list valist;
    va_start(valist, num);
    ASTnode* node = va_arg(valist, ASTnode*);
    for (int i = 1; i < num; i++) {
        ASTnode* next = va_arg(valist, ASTnode*);
        node->next = next;
        node = next;
    }
    node->next = NULL;
    va_end(valist);
}

// print
void printAST(ASTnode* head, int tab) {
    switch (head->type) {
        case INT_P:
        {
            printf(CYAN "%d" RESET "\n", head->num1);
            break;
        }
        case FLOAT_P:
        {
            printf(BLUE "%f" RESET "\n", head->num2);
            break;
        }
        case TEXT:
        {
            if (head->child != NULL) {
                printf(GREEN "%s" RESET "\n", head->text);
            } else {
                printf(YELLOW "%s" RESET "\n", head->text);
            }
            break;
        }
    }
    ASTnode* node = head->child;
    while (node != NULL) {
        for (int i = 0;i < tab;i++) {
            printf("\t");
        }
        printf("└───────");
        printAST(node, tab + 1);
        node = node->next;
    }
}


// free
void freeAST(ASTnode* head) {
    ASTnode* node = head->child;
    while (node != NULL) {
        freeAST(node);
        node = node->next;
    }
    if (head->type == TEXT) {
        free(head->text);
    }
    free(head);
}