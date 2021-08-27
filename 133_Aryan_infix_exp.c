// Author : Aryan Sharma 133

#include <stdio.h>
char expr[20];
char symbol='E',temp_symbol;
int i, a, b, value=0;
int operand[12];
int dtop=-1 ,symbol_precedance=0,rtop_symbol_precedance=0;
char operator[10];
int rtop=-1,x;

void pushoperand(){
   dtop=dtop+1;
   operand[dtop]=value;
}

int popoperand(){
   if(dtop==-1)
   {
      x=0;  
   }else{
      dtop=dtop-1;
   }
}

void pushoperator(){
   temp_symbol=symbol;
   symbol_precedance =  precedance();

   symbol=operator[rtop];
   rtop_symbol_precedance = precedance();
   
   if(rtop==-1 || temp_symbol=='('){
      rtop=rtop+1;
      operator[rtop]=temp_symbol;
   }else{
      if(symbol_precedance <=rtop_symbol_precedance){
         b=operand[dtop];
         popoperand();
                       
         a=operand[dtop] ;
         popoperand();

         popoperator();
         evaluate();

         pushoperand();

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
   switch(symbol){ 

      case'+':
      case'-':
         return 1;
      
      case'*':
      case'/':
         return 2;
      
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
      if (expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*' || expr[i]=='(' || expr[i]==')'){
         symbol=expr[i];

         if(expr[i]==')'){
            while(operator[rtop] != '('){
          
               b=operand[dtop];
               popoperand();
                    
               a=operand[dtop] ;
               popoperand();
                     
               symbol=operator[rtop] ;
               popoperator();

               evaluate();
               }
            popoperator();
         }else{           
            pushoperator();
         }
      }else{
         value=expr[i]-48;
         pushoperand();
      }
   }

   while(rtop != -1){

      b=operand[dtop];
      popoperand();
      
      a=operand[dtop];
      popoperand();
      
      symbol=operator[rtop];
      popoperator();
      
      evaluate();
   }  

   printf("Evaluated expression is: %d\n.....................", operand[dtop]);
   scanf("%d",&i);
}
