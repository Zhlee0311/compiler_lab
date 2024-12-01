%option yylineno

%{  
    #include <ctype.h>
    #include <stdio.h>
    #include "translator.h"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BLUE    "\033[34m"
    #define PURPLE  "\033[35m"
    #define CYAN    "\033[36m"
    #define RESET   "\033[0m"
%}

TYPE                int|float|void
KEYWORD             if|else|while|break|continue|return
OPERATOR            "+"|"-"|"!"|"*"|"%"|"/"|"="
COMPARISON          "=="|"!="|">"|"<"|">="|"<="
NONZERO             [1-9]
DIGIT               [0-9]
LETTER              [A-Za-z]
OCTAL_DIGIT         [0-7]
OCTAL_CONST         [+-]?0{OCTAL_DIGIT}+
ILLEGAL_OCTAL_CONST [+-]?0{OCTAL_DIGIT}*[^0-7;]+
HEX_PREFIX          [+-]?0[xX]
HEX_DIGIT           [0-9a-fA-F]
HEX_CONST           {HEX_PREFIX}{HEX_DIGIT}+
ILLEGAL_HEX_CONST   {HEX_PREFIX}{HEX_DIGIT}*[^0-9a-fA-F;]*
NONDIGIT            {LETTER}|"_"
ID                  {NONDIGIT}({DIGIT}|{NONDIGIT})*
DEC_CONST           ([+-]?{NONZERO}{DIGIT}*)|0
FLOAT               [+-]?(0|{NONZERO}{DIGIT}*)\.{DIGIT}*
COMMENT1            "/*"[^*]*"*"+([^*/][^*]*"*"+)*"/"
COMMENT2            "//".*

%%
{TYPE}                  {
                            printf(YELLOW "<" PURPLE "TYPE" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return TYPE;
                        }
{FLOAT}                 {
                            printf(YELLOW "<" PURPLE "FLOAT" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                        }
{DEC_CONST}             {
                            printf(YELLOW "<" PURPLE "DEC_CONST" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return DEC_CONST;
                        }
{HEX_CONST}             {
                            printf(YELLOW "<" PURPLE "HEX_CONST" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return HEX_CONST;
                        }
{OCTAL_CONST}           {
                            printf(YELLOW "<" PURPLE "OCTAL_CONST" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return OCTAL_CONST;
                        }
{ILLEGAL_HEX_CONST}     {
                            return ILLEGAL_HEX_CONST;
                        }
{ILLEGAL_OCTAL_CONST}   {
                            return ILLEGAL_OCTAL_CONST;
                        }
{KEYWORD}               {
                            printf(YELLOW "<" PURPLE "KEYWORD" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return KEYWORD;
                        }
{ID}                    {
                            printf(YELLOW "<" PURPLE "ID" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return ID;
                        }  
"!"                     {
                            printf(YELLOW "<" PURPLE "NOT" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return NOT;
                        } 
{OPERATOR}              {
                            printf(YELLOW "<" PURPLE "OPERATOR" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return OPERATOR;
                        }   
{COMPARISON}            {
                            printf(YELLOW "<" PURPLE "COMPARISON" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return COMPARISON;
                        }
"("                     {
                            printf(YELLOW "<" PURPLE "LPARENT" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return LPARENT;
                        }
")"                     {
                            printf(YELLOW "<" PURPLE "RPARENT" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return RPARENT;
                        }   
"["                     {
                            printf(YELLOW "<" PURPLE "LBRACKET" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return LBRACKET;
                        }
"]"                     {
                            printf(YELLOW "<" PURPLE "RBRACKET" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return RBRACKET;
                        }
"{"                     {
                            printf(YELLOW "<" PURPLE "LBRACE" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return LBRACE;
                        }
"}"                     {
                            printf(YELLOW "<" PURPLE "RBRACE" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return RBRACE;
                        }
";"                     {
                            printf(YELLOW "<" PURPLE "SEMICN" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return SEMICN;
                        }
","                     {
                            printf(YELLOW "<" PURPLE "COMMA" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return COMMA;
                        }
"."                     {
                            printf(YELLOW "<" PURPLE "DOT" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return DOT;
                        }
"&&"                    {
                            printf(YELLOW "<" PURPLE "AND" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return AND;
                        }
"||"                    {
                            printf(YELLOW "<" PURPLE "OR" YELLOW " : " BLUE "%s" YELLOW ">" RESET "\n", yytext);
                            return OR;
                        }
{COMMENT1}|{COMMENT2}   { }
[ \t\n]                 { }
.                       {return UNEXPECTED;}
%%

int main(){
    int token_type;
    while(token_type = yylex()){
        switch(token_type){
            case UNEXPECTED:
                {
                    printf(RED "Error type A at Line %d: Invalid characters \"%s\"" RESET "\n", yylineno, yytext);
                    break;
                }
            case OCTAL_CONST:
                {
                    int sum = 0;
                    for(int i = 1; i < yyleng; i++){
                        sum = sum * 8 + (yytext[i] - '0');
                    }
                    printf(GREEN "OCT: %d\n"RESET, sum);
                    break;
                }
            case HEX_CONST:
                {
                    int sum = 0;
                    for(int i = 2; i < yyleng; i++){
                        if(yytext[i] <= '9' && yytext[i] >= '0'){
                            sum = sum * 16 + (yytext[i] - '0');
                        }else if(isupper(yytext[i])){
                            sum = sum * 16 + (yytext[i] - 'A' + 10);
                        }else if(islower(yytext[i])){
                            sum = sum * 16 + (yytext[i] - 'a' + 10);
                        }
                    }
                    printf(GREEN "HEX: %d\n"RESET, sum);
                    break;
                }
            case ILLEGAL_OCTAL_CONST:
                {
                    printf(RED "Error type B at Line %d: Illegal octal number \"%s\"" RESET "\n", yylineno, yytext);
                    break;
                }
            case ILLEGAL_HEX_CONST:
                {
                    printf(RED "Error type B at Line %d: Illegal hex number \"%s\"" RESET "\n", yylineno, yytext);
                    break;
                }
        }
    }
}