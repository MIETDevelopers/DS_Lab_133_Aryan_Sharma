// Author : Aryan Sharma 133
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head , *ptr , *temp ,*temp2;
int element, num_element=0;

int insert()
{
    int position , x , present_position = 0;
    ptr=(struct node*)malloc(sizeof(struct node));

    if(ptr==NULL){
        printf("\n-->!! RAM FULL !!\n");
    }else{
        printf("\n-->Enter element to be added : ");
        scanf("%d",&element);
        
        ptr->data = element ;
        ptr->next = NULL ;
        
        if(head == NULL){
            head = ptr ;
            num_element=1;
        }else{
            do{
                printf("\nWhere you want to insert the element : ");
                scanf("%d",&position);
                
                if(position > (num_element + 1) || position <= 0)
                {
                    printf("\n-->Position where you want to insert is invalid.\n");
                    x = 0 ;
                }else{
                    x = 1 ;
                }
            }while(x != 1);

            temp = head;
            if(position == 1){
                
                head = ptr;
                ptr->next = temp;
                num_element++;
            }else{
                x = 0 ;
                while (x != 1)
                {   
                    present_position++;
                    if(position == present_position){

                        ptr->next = temp;
                        temp = temp2 ;
                        temp->next = ptr ;

                        x = 1 ;
                        num_element++;
                    }
                    temp2 = temp;
                    temp = temp->next;  
                } 
            }
        }
        printf("\n-->Node inserted at address : %p\n",ptr);
    }
}

int delete(){
    int y=1;
    if(head==NULL)
    {
        printf("\n-->Nothing to delete.\n");
        num_element = 0;
    }else{
        temp = head;
        
        printf("\nEnter element you want to be delete : ");
        scanf("%d",&element);

        while(temp != NULL)
        {
            if(temp->data == element)
            {                   
                temp = temp->next;
                
                printf("\n-->Element %d present at %p .\n", element,ptr->next);
                //printf("\nNode deleated at address : %p\n",ptr);
                
                if(head->next == temp){
                    if(head->next == NULL){
                        head = NULL;
                        free(head);

                    }else{
                        head = ptr->next;   
                    }
                }else{

                    free(ptr->next);
                    ptr->next = temp;
                }
                y=0;
            }else{
                ptr = temp;
                temp = temp->next ;
            }
        }
        if(y == 0){
            printf("\n-->Node deleated\n");
            num_element--;
        }else{
            printf("\n-->Element not found on list.\n");
        }
    }
}

int search(){
    int x=1;
    ptr = head;   
    
    if(ptr== NULL)  
    {  
        printf("\n-->Nothing to search.\n");  

    }else{   
        
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
            printf("\n-->Element %d not found. \n\n",element);
        }
    } 
}

int display(){
    ptr = head;   
    if(ptr== NULL)  
    {  
        printf("\n-->Nothing to print\n");  
    
    }else{  
    
        printf("\n-->Elements present :\n");   
        
        while (ptr != NULL)
        {  
            printf("-->%d at address %p\n", ptr->data, ptr);  
            ptr = ptr->next;  
        }
    } 
}

int main(){
    int ch;
    do{
        printf("\nEnter:\n   ->1.To insert\n   ->2.To delete\n   ->3.To search\n   ->4.To display\n   ->5.To Exit\n\n-->");    
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