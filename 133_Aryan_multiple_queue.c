// Author : Aryan Sharma 133

#include <stdio.h>

# define MAX 4
int queue[MAX] , val , rear1 = -1 , front1 = -1 , rear2 = MAX , front2 = MAX;

void insert1();      // enqueue
void delete1();      // dequeue
void display1();
void rearrange1();

void insert2();
void delete2();
void display2();
void rearrange2();     

int main()
{
    int ch;
    do{
        printf("\n\nEnter :\n");    
        printf("  For queue1 :\n    1 to Enqueue\n    2 to Dequeue\n    3 to Display\n  For queue2 :\n    4 to Enqueue\n    5 to Dequeue\n    6 to Display\n    7 to Exit\n--> ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 1:
                insert1();
                break;
            
            case 2:
                delete1();
                break;
            
            case 3:
                display1();
                break;
            
            case 4:
                insert2();
                break;
            
            case 5:
                delete2();
                break;
            
            case 6:
                display2();
                break;
            
            case 7:
                printf("\nProcess ended.");
                break;
            
            default:
                printf("\n!!!!ERROR!!!!\n");    
        }
    }while(ch != 7);
}

void insert1()
{
    if(rear1 == rear2 - 1)
    {
        printf("\n--> Queue 1 is overflow\n");
    }else{
        printf("\n--> Enter element to insert: ");
        scanf("%d",&val);
        
        if(rear1 == -1 && front1 == -1)
        {
            rear1 = 0;
            front1 = 0;
        }else{
            rear1++;
        }

        queue[rear1] = val ;
        printf("\n--> Value inserted in queue 1.\n");
    }
}

void delete1()
{
    if(front1 == -1)
    {
        printf("\n--> Queue 1 is underflow.\n");
    }else{
        val = queue[front1];
        printf("\n--> Deleted element : %d\n", val);
        
        rearrange1();
        
        if(rear1 == 0  && front1 == 0)
        {
            front1 = -1;
            rear1 = -1;
        }else{
            rear1--;
        }
    }
}

void rearrange1()
{
    int i;
    if (rear1 == front1)
    {
        queue[0]=queue[1];
    }else{
        for(i=-1 ; i <= rear1 - 1 ;i++)
        {
            queue[i] = queue[i+1];
        }
    }
}

void display1()
{
    int i;
    if(rear1 == -1)
    {
        printf("\n--> Queue 1 is empty.\n");
    }else{
        printf("\n--> Elements present in the queue 1 are: ");
        
        for(i=front1; i<=rear1; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

void insert2()
{
    if(rear2 == rear1 +1)
    {
        printf("\n--> Queue 2 is overflow\n");
    }else{
        printf("\n--> Enter element to insert: ");
        scanf("%d",&val);
        
        if(rear2 == MAX && front2 == MAX)
        {
            rear2 = MAX - 1;
            front2 = MAX - 1;
        }else{
            rear2--;
        }
        
        queue[rear2] = val ;
        printf("\n--> Value inserted in queue 2.\n");
    }
}

void delete2()
{
    if(front2 == MAX)
    {
        printf("\n--> Queue 2 is underflow.\n");
    }else{
        val = queue[front2];
        printf("\n--> Deleted element : %d\n", val);
        
        rearrange2();
        
        if(rear2 == MAX-1  && front2 == MAX-1)
        {
            front2 = MAX;
            rear2 = MAX;
        }else{
            rear2++;
        }
    }
}

void rearrange2()
{
    int i;
    if (rear2 == front2)
    {
        queue[MAX]=queue[MAX-1];
    }else{
        for(i=MAX; i >= rear2 ;i--)
        {
            queue[i+1] = queue[i];
        }
    }
}

void display2()
{
    int i;
    if(front2 == MAX)
    {
        printf("\n--> Queue 2 is empty.\n");
    }else{
        printf("\n--> Elements present in the queue 2 are: ");
        
        for(i=front2; i>=rear2; i--)
        {
            printf("%d ",queue[i]);
        }
    }
}