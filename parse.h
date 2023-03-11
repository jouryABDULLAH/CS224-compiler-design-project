#ifndef PARSE_H_
#define PARSE_H_
#include "emitter.h"
#include "error.h"
#include "lexer.h"

void if1(int x);
void if2(int x);
void w1(int y);
void w2(int y);
void w3(int y);
int ifcount = -1,whilecount = -1;
int icounter = 0,wcounter = 0;
int tok; // store index

void parse(){
  lookahead = lexan();
  stmt();
  FuncDec();
  match(DONE);
}

void stmt(){
    switch(lookahead){
        case ID:
            tok = token;
            match(ID);
            restID();
            break;
        case IF:
            ifcount++;
            icounter++;
            match(IF);
            match('('); expr(); match(')');
            printf("pop r2\ncmp r2,0\nbe else%d\n",ifcount);
            match(THEN);
            stmt();
            printf("else%d:\n",ifcount);
            if(icounter >= 2)
                ifcount--;
            break;
        case WHILE:
            whilecount++;
            wcounter++;
            printf("while%d:\n",whilecount);
            match(WHILE);
            match('('); expr(); match(')');
            printf("pop r2\ncmp r2,0\nbe endwhile%d\n",whilecount);
            match(DO);
            stmt();
            printf("b while%d\nendwhile%d:\n",whilecount,whilecount);
            if(wcounter >= 2)
                whilecount--;
            break;
        case BEGIN:
            match(BEGIN);
            CS();
            match(END);
            break;
        default:
            return;
    }
}
void CS(){
    while(lookahead != END){
        stmt();match(';');
    }

}

void expr()
{
	int t;
	term();

	while(1)
	   switch (lookahead) {
	     case '+': case '-':
	        t = lookahead;
	        match(lookahead); term(); emit(t, NONE);
	       continue;
	    default:
	       return;
	}
}
void term()
{
	int t;
	factor();
	while(1)
	     switch (lookahead) {
	        case '*': case '/': case DIV: case MOD:
		t = lookahead;
		match(lookahead); factor(); emit(t, NONE);
		continue;
	         default:
		return;
	}
}
void factor()
{
	switch (lookahead) {
	case '(':
		match ('('); expr(); match(')'); break;
	case NUM:
		emit(NUM, token);
		match(NUM); break;
	case ID:
		emit(ID, token);
		match(ID);
		break;
	default:
		error("syntax error");
	}
}

void match(int t)
{
    //char t;

	if (lookahead == t)
		lookahead = lexan();
	else 
        error ("syntax error");
}

void restID(){
    switch(lookahead){
        case '=':
            match('=');
            expr();
            printf("pop %s\n",symtable[tok].lexptr);
            break;
        case '(':
            match('(');
            match(')');
            printf("call %s\n",symtable[tok].lexptr);
            break;
        default:
            error("syntax error");
    }
}
void FuncDec(){
    while(lookahead == VOID){
        match(VOID);
        tok = token;
        match(ID);
        printf("%s:\n",symtable[tok].lexptr);
        match('(');
        match(')');
        match(BEGIN);
        CS();
        match(END);
        printf("ret\n");
    }
}

void if1(int x){
    printf("pop r2\ncmp r2,0\nbe else%d\n",x);
}
void if2(int x){
     printf("else%d\n",x);
}
void w1(int y){
    printf("while%d\n",y);
}
void w2(int y){
    printf("pop r2\ncmp r2,0\nbe endwhile%d\n",y);
}
void w3(int y){
    printf("b while%d\nendwhile%d\n",y,y);
}

#endif