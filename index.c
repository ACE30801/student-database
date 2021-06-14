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
void deletefun();
void deletefunbycode();
void displayfun();
void edit();
void top_ten_students();

int main(){

stud s;
studl sl;
start();

    printf("enter choice ( 1 ->insert , 2->display , 3->stop 4-> search 5-> delete 6-> delete by code 7-> edit subject mark by its number 8-> Top ten students) : ");
    unsigned int choice;
    scanf("%u", &choice);

    while (choice != 3) {


     switch (choice) {
     case 1:
     insert();
     displayfun();
     break;

     case 2:
        displayfun();
        break;

    case 4:
        mainsearch();
        break;
    case 5:
        deletefun();
        break;
    case 6:
        deletefunbycode();
        break;
    case 7:
        edit();
        break;
    case 8:
        top_ten_students();
        break;
     default :
        printf("invalid input\n");
        break;
     }
        printf("enter choice ( 1->insert , 2->display , 3->stop  4-> search 5-> delete 6-> delete by code) : ");
        scanf("%u", &choice);
     }



    FILE *fptrW;

   fptrW = fopen("data.txt","wb+");

    infostptr tempW = head;
    while(tempW != NULL){

        fwrite(&tempW->name,sizeof(tempW->name),1,fptrW);
        fwrite(&tempW->code,sizeof(tempW->code),1,fptrW);
        fwrite(&tempW->national_id,sizeof(tempW->national_id),1,fptrW);
        fwrite(&tempW->Birthday,sizeof(tempW->Birthday),1,fptrW);
        fwrite(&tempW->email,sizeof(tempW->email),1,fptrW);
        fwrite(&tempW->currentyear,sizeof(tempW->currentyear),1,fptrW);
        fwrite(&tempW->section,sizeof(tempW->section),1,fptrW);

        fwrite(&tempW->subjects[0]->name,sizeof(tempW->subjects[0]->name),1,fptrW);
        fwrite(&tempW->subjects[0]->mark,sizeof(tempW->subjects[0]->mark),1,fptrW);
        fwrite(&tempW->subjects[1]->name,sizeof(tempW->subjects[1]->name),1,fptrW);
        fwrite(&tempW->subjects[1]->mark,sizeof(tempW->subjects[1]->mark),1,fptrW);
        fwrite(&tempW->subjects[2]->name,sizeof(tempW->subjects[2]->name),1,fptrW);
        fwrite(&tempW->subjects[2]->mark,sizeof(tempW->subjects[2]->mark),1,fptrW);
        fwrite(&tempW->subjects[3]->name,sizeof(tempW->subjects[3]->name),1,fptrW);
        fwrite(&tempW->subjects[3]->mark,sizeof(tempW->subjects[3]->mark),1,fptrW);

        tempW=tempW->nextptr;
    }

    fclose(fptrW);


    return 0;
}


