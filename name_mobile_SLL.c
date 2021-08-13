// Author : Aryan Sharma 133
#include <stdio.h>
#include <stdlib.h>

struct node{
    char name[9];
    int  mobile[10];
    struct node *next;
} *head , *ptr , *temp ;
int num_element=0;

typedef struct node NODE;

int insert()
{

    ptr=(NODE*)malloc(sizeof(NODE));

    if(ptr==NULL){
        printf("\nRAM FULL!!\n");
    }else{
        printf("\nEnter name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter mobile number :");
        scanf("%s",&ptr->mobile);

        
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


int display(){
    ptr = head;   
    if(ptr== NULL)  
    {  
        printf("\nNothing to print\n");  
    }  
    else  
    {  
        printf("\nData present :\n");   
        
        while (ptr != NULL)
        {
            printf("-->Name :%s   Mobile No.:%s\n", ptr->name, ptr->mobile);  
            
            ptr = ptr->next;  
        }
    printf("\n-->Number of node present : %d.\n",num_element);
    } 
}

int main(){
    int ch;
    do{
        printf("\nEnter\n   1.To insert\n   2.To delete\n   3.To display\n   4.To Exit\n\n");    
        scanf("%d",&ch);
        
        switch(ch){
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
                printf("\nProcess ended.\n");
                break;

            default:
                printf("\n!!ERROR!!\n");
        }
    }while (ch != 4);
}