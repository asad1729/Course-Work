#include <stdio.h>
#define V 4
#define inf 9999
void printSolution(int dist[][V]);
void floydWarshall(int graph[][V])
{
  int dist[V][V];
  int i,j,k;
  for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
        {
          dist[i][j]=graph[i][j];
        }
    }
  for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
        {
          for(k=0;k<V;k++){
            if(dist[i][k]+dist[k][j]<dist[i][j])
              dist[i][j]=dist[i][k]+dist[k][j];
          }
        }
    }
  printSolution(dist);
}
void printSolution(int dist[][V])
{
  printf("The matrix is : \n");
  for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
        {
          if(dist[i][j] == inf)
            printf("%7s", "inf");
          else
            printf("%7d", dist[i][j]);
        }
      printf("\n");
    }
}

int main()
{
  int graph[V][V] = {{0, 9, -4, inf},{6, 0, inf, 2},{inf, 5, 0, inf}, {inf,inf,1,0}};
  floydWarshall(graph);
}