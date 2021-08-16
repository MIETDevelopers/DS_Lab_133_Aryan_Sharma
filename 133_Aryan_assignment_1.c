// Author : Aryan Sharma 133
// Assignment 1: Find the cheapest walnut in Raghunath Bazaar of Jammu.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int price;
    char name[30];
    struct node *next;
} *head, *ptr;

typedef struct node NODE;

int num=0;


int insert()
{
    ptr=(NODE*)malloc(sizeof(NODE));        

    if(ptr==NULL){
        printf("\nRAM FULL!!\n");
    }else{
        printf("\nEnter shop name: ");
        scanf("%*c%[^\n]",&ptr->name);

        printf("\nEnter price of walnut: ");
        scanf("%d",&ptr->price);

        if(head == NULL){
            head = ptr ;
            head->next = NULL ;
        }else{
            if(head->price >= ptr->price){ //If the price is cheaper node will be added at first spot.
                ptr->next = head;
                head = ptr;
            }else{                  //If the price is not cheaper node will be added at second spot.
                ptr->next = head->next;
                head->next = ptr;
            }
        }
        num++;
    }
}

int cheapest(){
       
    if(head==NULL)  
    {  
        printf("\nNo data present.\n");  
    }  
    else  
    {
        printf("\nShop that sells cheapest walnut in Raghunath Bazaar is %s at %d Rs.\n",head->name,head->price);
    }
}

int display(){
    ptr = head;   
    if(ptr==NULL)  
    {  
        printf("\nNo data present.\n");
    }  
    else  
    {  
        printf("\nData of all shops :\n");   
        
        while (ptr != NULL)
        {  
            printf("-->Shop name: '%s' sells walnut at %d Rs.\n", ptr->name, ptr->price);  
            ptr = ptr->next;
        }
    printf("\n-->Data of %d shops in Raghunath Bazaar is present.\n",num);
    } 
}

int main(){
    int ch;
    do{
        printf("\nEnter\n   1.To enter shop details\n   2.To display shop which sells cheapest walnut\n   3.To display cost of walnut of all shops\n   4.To Exit\n");    
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                insert();
                break;

            case 2:
                cheapest();
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