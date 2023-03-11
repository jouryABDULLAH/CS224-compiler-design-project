#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BSIZE  128
#define NONE   -1
#define EOS    '\0'
#define NUM     256
#define DIV       257
#define MOD    258
#define ID          259
#define DONE   260
#define IF 261
#define THEN 262
#define END  263
#define WHILE 264
#define DO    265
#define BEGIN 266
#define VOID 267

FILE *inp;
int lookahead;
int token; int lineno;
struct entry {
   char *lexptr;
   int token;  };
    #endif
