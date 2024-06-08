#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


#include "relationship.h"


int findPath(member *root,int id,member **path,int pathIndex)
{
	if(root==NULL) return 0;
	path[pathIndex]=root;
	if(root->data.id==id) return 1;
	if(root->married!=NULL)
	{
		if(root->married->data.id==id)
		{
			path[pathIndex+1]=root->married;
			return 1;
		}
	}
	if(root->child!=NULL)
	{
		if(findPath(root->child,id,path,pathIndex+1)) return 1;
	member *next =root->child->next;
	while(next!=NULL)
	{
		if(findPath(next,id,path,pathIndex+1)) return 1;
		next=next->next;
	}
	}
	return 0;
}
void relation1(member *a,member *b)//me con
{
if(abs(a->data.generation-b->data.generation)==1)
	{
	member *old,*young;
    (a->data.generation<b->data.generation)?(old=a,young=b):(old=b,young=a);
	endl;tab4;printf("%s la me cua %s",n(old),n(a));
	endl;tab4;printf("%s la con %s cua %s",n(young),boyOrGirl(young),n(old));
	}
}
void relation2(member *a,member *b)//anh,chi,em ruot
{
if(a->data.checkadn==b->data.checkadn)
	{
    member *old,*young;
    (compare(a,b))?(old=a,young=b):(old=b,young=a);
	endl;tab4;printf("%s la %s ruot cua %s",old->data.name,broOrSis(old),young->data.name);
	endl;tab4;printf("%s la em %s cua %s",young->data.name,boyOrGirl(young),old->data.name);
	}
}
void relation3(member *a,member *b)//bo con
{
 if(a->data.generation!=b->data.generation)	
	{
     member *old,*young;
	(a->data.generation<b->data.generation)?(old=a,young=b):(old=b,young=a);
	endl;tab4;printf("%s la bo cua %s",old->data.name,young->data.name);
	endl;tab4;printf("%s la con %s cua %s",young->data.name,boyOrGirl(young),old->data.name);
	}	
}
void relation4(member *a,member *b)//vo chong
{
	member *husband,*wife;
 if(a->data.generation==b->data.generation)
 {
 	(a->data.checkadn==1)?(husband=a,wife=b):(husband=b,wife=a);
	endl;tab4;printf("%s la chong cua %s",husband->data.name,wife->data.name);
	endl;tab4;printf("%s la vo cua %s",wife->data.name,husband->data.name);
 }
}
#define iswife(a) (isGenderMale(a->data))?"vo":"chong"
#define ismarried(a) (isGenderMale(a->data))?"re":"dau"
void relation5(member *a,member *b)//bo//con dau\re
{
	if(a->data.checkadn==0||b->data.checkadn==0)
	{
	member *old,*young;
	(a->father==NULL)?(young=a,old=b):(young=b,old=a);
    endl;tab4;printf("%s la bo %s cua %s",old->data.name,iswife(young),young->data.name);
    endl;tab4;printf("%s la con %s cua %s",young->data.name,ismarried(young),old->data.name);
	}
}
void relation6(member *a,member *b)
{
	if((a->data.checkadn==1)&&(b->data.checkadn==1))
	{
	member *old,*young;
	(a->data.generation<b->data.generation)?(old=a,young=b):(old=b,young=a);
	endl;tab4;printf("%s la ong noi cua %s",old->data.name,young->data.name);
    endl;tab4;printf("%s la chau %s cua %s",young->data.name,boyOrGirl(young),old->data.name);
	}
}
void relation7(member *a,member *b)
{
	if((a->data.checkadn==0)||(b->data.checkadn==0))
	{
	member *old,*young;
	(a->data.generation<b->data.generation)?(old=a,young=b):(old=b,young=a);
	endl;tab4;printf("%s la ong noi cua %s %s",old->data.name,iswife(young),young->data.name);
    endl;tab4;printf("%s la chau %s cua %s",young->data.name,ismarried(young),old->data.name);
	}
	
}
void relation8(member *a,member *b)//me//con dau\re
{
if(a->data.checkadn==0&&b->data.checkadn==0)
	{
	member *mother,*childv2;
	(a->data.generation>b->data.generation)?(childv2=a,mother=b):(childv2=b,mother=a);
    endl;tab4;printf("%s la me %s cua %s",mother->data.name,iswife(childv2),childv2->data.name);
    endl;tab4;printf("%s la con %s cua %s",childv2->data.name,ismarried(childv2),mother->data.name);
	}
}
void relation9(member *a,member *b)// ba chau
{
if(abs(a->data.generation-b->data.generation)==2)
	{
		member *grandpa,*child;
		(a->data.generation<b->data.generation)?(grandpa=a,child=b):(grandpa=b,child=a);
	endl;tab4;printf("%s la ba noi cua %s",grandpa->data.name,child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,boyOrGirl(child),grandpa->data.name);
	}
}

