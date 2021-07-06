/*
Author Aryan Sharma 133
Purpose: Fibaonacci series using recursion.
*/

#include<stdio.h>
int fibonacci(int num);

int main(){
    int num, i = 0, x;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
 
    printf("\nFibonacci series : ");
    for(x = 1 ; x <= num ; x++ ){
        printf("%d ", fibonacci(i));
        i=i+1; 
    }

    scanf("\n%d",&i);
    return 0;
}

int fibonacci(int num){
    if(num == 0){
        return 0;
    }else{  
        if(num == 1){ 
            return 1;
        }else{
            return(fibonacci(num-1) + fibonacci(num-2));
        }
    }
}