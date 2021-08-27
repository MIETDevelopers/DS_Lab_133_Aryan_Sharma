#include <stdio.h>
char expr[20] , symbol;
int i, a, b, x, value=0;
int operand[12];
int dtop=-1 ;

void pushoperand(){

   dtop=dtop+1;

   operand[dtop]=value;
}


int popoperand(){
   dtop=dtop-1;
}

int evaluate(){

   switch(symbol)
   {
      case '+':
         value = a+b;
         pushoperand();
         break;
      
      case '-':
         value = a-b;
         pushoperand();
         break;
      
      case '*':
         value = a*b;
         pushoperand();
         break;
      
      case '/':
         value = a/b;
         pushoperand();
         break;
      
      default:
         printf("\n\n!!!!ERROR!!!!\n\n");
   }
}

void main(){
  
   printf("Enter expression (do not use ^ operator) : \n");
   scanf("%s", &expr);
   for (i=0; expr[i] != '\0'; i++){
      x++;
   }

   for (i=x ;i>=0 ; i--){
      if (expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*'){
         symbol=expr[i];
         
         a=operand[dtop];
         popoperand();
         
         b=operand[dtop];
         popoperand();
         
         evaluate();
      
      }else{
         value=expr[i]-48;
         pushoperand();
      }
   }
   printf("Evaluated expression is: %d\n ", operand[dtop]);
   scanf("%d",&i);
}