void relation10(member *a,member *b)//chu bac co //chau
{
if(a->data.checkadn==1&&b->data.checkadn==1)
	{
	member *older,*child;
	(a->data.generation>b->data.generation)?(child=a,older=b):(child=b,older=a);
	if(compare(older,child->father))
	{
	endl;tab4;printf("%s la bac cua %s",older->data.name,child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,boyOrGirl(child),older->data.name);
	}
	if(compare(older,child->father)==0)
	{
	endl;tab4;printf("%s la %s cua %s",older->data.name,isuncle(older),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,boyOrGirl(child),older->data.name);
	}
   	}
}

void relation11(member *a,member *b)// anh,chi em dau re
{
if(a->data.generation==b->data.generation)
	{
		member *married,*nomarried,*old,*young;
		(a->data.checkadn)?(married=b,nomarried=a):(nomarried=b,married=a);
		(compare(married->married,nomarried))?(old=married,young=nomarried):(old=nomarried,young=married);	
	endl;tab4;printf("%s la %s %s cua %s",old->data.name,broOrSis(married),ismarried(young),young->data.name);
	endl;tab4;printf("%s la em %s cua %s",young->data.name,iswife(old),old->data.name);
	}
}
void relation12(member *a,member *b)//ba chau dau re
{
	if((a->data.checkadn==0)&&(b->data.checkadn==0))
	{
		member *grandpa,*childv2;
		(a->data.generation < b->data.generation)?(grandpa=a,childv2=b):(grandpa=b,childv2=a);
	endl;tab4;printf("%s la ba noi cua %s %s",grandpa->data.name,iswife(childv2),childv2->data.name);
    endl;tab4;printf("%s la chau %s cua %s",childv2->data.name,ismarried(childv2),grandpa->data.name);
	}
}
void relation13(member *a,member *b)//chu bac co //chau dau/re
{
	if(a->data.checkadn==1&&b->data.checkadn==1)
	{
	member *older,*child;
	(a->data.generation>b->data.generation)?(child=a,older=b):(child=b,older=a);
	member *father=child->father;
	if(compare(older,child->father))
	{
	endl;tab4;printf("%s la bac cua %s %s",older->data.name,iswife(child),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,ismarried(child),older->data.name);
	}
	if(compare(older,child->father)==0)
	{
	endl;tab4;printf("%s la %s cua %s %s",older->data.name,isuncle(older),iswife(child),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,ismarried(child),older->data.name);
	}
   	}
}
void relation14(member *a,member *b)//anh,chi,em dau,re
{
	if(a->data.checkadn==0&&b->data.checkadn==0)
	{
        member *older,*young;
        compare(a->married,b->married)?(older=a,young=b):(older=b,young=a);
	    endl;tab4;printf("%s la %s %s cua %s",older->data.name,broOrSis(older),ismarried(older),young->data.name);
		endl;tab4;printf("%s la em %s cua %s",young->data.name,ismarried(young),older->data.name);
	}
}

