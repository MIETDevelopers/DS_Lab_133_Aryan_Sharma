// Author : Aryan Sharma 133
// Infix to Postfix Conversion

#include <stdio.h>
char expr[40];
char symbol='E',temp_symbol;
int i;
char element;
char output[40];
int dtop=-1 ,symbol_precedance=0,rtop_symbol_precedance=0;
char operator[30];
int rtop=-1,x;

char pushoutput(){
   dtop=dtop+1;
   output[dtop]=element;
}

char pushoperator(){
   temp_symbol=element;
   symbol_precedance =  precedance();

   element=operator[rtop];
   rtop_symbol_precedance = precedance();
   
   if(rtop==-1 || temp_symbol=='('){
      rtop=rtop+1;
      operator[rtop]=temp_symbol;
   }else{
      if(symbol_precedance <= rtop_symbol_precedance){
         while(symbol_precedance <= rtop_symbol_precedance){
            element=operator[rtop];
            rtop_symbol_precedance = precedance();
            popoperator();
            
            pushoutput();
         }
         rtop=rtop+1;
         operator[rtop]=temp_symbol;         
      }else{
         rtop=rtop+1;
         operator[rtop]=temp_symbol;     
      }   
   }
}

int precedance()
{
   switch(element){ 

      case'+':
      case'-':
         return 1;
      
      case'*':
      case'/':
         return 2;

      case '^':
         return 3;
      
      default :
         return -1;  
   }
}


int popoperator(){
   if(rtop==-1)
   {
      x=0;
   }else{
      rtop=rtop-1;
   }
}

void main(){
  
   printf("Enter Infix expression : \n");
   scanf("%s", &expr);

   for (i=0; expr[i] != '\0'; i++){
      if (expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*' || expr[i]=='(' || expr[i]==')' || expr[i]=='^'){
         element=expr[i];

         if(expr[i]==')'){
            while(operator[rtop] != '(')
            {         
               element=operator[rtop];
               popoperator();

               pushoutput();
            }
            popoperator();
         }else{            
            pushoperator();
         }
      }else{

         element=expr[i];
         pushoutput();
      }
   }

   while(rtop != -1){      
      element=operator[rtop];
      popoperator();
      pushoutput();
   }  

   printf("Postfix expression is: ");
   for(i=0 ; i <= dtop ; i++){
      printf("%c",output[i]);
   }
   scanf("%d",&i);
}
