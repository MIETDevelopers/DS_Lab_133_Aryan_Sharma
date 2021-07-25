// Author : Aryan Sharma 133
#include <stdio.h>
# define MAX 5
int queue[MAX] , val ,rear = -1 , front = -1 , wasted = 0;

void insert();      // enqueue
void delete();      // dequeue
void display();
void memory();      // memory wated

int main()
{
    int ch;
    do{
        printf("\n\nEnter :\n");    
        printf("    1 to Enqueue\n    2 to Dequeue\n    3 to Display\n    4 to memory wasted\n    5 to Exit\n--> ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                memory();
                break;
            case 5:
                printf("\nProcess ended.");
                break;
            default:
                printf("\n!!!!ERROR!!!!\n");    
        }
    }while(ch != 5);
}

void insert()
{
    if(rear == MAX - 1)
    {
        printf("\n--> Overflow\n");
    }else{
        printf("\n--> Enter element to insert: ");
        scanf("%d",&val);
        if(rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }else{
            rear++;
        }

        queue[rear] = val ;
        printf("\n--> Value inserted.\n");
    }
}

void delete()
{
    if(front == -1)
    {
        printf("\n--> Underflow.\n");
    }else{
        val = queue[front];
        printf("\n--> Deleted element : %d\n", val);
        if(rear == front)
        {
            front = -1;
            rear = -1;
            wasted = 0;
        }else{
            front++;
            wasted++;
        }
    }
}

void display()
{
    int i;
    if(rear == -1)
    {
        printf("\n--> Queue is empty.\n");
    }else{
        printf("\n--> Elements present in the queue are: ");
        for(i=front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

void memory()
{   
    int memorywasted = 0;
    memorywasted = wasted * 4;
    printf("--> Memory wasted : %d bytes\n",memorywasted);
}