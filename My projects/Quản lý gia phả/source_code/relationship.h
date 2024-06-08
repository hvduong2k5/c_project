#ifndef RELATIONSHIP
#define RELATIONSHIP

#include "member.h"
#include "function_other.h"
#define  boyOrGirl(memb) (isGenderMale(memb->data))?"trai":"gai"
#define  older(a,b) compare(a,b)?a->data.name:b->data.name
#define  younger(a,b) (!compare(a,b))?a->data.name:b->data.name
#define  n(a) a->data.name
#define broOrSis(a) (isGenderMale(a->data))?"anh":"chi"
#define not_relationship endl;tab4;printf("%s la ho hang xa cua %s",memb1->data.name,memb2->data.name)
#define isuncle(a) (isGenderMale(a->data))?"chu":"co"
#define isuncle1(a) (isGenderMale(a->data))?"duong":"thim"


int findPath(member *root,int id,member **path,int pathIndex);

void relation1(member *a,member *b);
void relation2(member *a,member *b);
void relation3(member *a,member *b);
void relation4(member *a,member *b);
void relation5(member *a,member *b);
void relation6(member *a,member *b);
void relation7(member *a,member *b);
void relation8(member *a,member *b);
void relation9(member *a,member *b);
void relation10(member *a,member *b);
void relation11(member *a,member *b);
void relation12(member *a,member *b);
void relation13(member *a,member *b);
void relation14(member *a,member *b);
void relation15(member *a,member *b);
void relation16(member *a,member *b);
void relation17(member *a,member *b);
void findRelationship(member *root,int id1,int id2,int currentId);


#endif
