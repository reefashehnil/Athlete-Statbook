#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int,int );
void login_player();
void register_player();
void lock();
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
void register_player()
{
    char usern[20],pass[20];
    FILE *fp;
    fp=fopen("login.txt","ab+");
    system("cls");
    purple();
    gotoxy(50,3);
    printf("REGISTER USER\n");
    gotoxy(50,5);
    printf("Enter Username : ");
    scanf("%s",&usern);
    gotoxy(50,7);
    printf("Enter Password : ");
    scanf("%s",&pass);
    fprintf(fp,"%s %s",usern,pass);
    fprintf(fp,"\n");
    gotoxy(50, 10);
    printf("Successfully Registered");
    reset();
    gotoxy(50,15);
    green();
    printf("Press any key to continue.");
    reset();
    getch();
    login_player();

}
void  login_player()
{
    system("cls");
    char u_id[20],p[20];
    char usern[20],pass[20];
    FILE *fp;
    fp=fopen("login.txt","rb");
    gotoxy(50,5);
    reset();
    purple();
    printf("Username : ");
    scanf("%s",u_id);
    while(fscanf(fp,"%s %s",&usern,&pass)!=EOF)
    {
        if(strcmp(u_id,usern)==0)
        {
            gotoxy(50,6);
            printf("Password : ");
            scanf("%s",&p);
            if(strcmp(p,pass)==0)
            {
                system("cls");
                gotoxy(50,9);
                printf("WELCOME! LOGIN SUCCESSFUL");
                reset();
                green();
                gotoxy(50,17);
                printf("Press any key to continue ");
                reset();
                fflush(stdin);
                getch();
                menu();

            }
            else
            {
                gotoxy(50,9);
                reset();
                red();
                printf("Incorrect username or password");
                gotoxy(50,11);
                printf("TRY AGAIN");
                reset();
                gotoxy(50,15);
                green();
                printf("Press any key to continue.");
                reset();
                getch();
                login_player();
            }
        }
        gotoxy(50,10);
        reset();
        red();
        printf("Incorrect Username!!! try again");
        reset();
        gotoxy(50,15);
        green();
        printf("Press any key to continue.");
        reset();
        getch();
        login_player();
    }
}
void lock()
{
    char name[30];
    int id;
    int ch;
    char username[20];
    char password[20];

    system("cls");
    int cho;
    purple();
    gotoxy(50,3);
    printf("1.Login ");
    gotoxy(50,4);
    printf("2.New player? Register. ");
    gotoxy(50,7);
    printf("Enter your Choice : ");
    scanf("%d",&cho);

    switch(cho)
    {
    case 1:
        system("cls");
        gotoxy(50,3);
        printf("PLAYER LOGIN");
        login_player();
        break;

    case 2:
        system("cls");
        register_player();
        break;

    default:
        gotoxy(50,9);
        reset();
        red();
        printf("Invalid Choice!");
        break;

    }
}
struct player
{
    char name[20];
    float height;
    float weight;
    int playernum;
    char fieldPosition[20];
    char DOB[20];
    char nationality[20];
    char mobile[11];
    char address[50];
};
int main()
{
    system("cls");
    gotoxy(50,10);
    red();
    char senta[]="<---:Football Team Database:--->\n\t\t\t\t\tProject by:Team RTX\tMembers(Reefa,Xaima,Taufiq)";
    int x;
    int size;
    size=strlen(senta);
    for(x=0; x<size; x++)
    {
        Sleep(25);
        printf("%c",senta[x]);
    }

    reset();
    gotoxy(50,15);
    green();
    printf("Press any key to continue.");
    reset();
    getch();
    lock();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(50,3);
    yellow();
    printf("<--:MENU:-->");
    reset();
    cyan();
    gotoxy(50,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(50,7);
    printf("1 : Add Record.");
    gotoxy(50,8);
    printf("2 : View Record.");
    gotoxy(50,9);
    printf("3 : Search Record.");
    gotoxy(50,10);
    printf("4 : Modify Record.");
    gotoxy(50,11);
    printf("5 : Delete.");
    reset();
    gotoxy(50,12);
    red();
    printf("6 : Exit.");
    reset();
    gotoxy(50,15);
    green();
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct player plyr;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of player.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(plyr.name);
        gotoxy(10,8);
        printf("Enter Height in (m) : ");
        scanf("%f",&plyr.height);
        fflush(stdin);
        gotoxy(10,9);
        printf("Enter Weight in (kg) : ");
        scanf("%f",&plyr.weight);
        gotoxy(10,10);
        fflush(stdin);
        printf("Enter Player Number : ");
        scanf("%d", &plyr.playernum);
        fflush(stdin);
        gotoxy(10,11);
        printf("Enter Field Position : ");
        gets(plyr.fieldPosition);
        gotoxy(10,12);
        printf("Enter DOB (dd.mm.yyyy) : ");
        gets(plyr.DOB);
        gotoxy(10,13);
        printf("Enter Nationality : ");
        gets(plyr.nationality);
        gotoxy(10,14);
        printf("Enter Mobile Number (11 digits) : ");
        gets(plyr.mobile);
        fflush(stdin);
        fwrite(&plyr,sizeof(plyr),1,fp);
        gotoxy(10,20);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,20);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct player plyr;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("Sl.No   Name of player        Height    Weight   P.Number    F.Position       DOB        Nationality      Mobile");
    gotoxy(10,7);
    printf("--------------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,9);
        printf("Error opening file.");
        exit(1);
    }
    j=10;
    while(fread(&plyr,sizeof(plyr),1,fp) == 1)
    {
        gotoxy(10,j);
        printf("%-7d %-22s %-9.1f %-10.1f %-10d %-11s %-13s %-15s %-15s",i,plyr.name,plyr.height,plyr.weight,plyr.playernum,plyr.fieldPosition,plyr.DOB,plyr.nationality,plyr.mobile);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct player plyr;
    char plname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of player : ");
    fflush(stdin);
    gets(plname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&plyr,sizeof(plyr),1,fp ) == 1)
    {
        if(strcmp(plname,plyr.name) == 0)
        {
            gotoxy(10,8);
            printf("Name : %s",plyr.name);
            gotoxy(10,9);
            printf("Height : %.1f",plyr.height);
            gotoxy(10,10);
            printf("Weight : %.1f",plyr.weight);
            gotoxy(10,11);
            printf("Player Number : %d",plyr.playernum);
            gotoxy(10,12);
            printf("Field Position : %s",plyr.fieldPosition);
            gotoxy(10,13);
            printf("DOB : %s", plyr.DOB);
            gotoxy(10,14);
            printf("Nationality : %s", plyr.nationality);
            gotoxy(10,15);
            printf("Mobile : %s", plyr.mobile);


        }
    }
    fclose(fp);
    gotoxy(10,20);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char plname[20];
    FILE *fp;
    struct player plyr;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of player to modify: ");
    fflush(stdin);
    gets(plname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&plyr,sizeof(plyr),1,fp) == 1)
    {
        if(strcmp(plname,plyr.name) == 0)
        {
            gotoxy(10,7);
            printf("Enter Name : ");
            gets(plyr.name);
            gotoxy(10,8);
            printf("Enter Height in (m) : ");
            scanf("%f",&plyr.height);
            fflush(stdin);
            gotoxy(10,9);
            printf("Enter Weight in (kg) : ");
            scanf("%f",&plyr.weight);
            gotoxy(10,10);
            fflush(stdin);
            printf("Enter Player Number : ");
            scanf("%d", &plyr.playernum);
            fflush(stdin);
            gotoxy(10,11);
            printf("Enter Field Position : ");
            gets(plyr.fieldPosition);
            gotoxy(10,12);
            printf("Enter DOB (dd.mm.yyyy) : ");
            gets(plyr.DOB);
            gotoxy(10,13);
            printf("Enter Nationality : ");
            gets(plyr.nationality);
            gotoxy(10,14);
            printf("Enter Mobile Number (11 digits) : ");
            gets(plyr.mobile);
            fseek(fp,-sizeof(plyr),SEEK_CUR);
            fwrite(&plyr,sizeof(plyr),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,19);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char plname[20];
    FILE *fp,*ft;
    struct player plyr;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of player to delete record : ");
    fflush(stdin);
    gets(plname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&plyr,sizeof(plyr),1,fp) == 1)
    {
        if(strcmp(plname,plyr.name)!=0)
            fwrite(&plyr,sizeof(plyr),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void reset()
{
    printf("\033[0m");
}

void purple()
{
    printf("\033[1;35m");
}

void cyan()
{
    printf("\033[1;36m");
}

void green()
{
    printf("\033[1;32m");
}

void yellow()
{
    printf("\033[1;33m");
}

void red()
{
    printf("\033[1;31m");
}

