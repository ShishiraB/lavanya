#include<stdio.h> 
#include<stdlib.h> 
#define MAX 5 
int q[MAX];
int front=0,rear=-1; 
void insert_rear();
void insert_front(); 
void delete_rear(); 
void delete_front();
void display();
int main()
{
    int choice; 
    do
    {
        printf("\n1.Insert at rear ");
        printf("\n2.Insert at front ");
        printf("\n3.Delete from rear ");
        printf("\n4.Delete from front ");
        printf("\n5.Display ");
        printf("\n6.Exit");
        printf("\n\nEnter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_rear();
                break;
            case 2:
                insert_front();
                break;
            case 3:
                delete_rear();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                display();
                break;
        }
    }while(choice!=6);
    getchar();
    return 0;
}
void insert_rear()
{
    int val;
    printf("\nEnter the value to be added ");
    scanf("%d",&val);
    if(rear==MAX-1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    q[++rear]=val;
}
void insert_front()
{
    int val;
    printf("\nEnter the value to be added ");
    scanf("%d",&val);
    if(front==0 && rear==-1)
    {
        q[++rear]=val;
        return;
    }
    if(front!=0)
    {
        q[--front]=val;
        return;
    }
    printf("\nOVERFLOW\n");
}
void delete_rear()
{
    if(front>rear)
    {
        printf("\nUNDERFLOW\n");
        front=0;
        rear=-1;
        return;
    }
    printf("\nThe deleted element is %d\n", q[rear--]);
}
void delete_front()
{
    if(front>rear)
    {
        printf("\nUNDERFLOW\n");
        front=0;
        rear=-1;
        return;
    }
    printf("\nThe deleted element is %d\n", q[front++]);
}
void display()
{
    if(front>rear)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nThe elements in the queue are: ");
    for (int i = front; i<=rear;i++)
        printf("%d ",q[i]);
}