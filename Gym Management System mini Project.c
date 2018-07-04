#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void master();
void addmember();
void dele();
void rules();
void diseuip();
void delequip();
void addequip();
void equipe();
void display();


struct emply
{
    char ename[20];
    int empid;
    int age;
    char adds[30];
    int phno;
    int deposit;
    int due;
}emp;
struct equipse
{
    char eqname[20];
}equips;
FILE *rmembe;
FILE *temp;
FILE *equip;

main()
{
    int i=0,choice;
    char login[20],pass[15],p;
    char pas[20]={"anjan"};
    printf("\t\t\t_____________________________________________\n");
    printf("\t\t\t*********** GYM MANAGEMENT SYSTEM ***********\n");
     printf("\t\t\t--------------------------------------------\n");
    printf("\t\t\t********Welcome To Your Fitness Centre*******\n");
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
        printf("\nYou are successfully logged in...\n");
        printf("_______________________________\n");
        printf("             MENU              \n");
        printf("_______________________________\n");
        for(;;)
        {
            printf("\n1.ADMIN LOGIN\n2.RULES AND INSTRUCTIONS\n3.MEMBER DETAILS\n4.GYM EQUIPMENTS\n");
            //printf("\n1.ADMIN LOGIN\n2.RULES AND INSTRUCTIONS\n3.MEMBER DETAILS\n4.MEDICINES\n5.GYM EQUIPMENTS\n");
            printf("\nplease enter the choice\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: master();
                        break;
                case 2: rules();
                        break;
                case 3: display();
                        break;
                //case 4: medicines();
                        //break;
                case 4: equipe();
                        break;

                default: printf("\nEnter the valid option\n");
                        return;
            }
        }

    }
    else
        printf("\nIncorrect password\n");
}
void master()
{
    char logi[20],ass[15],p;
    char pa[20]={"admin"};
    int choice,i=0;
    printf("\nEnter Admin Username : ");
    getchar();
    gets(logi);
    printf("\nEnter Admin Password : ");
    while((p=getch())!=13)
    {
        printf("*");
        ass[i]=p;
        i++;
    }
    ass[i]='\0';
    if(strcmp(pa,ass)==0)
    {
        printf("\nyou are successfully logged in...\n");
        //for(;;)
        //{
            printf("\n1.ADD MEMBER\n2.REMOVE MEMBER\n");
            printf("Enter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: addmember();
                        break;
                case 2: dele();
                        break;
                default: printf("\nno such option available\n");
                        return;
            }
       // }

    }
    else
        printf("\nIncorrect password\n");
}
void addmember()
{
    rmembe=fopen("rmembe.txt","a+");
    printf("\nEnter the name of the member\n");
    getchar();
    gets(emp.ename);
    printf("\nEnter the member id\n");
    scanf("%d",&emp.empid);


    printf("\nEnter the age of member\n");
    scanf("%d",&emp.age);


    printf("\nEnter the address of the member\n");
    getchar();
    gets(emp.adds);
    printf("\nEnter the contact number\n");
    scanf("%d",&emp.phno);
    printf("\nEnter the amount deposited\n");
    scanf("%d",&emp.deposit);
    emp.due=(500-emp.deposit);
    //printf("enter the member status\n");
    //scanf("%s",emp.status);
    fprintf(rmembe,"%s %d %d %s %d %d %d\n",emp.ename,emp.empid,emp.age,emp.adds,emp.phno,emp.deposit,emp.due);
    fclose(rmembe);
    printf("\nMember added successfully\n");
}

void dele()
{
    char mem[20],adrs[25];
    int ag,cono,id,count=0;
    FILE *fp;
    rmembe=fopen("rmembe.txt","r");
    fp=fopen("fp.txt","w");
    printf("\nEnter the name of member\n");
    getchar();
    gets(mem);
    printf("\nEnter the member id\n");
    scanf("%d",&id);
    //printf("\nEnter the age of the member\n");
    //scanf("%d",&ag);
    //printf("\nEnter the address of the member\n");
    //getchar();
    //gets(adrs);
    //printf("\nEnter the contact number\n");
    //scanf("%d",&cono);

    while(!feof(rmembe))
    {
        fscanf(rmembe,"%s %d %d %s %d %d %d\n",emp.ename,&emp.empid,&emp.age,emp.adds,&emp.phno,&emp.deposit,&emp.due);
        if(strcmp(emp.ename,mem)!=0&&(id-(emp.empid))!=0)
        {
            fprintf(fp,"%s %d %d %s %d %d %d\n",emp.ename,emp.empid,emp.age,emp.adds,emp.phno,emp.deposit,emp.due);

        }
        else  if(strcmp(emp.ename,mem)==0&&(id-(emp.empid))==0)
    {
    printf("\nDetails of the deleted member is:\n");
    printf("Name : %s\nId : %d\nAge : %d\nAddress : %s\nContact no. : %d\n",emp.ename,emp.empid,emp.age,emp.adds,emp.phno);
    }
    else
    {
        printf("\nPlease enter the correct details\n");
    }

    }


    fclose(rmembe);
    fclose(fp);
    rmembe=fopen("rmembe.txt","w");
    fp=fopen("fp.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s %d %d %s %d %d %d\n",emp.ename,&emp.empid,&emp.age,emp.adds,&emp.phno,&emp.deposit,&emp.due);
        fprintf(rmembe,"%s %d %d %s %d %d %d\n",emp.ename,emp.empid,emp.age,emp.adds,emp.phno,emp.deposit,emp.due);
    }
    fclose(fp);
    fclose(rmembe);
}

