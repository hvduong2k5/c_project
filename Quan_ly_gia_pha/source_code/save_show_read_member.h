#ifndef SAVESHOWREAD
#define SAVESHOWREAD

#include "member.h"
#include "function_other.h"

void saveTreeMemb(member* rootchild,int check[],FILE *file);
void saveLineMemb(FILE *file,member* rootchild);
void saveFileTree(member *root,char namefile[],int *currentId);
void scanToSaveList(FILE *file,member* rootchild);
void saveFileList(member* root,char namefile[]);

void scanToShowList(member* rootchild);
void showTreeMemb(member* rootchild,int check[]);
void showListMemb(member *root);
void showLineMemb(member *memb);
void showMemb(struct Data data);
void readFileList(member *root,char namefile[],int *currentId);



#endif
