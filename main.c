#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 typedef struct list_infostudent{
 char name [100];
 char depart[20];
 char currentyear[15];
 int section;
 int bn;
 long long int code;
 long long int national_id;
 char email[30];
 unsigned int phone;
 char General_appre[20];
 char address[50];
 char Barthday[30];

 struct sub *subjects[10];
 char notes[75];
 struct list_infostudent *nextptr;
 }studl;

 typedef struct infostudent{
 char name [100];
 char depart[20];
 char currentyear[15];
 int section;
 int bn;
 long long int code;
 long long int national_id;
 char email[30];
 unsigned int phone;
 char General_appre[20];
 char address[50];
 char Barthday[30];

 struct sub *subjects[10];
 char notes[75];
 }stud;
 struct sub{
 char name[20];
 int mark;
 };
studl *head = NULL;
studl *curr = NULL;
void append(int x,char y[20]){
studl*newnode,*tem;
newnode=( studl*)malloc(sizeof( studl));
newnode->code=x;

strcpy(newnode->name,y);
newnode->nextptr=NULL;
if (head==NULL){

head=newnode;

}
else{
        tem=head;
        while(tem->nextptr!=NULL){
            tem=tem->nextptr;
        }

tem->nextptr=newnode;
}
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
void display(){
studl *tem=head;
while(tem!=NULL){
    printf("%l",tem->code);
    printf("%s\n",tem->name);
    tem=tem->nextptr;

}
if(tem==NULL){
    return;
}


}
void searchbyname(){
    studl*tem;
    tem=head;
char name[50];
printf("enter name of student\n");
scanf("%d\n",50);
fgets(name,sizeof name,stdin);



while((strcmp(name,tem->name))!=0 && tem->nextptr!=NULL){
    tem=tem->nextptr;
}
if((strcmp(name,tem->name))==0){
    printf("NAME:%s\t",tem->name);
    printf("CODE:%d\t",tem->code);
    return;
}
printf("the student isnt in the university\n");


}
void searchbycode(){
 int code;
printf("\n enter code of student");
scanf("%d",&code);
studl*tem;
tem=head;
while(tem->code!=code&&tem->nextptr!=NULL){

    tem=tem->nextptr;
}
if(tem->code==code){
         printf("NAME:%s\t",tem->name);
    printf("CODE:%d\t",tem->code);

 /* printf("%l",tem->national_id);
   printf("%s",tem->depart);
   printf("%s",tem->address);
    printf("%s",tem->currentyear);
     printf("%s",tem->General_appre);
      printf("%s",tem->Barthday);
       printf("%s",tem->email);
        printf("%s",tem->notes);
        printf("%d",tem->bn);
          printf("%d",tem->section);
            printf("%d",tem->phone);
            printf("%s",tem->subjects->name);
            printf("%s",tem->subjects->mark);*/

    return;
}

            printf("the code of student incorrect");



}
int main()
{
   /* FILE *pfile;
    pfile = fopen("data.txt","rb");
    if(pfile==NULL)
    {
        printf("couldn't find the file\n");
    }
        printf("succesfully found the file\n");
    fclose(pfile);*/
    append(50,"hossam ali\n");
    display();
 mainsearch();
    return 0;
}
