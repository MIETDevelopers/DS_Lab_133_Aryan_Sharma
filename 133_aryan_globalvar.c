/*
	A C program demonstrating use of global.
	By Aryan Sharma 133
*/
#include<stdio.h>
int a=4,b=2,c;
int multi(int a,int b, int c);
int main (){
	printf("Global  variable a & b = %d & %d\n",a,b);
	multi(a, b, c);
}
int multi(int a,int b, int c){
	c=a*b;
	printf("a * b = %d",c);
}