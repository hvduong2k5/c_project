#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "save_show_read_member.h"

void saveTreeMemb(member* rootchild,int check[],FILE *file)
{
member* memb=rootchild;
if(rootchild==NULL) return;
if(rootchild->data.generation==1)
{
fprintf(file,"Chu thich:\n");
fprintf(file,"__+A :A la ho ten cua thanh vien trong dong ho\n"); 
fprintf(file,"==[B] :B la ho ten vo hoac chong cua A\n");
fprintf(file,"\n");
fprintf(file,"+%s (%s)\n",rootchild->data.name,rootchild->data.gender);
}    
if(rootchild->data.generation!=1)
	{
		if(rootchild->data.generation==2||check[2]==1)	
			fprintf(file,"  |");
		else if(rootchild->data.generation!=2&&check[2]!=1)
		    fprintf(file,"   ");
		
		if(rootchild->next!=NULL)
		{
			check[rootchild->data.generation]=1;
		}
		if(rootchild->next==NULL)
		check[rootchild->data.generation]=0;
		int i;
		for( i=3;i<=rootchild->data.generation;i++)
		{
		if(rootchild->data.generation==i||check[i]==1)
		    fprintf(file,"     |");
		else if(rootchild->data.generation!=i&&check[i]!=1)
		    fprintf(file,"      ");
    	}
	
		fprintf(file,"__+%s (%s)\n",rootchild->data.name,rootchild->data.gender);
	}
if(rootchild->married!=NULL)
	{
	if(rootchild->married->data.generation==1)
	  fprintf(file,"[%s (%s)]\n",rootchild->married->data.name,rootchild->married->data.gender);
      
	if(rootchild->married->data.generation!=1)
      {
		if(rootchild->married->data.generation==2||check[2]==1)
			fprintf(file,"  |");
		else if(rootchild->married->data.generation!=2&&check[2]!=1)
		    fprintf(file,"   ");
		int i;
		for( i=3;i<=rootchild->married->data.generation;i++)
	    {	
		if(rootchild->data.generation==i||check[i]==1)
		    fprintf(file,"     |");
		else if(rootchild->married->data.generation!=i&&check[i]!=1)
	    	fprintf(file,"      ");
	 	}
	    fprintf(file,"==[%s (%s)]\n",rootchild->married->data.name,rootchild->married->data.gender);
	  }
	}
	if(rootchild->child!=NULL)
	    saveTreeMemb(rootchild->child,check,file);
	if(rootchild->next!=NULL)
	    saveTreeMemb(rootchild->next,check,file);

}
void saveFileTree(member *root,char namefile[],int *currentId)
{
	FILE *file;
	file=fopen(namefile,"w");
	if(file==NULL)
	{
		endl;tab4;printf("file %s khong ton tai",namefile);
		endl;tab4;system("pause");
		return;
	}
	int check[*currentId];
	saveTreeMemb(root->child,check,file);
	fclose(file);
}
void saveLineMemb(FILE *file,member* rootchild)
{
member *memb=rootchild;
fprintf(file,"\n|%-3d|",memb->data.id);
(memb->father!=NULL)?fprintf(file,"%-3d|",memb->father->data.id):fprintf(file,"%-3d|",-1);
(memb->mother!=NULL)?fprintf(file,"%-3d|",memb->mother->data.id):fprintf(file,"%-3d|",-1);
(memb->married!=NULL)?fprintf(file,"%-3d|",memb->married->data.id):fprintf(file,"%-3d|",-1);
fprintf(file,"%-6d|",memb->data.generation);
fprintf(file,"%-25s|",memb->data.name);
fprintf(file,"%-9s|",memb->data.gender);
fprintf(file,"%-2d/%-2d/%-4d|",memb->data.day,memb->data.month,memb->data.year);
fprintf(file,"%-11s|",memb->data.job);
fprintf(file,"%-23s|",memb->data.note);
}
void scanToSaveList(FILE *file,member* rootchild)
{
	if(rootchild==NULL) return;
	saveLineMemb(file,rootchild);
	if(rootchild->married!=NULL)
	saveLineMemb(file,rootchild->married);
	if(rootchild->next!=NULL)
	scanToSaveList(file,rootchild->next);
	if(rootchild->child!=NULL)
	scanToSaveList(file,rootchild->child);
}
void saveFileList(member* root,char namefile[])
{	
FILE *file;
file=fopen(namefile,"w+");
	if(file==NULL)
    {
	endl;tab4;printf("file %s khong ton tai!",namefile);
	endl;tab4;system("pause");
	return;
   	} 
fprintf(file,"\n __________________________________________________________________________________________________________");
fprintf(file,"\n|ID1|BO |ME |ID2|The he|Ho va Ten                |Gioi tinh|ngay sinh |Nghe nghiep|  Ghi chu              |");
fprintf(file,"\n|===|===|===|===|======|=========================|=========|==========|===========|=======================|");
	{
	scanToSaveList(file,root->child);	
	}
fprintf(file,"\n|000|000|000|000|*****************************************************************************************|");
fclose(file);
}

