/*  By Aryan Shamra 133
    Creation Date : 17-05-21
    Purpose : Program to check if a given expression is correctly parenthesized using Stacks
*/  
#include<stdio.h>
int main(){
    int i,n,top=1;
    int stack[80];
    char ch[80];

    printf("Enter expression :");
    scanf("%s", &ch);
    for(i=0; ch[i] != '\0'; i++){
        if(ch[i]=='(' || ch[i]==')'){ 
            if(ch[i] == '('){
                top = top + 1;
                stack[top] = 1;
            }else{
                top=top-1;
            }

        }else{
            n=0;
        }
    }
    if(&stack[top]==&stack[1]){
            printf("\nExpression is correctly parenthesized.\n");
    }else{
        printf("\nExpression is incorrectly parenthesized.\n");
    }
    scanf("%d",&i);
    return 0;
}