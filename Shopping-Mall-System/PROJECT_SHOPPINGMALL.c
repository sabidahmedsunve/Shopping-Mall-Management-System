#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cloths
{
    char pname[40];
    float price;
    struct Cloths *next;
} clothes;

clothes *head;


void Add_A_Product(char s[],float p)
{
    clothes *temp=(clothes*)malloc(sizeof(clothes));

    strcpy(temp->pname,s);
    temp->price = p;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        clothes *x = head;
        while(x->next != NULL)
        {
            x = x->next;
        }
        x->next=temp;
    }
}
void Search()
{
    char prodName[100];
    printf("Enter product name to serach: ");
    scanf("%s", prodName);
    clothes * temp = head;

    while(temp != NULL)
    {
        if(strcmp(prodName, temp ->pname) == 0)
        {
          printf("This product is available\n");
            return;
        }
        temp = temp->next;
    }
    printf("This product is not available now\n");
}

int returnDel()
{
    char prodName[100];

    printf("Please Enter The Product Name: ");
    scanf("%s", prodName);

    clothes *temp = head;
    int  cnt = 0;

    while(temp != NULL)
    {
        if(strcmp(temp->pname, prodName) == 0)
        {
            return cnt+1;
        }
        cnt++;
        temp = temp ->next;
    }
    printf("This product is not available\n");
    return -1;
}
void Delete()
{
    int n;
    clothes *temp = head;
    n = returnDel();

    if(n == -1){
        return;
    }

    n=n-2;
    while(n--)
    {
        temp = temp ->next;
    }
    clothes *del;
    del = temp->next;
    temp ->next = del->next;
    free(del);
    printf("The product Is Deleted\n");
}
void Display()
{
    clothes * temp = head;
    if(temp == NULL)
    {
        printf("Sorry!!! nothing to Show\n");
    }
    int cnt = 1;
    while(temp != NULL)
    {
        printf("\t%d. Product name = %s   ||   product price = %.2f\n",cnt++, temp->pname, temp->price);
        temp = temp->next;
    }
}
double findPrice(int n)
{
    clothes *temp = head;
    n=n-1;
    while(n--)
    {
        temp = temp->next;
    }
    return temp->price;
}

double Fair()
{
    Display();
    printf("Input the number of the displayed products to calculate the fair [Enter 0 to terminate]: \n");
    int pid,temp;
    double totFair = 0.0;

    scanf("%d",&pid);
    while(pid!=0){
        totFair+=(findPrice(pid));
        scanf("%d",&pid);
    }
    return totFair;

}

int main()
{
    system("color B");
    wellcome_message();

    head = NULL;


    int c;
    int choice;
    while(1){
    printf("                   ============================================\n");
    printf("                   =         => MENU:                         =\n");
    printf("                   =         1.CUSTOMER                       =\n");
    printf("                   =         2.OWNER                          =\n");
    printf("                   =         3.Exit Store                     =\n");
    printf("                   ============================================\n");
    printf("\nEnter Your Choiose: ");
    scanf("%d",&c);

    if(c==1)
    {
        printf("\n\t******************** CUSTOMER AREA *************************\n\n");

         while(1){
            printf("                                                                                          ");
            printf("                                                                                          ");
            printf("\n\t\tEnter [1] To Check If The Item You Want To Buy Is Available Or Not");
            printf("\n\t\tEnter [2] To View Items");
            printf("\n\t\tEnter [3] To Buy Product And Calculate Bill");
            printf("\n\t\tEnter [0] To Back to main menu");
            printf("\n\nEnter your choice[0-3] : ");
            scanf("%d", &choice);

            if(choice == 1){
            Search();
            }
            else if(choice == 2){
            Display();
            }
            else if(choice == 3){
            double temp;
            temp = Fair();
            printf("The Total Fair is: %.2lf\n",temp);
            }
            else if(choice== 0){
                break;
            }
         }
    }
   else if(c==2){
     printf("\n\tEnter Password to verify its You: ");
     int pass;
     scanf("%d",&pass);

     if(pass==1234){
                    printf("\n\t******************** OWNER AREA *************************\n\n");

        while(1){
        printf("                                                                                          ");
        printf("                                                                                          ");
        printf("\n\t\tEnter [1] To Add Items In The Shop");
        printf("\n\t\tEnter [2] To Delete An Items");
        printf("\n\t\tEnter [3] To Show All Items");
        printf("\n\t\tEnter [0] To Back To Main Menu");

        printf("\n\nEnter your choice[0-3] : ");
        scanf("%d", &choice);

        if(choice == 1){
            char pname[100];
            float price;
            printf("Enter Product Name: ");
            scanf("%s", pname);
            printf("Enter Product Price: ");
            scanf("%f", &price);
            Add_A_Product(pname, price);
        }
        else if(choice == 2){
            Delete();
        }
        else if(choice == 3){
            Display();
        }
        else if(choice == 0){
            break;
        }
      }
     }
     else{
        printf("\n\n\tWRONG PASSWORD!!! :(\n\n\n");
     }
    }
    else if(c==3){
        printf("\n\n\tTHANKS FOR VISIT :)\n\n");
        break;
    }
  }
}



