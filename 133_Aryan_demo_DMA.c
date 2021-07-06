#include<stdio.h>
#include<stdlib.h>

int *ptr,i,s,ch;

void demo_malloc();
void demo_calloc();
void demo_realloc();

int main ()
{
    do
    {
        printf("\n\n1. Malloc\n2. Calloc\n3. Realloc\n4. End\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:
                demo_malloc();
                break;
            
            case 2:
                demo_calloc();
                break;
            
            case 3:
                demo_realloc();
                break;
            
            case 4:
                printf("\nProcess  end!!\n");
                break;

            default :
                printf("\n\n!!ERROR!!\n");
        }
    }while(ch!=4);
}

void demo_malloc()
{
    printf("Enter the size of array : ");
    scanf("%d",&s);
    ptr=(int *)malloc(s*sizeof(int));
    printf("Enter elements : ");
    for(i=0;i<s;i++){
        scanf("%d",(ptr+i));
    }  

    for(i=0;i<s;i++){
        printf("\n%d",*(ptr+i));
    }
}

void demo_calloc()
{
    printf("Enter the size of array : ");
    scanf("%d",&s);
    ptr=(int *)calloc(s,sizeof(int));
    printf("Enter elements : ");
    for(i=0;i<s;i++){
        scanf("%d",(ptr+i));
    }

    for(i=0;i<s;i++){
        printf("\n%d",*(ptr+i));
    }
}

void demo_realloc()
{
    printf("Enter the size of array : ");
    scanf("%d",&s);
    ptr=(int *)realloc(ptr,s*sizeof(int));
    printf("Enter elements : ");
    for(i=0;i<s;i++){
        scanf("%d",(ptr+i));
    }  
    
    for(i=0;i<s;i++){
        printf("\n%d",*(ptr+i));
    }
    free(ptr);
}