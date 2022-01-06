#include <stdio.h>

typedef struct GeoPos//type geopos which contains latitude(x) and longitude(y)
{
  double x;
  double y;
}geopos;

void main()
{
	geopos *pos;
	int i=0;
	char c;
	pos=malloc(sizeof(geopos));//making an array of geopos of size 1
	do
	{
		printf("Enter latitude: ");
		scanf("%lf",&pos[i].x);//to input latitude
		printf("Enter longitude: ");
		scanf("%lf",&pos[i].y);//to input longitude
		printf("Enter another geographic location (y/n): ");
		do//to clear the input buffer
		{
			c=getchar();
		}while(c=='\n');
		if(c=='y')
		{
			i++;
			pos=realloc(pos,sizeof(geopos)*(i+1));//to reallocate the space for the array to make it 1 larger
		}
	}while(c=='y');//loops when 'y' is entered
	printf("\nPositions:\n");
	for(int j=0;j<=i;j++)//to print the positions as they were entered
	{
		printf("%lf, %lf\n",pos[j].x,pos[j].y);
	}
	for(int j=0;j<i;j++)//selection sort
	{
		geopos max=pos[j];
		int m=j;
		for(int k=j+1;k<=i;k++)
		{
			if(max.x<pos[k].x)
			{
				max=pos[k];
				m=k;
			}
		}
		geopos temp=pos[j];
		pos[j]=max;
		pos[m]=temp;
	}
	printf("\nPositions:\n");
	for(int j=0;j<=i;j++)//to print the sorted positions
	{
		printf("%lf, %lf\n",pos[j].x,pos[j].y);
	}
	free(pos);
}