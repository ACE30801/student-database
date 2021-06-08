#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

struct sub{
 char name[15];
 int mark;
 };

 typedef struct infostudent{
 char name [50];
 char currentyear[15];
 int section;
 int code;
 long long int national_id;
 char email[30];
 char Birthday[30];
 struct sub *subjects[4];
int totalmark;

 }stud;


 typedef struct list_infostudent{

    char name [50];
    long long int national_id;
    char currentyear[15];
    int section;
    int code;
    char email[30];
    char Birthday[30];
    struct sub *subjects[4];
    int totalmark;

    struct list_infostudent *nextptr;

 }studl;

 typedef studl *infostptr;

    studl *head = NULL;
    studl *curr = NULL;


void start();
void insert();
void mainsearch();
void searchbyname();
void searchbycode();



int main()
{


    return;
}




void insert()
 {

    infostptr newPtr = malloc(sizeof(studl));

    newPtr->subjects[0] =  malloc(sizeof(struct sub));
    newPtr->subjects[1] =  malloc(sizeof(struct sub));
    newPtr->subjects[2] =  malloc(sizeof(struct sub));
    newPtr->subjects[3] =  malloc(sizeof(struct sub));

    if (newPtr != NULL) {

//adding all data for a new student

    printf("Enter the student's name : ");
    fflush(stdin);
    gets(newPtr->name);
    printf("Enter the student's code : ");
    fflush(stdin);
    scanf("%d",&newPtr->code);

    printf("Enter the student's ID :");
    fflush(stdin);
    scanf("%lli",&newPtr->national_id);
    printf("Enter the student's date of birth :");
    fflush(stdin);
    gets(newPtr->Birthday);

    printf("Enter the student's E-mail :");
    fflush(stdin);
    gets(newPtr->email);

    printf("Enter the student's current year :");
    fflush(stdin);
    gets(newPtr->currentyear);
    printf("Enter the student's section :");
    fflush(stdin);
    scanf("%d",&newPtr->section);

    printf("Enter [name] of the subject No.1 :");
    fflush(stdin);
    gets(newPtr->subjects[0]->name);
    printf("Enter [degree] of the subject No.1 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[0]->mark);

    printf("Enter [name] of the subject No.2 :");
    fflush(stdin);
    gets(newPtr->subjects[1]->name);
    printf("Enter [degree] of the subject No.2 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[1]->mark);

    printf("Enter [name] of the subject No.3 :");
    fflush(stdin);
    gets(newPtr->subjects[2]->name);
    printf("Enter [degree] of the subject No.3 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[2]->mark);

    printf("Enter [name] of the subject No.4 :");
    fflush(stdin);
    gets(newPtr->subjects[3]->name);
    printf("Enter [degree] of the subject No.4 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[3]->mark);

    newPtr->nextptr = NULL;



    studl *previousPtr = NULL;
    studl *currentPtr = head;


    int record ,fname ,lname,space1 ,space2;
    bool bigger ,lower;


    for(record=0; currentPtr != NULL ;record++){
            bigger=false ,lower=false;
        for(fname=0; fname<3; fname++){
            if(newPtr->name[fname] < currentPtr->name[fname]){
                    lower=true; break;  }
            else if(newPtr->name[fname] == currentPtr->name[fname]) {continue;}
            else{ bigger=true ; break;}
        }

                if(lower){ break;}
                if(bigger){
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextptr;
                    continue;}

        for(space1=1; newPtr->name[space1]!=' ' ; space1++){}
        for(space2=1; currentPtr->name[space2]!=' ' ; space2++){}

        for(lname=0; lname<3; lname++, space1++,space2++){
            if(newPtr->name[space1] < currentPtr->name[space2]){ lower=true; break;}
            else if(newPtr->name[space1] == currentPtr->name[space2]) {continue;}
            else{  break;}
        }
                if(lower){break;}

                previousPtr = currentPtr;
                currentPtr = currentPtr->nextptr;
    }

 if (previousPtr == NULL) {
 newPtr->nextptr = head;
 head = newPtr;
 }
 else {
 previousPtr->nextptr = newPtr;
 newPtr->nextptr = currentPtr;
 }
 }
 else {
 printf(" No memory available.\n" );
 }
 }





void start()
{


     FILE *pfile1 ;
    pfile1= fopen("data.txt","rb");
    if(pfile1==NULL)
    {
        printf("couldn't find the file\n");
        exit(1);
    }

 studl *cur = malloc(sizeof(studl));

    while( 1 ){

        studl *temp = malloc(sizeof(studl));
        if( fread(&temp->name,sizeof(temp->name),1,pfile1)  == 0 ) {  break;}

        temp->subjects[0] =  malloc(sizeof(struct sub));
        temp->subjects[1] =  malloc(sizeof(struct sub));
        temp->subjects[2] =  malloc(sizeof(struct sub));
        temp->subjects[3] =  malloc(sizeof(struct sub));

        fread(&temp->code,sizeof(temp->code),1,pfile1);
        fread(&temp->national_id,sizeof(temp->national_id),1,pfile1);
        fread(&temp->Birthday,sizeof(temp->Birthday),1,pfile1);
        fread(&temp->email,sizeof(temp->email),1,pfile1);
        fread(&temp->currentyear,sizeof(temp->currentyear),1,pfile1);
        fread(&temp->section,sizeof(temp->section),1,pfile1);

        fread(&temp->subjects[0]->name,sizeof(temp->subjects[0]->name),1,pfile1);
        fread(&temp->subjects[0]->mark,sizeof(temp->subjects[0]->mark),1,pfile1);
        fread(&temp->subjects[1]->name,sizeof(temp->subjects[1]->name),1,pfile1);
        fread(&temp->subjects[1]->mark,sizeof(temp->subjects[1]->mark),1,pfile1);
        fread(&temp->subjects[2]->name,sizeof(temp->subjects[2]->name),1,pfile1);
        fread(&temp->subjects[2]->mark,sizeof(temp->subjects[2]->mark),1,pfile1);
        fread(&temp->subjects[3]->name,sizeof(temp->subjects[3]->name),1,pfile1);
        fread(&temp->subjects[3]->mark,sizeof(temp->subjects[3]->mark),1,pfile1);

        if(head == NULL){head = temp; cur=temp;}

        cur->nextptr=temp;
        cur=cur->nextptr;

        }
    cur->nextptr = NULL ;
    fclose(pfile1);

 }
 void mainsearch(){
    int choice;
    int i;
    printf("%c",201);
         for(i=0;i<22;i++)
printf("%c",205);
printf("%c",187);
printf("\n");
printf("%c",186);
    printf("1- for search by name %c\n",186);

printf("%c",186);
    printf("2- for search by code %c\n",186);
    printf("%c",200);
    for(i=0;i<22;i++)
printf("%c",205);
printf("%c",188);
printf("\n");
printf("ENTER YOUR CHOICE:");
scanf("%d",&choice);


if(choice==1){
    searchbyname();
}
 else if(choice==2){
    searchbycode();
}
else{
    mainsearch();
}

 }
void searchbycode(){
 int code,j,i;
printf("\n enter code of student:");
scanf("%d",&code);
studl*tem;
tem=head;
while(tem->code!=code&&tem->nextptr!=NULL){

    tem=tem->nextptr;
}
if(tem->code==code){

   //printing
         printf("%c",201);
         for(i=0;i<32;i++)
         printf("%c",205);
            printf("%c\n",187);
            printf("%c",186);//
        printf("result of searching:            ");
       printf("%c\n",186);
            printf("%c",186);
         printf("NAME:%27s",tem->name);
        printf("%c\n",186);
           printf("%c",186);
    printf("CODE:%26d.",tem->code);
printf("%c\n",186);
           printf("%c",186);
  printf("national id %20d",tem->national_id);
 printf("%c\n",186);//
  printf("%c",186);//
    printf("current year%20s",tem->currentyear);
     printf("%c\n",186);//
      printf("%c",186);//
    printf("birthday%24s",tem->Birthday);
     printf("%c\n",186);//
      printf("%c",186);//
       printf("email%27s",tem->email);
        printf("%c\n",186);//
 printf("%c",186);//
          printf("section%25d",tem->section);
 printf("%c\n",186);//
          for(j=0;j<4;j++){
            printf("%c",186);
            printf("subject: %23s",tem->subjects[j]->name);// maybe
            printf("%c\n",186);
            printf("%c",186);
            printf("student mark: %18d",tem->subjects[j]->mark);
           printf("%c\n",186);
            }


            printf("%c",200);
        for(i=0;i<32;i++)
        printf("%c",205);
        printf("%c\n",188);




            printf("the code of student incorrect");



}}



 void searchbyname(){
    studl*tem=head;
    int i=0,j;
char namesearch[20],inputt[20];
    printf("Enter the student's name : ");
   // scanf("\n");scanf("%s",namesearch);//\\scanning
   scanf("\n%[^\n]",namesearch);
while( tem!=NULL){//reaching the wanted node
        if(strcmp(namesearch,tem->name)==0)break;
    tem=tem->nextptr;
}
if(tem==NULL){
    printf("Student not found\n");
    return;
}
//printing
         printf("%c",201);
         for(i=0;i<32;i++)
         printf("%c",205);
            printf("%c\n",187);
            printf("%c",186);//
        printf("result of searching:            ");
       printf("%c\n",186);
            printf("%c",186);
         printf("NAME:%27s",tem->name);
        printf("%c\n",186);
           printf("%c",186);
    printf("CODE:%26d.",tem->code);
printf("%c\n",186);
           printf("%c",186);
  printf("national id %20d",tem->national_id);
 printf("%c\n",186);//
  printf("%c",186);//
    printf("current year%20s",tem->currentyear);
     printf("%c\n",186);//
      printf("%c",186);//
    printf("birthday%24s",tem->Birthday);
     printf("%c\n",186);//
      printf("%c",186);//
       printf("email%27s",tem->email);
        printf("%c\n",186);//
 printf("%c",186);//
          printf("section%25d",tem->section);
 printf("%c\n",186);//
          for(j=0;j<4;j++){
            printf("%c",186);
            printf("subject: %23s",tem->subjects[j]->name);// maybe
            printf("%c\n",186);
            printf("%c",186);
            printf("student mark: %18d",tem->subjects[j]->mark);
           printf("%c\n",186);
            }


            printf("%c",200);
        for(i=0;i<32;i++)
        printf("%c",205);
        printf("%c\n",188);




            printf("the code of student incorrect");



}


