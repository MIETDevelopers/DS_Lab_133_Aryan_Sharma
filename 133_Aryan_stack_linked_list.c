// Author : Aryan Sharma 133
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head = NULL , *ptr;
typedef struct node NODE;
int num_element=0;

int push()
{
    
    ptr=(NODE*)malloc(sizeof(NODE));

    if(ptr==NULL){
        printf("\nRAM FULL!!\n");
    }else{
        printf("\nEnter element to be pushed : ");
        scanf("%d",&ptr->data);
        
        if(head == NULL){
            head = ptr ;
            ptr->next = NULL ;
        }else{
            ptr->next = head;
            head = ptr;
        }
        printf("\nNode inserted at address : %p\n",ptr);
        num_element++;
    }
}

int  pop(){
    if(head==NULL)
    {
        printf("Nothing to pop.\n");
        num_element=0;
    }else{
        
        if(head->next == NULL){
            head = NULL;
            free(head);
        }else{
            ptr = head;
            head = head->next;
            free(ptr);
        }
        num_element--;
        printf("\nNode deleted.\n");
    }
}

int search(){
    int element , x=1;
    ptr = head;
    if(ptr== NULL) 
    {
        printf("\nNothing to search.\n");
    }  
    else
    {   
        printf("Enter element to search : ");
        scanf("%d",&element);   
        while (ptr != NULL)
        {    
            if(ptr->data == element){
                printf("\n-->Element %d present at %p .\n", element, ptr);
                x=0;
            }
            ptr = ptr->next;    
        }
        if(x != 0){
            printf("\n-->Element %d not found \n\n",element);
        }
    } 
}

int display(){
    ptr = head;   
    if(ptr== NULL)  
    {  
        printf("\nNothing to print\n");  
    }  
    else  
    {  
        printf("\nElements present :\n");   
        
        while (ptr != NULL)
        {  
            printf("-->%d at address %p\n", ptr->data, ptr);  
            ptr = ptr->next;  
        }
    printf("\n-->Number of node present : %d.\n",num_element);
    } 
}

int main(){
    int ch;
    do{
        printf("\nEnter\n   1.To push\n   2.To pop\n   3.To search\n   4.To display\n   5.To Exit\n\n");    
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProcess ended.\n");
                break;

            default:
                printf("\n!!ERROR!!\n");
        }
    }while (ch != 5);
}