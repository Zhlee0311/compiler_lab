%start CompUnit
%expect 1

%{
    #include "parser.h"
%}


%union
{
    int                 num;
    char*               str;
    struct  ASTnode*    node;
}


%token <str> INT FLOAT VOID CONST IF ELSE WHILE BREAK CONTINUE RETURN ID OCTAL_CONST HEX_CONST DEC_CONST FLOAT_CONST
%right <str> ASSIGN NOT
%left  <str> OR
%left  <str> AND
%left  <str> EQNEQ
%left  <str> CMP
%left  <str> ADDSUB
%left  <str> MULDIVSUR

%type<node>Number CompUnit Decl FuncDef ConstDecl VarDecl ConstDef ConstDefBlock ConstExpBlock ConstInitVal ConstExp ConstInitFlag ConstValBlock VarDef
    VarDefFlag InitVal Exp InitValFlag InitValBlock FuncType FuncFParams Block FuncFParam FuncFParamBlock ExpBlockFlag ExpBlock BlockItemBlock BlockItem 
    Stmt LVal ExpFlag StmtFlag Cond AddExp LOrExp PrimaryExp UnaryExp FuncFParamsFlag FuncRParams UNARYOP CommaExpBlock MulExp RelExp EqExp LAndExp

%%
CompUnit:       CompUnit Decl                           {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "CompUnit", 0, NULL, $1);
                                                            ASThead = $$;
                                                        }
                | CompUnit FuncDef                      {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "CompUnit", 0, NULL, $1);
                                                            ASThead = $$;
                                                        }
                | Decl                                  {
                                                            $$ = newASTnode(TEXT, "CompUnit", 0, NULL, $1);
                                                            ASThead = $$;
                                                        }
                | FuncDef                               {
                                                            $$ = newASTnode(TEXT, "CompUnit", 0, NULL, $1);
                                                            ASThead = $$;
                                                        } 
Decl:           ConstDecl                               { $$ = newASTnode(TEXT, "Decl", 0, NULL, $1); }
                | VarDecl                               { $$ = newASTnode(TEXT, "Decl", 0, NULL, $1); } 
ConstDecl:      CONST FuncType ConstDef ConstDefBlock ';'  {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n5 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(5, n1, $2, $3, $4, n5);
                                                            $$ = newASTnode(TEXT, "ConstDecl", 0, NULL, n1);
                                                        }
ConstDefBlock:  ConstDefBlock ',' ConstDef              {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, $3, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "ConstDefBlock", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ConstDefBlock", 0, NULL, n);
                                                        }
ConstDef:       ID ConstExpBlock ASSIGN ConstInitVal    {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, $3, 0, NULL, NULL);
                                                            connectASTnode(4, n1, $2, n3, $4);
                                                            $$ = newASTnode(TEXT, "ConstDef", 0, NULL, n1);
                                                        }
ConstExpBlock:  ConstExpBlock '[' ConstExp ']'          {
                                                            ASTnode* n2 = newASTnode(TEXT, "[", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, "]", 0, NULL, NULL);
                                                            connectASTnode(4, $1, n2, $3, n4);
                                                            $$ = newASTnode(TEXT, "ConstExpBlock", 0, NULL, $1);
                                                        }   
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ConstExpBlock", 0, NULL, n);
                                                        }
ConstInitVal:   ConstExp                                { $$ = newASTnode(TEXT, "ConstInitVal", 0, NULL, $1); }
                |'{'ConstInitFlag'}'                    {
                                                            ASTnode* n1 = newASTnode(TEXT, "{", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "}", 0, NULL, NULL);
                                                            connectASTnode(3, n1, $2, n3);
                                                            $$ = newASTnode(TEXT, "ConstInitVal", 0, NULL, n1);
                                                        }   
ConstInitFlag:  ConstInitVal ConstValBlock              {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "ConstInitFlag", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode*n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ConstInitFlag", 0, NULL, n);
                                                        }
