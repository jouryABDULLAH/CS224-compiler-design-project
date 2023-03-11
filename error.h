#ifndef ERROR_H_
#define ERROR_H_
#include "global.h"
void error(char* m)
{
	fprintf(stderr, "line %d: %s\n", lineno, m);
	exit(1); }
#endif 