//By Aryan Sharma   
//Roll no. 133
#include <stdio.h>
#include <stdlib.h>
#define Max 5
void insert();
void pop();
void view();
void insert2();
void pop2();
void view2();
int Stack[Max], Top = -1, ch, val, i, Top2 = Max;

int main()
{
    do
    {
        printf("\nMain menu");
        printf("\nEnter Number 1 to push element to stack A");
        printf("\nEnter Number 2 to pop element to stack A");
        printf("\nEnter Number 3 to display elements from stack A");
        printf("\nEnter Number 4 to insert push to stack B");
        printf("\nEnter Number 5 to pop from stack B");
        printf("\nEnter Number 6 to display element from stack B");
        printf("\nEnter Number 7 to Exit");

        printf("\n  Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            pop();
            break;
        case 3:
            view();
            break;
        case 4:
            insert2();
            break;
        case 5:
            pop2();
            break;
        case 6:
            view2();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("!!ERROR!!\n");
        }
    } while (1);
}
void insert()
{
    if (Top == Top2 - 1)
    {
        printf("  Stack overflow\n ");
    }
    else
    {
        printf("  Enter number which you want to insert in stack A\n");
        scanf("%d", &val);
        Top = Top + 1;
        Stack[Top] = val;
    }
}
void pop()
{
    if (Top == -1)
    {
        printf("  Stack A is underflow\n");
    }
    else
    {
        Top = Top - 1;
        val = Stack[Top];
    }
}
void view()
{
    if (Top == -1)
    {
        printf("  Stack A is empty\n");
    }
    else
    {
        for (i = Top; i >= 0; i--)
        {
            printf("%d\t", Stack[i]);
        }
    }
}
void insert2()
{
    if (Top2 - 1 == Top)
    {
        printf("  Stack B is overflow");
    }
    else
    {
        printf("  Enter number which you want to insert in stack B\n");
        scanf("%d", &val);
        Top2 = Top2 - 1;
        Stack[Top2] = val;
    }
}
void pop2()
{
    if (Top2 == Max)
    {
        printf("  Stack B is underflow");
    }
    else
    {
        Top2 == Top2 + 1;
        Stack[Top2] = val;
    }
}
void view2()
{
    if (Top2 == Max)
    {
        printf("  Stack B is empty\n");
    }
    else
    {
        for (i = Top2; i < Max; ++i)
        {
            printf("%d\t", Stack[i]);
        }
    }
}