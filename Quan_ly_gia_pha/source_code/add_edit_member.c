#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "add_edit_member.h"

void addMemb(member *root,int *currentId)
{
	
	struct Data data;
	int check=0;
	data.id=(*currentId)+1;
	data.checkadn=1;
	system("cls");
	
	tab4;printf("===============BO=SUNG=THANH=VIEN=1==============");endl;
	endl;tab4;printf("Vui long nhap the he thu : ");
	scanf("%d",&data.generation);
	getchar();
	endl;tab4;printf("Vui long nhap Ho va Ten : ");
    scanf("%[^\n]%*c",data.name);
    debugFirstLetter(data.name);
	scanDay(&data);
	getchar();
	endl;tab4;printf("Vui long nhap nghe nghiep : ");
	scanf("%[^\n]%*c",data.job);
	endl;tab4;printf("Vui long chon gioi tinh : ");
	scanf("%s",&data.gender);
	debugFirstLetter(data.gender);
	getchar();
	endl;tab4;printf("Vui long nhap ghi chu (neu co) : ");
	scanf("%[^\n]%*c",data.note);
	endl;tab4;printf("=================================================");endl;
	endl;tab4;printf("Ban co muon them bo/me cua thanh vien nay khong : ");
	endl;tab4;printf("1.Co");
    endl;tab4;printf("0.Khong");
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
   char numparent;
   do{
   fflush(stdin);
	 numparent=getche();
	 if(numparent!='1'&&numparent!='0')
	 {endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
   }while(numparent!='1'&&numparent!='0');
    
	member *father=NULL,*mother=NULL;
	member *parent=NULL;
	if(numparent=='1')
	{
	 
		
		int idparent;
		system("cls");
		showListMemb(root);
	do{
		if(check==1)
		{
			endl;tab4;printf("Khoang cach the he voi bo/me qua xa");
			endl;tab4;printf("Vui long nhap lai the he :");
			scanf("%d",&data.generation);
		}
		endl;tab4;printf("Them bo/me cua thanh vien bang id bo,me.");
	    endl;tab4;printf("Vui long nhap id cua bo hoac me : ");
	scanf("%d",&idparent);

	parent=findFromId(root,idparent);
	if(isGenderMale(parent->data))	{
	              	father=parent;
	              	mother=father->married;
                	} else{   
                	mother=parent;
                	father=mother->married;
				}
		if(data.generation-parent->data.generation!=1)check=1;
	    }while(data.generation-parent->data.generation!=1);
	}
	
	system("cls");
	tab4;printf("===============BO=SUNG=THANH=VIEN=1==============");endl;
	tab4;printf("thanh vien vua nhap la:");
	showMemb(data);
	
	if(father!=NULL)
	{
		endl;tab4;printf("Bo cua thanh vien vua nhap la:");
		showMemb(father->data);
	}
	if(mother!=NULL)
	{	
	    endl;tab4;printf("Me cua thanh vien vua nhap la:");
		showMemb(mother->data);
	}
	endl;tab4;printf("=================================================");endl;
	endl;tab4;printf("Ban co muon luu thanh vien vua nhap vao gia pha khong.");
    endl;tab4;printf("1.Co");
    endl;tab4;printf("0.Khong");
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
	char yes;
	 do{fflush(stdin);
	 yes=getche();
	 if(yes!='1'&&yes!='0')
	 {endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
   }while(yes!='1'&&yes!='0');

	if(yes=='1'){
	(*currentId)++;
	member *newmemb=creatMemb(root,data,father,mother,NULL);
    }
    
}
void addMarried(member* root,int *currentId)
{
	int idmarried;
	system("cls");
	tab4;printf("===============BO=SUNG=THANH=VIEN=2==============");endl;
	showListMemb(root);
	endl;tab4;printf("Nhap vao id chong/vo cua nguoi sap them vao : ");
	scanf("%d",&idmarried);
	member *married;
	married=findFromId(root,idmarried);
	if(married!=NULL)
	{
		system("cls");
		tab4;printf("===============BO=SUNG=THANH=VIEN=2==============");endl;
		struct Data data;
		if(isGenderMale(married->data)){
		 		 strcpy(data.gender,"Nu");
		   }else{
		         strcpy(data.gender,"Nam");
				 }
		data.id=(*currentId)+1;
		data.checkadn=0;
		data.generation=married->data.generation;
		
		endl;tab4;printf("Vui long nhap Ho va Ten : ");
	    getchar();
		scanf("%[^\n]%*c",data.name);
		debugFirstLetter(data.name);
		scanDay(&data);
        getchar();
		endl;tab4;printf("Vui long nhap nghe nghiep : ");
		scanf("%[^\n]%*c",data.job);
		fflush(stdin);
		endl;tab4;printf("Vui long nhap ghi chu : ");
		scanf("%[^\n]%*c",data.note);
		system("cls");
		tab4;printf("===============BO=SUNG=THANH=VIEN=2==============");
		endl;tab4;printf("Thanh vien vua nhap la :");
		showMemb(data);
		endl;tab4;printf("Vo/chong cua thanh vien vua nhap la:");
		showMemb(married->data);
		endl;tab4;printf("=================================================");endl;
		endl;tab4;printf("Ban co muon luu thanh vien vua nhap vao gia pha khong.");
        endl;tab4;printf("1.Co");
        endl;tab4;printf("0.Khong");
        endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
char yes;
do{fflush(stdin);
	 yes=getche();
	 if(yes!='1'&&yes!='0')
	 {endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
   }while(yes!='1'&&yes!='0');
if(yes=='1')
{
	(*currentId)++;
	member* newmemb=creatMemb(root,data,NULL,NULL,married);
		}		
	}
}
void scanDay(struct Data *noname)
{
	do{
	endl;tab4;printf("Vui long nhap ngay thang nam sinh : ");
	scanf("%d %d %d",&noname->day,&noname->month,&noname->year);	
	}while (!isInputDay(noname->day,noname->month,noname->year));
}
void editIn4(member *memb)
{
	char numb;
	do{
	system("cls");
	tab4;printf("=============Chinh=sua=thanh=vien================");endl;
	tab4;printf("Thanh vien duoc tim thay :");endl;
	showMemb(memb->data);
	endl;tab4;printf("Chon thong tin can sua :");
	endl;tab4;printf("1.Ho va Ten");
	endl;tab4;printf("2.The he");
	endl;tab4;printf("3.Ngay thang nam sinh");
	endl;tab4;printf("4.Nghe nghiep");
	endl;tab4;printf("5.Gioi tinh");
	endl;tab4;printf("6.Ghi chu");
	endl;tab4;printf("0.Tro lai");
	endl;tab4;printf("Nhap lua chon :");
	fflush(stdin);
	numb=getche();
	system("cls");
	switch(numb)
	{
	case '1':
	tab4;printf("===============Chinh=sua=Ho=va=ten===============");endl;
	tab4;printf("Ho va ten ban dau : %s",memb->data.name);endl;
	tab4;printf("Nhap Ho va ten moi : ");
	scanf("%[^\n]%*c",memb->data.name);
	break;
	case '2':
	tab4;printf("=================Chinh=sua=The=he================");endl;
	tab4;printf("The he ban dau : %d",memb->data.generation);endl;
	tab4;printf("Nhap the he moi : ");
	scanf("%d",&memb->data.generation);
	break;
	case '3':
	tab4;printf("=================Chinh=sua=ngay=sinh=============");endl;
	tab4;printf("Ngay thang nam sinh ban dau : %d/%d/%d",memb->data.day,memb->data.month,memb->data.year);endl;
	tab4;printf("Nhap thang nam sinh moi : ");
	scanf("%d%d%d",&memb->data.day,&memb->data.month,&memb->data.year);
	break;
	case '4':
	tab4;printf("===============Chinh=sua=Nghe=nghiep=============");endl;
	tab4;printf("Nghe nghiep ban dau : %s",memb->data.job);endl;
	tab4;printf("Nhap nghe nghiep moi : ");
	scanf("%[^\n]%*c",memb->data.job);
	break;
	case '5':
	tab4;printf("===============Chinh=sua=Gioi=tinh===============");endl;
	tab4;printf("Gioi tinh ban dau : %s",memb->data.gender);endl;
	tab4;printf("Nhap gioi tinh moi : ");
	scanf("%s",memb->data.gender);
	break;
	case '6':
	tab4;printf("===============Chinh=sua=Ghi=chu=================");endl;
	tab4;printf("Ghi chu ban dau : %s",memb->data.note);endl;
	tab4;printf("Nhap ghi chu moi : ");
	scanf("%[^\n]%*c",memb->data.note);
	break;
	case '0':
	break;
	default:
	endl;tab4;printf("Lua chon khong thich hop!");
	endl;tab4;printf("Vui long nhap lai!");
	endl;tab4;system("pause");
	}
}while(numb!='0');					
}
void editMember(member *root,int currentId)
{ char numb;
do{
	system("cls");
	tab4;printf("=======TIM=KIEM=VA=CHINH=SUA=THANH=VIEN==========");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("    1.Tim thanh vien(ID)                         ");endl;
	tab4;printf("    2.Tim thanh vien(Ho ten)                     ");endl;
	tab4;printf("    3.Tim thanh vien(The he)                     ");endl;
	tab4;printf("    0.Tro lai                                    ");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
	tab4;printf("Vui long nhap so de chon chuc nang:");
	fflush(stdin);
	numb=getche();
	system("cls");
	switch(numb)
	{
	case '1':	
	{
	int id;
	system("cls");        
	tab4;printf("=======TIM=KIEM=VA=CHINH=SUA=THANH=VIEN==========");endl;                        
	tab4;printf("Nhap vao id cua thanh vien can sua thong tin :");
	scanf("%d",&id);
	member *editMemb1;
	editMemb1=findFromId(root,id);
	if(editMemb1!=NULL)
	editIn4(editMemb1);
    else{
        tab4;printf("Khong tim thay thanh vien co id :%d",id);endl;
        tab4;system("pause");endl;
	    }
	}
	break;
	case '2':
	{
	char name[MAX_NAME];
	system("cls");        
	tab4;printf("=======TIM=KIEM=VA=CHINH=SUA=THANH=VIEN==========");endl;                        
	tab4;printf("Nhap vao ho va ten cua thanh vien can sua thong tin :");
	scanf("%[^\n]%*c",&name);
	member *editMemb2[currentId];
	editMemb2[0]=NULL;
	editMemb2[1]=NULL;
	if(findFromName(root,name)!=NULL)
	editMemb2[0]=findFromName(root,name);
	if(editMemb2[0]!=NULL)
	{ 
	int i=1;
	member *memb;
	endl;tab4;printf("stt:0");
	showMemb(editMemb2[0]->data);
	while(findFromName(editMemb2[i-1],name)!=NULL)
	{
	editMemb2[i]=findFromName(editMemb2[i-1],name);
	if(findFromName(editMemb2[i-1],name)!=NULL){
	endl;endl;tab4;printf("stt:%d",i);
	showMemb(editMemb2[i]->data);
	}
	i++;
	}
	int stt=0;
	if(editMemb2[1]!=NULL)
	{
	endl;tab4;printf("Vui long chon stt cua thanh vien muon sua thong tin :");
	scanf("%d",&stt);
	}
	editIn4(editMemb2[stt]);
	}
	else{
	endl;tab4;printf("Khong tim thay thanh vien co ho va ten :%s",name);
	endl;tab4;system("pause");
	}			
	}	
	break;
	case '3':
	{
		int generation;
	system("cls");        
	tab4;printf("=======TIM=KIEM=VA=CHINH=SUA=THANH=VIEN==========");endl;                        
	tab4;printf("Nhap vao the he cua thanh vien can tim kiem va sua thong tin :");
	scanf("%d",&generation);
	member *editMemb3[currentId+99];
	editMemb3[0]=NULL;
	editMemb3[1]=NULL;	
	int i=0;
	member *memb;
	member *findG;
	findG=root;
	while(findG->find!=NULL)
	{
		if(findG->find->data.generation==generation)
		{
			editMemb3[i]=findG->find;
			endl;endl;tab4;printf("stt:%d",i);
	        showMemb(editMemb3[i]->data);
			i++;
		}
	findG=findG->find;
	}
	int stt=0;
	if(editMemb3[1]!=NULL)
	{	
	endl;endl;tab4;printf("*Luu y : nhap stt khong co se thoat!");
	endl;tab4;printf("Vui long chon stt cua thanh vien muon sua thong tin :");
	scanf("%d",&stt);	
	}
	if(stt<i&&stt>=0)
	editIn4(editMemb3[stt]);
	if(editMemb3[0]==NULL){
	endl;tab4;printf("Khong tim thay thanh vien co the he :%d",generation);
	endl;tab4;system("pause");
	}	
	}
	break;
	case '0':
	return;
	break;
	default:
	endl;tab4;printf("Lua chon khong thich hop!");
	endl;tab4;printf("Vui long nhap lai!");
	endl;tab4;system("pause");
    }
}while(numb!='0');
}
