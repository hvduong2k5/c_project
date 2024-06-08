#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


#include "function_other.h"

int compareName(char name1[],char name2[])
{
return (strcmp(name1,name2)==0);
}
void debugChar(char input[])
{
	int i;
	for( i=0;i<60;i++)
	{
		if(input[i]==' ')
		{
			if(input[i+1]==' ')input[i]='\0';
		}
	}
}
int compare(member *a,member *b)
{
	if(a->data.year>b->data.year) return 1;
	else if(a->data.year==b->data.year)
	{
		if(a->data.month>b->data.month)return 1;
		else if(a->data.month==b->data.month)
		{if(a->data.day>=b->data.day) return 1;	}
	}
	return 0;//a<b
}
int isInputDay(int day,int month,int year)
{
	if(day<1||month<1||year<0||day>31||month>12){
		endl;tab4;printf("Ban da nhap sai ngay/thang/nam\n");
		return 0;
	}
	if(month%2==0){
		if(month!=2){
			if(day==31){
	    		endl;tab4;printf("trong thang nay khong co 31  ngay \n");
	    		return 0;
			}
		}
	
		else{
				if(year%4==0&&(year%100!=0||year%400==0)){
					 if(day>29){
					 endl;tab4;printf("nam nhuan nen ban da nhap sai roi\n");
					 return 0;
					 }					
				}
				else{
					if(day>28){
					endl;tab4;printf("trong thang 2 khong co ngay nay \n");
	    		    return 0;

					}					
				}
			}	
	}
	return 1;  
}
void freeRoot(member *root)
{
 	member *memb;
 	memb=root->find;
 	while(memb!=NULL)
 	{member *delmemb;
 	delmemb=memb;
 	memb=delmemb->find;
 		free(delmemb);
	 }
}
void debugFirstLetter(char input[])
{
	int a,i;
		for( i=0;i<6;i++){
		if(97<=(int)input[0]&&122>=(int)input[0]){
			a=(int)input[0];
			input[0]=(char)a-32;
		}
		else if(input[i]==' '){
			if(97<=(int)input[i+1]&&122>=(int)input[i+1])
			{a=(int)input[i+1];
			input[i+1]=(char) (a-32);}
		}
	}
}
int isGenderMale(struct Data noname)
{
	if(strncmp(noname.gender,"Nam",3)==0)
	{
		return 1;//nam
	}
	return 0;//nu
}
