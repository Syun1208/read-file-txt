#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Readfile(int *num,int n)
{
    FILE *f;
    f=fopen("C:\\input.txt","rt");
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
        fscanf(f,"%d",*(num+i));
    fclose(f);
}
void Output(int *num, int n)
{
	printf("\nThe result of reading file:\n\n");
    for(int i=0;i<n;i++)
    printf("%3d",*(num+i));
}
bool IsPrime(int *num)
{
    if (*num < 2)
        return false;
    for (int i = 2; i <= sqrt(*num); i++)
    {
        if (*num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void Prime(int *num,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (IsPrime(num+i))
        {
        	printf("PRIME NUMBERS\n");
            printf("%d\t", *(num+i));
        }
    }
 
}
int main()
{
	int n, *num;
	FILE *fptr = fopen("C:\\input.txt","w");
	printf("Input n: \n");
	scanf("%d", &n);
	num = (int*) malloc(100 * sizeof(int));
	for(int i=0;i<n;++i)
	{
		printf("Input number [%d]: \n", i+1);
		scanf("%d",num+i);	
		fprintf(fptr, "%d\t", *(num+i));
	}
	Readfile(num,n);
	Output(num,n);
	Prime(num,n);
}
