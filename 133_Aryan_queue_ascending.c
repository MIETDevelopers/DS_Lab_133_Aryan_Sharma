// Author : Aryan Sharma 133

#include <stdio.h>
# define MAX 5
int queue[MAX] , val ,rear = -1 , front = -1;

void insert();      // enqueue
void delete();      // dequeue
void display();
void rearrange();
void priorityarrange();     

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
        printf("\n--> Value inserted : %d.\n",val);
        priorityarrange();  
    }
}

void priorityarrange()
{
    int j , temp;
    for (int i = front; i <= rear; ++i) 
    {
        for (j = i + 1; j <= rear; ++j)
        {
            if (queue[i] > queue[j]) 
            {
                temp =  queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
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
        rearrange();
        if(rear == 0  && front == 0)
        {
            front = -1;
            rear = -1;
        }else{
            rear--;
        }
    }
}

void rearrange()
{
    int i;
    if (rear == front)
    {
        queue[0]=queue[1];
    }else{
        for(i=-1 ; i <= rear - 1 ;i++)
        {
            queue[i] = queue[i+1];
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
        printf("\n--> Elements present in the queue in ascending order are: ");
        for(i=front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}