void insert()
 {

    infostptr newPtr = malloc(sizeof(studl));

    newPtr->subjects[0] =  malloc(sizeof(struct sub));
    newPtr->subjects[1] =  malloc(sizeof(struct sub));
    newPtr->subjects[2] =  malloc(sizeof(struct sub));
    newPtr->subjects[3] =  malloc(sizeof(struct sub));

    int subCounter=0;

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

    while(subCounter<4){

        printf("Enter [name] of the subject No.%d :",subCounter+1);
        fflush(stdin);
        gets(newPtr->subjects[subCounter]->name);
        printf("Enter [mark] of the subject No.%d :",subCounter+1);
        fflush(stdin);
        scanf("%d",&newPtr->subjects[subCounter]->mark);

        subCounter++;
    }

    newPtr->nextptr = NULL;



    studl *previousPtr = NULL;
    studl *currentPtr = head;


    int fname ,lname;
    bool bigger ,less;

    while(currentPtr != NULL){

            bigger=false ,less=false;
            fname=0 , lname=0;

        while( newPtr->name[fname]!='\0' && currentPtr->name[lname]!='\0' ){
            for(fname, lname; newPtr->name[fname]!=' ' && currentPtr->name[lname]!=' ' ; fname++, lname++){
                if(newPtr->name[fname] < currentPtr->name[lname]){
                        less=true; break;  }
                else if(newPtr->name[fname] == currentPtr->name[lname]) {continue;}
                else{ bigger=true ; break;}
            }
            if(less){break;}
            if(bigger){break;}

            fname++;
            lname++;
        }
                if(less){break;}

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

        temp->subjects[3] =  malloc(sizeof(struct sub));
        temp->subjects[0] =  malloc(sizeof(struct sub));
        temp->subjects[1] =  malloc(sizeof(struct sub));
        temp->subjects[2] =  malloc(sizeof(struct sub));

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


void deletefun()
{

    char delname[20];

    printf("Enter student name to delete\n");

    scanf("\n%[^\n]", delname);
     printf("%s\n",delname);
 studl *cur=head;
 studl *pre=NULL;
while(cur !=NULL)
{
    if(strcmp(cur->name,delname)==0)
        {
        if(cur==head)
            {
            head=cur->nextptr;
            free(cur);
            printf("Done\n");
        }
        else{
            pre->nextptr=cur->nextptr;
            free(cur);
            printf("Done\n");
        }
    }
    else{
        pre=cur;
        cur=cur->nextptr;
    }
}
    }

void deletefunbycode()
{
    int studcode;
    printf("Enter student code to delete\n");
    scanf("%d",&studcode);
 studl *cur=head;
 studl *pre=NULL;
while(cur !=NULL)
{
    if(cur->code==studcode)
        {
        if(cur==head)
            {
            head=cur->nextptr;
            free(cur);
            printf("Doneee\n");
            return;
        }
        else{
            pre->nextptr=cur->nextptr;
            free(cur);
            printf("Done\n");
            return;
        }
    }
    else{
        pre=cur;
        cur=cur->nextptr;
    }
}
printf("%s\n", "code doesn't exist");
    }
void displayfun()//display all nodes
{
    int i,j;
studl *cur=head;
while(cur != NULL){


//printing
         printf("%c",201);
         for(i=0;i<32;i++)
         printf("%c",205);
            printf("%c\n",187);
            printf("%c",186);//
        printf("result of searching:            ");
       printf("%c\n",186);
            printf("%c",186);
         printf("NAME:%27s",cur->name);
        printf("%c\n",186);
           printf("%c",186);
    printf("CODE:%26d.",cur->code);
printf("%c\n",186);
           printf("%c",186);
  printf("national id %20d",cur->national_id);
 printf("%c\n",186);//
  printf("%c",186);//
    printf("current year%20s",cur->currentyear);
     printf("%c\n",186);//
      printf("%c",186);//
    printf("birthday%24s",cur->Birthday);
     printf("%c\n",186);//
      printf("%c",186);//
       printf("email%27s",cur->email);
        printf("%c\n",186);//
 printf("%c",186);//
          printf("section%25d",cur->section);
 printf("%c\n",186);//
          for(j=0;j<4;j++){
            printf("%c",186);
            printf("subject: %23s",cur->subjects[j]->name);// maybe
            printf("%c\n",186);
            printf("%c",186);
            printf("student mark: %18d",cur->subjects[j]->mark);
           printf("%c\n",186);
            }


            printf("%c",200);
        for(i=0;i<32;i++)
        printf("%c",205);
        printf("%c\n",188);







cur=cur->nextptr;
}


return;
}


void edit(){
 int code,numofsub,newmark;
printf("\n enter code of student:");
scanf("%d",&code);
studl *tem;
tem=head;
while( tem->code !=code && tem->nextptr!=NULL ){

    tem=tem->nextptr;
}
if(tem->code==code){

do{
    printf("\nEnter number of subject that you want to change its mark\n");
    printf(" 1 )for  %s \n 2 )for  %s \n 3 )for  %s \n 4 )for  %s \n ",tem->subjects[0]->name, tem->subjects[1]->name , tem->subjects[2]->name , tem->subjects[3]->name);

    scanf("%d",&numofsub);
}while(numofsub>4 || numofsub<0);

    printf("enter the new mark");
    scanf("%d",&newmark);
    tem->subjects[numofsub-1]->mark=newmark;

}else{
    printf("\nNo student has this code\n");
}

}



void top_ten_students(){


if(head != NULL){
    int max,i,j,sum=0;
    int max_ten[10] = {0};

    studl *temp=head;

    while( temp!=NULL ){
        for(i=0 ;i<4; i++){
            sum+= temp->subjects[i]->mark;
        }
        temp->totalmark = sum;
        sum=0;
        temp = temp->nextptr;
    }

    temp=head;
    max = head->totalmark;

    while(  temp!=NULL ){
        if(temp->totalmark > max){ max = temp->totalmark; }
         temp = temp->nextptr;
    }

    max_ten[0]=max;
    max=-1;

    temp=head;

    for(i=1; i<10; i++){
        while( temp!= NULL){
            if(temp->totalmark > max && temp->totalmark < max_ten[i-1] ){
                    max = temp->totalmark;
            }
            temp = temp->nextptr;
        }
        max_ten[i] = max;
        max=-1;
        temp=head;
    }


    int num=1;
    temp = head;

    i=0;
    while( max_ten[i]!=-1 && i<10 ){
        while( temp != NULL){

            if(temp->totalmark == max_ten[i]){
                printf("\t[%d] %s with [%d] degrees\n",num, temp->name ,temp->totalmark);
                i++;
                num++;
                break; }

            temp = temp->nextptr;
        }
        temp = head;
    }
}else{
    printf("There are no students\n");
}

}
