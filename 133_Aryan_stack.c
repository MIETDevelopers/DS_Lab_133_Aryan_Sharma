//By Aryan Sharma 133
//Purpose : TO "push" and "pop" elements in the stack.
#include <stdio.h>

int i, n, c, stack[20], top=-1;

void push();
void pop();
void view();

int main ()
{
     
    printf("Enter the number of elements to be stored in stack:\n");
    scanf("%d", &n);

    do
    {   
        printf("\nPress 1 to Push \nPress 2 to Pop \nPress 3 to view \nPress 4 to Exit\n");
        scanf("%d", &c);
        switch (c)
        {
            case 1: 
            {
                push();
                break;
            }

            case 2:
            {
                pop();
                break;
            }

            case 3:
            {
                view();
                break;
            }

            case 4:
            {
                printf("\nProcess stopped.");
                break;
            }

            default:
            {
                printf("\n\n!!ERROR!!\n\n");
                break;
            }
        }
    }while (c != 4);
}

void push() 
{
    int val;
    if (top == n)
    printf("Stack is Overflow\n");

    else
    {
        printf("\nEnter the number you want to enter\n");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop ()
{
    if (top == -1)
        printf("Stack is Underflow\n");
    else
    {
        printf("\nThe element present at the end.\n");
        top = top - 1;
    }
}

void view ()
{
    printf("\nThe element present in the stack are:\n");
    for(i=top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}