ConstValBlock:  ConstValBlock ',' ConstInitVal          {
                                                            ASTnode* n2 = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, $1, n2, $3);
                                                            $$ = newASTnode(TEXT, "ConstValBlock", 0, NULL, $1);    
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ConstValBlock", 0, NULL, n);
                                                        }
VarDecl:        FuncType VarDef VarDefFlag ';'             {
                                                            ASTnode* n = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(4, $1, $2, $3, n);
                                                            $$ = newASTnode(TEXT, "VarDecl", 0, NULL, $1);
                                                        }
VarDefFlag:    ',' VarDef VarDefFlag                    {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, n, $2, $3);
                                                            $$ = newASTnode(TEXT, "VarDefFlag", 0, NULL, n);
                                                        }
                |  /*ε*/                                {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "VarDefFlag", 0, NULL, n);
                                                        }
VarDef:         ID  ConstExpBlock                       {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            connectASTnode(2, n, $2);
                                                            $$ = newASTnode(TEXT, "VarDef", 0, NULL, n);
                                                        }
                | ID ConstExpBlock ASSIGN InitVal       {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, $3, 0, NULL, NULL);
                                                            connectASTnode(4, n1, $2, n3, $4);
                                                            $$ = newASTnode(TEXT, "VarDef", 0, NULL, n1);
                                                        }
InitVal:        Exp                                     { $$ = newASTnode(TEXT, "InitVal", 0, NULL, $1); }
                | '{'InitValFlag'}'                   {
                                                            ASTnode* n1 = newASTnode(TEXT, "{", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "}", 0, NULL, NULL);
                                                            connectASTnode(3, n1, $2, n3);
                                                            $$ = newASTnode(TEXT, "InitVal", 0, NULL, n1);
                                                        }
InitValFlag:    InitVal InitValBlock                    {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "InitValFlag", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "InitValFlag", 0, NULL, n);
                                                        }
InitValBlock:   InitValBlock ',' InitVal                {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "InitValBlock", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "InitValBlock", 0, NULL, n);
                                                        }
FuncDef:        FuncType ID '(' FuncFParams ')' Block   {
                                                            ASTnode* n2 = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n5 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(6, $1, n2, n3, $4, n5, $6);
                                                            $$ = newASTnode(TEXT, "FuncDef", 0, NULL, $1);
                                                        }
FuncType:       VOID                                    {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "FuncType", 0, NULL, n);
                                                        }
                | INT                                   {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "FuncType", 0, NULL, n);
                                                        }
                | FLOAT                                 {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "FuncType", 0, NULL, n);
                                                        }
FuncFParams:    FuncFParam  FuncFParamBlock             {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "FuncFParams", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "FuncFParams", 0, NULL, n);
                                                        }
FuncFParamBlock:FuncFParamBlock ',' FuncFParam          {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "FuncFParamBlock", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "FuncFParamBlock", 0, NULL, n);
                                                        }
FuncFParam:     FuncType ID ExpBlockFlag                   {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "FuncFParam", 0, NULL, $1);
                                                        }
