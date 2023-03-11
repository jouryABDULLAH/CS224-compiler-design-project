#ifndef LEXER_H_
#define LEXER_H_
#include "global.h"
#include "symbol.h"

char lexbuf[BSIZE];
int lineno = 1;
int token = NONE;


int lexan(){

	int input;
	while(1) {
		input = getc(inp);
		if(input == '^'){
		    while(1){
		        input = getc(inp);
		        if(input == '\n'){
		            break;
		        }
		    }
		    input = getc(inp);
		}
		if(input == '%'){
		    while(1){
		        input = getc(inp);
		        if(input == '%'){
		            break;
		        }
		    }
		    input = getc(inp);
		}
		if (input == ' ' || input == '\t');
		else if (input == '\n')
            lineno++;
        else if (isdigit(input)) {
                ungetc(input,inp);
                fscanf(inp,"%d",&token);
                return NUM;
		        }
        else if (isalpha(input)){
                int p, b = 0;
            while (isalnum(input)) {
                lexbuf[b++] = input;
                input = getc(inp);
                if (b >= BSIZE)
                    error("compiler error");
	}

	lexbuf[b] = EOS;
	if (input != EOF)
		ungetc(input, inp);
	p = search(lexbuf);
	if(p == 0)
		p = insert(lexbuf, ID);
	token = p;
	return symtable[token].token;
	}
	else if (input == EOF)
		return DONE;
    else {
        token = NONE;
        return input;
	       }
	}
}


#endif 
