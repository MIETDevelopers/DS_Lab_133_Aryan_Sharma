/*  Name: Aryan Sharma
	Purpose:  A functions to perform insertion, deletion and linear search operations.
	Date: 25 May
*/
#include<stdio.h>

int addarr(int arr[], int intt, int n);
int delete(int arr[],int index, int n);
int Search(int arr[], int ch);

int main()
{
	int arr[6], ch, i, intt, index;
	int n = 5;

	printf("Enter 5 element for array: \n");
	for(i=0 ; i<5 ; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Entered elements of array are\n");
	for (i = 0; i<5; ++i)
	{
		printf("%d ",arr[i]);
	}

	printf("\nChoose an operation to perform:\n1.Insertion\n2. Deletion\n3. Linear Search\n");
	scanf("%d",&ch);
	
	switch (ch)
	{
		case 1:
			printf("Ener the integer to be added at the end of array:\n");
			scanf("%d", &intt);
			addarr(arr, intt, n);
			printf("Elements of array after addition :\n");
			for(i = 0; i<6; ++i){
				printf("%d ",arr[i]);
			}
			break;

		case 2:
			printf("Enter the index of the element delete: \n");
			scanf("%d", &index);
			delete(arr, index, n);
			index-=1;
			printf("Elements of array after deletion :\n");
			for(i=0 ; i<4 ; i++)
			{
				printf("%d ",arr[i]);
			}
		break;

		case 3:
			printf("Enter the element to be searched:\n ");
			scanf("%d", &ch);
			int search = Search(arr, ch);
			if (search == -1)
				printf("\nElement not found!\n");
			else
				printf("\nThe element %d was found at Index %d \n", ch, search);
		break;

		default:
			printf("!! Error  !!");
			break;
	}
}

int addarr(int arr[], int intt, int n)
{
    if (n >= 6)
    {
    	return -1;
    }
	for (int i= 5; i>= intt ;i--) 
	{
		arr[i+1] = arr[i];
	} 
    arr[n] = intt;
 
    return (n + 1);
}

int delete(int arr[],int index, int n)
{	
	int i = 5;
	for (int i=index; i<n-1; i++){
		arr[i] = arr[i + 1];
	}

}

int Search(int arr[], int ch)
{
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == ch)
			return i;
	}
	return 1;
}