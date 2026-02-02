#include <stdio.h>
float findMax (float a1, float a2, float a3, float a4)
{
	float max=a1;
	if (max<a2) max=a2;
	if (max<a3) max=a3;
	if (max<a4) max=a4;
	return max;
}

float Average (float* start, float* end)
{
	float* this1;
	int num=0;
	float sum=0;
	for (this1=start;this1<=end;this1++)
	{
		sum+=*this1;
		num++;
	}
	return sum/num;
}
int main()
{	
	FILE* indata=fopen("F:\\lab\\lab7\\base\\READING.INF","r");
	if (indata==NULL)
	{
		printf("can't open");
		return 0;
	}
	float highest[31];
	float a1,a2,a3,a4;
	int num=0;
	for (int i=0;fscanf(indata,"%f%f%f%f",&a1,&a2,&a3,&a4) == 4;i++)
	{
		highest[i]=findMax(a1,a2,a3,a4);
		num++;
	}
	fclose (indata);
	printf(" Day          Highest temperature\n");
	printf("---------------------------------\n");
	for (int j=0;j<num;j++)
	{
		printf("%2d.                  %.2f\n",j+1,highest[j]);
	}
	printf("Average of highest in the first 5 day: %.2f\n", Average( (highest+0),(highest+4) ) );
	printf("Average of highest in the last 5 day: %.2f\n", Average( &highest[num-5], &highest[num-1] ));
	return 0;
}