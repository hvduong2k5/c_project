#ifndef FUNCTION_OTHER
#define FUNCTION_OTHER

#include "member.h"

int isInputDay(int day,int month,int year);
int isGenderMale(struct Data noname);
void debugFirstLetter(char input[]);
void freeRoot(member *root);
void debugChar(char input[]);
int compareName(char name1[],char name2[]);
int compare(member *a,member *b);
#endif
