#include<stdio.h>
#include<stdlib.h>
int cost[20][20];
int done[];
int n;
int total;
int main()
{
  printf("enter the no of cities : ");
  scanf("%d", &n);
  printf("Enter the cost of travelling : ");
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
        scanf("%d",cost[i][j]);
      }
  }
  n=0;
  printf("\n");
  for(int i=0;i<n;i++)
  {
      printf("\n");
      for(int j=0;j<n;j++)
      {
          printf("\t%d",cost[i][j]);
      }
  }
}


