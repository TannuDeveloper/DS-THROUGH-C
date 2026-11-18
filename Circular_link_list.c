#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int info;
    struct node *link;
};
struct node *create_node();
struct node *create_Circular_Link_list(struct node *);
void traversal(struct node *);
int main()
{
    struct node *start=NULL;
    int choice;
    while(1)
    {
        printf("Enter 1:create circular link list\n");
        printf("Enter 3:traversal\n");
        printf("Enter 10:exit for loop\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:start=create_Circular_Link_list(start);
                     break;
            case 3:traversal(start);
                     break;
            case 10:exit(1);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}

struct node *create_node()
{
    struct node *temp;
    int data;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter a data\n");
    scanf("%d",&data);
    temp->info=data;
    temp->link=NULL;
    return temp;
}

struct node *create_Circular_Link_list(struct node *start)
{
    struct node *temp,*p;
    int n;
    printf("How many nodes\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(start==NULL)
        {
            temp=create_node();
            printf("Node is created\n");
            temp->link=temp;
            start=temp;

        }
        else
        {
            p=start;
            while(p->link!=start)
            {
                p=p->link;
            }
            temp=create_node();
            printf("Node is created\n");
            temp->link=p->link;
            p->link=temp;
        }
    }
    return start;
}

void traversal(struct node *start)
{
    struct node *p=start;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=start;
    do{
        printf("%d\t",p->info);
        p=p->link;
    }while(p!=start);
}