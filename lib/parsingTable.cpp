#include "parsingTable.h"

ParsingTable::ParsingTable()
{
    table[{"S", "type"}] = {"type", "main", "lbt", "rbt", "beg", "CODE",
                            "end"};
    table[{"S", "$"}] = {"SYNCH"};
    table[{"CODE", "type"}] = {"DEC", "CODE"};
    table[{"CODE", "if"}] = {"IF_STMT", "CODE"};
    table[{"CODE", "end"}] = {" "};
    table[{"IF_STMT", "if"}] = {"if", "lbt", "COND", "rbt", "beg", "PRT", "end"};
    table[{"IF_STMT", "end"}] = {"SYNCH"};
    table[{"IF_STMT", "type"}] = {"SYNCH"};
    table[{"PRT", "end"}] = {" "};
    table[{"PRT", "prt"}] = {"prt", "lbt", "var", "rbt", "sm"};
    table[{"DEC", "type"}] = {"type", "LIST", "sm"};
    table[{"DEC", "end"}] = {"SYNCH"};
    table[{"DEC", "if"}] = {"SYNCH"};
    table[{"LIST", "var"}] = {"var", "LIST2"};
    table[{"LIST", "sm"}] = {"SYNCH"};
    table[{"LIST2", "sm"}] = {" "};
    table[{"LIST2", "cm"}] = {"cm", "LIST"};
    table[{"COND", "lbt"}] = {"EXPR"};
    table[{"COND", "var"}] = {"EXPR"};
    table[{"COND", "num"}] = {"EXPR"};
    table[{"COND", "rbt"}] = {"SYNCH"};
    table[{"EXPR", "lbt"}] = {"lbt", "EXPR", "rbt", "EXPRP"};
    table[{"EXPR", "var"}] = {"EXPRT", "EXPRP"};
    table[{"EXPR", "num"}] = {"EXPRT", "EXPRP"};
    table[{"EXPR", "rbt"}] = {"SYNCH"};
    table[{"EXPRT", "var"}] = {"var"};
    table[{"EXPRT", "num"}] = {"num"};
    table[{"EXPRT", "relop"}] = {"SYNCH"};
    table[{"EXPRT", "rbt"}] = {"SYNCH"};
    table[{"EXPRP", "rbt"}] = {" "};
    table[{"EXPRP", "relop"}] = {"relop", "EXPR"};
}