void display()
{
    rmembe=fopen("rmembe.txt","r");
    if(rmembe==NULL)
    {
        printf("\nFile can't be opened\n");
        return;
    }
    printf("%-15s%-10s%-20s%-20s%-20s%-12s%-15s\n","NAME","ID","AGE","ADDRESS","CONTACT NO.","DEPOSIT","DUE");
    while(!(feof(rmembe)))
    {
        fscanf(rmembe,"%s %d %d %s %d %d %d\n",emp.ename,&emp.empid,&emp.age,emp.adds,&emp.phno,&emp.deposit,&emp.due);
        printf("\n%-15s%-10d%-20d%-20s%-20d%-12d%-15d\n",emp.ename,emp.empid,emp.age,emp.adds,emp.phno,emp.deposit,emp.due);
    }
    fclose(rmembe);
}



void equipe()
{
    int choice;

    printf("\n1.Add Equipment\n2.Remove Equipments\n3.Display Equipments\n");
    printf("\nEnter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: addequip();
                break;
        case 2: delequip();
                break;
        case 3: disequip();
                break;
        default: printf("\nEnter the valid option\n");
                    return;
    }
}



void addequip()
{
    equip=fopen("equip.txt","a+");
    printf("\nEnter the name of the equipment to be added\n");
    getchar();
    gets(equips.eqname);
    fprintf(equip,"\n%s",equips.eqname);
    printf("\nEquipment %s is added successfully\n",equips.eqname);
    fclose(equip);
}




void delequip()
{
    char e[30];
    FILE *fp;
    printf("\nEnter the name of the equipment to be deleted\n");
    getchar();
    gets(e);
    fp=fopen("fp.txt","w");
    equip=fopen("equip.txt","r");
    while(!feof(equip))
    {
        fscanf(equip,"%s\n",equips.eqname);
        if(strcmp(equips.eqname,e)!=0)
        {
            fprintf(fp,"%s\n",equips.eqname);
        }
    }
    fclose(fp);
    fclose(equip);
    fp=fopen("fp.txt","r");
    equip=fopen("equip.txt","w");
    while(!feof(fp))
    {
        fscanf(fp,"%s\n",equips.eqname);
        fprintf(equip,"%s\n",equips.eqname);
    }
    printf("\nEquipment %s is succesfully deleted\n",e);
    fclose(fp);
    fclose(equip);

}


void disequip()
{
    equip=fopen("equip.txt","r");
    if(equip==NULL)
    {
        printf("\nFile can't be open\n");
        exit(0);
    }
    printf("\nAvailable Gym Equipments are :- \n");
    while(!feof(equip))
    {
        //printf("\n Available Gym Equipments are :-");
        fscanf(equip,"%s\n",equips.eqname);
        printf("%s\n",equips.eqname);
    }
}




void rules()
{
    printf("\t\t________________________________________\n");
    printf("\n\t\t******* Rules and Regulations *********\n");
    printf("\t\t----------------------------------------\n");
    printf("\n1.Do not bring your gym bag or other personal belongings onto the fitness floor.\n");
    printf("2.Refrain from yelling, using profanity, banging weights and making loud sounds\n");
    printf("3.Do not sit on machines between sets\n");
    printf("4.Re-rack weights and return all other equipment and accessories to their proper locations\n");
    printf("5.Ask staff to show you how to operate equipment properly so that others are not waiting as you figure it out.\n");
    printf("6.Wipe down all equipment after use.\n");
    printf("7.Stick to posted time limits on all cardiovascular machines.\n");
    printf("8.Do not bring children onto the gym floor. Children must remain in the childcare area.\n");
    printf("9.Do not disturb others. Focus on your own workout and allow others to do the same.\n");
    printf("10.Before beginning your workout, wash your hands and wipe off any cologne or perfume.\n");

}



