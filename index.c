#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 typedef struct list_infostudent{
 char name [100];
 char depart[20];
 char currentyear[15];
 int section;
 int bn;
 int code;
 long long int national_id;
 char email[30];
 unsigned int phone;
 char General_appre[20];
 char address[50];
 char Birthday[30];
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
 int code;
 long long int national_id;
 char email[30];
 unsigned int phone;
 char General_appre[20];
 char address[50];
 char Birthday[30];
 struct sub *subjects[10];
 char notes[75];
 }stud;

 struct sub{
 char name[20];
 int mark;
 };
studl *head = NULL;
studl *curr = NULL;

void start(char name[100], char depart[20], char currentyear[15],
int section, int bn, int code, long long int national_id,
char email[30], unsigned int phone, char General_appre[20],
char address[50], char Birthday[30], struct sub *subjects[10], char notes[75]);

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
    printf("succesfully found the file\n");
    while(fread(&s, sizeof(s), 1, pfile)==1){
start(s.name,s.depart, s.currentyear, s.section,
s.bn, s.code, s.national_id,s.email, s.phone,
s.General_appre, s.address, s.Birthday, s.subjects,
 s.notes);
 printf("yes\t");
        }
    }

    fclose(pfile);
    return 0;
}
void start(char name[100], char depart[20], char currentyear[15],
int section, int bn, int code, long long int national_id,
char email[30], unsigned int phone, char General_appre[20],
char address[50], char Birthday[30], struct sub *subjects[10], char notes[75])
{
    studl *std = (studl *)malloc(sizeof(studl));
    strcpy(std->name, name);
    strcpy(std->depart, depart);
    strcpy(std->currentyear, currentyear);
    std->section = section;
    std->bn = bn;
    std->code = code;
    std->national_id = national_id;
    strcpy(std->email, email);
    std->phone = phone;
    strcpy(std->General_appre, General_appre);
    strcpy(std->address, address);
    strcpy(std->Birthday, Birthday);
    for(int i=0;i<=10;i++){
       std->subjects[i] = subjects[i];
    }
    strcpy(std->notes, notes);

    std->nextptr = NULL;
    if (head == NULL)head = std;
    else {
        studl *temp = head;
        while (temp->nextptr != NULL)temp = temp->nextptr;
        temp->nextptr = std;
    }
    return;
}