void scanToShowList(member* rootchild)
{
	member* memb=rootchild;
	if(rootchild==NULL) return;
	showLineMemb(rootchild);
	if(rootchild->married!=NULL)
	showLineMemb(rootchild->married);
	if(rootchild->next!=NULL)
	scanToShowList(rootchild->next);
	if(rootchild->child!=NULL)
	scanToShowList(rootchild->child);
}
void showTreeMemb(member* rootchild,int check[])
{
member* memb=rootchild;
if(rootchild==NULL) return;
if(rootchild->data.generation==1)
{
tab4;printf("Chu thich:");
endl;tab4;printf("|x| :the he x");
endl;tab4;printf("__+A :A la ho ten cua thanh vien trong dong ho");
endl;tab4;printf("==[B] :B la ho ten vo hoac chong cua A");
endl; 
printf("|1|__+%s (%s) ID:%d\n",rootchild->data.name,rootchild->data.gender,rootchild->data.id);
}


if(rootchild->data.generation!=1)
{	
if(rootchild->next!=NULL)
{
check[rootchild->data.generation]=1;
}
if(rootchild->next==NULL)
	check[rootchild->data.generation]=0;		
int i;
for( i=2;i<=rootchild->data.generation;i++)
{
	if(rootchild->data.generation==i||check[i]==1)
	    printf("     |",i);
	else if(rootchild->data.generation!=i&&check[i]!=1)
	    printf("      ");
}
printf("%d|__+%s (%s) ID:%d\n",i-1,rootchild->data.name,rootchild->data.gender,rootchild->data.id);
}
if(rootchild->married!=NULL)
{
	if(rootchild->married->data.generation==1)
    printf("|1|==[%s (%s) ID:%d]\n",rootchild->married->data.name,rootchild->married->data.gender,rootchild->married->data.id);    
	if(rootchild->married->data.generation!=1)
    {	
		int i;
		for( i=2;i<=rootchild->married->data.generation;i++)
	    {	
		if(rootchild->data.generation==i||check[i]==1)
		    printf("     |");
		else if(rootchild->married->data.generation!=i&&check[i]!=1)
	    	printf("      ");
	 	}
	    printf("%d|==[%s (%s) ID:%d]\n",i-1,rootchild->married->data.name,rootchild->married->data.gender,rootchild->married->data.id);
    }
}
	if(rootchild->child!=NULL)
	    showTreeMemb(rootchild->child,check);
	if(rootchild->next!=NULL)
	    showTreeMemb(rootchild->next,check);
}
void showLineMemb(member *memb)
{
printf("\n|%-3d|",memb->data.id);
(memb->father!=NULL)?printf("%-3d|",memb->father->data.id):printf("%-3d|",-1);
(memb->mother!=NULL)?
printf("%-3d|",memb->mother->data.id):printf("%-3d|",-1);
(memb->married!=NULL)?
printf("%-3d|",memb->married->data.id):printf("%-3d|",-1);
printf("%-6d|",memb->data.generation);
printf("%-25s|",memb->data.name);
printf("%-9s|",memb->data.gender);
printf("%-2d/%-2d/%-4d|",memb->data.day,memb->data.month,memb->data.year);
printf("%-11s|",memb->data.job);
printf("%-23s|",memb->data.note);
}
void showListMemb(member *root)
{
endl;tab4;printf("Chu thich:");
endl;tab4;printf("ID1 : ID cua thanh vien");
endl;tab4;printf("BO : ID cua bo thanh vien");
endl;tab4;printf("ME : ID cua me thanh vien");
endl;tab4;printf("ID2 : ID cua vo/chong cua thanh vien");

printf("\n _________________________________________________________________________________________________________");
printf("\n|ID1|BO |ME |ID2|The he|Ho va Ten                |Gioi tinh|ngay sinh |Nghe nghiep|  Ghi chu              |");
printf("\n|===|===|===|===|======|=========================|=========|==========|===========|=======================|");
scanToShowList(root->child);
printf("\n***********************************************************************************************************");
}
void showMemb(struct Data data)
{
endl;tab4;printf("ID:%d-%s[%s]",data.id,data.name,data.gender);
printf("(%d/%d/%d);nghe nghiep:%s",data.day,data.month,data.year,data.job);
endl;tab4;printf("The he:%d;ghi chu:%s",data.generation,data.note);	
}