ExpBlockFlag:   '['']' ExpBlock                         {
                                                            ASTnode* n1 = newASTnode(TEXT, "[", 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "]", 0, NULL, NULL);
                                                            connectASTnode(3, n1, n2, $3);
                                                            $$ = newASTnode(TEXT, "ExpBlockFlag", 0, NULL, n1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ExpBlockFlag", 0, NULL, n);
                                                        }
ExpBlock:       ExpBlock '['Exp']'                      {
                                                            ASTnode* n2 = newASTnode(TEXT, "[", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, "]", 0, NULL, NULL);
                                                            connectASTnode(4, $1, n2, $3, n4);
                                                            $$ = newASTnode(TEXT, "ExpBlock", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ExpBlock", 0, NULL, n);
                                                        }
Block:          '{' BlockItemBlock '}'                  {
                                                            ASTnode* n1 = newASTnode(TEXT, "{", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, "}", 0, NULL, NULL);
                                                            connectASTnode(3, n1, $2, n3);
                                                            $$ = newASTnode(TEXT, "Block", 0, NULL, n1);
                                                        }
BlockItemBlock: BlockItemBlock BlockItem                {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "BlockItemBlock", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "BlockItemBlock", 0, NULL, n);
                                                        }
BlockItem:      Decl                                    {
                                                            $$ = newASTnode(TEXT, "BlockItem", 0, NULL, $1);
                                                        }
                | Stmt                                  {
                                                            $$ = newASTnode(TEXT, "BlockItem", 0, NULL, $1);
                                                        }
Stmt:           LVal ASSIGN Exp ';' %prec ASSIGN        {
                                                            ASTnode* n2 = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(4, $1, n2, $3, n4);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, $1);
                                                        }
                | ExpFlag ';'                           {
                                                            ASTnode* n = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(2, $1, n);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, $1);
                                                        }
                | Block                                 {
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, $1);
                                                        }
                | IF'('Cond')' Stmt StmtFlag            {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(6, n1, n2, $3, n4, $5, $6);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
                | WHILE'('Cond')' Stmt                  {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(5, n1, n2, $3, n4, $5);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
                | BREAK';'                              {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(2, n1, n2);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }                                              
                | CONTINUE';'                           {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(2, n1, n2);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
                | RETURN ExpFlag';'                     {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, ";", 0, NULL, NULL);
                                                            connectASTnode(3, n1, $2, n3);
                                                            $$ = newASTnode(TEXT, "Stmt", 0, NULL, n1);
                                                        }
ExpFlag:        Exp                                     {
                                                            $$ = newASTnode(TEXT, "ExpFlag", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "ExpFlag", 0, NULL, n);
                                                        }
StmtFlag:       ELSE Stmt                               {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            connectASTnode(2, n, $2);
                                                            $$ = newASTnode(TEXT, "StmtFlag", 0, NULL, n);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "StmtFlag", 0, NULL, n);
                                                        }
Exp:            AddExp                                  {
                                                            $$ = newASTnode(TEXT, "Exp", 0, NULL, $1);
                                                        }
Cond:           LOrExp                                  {
                                                            $$ = newASTnode(TEXT, "Cond", 0, NULL, $1);
                                                        }
LVal:           ID ExpBlock                             {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            connectASTnode(2, n, $2);
                                                            $$ = newASTnode(TEXT, "LVal", 0, NULL, n);
                                                        }
PrimaryExp:     '('Exp')'                               {
                                                            ASTnode* n1 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n3 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(3, n1, $2, n3);
                                                            $$ = newASTnode(TEXT, "PrimaryExp", 0, NULL, n1);
                                                        }
                | LVal                                  {
                                                            $$ = newASTnode(TEXT, "PrimaryExp", 0, NULL, $1);
                                                        }
                | Number                                {
                                                            $$ = newASTnode(TEXT, "PrimaryExp", 0, NULL, $1);
                                                        }
Number:         DEC_CONST                               {
                                                            ASTnode* n = newASTnode(INT_P, NULL, atoi($1), NULL, NULL);
                                                            $$ = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
                | OCTAL_CONST                           {
                                                            ASTnode* n = newASTnode(INT_P, NULL, OCT2DEC($1), NULL, NULL);
                                                            $$ = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
                | HEX_CONST                             {
                                                            ASTnode* n = newASTnode(INT_P, NULL, HEX2DEC($1), NULL, NULL);
                                                            $$ = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
                | FLOAT_CONST                           {
                                                            char* endptr;
                                                            float res = strtof($1, &endptr);
                                                            ASTnode* n = newASTnode(FLOAT_P, NULL, res, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "Number", 0, NULL, n);
                                                        }
UnaryExp:       PrimaryExp                              {
                                                            $$ = newASTnode(TEXT, "UnaryExp", 0, NULL, $1);
                                                        }
                | ID '(' FuncFParamsFlag ')'            {
                                                            ASTnode* n1 = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            ASTnode* n2 = newASTnode(TEXT, "(", 0, NULL, NULL);
                                                            ASTnode* n4 = newASTnode(TEXT, ")", 0, NULL, NULL);
                                                            connectASTnode(4, n1, n2, $3, n4);
                                                            $$ = newASTnode(TEXT, "UnaryExp", 0, NULL, n1);
                                                        }
                | UNARYOP UnaryExp                      {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "UnaryExp", 0, NULL, $1);
                                                        }
FuncFParamsFlag:FuncRParams                             {
                                                            $$ = newASTnode(TEXT, "FuncFParamsFlag", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "FuncFParamsFlag", 0, NULL, n);
                                                        }
FuncRParams:    Exp CommaExpBlock                       {
                                                            connectASTnode(2, $1, $2);
                                                            $$ = newASTnode(TEXT, "FuncRParams", 0, NULL, $1);
                                                        }
CommaExpBlock:  CommaExpBlock ',' Exp                   {
                                                            ASTnode* n = newASTnode(TEXT, ",", 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "CommaExpBlock", 0, NULL, $1);
                                                        }
                | /*ε*/                                 {
                                                            ASTnode* n = newASTnode(TEXT, "ε", 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "CommaExpBlock", 0, NULL, n);
                                                        }
UNARYOP:        ADDSUB                                  {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "UNARYOP", 0, NULL, n);
                                                        }
                | NOT                                   {
                                                            ASTnode* n = newASTnode(TEXT, $1, 0, NULL, NULL);
                                                            $$ = newASTnode(TEXT, "UNARYOP", 0, NULL, n);
                                                        }
MulExp:         UnaryExp                                {
                                                            $$ = newASTnode(TEXT, "MulExp", 0, NULL, $1);
                                                        }
                | MulExp MULDIVSUR UnaryExp             {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "MulExp", 0, NULL, $1);
                                                        }
AddExp:         MulExp                                  {
                                                            $$ = newASTnode(TEXT, "AddExp", 0, NULL, $1);
                                                        }
                | AddExp ADDSUB MulExp                  {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "AddExp", 0, NULL, $1);
                                                        }
