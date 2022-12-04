#include<stdio.h>
int max(int a, int b)
{
    return a>b? a: b;
}
int knapsack(int W, int wt[], int val[], int n)
{
    int i,w;
    int dp[n+1][W+1];
    for( i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0 || w==0)
               dp[i][w]=0;
            else if(wt[i-1]<=w)
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else 
               dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];
}
int main(){
    int i,  n;
    int val[20];
    int wt[20];
    int w;
    printf("Enter no of items : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter value : ");
        scanf("%d", &val[i]);
        printf("\n");
        printf("Enter weight : ");
        scanf("%d", &wt[i]);
        printf("\n");
    }

    printf("enter size of the knapsack : ");
    scanf("%d" , &w);


    printf("%d", knapsack(w,wt,val,n));
    return 0;

}