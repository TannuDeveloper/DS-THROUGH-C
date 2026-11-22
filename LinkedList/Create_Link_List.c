#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *addatbeginning();
struct node *addatend();
struct node *addafternode();
struct node *addbeforenode();
struct node *start=NULL;
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("Enter 1: Add at beginning\n");
        printf("Enter 2: add at end\n");
        printf("Enter 3: Add at after node\n");
        printf("Enter 4: Add at before node\n");
        printf("Enter 5:display all value\n");
        printf("Enter 10:exit for loop\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start=addatbeginning();
                        break;
            case 2: start=addatend();
                        break;
            case 3: start=addafternode();
                        break;
            case 4: start=addbeforenode();
                        break;
            case 5: display();
                        break;
            case 10:exit(1);
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}

struct node *addatbeginning()
{
    struct node *temp;
    int data;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data that you wants to insert at beginning\n");
    scanf("%d",&data);
    temp->info = data;
    if(start==NULL)
    {
        temp->link = start;
        start =temp;
    }
    else
    {
        temp->link = start;
        start = temp;
    }
    return start;
}

struct node *addatend()
{
    struct node *temp,*p;
    int data;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data that you wants to insert at end\n");
    scanf("%d",&data);
    temp->info = data;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    temp->link = p->link;
    p->link = temp;
    return start;
}

struct node *addafternode()
{
    struct  node *temp,*p;
    int data,item;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be insert\n");
    scanf("%d",&data);
     temp->info = data;
    printf("Enter the elements after which to insert\n");
    scanf("%d",&item);
    p=start;
    if(start==NULL)
    {
        printf("List is empty\n");
        free(temp);
        return start;
    }
    while(p!=NULL && p->info != item)
    {
         p=p->link;
    }
    if(p == NULL)
    {
        printf(" Element Node found\n");
        free(temp);
        return start;
    }
    temp->link=p->link;
    p->link=temp;
    return start;
}

struct node *addbeforenode()
{
   struct node *temp,*p;
   int data,item;
   temp = (struct node *)malloc(sizeof(struct node));
   printf("Enter the element to be insert :\n");
   scanf("%d",&data);
   temp->info = data;
   printf("Enter the element before which to insert :\n");
   scanf("%d",&item);
   if(start==NULL)
   {
    printf("List is empty\n");
    free(temp);
    return start;
   }
   p=start;
   // Insert before first node
   if(start->info==item)
   {
    temp->link=start;
    start=temp;
    return start;
   }
   while(p!=NULL && p->link!=NULL)
   {
    if(p->link->info == item)
    {
        temp->link = p->link;
        p->link = temp;
       return start;
    }
    p=p->link;
   }
   printf("Value not found\n");
   return start;
   
}


void display()
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=start;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->link;
    }
    printf("\n");
}