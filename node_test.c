#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*node1 , *node2 , *head;

int main(){
    int element1 , element2;
    printf("Enter data for node 1 and node 2\n");
    scanf("%d%d",&element1 , &element2);
    node1=(struct node *)malloc(sizeof(struct node));
    node2=(struct node *)malloc(sizeof(struct node));
    head=node1;
    node1->data=element1;
    node1->next=node2;
    node2->data=element2;
    node2->next=NULL;
    printf("Data in node 1 = %d at address %p\n", node1->data,head);
    printf("Data in node 2 = %d at address %p\n", node2->data,node1->next);
}