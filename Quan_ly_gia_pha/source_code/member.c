#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "member.h"

member* creatMemb(member *root,struct Data data,member*  father,member *mother,member* married)
{
	member *newmemb;
	newmemb=(member*) malloc(sizeof(member));
	if(newmemb==NULL){
    endl;tab4;printf("May tinh khong du bo nho !");
     return NULL;
     endl;tab4;system("pause");
     }
	newmemb->father=NULL;
	newmemb->mother=NULL;
	newmemb->married=NULL;
	newmemb->child=NULL;
	newmemb->next=NULL;
	newmemb->find=NULL;
	if(father!=NULL)
	{
		
	newmemb->father=father;
	if(father->child==NULL)
	{
	father->child=newmemb;
	}
	else if(father->child!=NULL)
	{
		member *a;
			a=father->child;
		do{
				if(a->next==NULL) 
				{
					a->next=newmemb;
					break;
				}
				member *b;
             	b=a->next;
                a=b;
		} while(1);
		
   }
}

	if(mother!=NULL){

	newmemb->mother=mother;
    	
	}
	if(married!=NULL)
	{
	
	newmemb->married=married;
    married->married=newmemb;
	}
	newmemb->data=data;
    member *find,*find1;
find=root;
while(find->find!=NULL)
{
    find=find->find;	
}
find->find=newmemb;
     
	return newmemb;
}
member* findFromId(member *root, int id)
{
if(id==-1) return NULL;
if (root == NULL) {
    return NULL;
}
if (root->data.id == id) {     
    return root;
}
member* find=root->find;
while(find!=NULL)
{
	if(find->data.id==id)return find;
	else find=find->find;
}
return NULL;
}
member *findFromName(member *root,char name[])
{
if (root == NULL) {
    return NULL;
}
member* find=root;
while(find->find!=NULL)
{
	if(compareName(find->find->data.name,name))return find->find;
	else find=find->find;
}
return NULL;
}
member* findFromGeneration(member *root,int generation)
{
if(generation==-1) return NULL;
if (root == NULL) {
    return NULL;
}

member* find=root;
while(find->find!=NULL)
{
	if(find->data.generation==generation)return find;
	else find=find->find;
}
return NULL;
}
