// Author : Aryan Sharma
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL, *end = NULL, *ptr, *temp, *temp2;

typedef struct node NODE;

int i, position, num_element = 0;

int insert(){
    int  present_position = 1, x=0; 
    ptr=(NODE*)malloc(sizeof(NODE));

    if(ptr == NULL){
        printf("\nRAM Full!\n");
    }else{
        printf("\nEnter element you want to insert : ");
        scanf("%d",&ptr->data);
        temp = head;
        
        if(i == 3){
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
        }

        if(position == 1){
            ptr->prev = NULL;
            ptr->next = head;
                        
            if(head == NULL ){
                end = ptr;
            }else{
                head->prev = ptr;
            }
            head = ptr;
        }else{
            x = 0 ;
            if(position == (num_element+1)){
                i = 2;
            }
            if(i == 2){
                ptr->next = NULL;
                end->next = ptr;
                ptr->prev = end;
                end = ptr;
            }else{

                while (x != 1){   
                    
                    temp2 = temp;
                    temp = temp->next;  
                    present_position++;
                    
                    if(position == present_position){
                        ptr->next = temp;
                        temp->prev = ptr;
                        ptr->prev = temp2;
                        
                        temp2->next = ptr;
                                        
                        x = 1 ;    
                    }
                }
            } 
        }
        printf("\nNode inserted at address : %p\n",ptr);
        num_element++;
    }
}

int delete(){
    int x=0, present_position=1;

    if(head->next == NULL){
        free(head);
        free(end);
    
        head = NULL;
        end = NULL;
        num_element = 0;
    }else{
        if(i == 3){
            do{
                printf("\nPosition where you want to delete the element : ");
                scanf("%d",&position);

                if(position > num_element || position <= 0)
                {
                    printf("\n-->Position where you want to insert is invalid.\n");
                    x = 0 ;
                }else{
                    x = 1 ;
                    if(position == 1){
                        i=1;
                    }else{
                        if(position == num_element)
                            i=2;
                    }
                }
            }while(x != 1);
        }

        if(i == 1){
            ptr = head;
            head = head->next;
            head->prev = NULL;
            free(ptr);    
        
        }else{
            if(i == 2){
                ptr = end;
                end = end->prev;
                end->next = NULL;
                free(ptr);
            
            }else{
                ptr = head;
                x = 0;
                
                if(i == 3){
                    while (x != 1){   
                    
                        temp = ptr;
                        ptr = ptr->next;  
                        present_position++;
                        
                        if(position == present_position){
                            temp->next = ptr->next;
                            temp2 = ptr;
                            
                            ptr = ptr->next;
                            ptr->prev = temp;

                            free(temp2);        
                            x = 1 ;    
                        }
                    }
                }
            }
        }   
        num_element--;
    }
    printf("\nNode deleted.\n"); 
}

int search(){
    int element , x=1;
    
    ptr = head; 
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

int display(){
    printf("\nElements present :\n");       
    
    if(i == 1){
        ptr = head;    
        
        while (ptr != NULL){  
            printf(">>>>%d at address %p\n", ptr->data, ptr);  
            ptr = ptr->next;  
        }
    }else{
        ptr = end;

        while(ptr != NULL){
            printf(">>>>%d at address %p\n", ptr->data, ptr);
            ptr = ptr->prev;
        }
    }
}


int main()
{
    int ch;
    do{
        printf("\nEnter\n   1.To insert\n   2.To delete\n   3.To search\n   4.To display\n   5.To Exit\n\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            
            if(head == NULL){
                i = 1;
                position = 1;
                insert();
                break;
            
            }else{
                do{
                    printf("\n--->Enter\n-->1.To insert at begning\n-->2.To insert at last\n");
                    printf("-->3.To insert at specific position\n-->4.To go back\n-->");
                    scanf("%d",&i);
                    
                    switch(i){
                        case 1:
                            position = 1;
                            insert();
                            break;
                        case 2:
                            position = num_element+1;
                            insert();
                            break;
                        case 3:
                            insert();
                            break;
                        case 4:
                            printf("\n<--> MAIN MENU <-->\n");
                            break;
                        default:
                            printf("\n-->Please enter correct input.\n");
                    }
                }while(i<1 || i>4);
            }        
            break;  

            case 2:
            
            if(head == NULL){
                printf("\nNothing to delete\n");
                break;
            
            }else{
                if(head->next == NULL){
                    delete();
                    break;
                
                }else{
                    do{
                        printf("\n--->Enter\n-->1.To delete at begning\n-->2.To delete at last\n");
                        printf("-->3.To delete at specific position\n-->4.To go back\n-->");
                        scanf("%d",&i);
                        
                        switch(i){
                            case 1:
                            case 2:
                            case 3:
                                delete();
                                break;

                            case 4:
                                printf("\n<--> MAIN MENU <-->\n");
                                break;
                            default:
                                printf("\n-->Please enter correct input.\n");
                        }
                    }while(i<1 || i>3);
                }
            }
            break;
            
            case 3:
            
            if(head == NULL) {
                printf("\nNothing to search.\n");
            }else{
                search();
            }
            break;

            case 4:
            
            if(head == NULL){
                printf("\nNothing to print\n");
                break;
            
            }else{
                if(head->next == NULL){
                    printf(">>>>%d at address %p\n", head->data, head);
                    break;
                
                }else{
                    do{
                        printf("\n--->Enter\n-->1.To display in forward direction\n");
                        printf("-->2.To display in backward direction\n-->3.To go back\n-->");
                        scanf("%d",&i);
                        
                        switch(i){
                            case 1:
                            case 2:
                                display();
                                break;
                            
                            case 3:
                                printf("\n<--> MAIN MENU <-->\n");
                                break;
                            default:
                                printf("\n-->Please enter correct input.\n");
                        }
                    }while(i<1 || i>3);
                }
            }
            break;

            case 5:
                printf("\nProcess ended.\n");
                break;

            default:
                printf("\n-->Please enter correct input.\n");
        }
    }while(ch != 5);
}