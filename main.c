#include "global.h"
#include "init.h"
#include "parse.h"
void main()
{
	inp = fopen("file.exp","r");
	if (inp == NULL)
        printf("the file input doesn't exist\n");
	init();
	parse();
	fclose(inp);
	exit(0);
}
