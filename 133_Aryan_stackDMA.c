#include<stdio.h>
#include<stdlib.h>
int top=-1,*stack,ch,size;
void push();
void pop();
void view();

int main()
{
    printf("Enter the size of the array");
    scanf("%d",&size);
    stack=(int *)malloc(size*sizeof(stack));
    
    do
    {   
        printf("\nPress 1 to Push \nPress 2 to Pop \nPress 3 to view \nPress 4 to Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch(ch){

            case 1: push();
            break;

            case 2: pop();
            break;
            
            case 3: view();
            break;
            
            case 4: printf("\nProcess  end!!\n");
            break; 
                
            default:printf("\n\n!!ERROR!!\n");
        
            }
    }while(ch!=4);
}
void push(){
    int element;
    if(top==size-1){
        printf("Stack is full\n");
    }else{
        printf("Enter the number to insert in stack\n");
        scanf("%d",&element);
        top=top+1;
        stack[top]=element;  
    }
}

void pop(){
    if(top==-1)
    {
        printf("Stack is empty\n");
    }else{
        printf("\n Popped the element %d",stack[top]);
        top=top-1;
    }
}

void view(){
    int i;
    if(top>=0)
    {
        printf("\nElements in the stack are\n");
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
            }
    }else{
        printf("Stack is empty.\n");
    }
}