#ifndef MEMBER
#define MEMBER

#define MAX_NAME 25
#define MAX_JOB 20
#define MAX_NOTE 30
#define MAX_GENDER 5
#define MAX_FILE 40

#define endl printf("\n");
#define tab4 printf("\t\t\t\t");
struct Data 
{
    int id;
	int generation;
	int checkadn;
	char name[MAX_NAME];
    char job[MAX_JOB];
	char gender[MAX_GENDER];
	char note[MAX_NOTE];
	int day;
	int month;
	int year;
};
struct Member
{
	struct Data data;
	struct Member *married;
	struct Member *father;
	
	struct Member *mother;
	struct Member  *child;
	struct Member *next;	
	struct Member *find;
};
typedef struct Member member;
member* findFromGeneration(member *root,int generation);
member *findFromName(member *root,char name[]);
member* findFromId(member *root, int id);
member* creatMemb(member *root,struct Data data,member*  father,member *mother,member* married);
#endif
