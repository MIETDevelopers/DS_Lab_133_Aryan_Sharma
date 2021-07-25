// Author : Aryan Sharma 133
// Circular queue

#include <stdio.h>
# define MAX 5
int queue[MAX] , val , rear = -1 , front = -1;

void insert();      // enqueue
void delete();      // dequeue
void display();


int main()
{
    int ch;
    do{
        printf("\n\nEnter :\n");    
        printf("    1 to Enqueue\n    2 to Dequeue\n    3 to Display\n    4 to Exit\n--> ");
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
                printf("\nProcess ended.");
                break;
            default:
                printf("\n!!!!ERROR!!!!\n");    
        }
    }while(ch != 4);
}

void insert()
{   
    int temp;
    temp=rear;
    temp++;
    if(temp==(MAX))
        temp=0;
    if(temp == front)
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
            if(rear==MAX)
                rear=0;
        }
        queue[rear] = val ;
        printf("\n--> Value inserted.\n");
    }
}

void delete()
{
    if(rear == -1)
    {
        printf("\n--> Underflow.\n");
    }else{
        val = queue[front];
        printf("\n--> Deleted element : %d\n", val);
        
        if(rear == front)
        {
            front = -1;
            rear = -1;
        }else{
            front++;
            if(front==MAX){
                front=0;
            }
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

        for(i=front; i !=rear; i=(i+1) % MAX)
        {
            printf("%d ",queue[i]);
        }
        printf("%d ",queue[i]);
    }
}
