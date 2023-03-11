#ifndef EMITTER_H_
#define EMITTER_H_
#include "global.h"
void emit(int t,int  tval)
{
	switch(t) {
	case '+':
		printf("pop r1\npop r2\nadd r2,r1\npush r2\n");
		break;
	case '-':
		printf("pop r1\npop r2\nsub r2,r1\npush r2\n");
		break;
	case '*':
		printf("pop r1\npop r2\nmult r2,r1\npush r2\n");
		break;
	case '/':
		printf("pop r1\npop r2\nrdiv r2,r1\npush r2\n");
		break;
	case DIV:
		printf("pop r1\npop r2\ndiv r2,r1\npush r2\n");
		break;
    case MOD:
		printf("pop r1\npop r2\nmod r2,r1\npush r2\n");
		break;
	case NUM:
		printf("push %d\n",tval);
		break;
	case ID:
		printf("push %s\n", symtable[tval].lexptr);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}}
#endif 
