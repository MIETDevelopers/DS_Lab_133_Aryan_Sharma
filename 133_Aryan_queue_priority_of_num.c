// Author : Aryan Sharma 133
//  program to implement priority queue ( different priority of different number) 

#include <stdio.h>
# define MAX 5
int queue[MAX] , val ,rear = -1 , front = -1 , temp , new_val;

void insert();      // enqueue
void delete();      // dequeue
void display();
void rearrange();
void priorityarrange();
void arrange();     
int prioritycheck();

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
        printf("\n--> Value inserted : %d.\n",val);
        
        if(rear == -1 && front == -1){
            rear = 0;
            front = 0;
            queue[rear] = val ;
        }else{
            rear++;
            priorityarrange();  
        }
    }
}

void priorityarrange()
{    
    int i=0 , new_val_precedance  , queue_val_precedance;
    
    new_val=val;
    new_val_precedance = prioritycheck();
    
    val=queue[0];
    queue_val_precedance = prioritycheck();

    if(new_val_precedance == 1)
    {
        queue[rear]=new_val;
    
    }else{
        while( new_val_precedance <= queue_val_precedance) 
        {
            i++;
            val=queue[i];
            queue_val_precedance=prioritycheck();
        }
        temp = i;
        arrange();
    }
}

void arrange()
{
    int i;
    if (rear == front)
    {
        queue[1]=queue[0];
        queue[temp] = new_val;
    }else{
        for(i = rear - 1 ;i>=temp ;i--)
        {
            queue[i+1] = queue[i];
        }
        queue[temp] = new_val;
    }
}

int prioritycheck()
{
   switch(val){ 

    case 4:
    case 2:
        return 2;
      
    case 7:
    case 9:
        return 3;
    
    case 1:
    case 5: 
        return 4;

    case 10:
    case 1:
        return 5;

    default:
        return 1;  
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
        printf("\n--> Elements present in the queue are: ");
        for(i=front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}