#include<stdio.h>

struct student
{
    int rollnum;
    char name[50];
    char d1[10],d2[10];//date
    char a1[30],a2[30];//author name
    char booknum1[20],booknum2[20];
    char b1[20],b2[20];//book name
};

void newstudent();
void list();
int search();
void modify();

FILE *fp;
struct student s;

int main()
{
    printf("\t\t\tWELCOME TO THE PORTAL.");
    int i;
    int choice;

    fp=fopen("library.txt","r+");

    if(fp==NULL)
    {
        fp=fopen("library.txt","w");
        fclose(fp);
        fp=fopen("library.txt","r+");
    }

do{
    printf("\n\t 1:LIST");
    printf("\n\t 2:ADD");
    printf("\n\t 3:SEARCH");
    printf("\n\t 4:MODIFY");
    printf("\n\t 5:EXIT");
    printf("\n\t ENTER CHOICE\t");
    scanf("%d",&i);
    switch(i)
    {

    case 1:list();
           break;
    case 2:newstudent();
            break;
    case 3:search();
            break;
    case 4:modify();
            break;
    }
   }
   while(choice!=5);
    fclose(fp);
return 0;
}
//END OF THE MAIN PROGRAM--------------------------------------------

void newstudent()
{
    fseek(fp,0L,SEEK_END);

    printf("\n\t enter roll number\t");
    scanf("%d",&s.rollnum);
    printf("\n\t enter name");
    scanf("%s",s.name);

    printf("\n\t enter book1 name");
    scanf("%s",s.b1);
    printf("\n\t enter book1 author name");
    scanf("%s",s.a1);
    printf("\n\t enter the date of issue dd/mm/yyyy");
    scanf("%s",s.d1);


    printf("\n\t enter book2 name\t");
    scanf("%s",s.b2);
    printf("\n\t enter book2 author name");
    scanf("%s",s.a2);
    printf("\n\t enter the date of issue dd/mm/yyyy");
    scanf("%s",s.d2);

    fwrite(&s,sizeof(s),1,fp);

}


void list()
{

    int count=0;
    fseek(fp,0L,SEEK_SET);

    printf("\n-------------------------------------------------------------------\n");
    printf("\n Rollnum  Name  Book1  Author1  Dateofissue1  Book2  Author2  Dateofissue2");
    printf("\n-------------------------------------------------------------------\n");

    while(fread(&s,sizeof(s),1,fp))
    {
        printf("\n %3d",s.rollnum);
        printf("  %-10s",s.name);
        printf("  %-10s",s.b1);
        printf("  %-10s",s.a1);
        printf("  %-10s",s.d1);

        printf("  %-10s",s.b2);
        printf("  %-10",s.a2);
        printf("  %-10s",s.d2);
        count++;
    }

    printf("\n-------------------------------------------------------------------\n");
    printf("\n\tTotal number of students are: %d",count);
    printf("\n-------------------------------------------------------------------\n");


}

int search()
{

    int rno,found=0;
    printf("\n\tEnter the roll number you want to search\t");
    scanf("%d",&rno);

    fseek(fp,0L,SEEK_SET);

    while(fread(&s,sizeof(s),1,fp))
    {
        if(rno==s.rollnum)
        {
            printf("\n\tRoll number : %d",s.rollnum);
            printf("\n\tName : %s",s.name);

            printf("\n\tBook1 name : %s",s.b1);
            printf("\n\tAuthor1 name : %s",s.a1);
            printf("\n\tDate of issue1 : %s",s.d1);

            printf("\n\tBook2 name : %s",s.b1);
            printf("\n\tAuthor2 name : %s",s.a1);
            printf("\n\tDate of issue2 : %s",s.d1);
            found=1;
            break;
        }

    }
    if(found!=1)
            printf("\nRoll number not found");

    return found;

}


void modify()
{
    int found;

    found=search();

    if(found)
    {
        printf("\n\tEnter the information u want to update and if dont want to update a specific column then enter the original name of that column to keep it same\t");
        printf("\n\tenter your Roll number");
        scanf("%d",s.rollnum);

         printf("\n\t enter name");
    scanf("%s",s.name);

    printf("\n\t enter new book1 name");
    scanf("%s",s.b1);
    printf("\n\t enter new book1 author name");
    scanf("%s",s.a1);
    printf("\n\t enter the new date of issue dd/mm/yyyy");
    scanf("%s",s.d1);


    printf("\n\t enter new book2 name");
    scanf("%s",s.b2);
    printf("\n\t enter new book2 author name");
    scanf("%s",s.a2);
    printf("\n\t enter the new date of issue dd/mm/yyyy");
    scanf("%s",s.d2);

    fseek(fp,-((long)sizeof(s)),SEEK_CUR);

        fwrite(&s,sizeof(s),1,fp);
        printf("\n\tData updated\n");

    }
}
