#include<stdio.h>
int N, M;
void createAdjMatrix(int adj[N+1][N+1],int arr[M][2])
{
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<N+1;j++)
        {
            adj[i][j]=0;
        }
    }

    for(int i=0;i<M;i++)
    {
        int x=arr[i][0];
        int y=arr[i][1];

        adj[x][y]=1;
        adj[y][x]=1;

    }
}
    void printAdjMatrix(int adj[N+1][N+1])
    {
        for(int i=1;i<N+1;i++){
            for(int j=1;j<N+1;j++)
            {
                printf("%d ", adj[i][j]);
            }
            printf("\n");
        }
    }
    int main(){  
        N=5;
        int arr[][2]={{1,2}, {2,3},{4,5}, {1,5}};
        
        M=sizeof(arr)/sizeof(arr[0]);

        int adj[N+1][N+1];

        createAdjMatrix(adj, arr);

        printAdjMatrix(adj);

        return 0;
    }