void relation15(member *a,member *b)//chu bac co (dau/re)//chau 
{
	if(abs(a->data.generation-b->data.generation)==1)
	{
	member *older,*child;
	(a->data.generation>b->data.generation)?(child=a,older=b):(child=b,older=a);
	if(compare(older,child->father))
	{
	endl;tab4;printf("%s la bac %s cua %s",older->data.name,boyOrGirl(older),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,boyOrGirl(child),older->data.name);
	}
	if(compare(older,child->father)==0)
	{
	endl;tab4;printf("%s la %s cua %s",older->data.name,isuncle1(older),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,boyOrGirl(child),older->data.name);
	}
   	}
}
void relation16(member *a,member *b)//anh,chi,em ho
{
	if(a->data.checkadn==1&&b->data.checkadn==1)
	{
        member *older,*young;
        (compare(a->father,b->father))?(older=a,young=b):(older=b,young=a);
		endl;tab4;printf("%s la %s ho cua %s",older->data.name,broOrSis(older),young->data.name);
		endl;tab4;printf("%s la em ho cua %s",young->data.name,older->data.name);
	}
}
void relation17(member *a,member *b)//chu bac co (dau/re)//chau 
{
if(abs(a->data.generation-b->data.generation)==1)
	{
	member *older,*child;
	(a->data.generation>b->data.generation)?(child=a,older=b):(child=b,older=a);
	if(compare(older->married,child->father))
	{
	endl;tab4;printf("%s la bac %s cua %s",older->data.name,boyOrGirl(older),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,ismarried(child),older->data.name);
	}
	if(compare(older,child->father)==0)
	{
	endl;tab4;printf("%s la %s cua %s",older->data.name,isuncle1(older),child->data.name);
    endl;tab4;printf("%s la chau %s cua %s",child->data.name,ismarried(child),older->data.name);
	}
   	}
}
void findRelationship(member *root,int id1,int id2,int currentId)
{
	int maxPerson=currentId+10;
member *path1[maxPerson],*path2[maxPerson];
if(!findPath(root,id1,path1,0)||!findPath(root,id2,path2,0))
{
	endl;tab4;printf("1 trong 2 nguoi ko co trong gia pha!");
	return ;
}
int i=0;
while(path1[i]!=NULL&&path2[i]!=NULL&&path1[i]->data.id==path2[i]->data.id)
{i++;}

int length1=0,length2=0;
int k;
for(k=i-1;path1[k]->data.id!=id1;k++)
length1++;

for(k=i-1;path2[k]->data.id!=id2;k++)
length2++;
member *memb1,*memb2;
memb1=path1[length1+i-1];
memb2=path2[length2+i-1];
system("cls");
tab4;printf("================TIM=KIEM=MOI=QUAN=HE===============");endl;
endl;showMemb(memb1->data);
endl;showMemb(memb2->data);endl;


{if(length1==0||length2==0)
{
	if((length1==0&&length2==1)||(length2==0&&length1==1))
	{
		relation3(memb1,memb2);//bo con
	    relation4(memb1,memb2);//vo chong
	}
   if((length1==0&&length2==2)||(length1==2&&length2==0))
   {
   	relation5(memb1,memb2);// bo //con dau/re
   	relation6(memb1,memb2);//ong chau
   }
   if((length1==0&&length2==3)||(length1==3&&length2==0))
   {relation7(memb1,memb2);//ong chau dau\re
   if(memb1->data.checkadn==memb2->data.checkadn) not_relationship;
   }
   
}
if(length1==1||length2==1)
{
	if(length1==1&&length2==1)
	 {
	 	relation2(memb1,memb2);//anh chi em ruot
     	relation1(memb1,memb2);//me con
	 }
    if((length1==2&&length2==1)||(length1==1&&length2==2))
    {
    	relation8(memb1,memb2);//me con dau\re
    	relation9(memb1,memb2);//ba chau
		relation10(memb1,memb2);//bac co chu//chau
	    relation11(memb1,memb2);//anh chi em dau
	}
	if((length1==1&&length2==3)||(length1==3&&length2==1))
	{
		relation12(memb1,memb2);//ba chau dau, re
		relation13(memb1,memb2);//bac co chu//chau dau re
	}
}
if(length1==2||length2==2)
{
	if(length1==2&&length2==2)
	{
		relation14(memb1,memb2);//anh chi em dau re
		relation15(memb1,memb2);//duong/thim/bac//chau
	    relation16(memb1,memb2);//anh chi em ho
	}
	if((length1==2&&length2==3)||(length1==3&&length2==2))
	{
	relation17(memb1,memb2);//duong/thim/bac//chau dau
	if(memb1->data.generation==memb2->data.generation) not_relationship;
	}
}
if(length1>=4||length2>=4||(length1==3&&length2==3))
{not_relationship;}
}
endl;tab4;printf("===================================================");endl; 
} 