RelExp:         AddExp                                  {
                                                            $$ = newASTnode(TEXT, "RelExp", 0, NULL, $1);
                                                        }
                | RelExp CMP AddExp                     {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "RelExp", 0, NULL, $1);
                                                        }
EqExp:          RelExp                                  {
                                                            $$ = newASTnode(TEXT, "EqExp", 0, NULL, $1);
                                                        }
                | EqExp EQNEQ RelExp                    {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "EqExp", 0, NULL, $1);
                                                        }
LAndExp:        EqExp                                   {
                                                            $$ = newASTnode(TEXT, "LAndExp", 0, NULL, $1);
                                                        }
                | LAndExp AND EqExp                     {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "LAndExp", 0, NULL, $1);
                                                        }
LOrExp:         LAndExp                                 {
                                                            $$ = newASTnode(TEXT, "LOrExp", 0, NULL, $1);
                                                        }
                | LOrExp OR LAndExp                     {
                                                            ASTnode* n = newASTnode(TEXT, $2, 0, NULL, NULL);
                                                            connectASTnode(3, $1, n, $3);
                                                            $$ = newASTnode(TEXT, "LOrExp", 0, NULL, $1);
                                                        }    
ConstExp:       AddExp                                  {
                                                            $$ = newASTnode(TEXT, "ConstExp", 0, NULL, $1);
                                                        }
%%              
int main(){
    yyparse();
    printAST(ASThead, 0);
    freeAST(ASThead);
    return 0;
}