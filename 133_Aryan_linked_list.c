// Author : Aryan Sharma 133
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head , *ptr , *temp ;
int num_element=0;

int insert()
{
    int element;
    ptr=(struct node *)malloc(sizeof(struct node));

    if(ptr==NULL){
        printf("\nRAM FULL!!\n");
    }else{
        printf("\nEnter element to be added : ");
        scanf("%d",&element);
        
        ptr->data = element ;
        ptr->next = NULL ;
        
        if(head == NULL){
            head = ptr ;
        }else{
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next ;
            }
            temp->next = ptr ;
        }
        printf("\nNode inserted at address : %p\n",ptr);
        num_element++;
        printf("\n-->Number of node present : %d.\n",num_element);
    }
}

int delete(){
    if(head==NULL)
    {
        printf("Nothing to delete.\n");
        num_element=0;
    }else{
        temp = head;

        if(head->next == NULL){
            head = NULL;
            free(head);
        }else{

            while(temp->next != NULL)
            {
                ptr = temp;
                temp = temp->next ;
            }
            ptr->next = NULL;
            free(temp);
        }
        num_element--;
        printf("\nNode deleated at address : %p\n",ptr);
        printf("\n-->Number of node left : %d.\n",num_element);
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
        printf("\nEnter\n   1.To insert\n   2.To delete\n   3.To search\n   4.To display\n   5.To Exit\n\n");    
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                insert();
                break;

            case 2:
                delete();
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