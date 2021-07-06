//By Aryan Sharma 133
//Purpose: C program demonstrating use of malloc().
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr;

    printf("Number of elements you want to insert: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    printf("Enter elements: ");
    for(i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
    }

    printf("\nPrinting elements: ");
    for(i = 0; i < n; ++i)
    {
        printf("%d ", *(ptr + i));
    }
    return 0;
}