#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
struct subscriber
{
char phonenumber[20];
char name[50];
float amount;
}s;
void addrecords();
void listrecords();
void modifyrecords();
void deleterecords();
void searchrecords();
void payment();
char get;
int main()
{	int password;
	int phonenumber;
	char choice;



	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t****************************************************************");
	printf("\n\t\t\t   ------PROJECT ON TELECOM BILLING MANAGEMENT SYSTEM-----");
	printf("\n\t\t\t****************************************************************");
	//Sleep(2000);
	getch();
    system("cls");
    
    int i=0;
    char login[20],pass[15],p;
    char pas[20]={"anjan"};
    printf("\t\t\t_____________________________________________\n");
    printf("\t\t\t********************OSPRO********************\n");
     printf("\t\t\t--------------------------------------------\n");
    printf("\t\t\t********A NEW GENERATION TELE MANAGEMENT******\n");
     printf("\t\t\t---------------------------------------------\n");
    printf("\n\n");
    printf("Enter login Username : ");
    gets(login);
    printf("\nEnter the password : ");
    while((p=getch())!=13)
    {
        printf("*");
        pass[i]=p;
        i++;
    }
    pass[i]='\0';
    if(strcmp(pas,pass)==0)
    {
        //printf("\nYou are successfully logged in...\n");
    
		while (1)
		{	
			system("cls");
			printf("\n\n\n-----WELCOME TO TELE MANAGEMENT DESK-----\n");
			printf("\n\n Choose From Below Options \n\n\n A : Add New Coustomer\n L : List Coustomers and Their Dues");
			printf("\n M : Modify Coustomer Records\n P : Pay ");
			printf("\n S : Searching records");
			printf("\n D : Delete Coustomer Records\n E : Exit\n");
			choice=getche();
			choice=toupper(choice);
			switch(choice)
			{
				case 'P':	payment();
							break;
				case 'A':	addrecords();
							break;
					
				case 'L':	listrecords();
							break;
					
				case 'M':	modifyrecords();
							break;
					
				case 'S':	searchrecords();
							break;
					
				case 'D':	deleterecords();
							break;
					
				case 'E':	system("cls");
							printf("\n\n\t\t\t\t\t     THANK YOU");
							printf("\n\t\t\t\t\tFOR USING OUR SERVICE");
							printf("\n");
							for(i=0;i<120;i++)
								printf("-");

							//Sleep(2000);
							exit(0);
							break;
					
				default:	system("cls");
							printf("Incorrect Input");
							printf("\nHit Any key to continue");
							getch();
					
			}
			
		}
		
	}
	
	else
       				 printf("\n\n\n\t\t\tWARNING ! Incorrect Username or Password\n");
}
void addrecords()
{
	FILE *f;
	char test;
	f=fopen("telecom.txt","ab+");
	if(f==0)
	{   f=fopen("telecom.txt","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter phone number : ");
		scanf("%s",&s.phonenumber);
		printf("\n Enter name : ");
		fflush(stdin);
		scanf("%[^\n]",&s.name);
		printf("\n Enter amount : ");
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("\n1 Record Successfully Added");
		printf("\n\nPress esc Key to Exit OR Hit any Other Key to Add Another Record : ");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}
void listrecords()
{
	FILE *f;
	int i;
	if((f=fopen("telecom.txt","rb"))==NULL)
		exit(0);
	system("cls");
	
		printf("\n\n\n");
		for(i=0;i<79;i++)
		printf("-");
	printf("\nPhone Number\t\tUser Name\t\t\tDue Amount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n\n\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.name,s.amount);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}

void deleterecords()
{
	FILE *f,*t;
	int i=1;
	char phonenumber[20];
	if((t=fopen("temp.txt","w+"))==NULL)
	exit(0);
	if((f=fopen("telecom.txt","rb"))==NULL)
	exit(0);
	system("cls");
	printf("\n\n\nEnter the phone number to be deleted from the Database : ");
	fflush(stdin);
	scanf("%s",phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       system("cls");
		printf("Phone number \"%s\" not found",phonenumber);
		remove("telecom.txt");
		rename("temp.txt","telecom.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("telecom.txt");
	rename("temp.txt","telecom.txt");
	//system("cls");
	printf("The Number %s Successfully Deleted!!!!",phonenumber);
	fclose(f);
	fclose(t);
	getch();
}

/*void deleterecords()
{
	FILE *f,*t;
	char phone[20];
	f=fopen("telecom.txt","r");
	t=fopen("temp.txt","w");
	printf("enter the phone number to be deleted\n");
	scanf("%s",phone);
	while(!feof(f))
	{
		fscanf(f,"%s %s %f",s.phonenumber,s.name,&s.amount);
		if(strcmp(s.phonenumber,phone)!=0)
		{
			fprintf(t,"%s %s %f",s.phonenumber,s.name,s.amount);
		}
		else
		printf("record deleted");
		
		
	}
	remove("telecom.txt");
	rename("temp.txt","telecom.txt");
	fclose(f);
	fclose(t);
	getch();
}*/

void searchrecords()
{
	FILE *f;
	char phonenumber[20];
	int flag=1;
	f=fopen("telecom.txt","rb+");
	if(f==0)
		exit(0);
	fflush(stdin);
	system("cls");
	printf("\n\n\nEnter Phone Number to Search in our Database : ");
	scanf("%s", phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{	system("cls");
			printf(" \n\n\n\t\tRecord Found ");
			printf("\n\n\t\tPhone Number: %s\n\t\tName: %s\n\t\tDue Amount: Rs.%0.2f\n",s.phonenumber,s.name,s.amount);
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("Requested Phone Number Not found in our database");
		}
	}
	getch();
	fclose(f);
}
void modifyrecords()
{
	FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	if((f=fopen("telecom.txt","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("\n\n\nEnter Phone Number of the Subscriber to Modify : ");
	scanf("%[^\n]",phonenumber);
	//fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			//system("cls");
			printf("\n\n\n\n Enter New phone number : ");
			scanf("%s",&s.phonenumber);
			printf("\n Enter New Name Of Subscriber :  ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter amount :  ");
			scanf("%f",&s.amount);
			printf("New Details are Updated Successfully....");
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			//printf("New Details are Updated Successfully....");
			break;
		}
	}
	fclose(f);
}
void payment()
{
	FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	float amt;
	int i;
	if((f=fopen("telecom.txt","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("\n\nEnter phone number of the subscriber for payment : ");
	scanf("%[^\n]",phonenumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			system("cls");
			printf("\n Phone No.: %s",s.phonenumber);
			printf("\n Name: %s",s.name);
			printf("\n Current amount: %f",s.amount);
			printf("\n");
			for(i=0;i<79;i++)
				printf("-");
			printf("\n\nEnter amount of payment :");
			fflush(stdin);
			scanf(" %f",&amt);
			s.amount=s.amount-amt;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t********THANK YOU %s FOR YOUR TIMELY PAYMENTS********",s.name);
	getch();
	fclose(f);
}
