#include<stdio.h>

int main()
{
	struct info
	{
		char name[12];
		int class;
		int rollno;
	};

	int x,i;
	printf("Number of student info you want to enter:");
	scanf("%d",&x);

	struct info info[x];
	for(int i=0; i<x ; i++)
	{
		printf("Enter student %d name, class and rollno :\n",i+1);
		scanf("%s",&info[i].name);
		scanf("%d",&info[i].class);
		scanf("%d",&info[i].rollno);
	}
	for (int i =0; i<x ; i++)
	{
		printf("Student %d name : %s\n",i+1,info[i].name);
		printf("Student %d class : %d\n",i+1,info[i].class);
		printf("Student %d rollno : %d\n",i+1,info[i].rollno);
	}
	return 0;
}