#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 typedef struct list_infostudent{
 char name [50];
 char currentyear[15];
 int section;
 int code;
 long long int national_id;
 char email[30];
 char Birthday[30];
 struct sub *subjects[4];
 struct list_infostudent *nextptr;
 }studl;

 typedef struct infostudent{
 char name [50];
 char currentyear[15];
 int section;
 int code;
 long long int national_id;
 char email[30];
 char Birthday[30];
 struct sub *subjects[4];
 }stud;

 struct sub{
 char name[15];
 int mark;
 };
studl *head = NULL;
studl *curr = NULL;

void start(char name[50], char currentyear[15],
int section, int code, long long int national_id,
char email[30], char Birthday[30], struct sub *subjects[4]);

int main()
{
stud s;
studl sl;
FILE *pfile;
pfile = fopen("data.txt","rb");
if(pfile==NULL)
    {
    printf("couldn't find the file\n");
    }
else{
    printf("successfully found the file\n");
    while(fread(&s, sizeof(s), 1, pfile)==1){
start(s.name, s.currentyear, s.section,
s.code, s.national_id,s.email,
s.Birthday, s.subjects);
 printf("yes\t");
        }
    }
    fclose(pfile);

    curr = head;
    pfile = fopen("data.txt","wb");
while(curr!=NULL){
    strcpy(s.name, curr->name);
    strcpy(s.currentyear, curr->currentyear);
    s.section = curr->section;
    s.code = curr->code;
    s.national_id = curr->national_id;
    strcpy(s.email, curr->email);
    strcpy(s.Birthday, curr->Birthday);
    for(int i=0;i<=10;i++){
       s.subjects[i] = curr->subjects[i];
    }

    }

    return 0;
}
void start(char name[50], char currentyear[15],
int section, int code, long long int national_id,
char email[30], char Birthday[30], struct sub *subjects[4])
{
    studl *std = (studl *)malloc(sizeof(studl));
    strcpy(std->name, name);
    strcpy(std->currentyear, currentyear);
    std->section = section;
    std->code = code;
    std->national_id = national_id;
    strcpy(std->email, email);
    strcpy(std->Birthday, Birthday);
    for(int i=0;i<=10;i++){
       std->subjects[i] = subjects[i];
    }
    std->nextptr = NULL;
    if (head == NULL)head = std;
    else {
        studl *temp = head;
        while (temp->nextptr != NULL)temp = temp->nextptr;
        temp->nextptr = std;
    }
    return;
}
