#include <stdio.h>
#include <stdlib.h>

#include "member.h"
#include "function_other.h"
#include "add_edit_member.h"
#include "relationship.h"
#include "save_show_read_member.h"

int main()
{
	int currentId=1;
	char fileinput[MAX_FILE];
member* root;
root=(member*) malloc(sizeof(member));
if(root==NULL)
{
printf("May tinh khong du bo nho !");
exit(0);
}
	root->father=NULL;
	root->married=NULL;
	root->mother=NULL;
	root->child=NULL;
	root->find=NULL;
	root->data.id=0;
	root->data.generation=0;
tab4;printf("=================Quan Ly Gia Pha=================");endl;
tab4;printf("                   Gioi Thieu:                   ");endl;
tab4;printf("   Giang vien huong dan : ThS. Nguyen Cong Danh  ");endl;
tab4;printf("   Nhom 10:                                      ");endl;
tab4;printf("   Hoang Van Duong                      23T_DT3  ");endl;
tab4;printf("   Phan cong tuan anh                   23T_DT3  ");endl;
tab4;printf("=================================================");endl;
tab4;system("pause");
int true0=0;
do{
	system("cls");
	tab4;printf("=================Quan Ly Gia Pha=================");endl;
	tab4;printf("                                                 ");endl;
    tab4;printf("    1.Doc file Input                             ");endl;
    tab4;printf("    0.Tiep tuc(khong doc file)                   ");endl;
    tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
    char choice0;
    do{
	fflush(stdin);
	if(true0!=2) choice0=getche();
	if(true0==2)choice0='1';
	if(choice0!='1'&&choice0!='0')
	{	
	endl;tab4;printf("Khong hop le! Vui long nhap lai :");
	}
      }while(choice0!='1'&&choice0!='0');
    if(choice0=='0') true0=0;
	if(choice0=='1')
    {
    system("cls");
    tab4;printf("=================Quan Ly Gia Pha=================");endl;
	tab4;printf("                                                 ");endl;
    tab4;printf("                 Doc file Input                  ");endl;
    tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
    if(root->child==NULL)
	{	
	tab4;printf("Nhap ten file :");
	scanf("%s",fileinput);    
	readFileList(root,fileinput,&currentId);
	true0=0;
	if(root->child==NULL)true0=1; 
	}
	else
	{
	tab4;printf("Da co du lieu input");endl;
	endl;tab4;printf("Ban co muon Doc file gia pha khac khong?");
    endl;tab4;printf("1.Co");
    endl;tab4;printf("0.Khong");
    endl;tab4;printf("(*)Luu y:Du lieu hien tai se duoc giai phong!");
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
	char yes;
	do{fflush(stdin);
    yes=getche();
	if(yes!='1'&&yes!='0')
	{endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
      }while(yes!='1'&&yes!='0');
    if(yes=='1'){
    freeRoot(root->child);
    root->child=NULL;
    root->find=NULL;
    true0=2;
		        } 
	if(yes=='0') true0=0;
	}            	
	}	
	while(true0==0){   
	system("cls");    
	tab4;printf("====================CHUC=NANG====================");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("    1.Bo sung them thanh vien                    ");endl;
	tab4;printf("    2.Hien thi thanh vien                        ");endl;
	tab4;printf("    3.Luu thanh vien vao file                    ");endl;
	tab4;printf("    4.Tim kiem,chinh sua                         ");endl;
	tab4;printf("    5.Tro lai                                    ");endl;
	tab4;printf("    0.Thoat.                                     ");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
	tab4;printf("Vui long nhap so de chon chuc nang:");
	char numb1;
	fflush(stdin);
	numb1=getche();
	system("cls");
	switch(numb1)
	{
	case '1':
	{
	int true1;
	do{
	char case1;
	system("cls");                                
	tab4;printf("================BO=SUNG=THANH=VIEN===============");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("    1.Them thanh vien la con cai trong dong ho.  ");endl;
	tab4;printf("    2.Them thanh vien la con dau,con re.         ");endl;
	tab4;printf("    0.Tro lai.                                   ");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
	tab4;printf("Vui long nhap so de chon chuc nang:");
	fflush(stdin);
	case1=getche();		
	switch(case1)
	{
	case '1':
    addMemb(root,&currentId);                   
	true1=1;
	break;
	case '2':
	{
	addMarried(root,&currentId);
	true1=1;
	}					
	break;
	case '0':
	true1=0;
	break;
	default:
	endl;tab4;printf("Lua chon khong thich hop!");
	endl;tab4;printf("Vui long nhap lai!");
	endl;tab4;system("pause");
	true1=1;					
	}		
    }while(true1);
	}
	break;    	   
	case '2':
	{
	int true2;
	do{
 	char case2;
 	system("cls");                                
	tab4;printf("===============HIEN=THI=THANH=VIEN===============");endl;
  	tab4;printf("                                                 ");endl;
	tab4;printf("    1.Hien thi dang bang.                        ");endl;
	tab4;printf("    2.Hien thi cay gia pha.                      ");endl;
	tab4;printf("    0.Tro lai.                                   ");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
	tab4;printf("Vui long nhap so de chon chuc nang:");
	fflush(stdin);
	case2=getche();endl;
	int check[currentId];
	switch(case2)
	{
	case '1':
	system("cls");
	tab4;printf("===============DANH=SACH=THANH=VIEN===============");
	showListMemb(root);
	endl;system("pause");
	true2=1;
	break;
	case '2':
	system("cls");
	tab4;printf("===============HIEN=THI=CAY=GIA=PHA===============");endl;
	showTreeMemb(root->child,check);
	endl;system("pause");
	true2=1;
	break;
	case '0':
	true2=0;
	break;
	default:
	endl;tab4;printf("Lua chon khong thich hop!");
	endl;tab4;printf("Vui long nhap lai!");
	endl;tab4;system("pause");
	true2=1;	
	}
	}while(true2);
    }
	break;
 	case '3':
 	{
  	int true3;
	do{	
	char case3;
  	system("cls");                                
	tab4;printf("=================LUU=THANH=VIEN==================");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("    1.Luu thanh vien vao file(danh sach).        ");endl;
	tab4;printf("    2.Luu cay gia pha vao file.                  ");endl;
	tab4;printf("    0.Tro lai.                                   ");endl;
	tab4;printf("                                                 ");endl;
	tab4;printf("=================================================");endl;
	tab4;printf("Vui long nhap so de chon chuc nang:");
	fflush(stdin);
	case3=getche();
	switch(case3)
	{
	case '1':
	system("cls");
	tab4;printf("=================LUU=THANH=VIEN=1================");endl;
	endl;tab4;printf("Ban co muon xem danh sach thanh vien truoc khi luu.");
    endl;tab4;printf("1.Co");
    endl;tab4;printf("0.Khong");
    endl;tab4;printf("=================================================");endl;
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
    char choice;
    do{fflush(stdin);
	choice=getche();
	if(choice!='1'&&choice!='0')
	{endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
    }while(choice!='1'&&choice!='0');
    if(choice=='1')
    {
    showListMemb(root);
	}								
	char namefile[MAX_FILE];
	endl;tab4;printf("Vui long nhap ten file can luu :");
	scanf("%s",namefile);
	endl;tab4;printf("Ban co muon luu danh sach thanh vien vao file %s.",namefile);
    endl;tab4;printf("1.Co");
    endl;tab4;printf("0.Khong");
    endl;tab4;printf("=================================================");endl;
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
    char yes;
    do{fflush(stdin);
	yes=getche();
	if(yes!='1'&&yes!='0')
	{endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
    }while(yes!='1'&&yes!='0');
    if(yes=='1')
    {
    saveFileList(root,namefile);
	}
	true3=1;
	break;
	case '2':
	system("cls");
	tab4;printf("=================LUU=THANH=VIEN=2================");endl;
	endl;tab4;printf("Ban co muon xem cay gia pha truoc khi luu.");
    endl;tab4;printf("1.Co");
    endl;tab4;printf("0.Khong");
    endl;tab4;printf("=================================================");endl;
    endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
    char choice2;
    do{fflush(stdin);
	choice2=getche();
	if(choice2!='1'&&choice2!='0')
	{endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
    }while(choice2!='1'&&choice!='0');
    if(choice2=='1')
    {
    endl;
    int check[currentId];
                    	showTreeMemb(root->child,check);
					}
						
						
						char namefile2[MAX_FILE];
						endl;tab4;printf("Vui long nhap ten file can luu :");
						scanf("%s",namefile2);
						endl;tab4;printf("Ban co muon luu cay gia pha vao file %s.",namefile2);
                        endl;tab4;printf("1.Co");
                        endl;tab4;printf("0.Khong");
                    endl;tab4;printf("=================================================");endl;
                        endl;tab4;printf("Vui long nhap so thu tu tuong ung :");
                    char yes2;
                     do{fflush(stdin);
	                 yes2=getche();
	                 if(yes2!='1'&&yes2!='0')
	                 {endl;tab4;printf("Khong hop le! Vui long nhap lai :");}
                     }while(yes2!='1'&&yes2!='0');
                    if(yes2=='1')
                    {
                    	saveFileTree(root,namefile2,&currentId);
					}
						true3=1;
						break;
					case '0':
						true3=0;
						break;
					default:
						endl;tab4;printf("Lua chon khong thich hop!");
						endl;tab4;printf("Vui long nhap lai!");
						endl;tab4;system("pause");
						true3=1;
				}
	          }while(true3);	
				}
			
				break;
	    	case '4':
	    		{
	    		int true4;
            do{
				
	    		system("cls");                                
				tab4;printf("================TIM=KIEM=VA=CHINH=SUA==============");endl;
	    		tab4;printf("                                                   ");endl;
	    		tab4;printf("    1.Tim kiem moi quan he giua 2 thanh vien       ");endl;
				tab4;printf("    2.Tim kiem va chinh sua thanh vien             ");endl;
				tab4;printf("    0.Tro lai.                                     ");endl;
				tab4;printf("                                                   ");endl;
				tab4;printf("===================================================");endl;
				tab4;printf("Vui long nhap so de chon chuc nang:");
				fflush(stdin);
				char case4;
				case4=getche(); 
				switch (case4)
				{
					case '1':
					{						
						system("cls");
						int id1,id2,check2[currentId];
						tab4;printf("================TIM=KIEM=MOI=QUAN=HE===============");endl;
						showTreeMemb(root->child,check2);
						endl;tab4;printf("Vui long nhap id thanh vien 1:");
						scanf("%d",&id1);
						endl;tab4;printf("Vui long nhap id thanh vien 2:");
						scanf("%d",&id2);
						findRelationship(root->child,id1,id2,currentId);
						endl;tab4;system("pause");
						true4=1;
						break;}
					case '2':
						editMember(root,currentId);
						true4=1;
						break;
					case '0':
						true4=0;
						break;
					default:
						endl;tab4;printf("Lua chon khong thich hop!");
						endl;tab4;printf("Vui long nhap lai!");
						endl;tab4;system("pause");
						true4=1;
				}
	}
				while (true4);	
				}
	    		break;
	    	case '5':
	    		
	    		true0=1;
	    		break;
	    	case '0':
	    		freeRoot(root);
	    		printf("Giai phong du lieu thanh cong!\n");
	    		printf("Ket thuc chuong trinh !\nHen gap lai!");
	    		return 0;
	    		break;
	    	default:
	    		endl;tab4;printf("Lua chon khong thich hop!");
				endl;tab4;printf("Vui long nhap lai!");
				endl;tab4;system("pause");
				true0=0;
           }
		}
    }while(true0);
return 0;
}

