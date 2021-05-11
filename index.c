#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    FILE *pfile;
    pfile = fopen("data.txt","rb");
    if(pfile==NULL)
    {
        printf("couldn't find the file\n");
    }
        printf("succesfully found the file\n");
    fclose(pfile);
    return 0;
}
