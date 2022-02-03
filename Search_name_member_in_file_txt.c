#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Information
{
	int MaCB;
	char TenGV[100];
	char Khoa[100];
};int n;
void Input(Information infor[], int n)
{
	for(int i = 0; i<n;++i)
	{
		printf("Input the infor of lecturer [%d]: \n", i+1);
		printf("Input lecturer ID: \n");
		scanf("%d",&infor[i].MaCB);
		printf("Input lecturer's name: \n");
		fflush(stdin);
		gets(infor[i].TenGV);
		printf("Input lecturer's falcuty: \n");
		fflush(stdin);
		gets(infor[i].Khoa);
	}
}
void Output(Information infor[], int n)
{
	for(int i = 0; i<n;++i)
	{
		printf("THE INFORMATION OF LECTURER [%d]\n", i+1);
		printf("Name: %s\n", infor[i].TenGV);
		printf("ID: %d\n", infor[i].MaCB);
		printf("Falcuty: %s\n", infor[i].Khoa);
	}
}
int Search(char name[], Information infor[], int n, int &result, int &add)
{
		printf("Input the lecturer that you want to search: \n");
		gets(name);
		for(int i =0; i<n;++i)
		{
			result = stricmp(name, infor[i].TenGV);
			if(result == 0)
			{
				add = i;	
			}
		}
		return add;
}
int main()
{
	Information infor[100];	
	do{
		printf("Input the number of lecturers: \n");
		scanf("%d", &n);
			if(n<=0)
			{
				printf("ERORR AMOUNT! PLEASE TRY AGAIN\n");
				}	
	}while(n<=0);
	Input(infor,n);
	Output(infor,n);
	FILE *fptr = fopen("C:\\output.txt","w");
	int result;
	int add;
	char name[100];
	if(fptr == NULL)
	{
		printf("Error!");
	}
	else
	{
		Search(name, infor, n, result, add);			
		switch(result)
			{
				case 0: fprintf(fptr, "Name: %s\n",infor[add].TenGV);fprintf(fptr,"ID: %d\n", infor[add].MaCB);fprintf(fptr,"Falcuty: %s\n", infor[add].Khoa);break;
				default: fprintf(fptr, "No exist\n");break;
			}
	}
	printf("Please check your file following to the address !\n");
}