void readFileList(member *root,char namefile[],int *currentId)
{
FILE *file;
	struct Data data;
	int i;
	int id=0,generation;
{
file=fopen(namefile,"r");
if(file==NULL)
{
endl;tab4;printf("file %s khong ton tai!",namefile);
endl;tab4;system("pause");
return;
}
fscanf(file,"\n __________________________________________________________________________________________________________");
fscanf(file,"\n|ID1|BO |ME |ID2|The he|Ho va Ten                |Gioi tinh|ngay sinh |Nghe nghiep|  Ghi chu              |");
fscanf(file,"\n|===|===|===|===|======|=========================|=========|==========|===========|=======================|");
for( i=1;i>=0;i++)
{
int idfather,idmother,idmarried;
fscanf(file,"\n|%3d |%3d |%3d |%3d |%6d |",&data.id,&idfather,&idmother,&idmarried,&data.generation);
if(data.id!=0)
{  
fscanf(file,"%25[^\n]|",data.name);
fscanf(file,"%s |%2d /%2d /%4d |",data.gender,&data.day,&data.month,&data.year);
fscanf(file,"%11[^\n]|%23[^\n]|",data.job,data.note);
if(data.generation==1&&isGenderMale(data)==1) data.checkadn=1;//1
if(data.generation==1&&isGenderMale(data)==0) data.checkadn=0;//1
if(idfather!=-1&&data.generation!=1) data.checkadn=1;
if(idfather==-1&&data.generation!=1) data.checkadn=0;
(*currentId)++;
debugChar(data.name);
debugChar(data.job);
debugChar(data.note);
debugFirstLetter(data.name);
debugFirstLetter(data.gender);                   
member *newmemb,*father,*mother,*married;
married=findFromId(root,idmarried); 
father=findFromId(root,idfather);
mother=findFromId(root,idmother);       
newmemb=creatMemb(root,data,father,mother,married);
}
else break;
}
fclose(file);
}
int maxId=0;;
member *findMax=root->find;    
for ( i=1;i<*currentId;i++)
{if(findMax!=NULL){
if(maxId<findMax->data.id) maxId=findMax->data.id;
 	findMax=findMax->find;
}	
}
*currentId=maxId;
}
