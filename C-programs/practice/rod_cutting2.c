#include <stdio.h>
int solution(int price[], int n1);
int main(void){
  int n;
  printf("Enter the size of the array : ");
  scanf("%d", &n);
  int price[n+1];
  int r;
  printf("Enter the rod to be sold  : ");
  scanf("%d", &r);
  printf("enter the elements of the array : ");
  for(int i=1;i<=n;i++){
  scanf("%d", &price[i]);
  }
  int ans= solution(price,r);
  printf("Maximum Profit : ");
  printf( "%d", ans);
  printf("\n");
  return 0;
}
int solution(int price[], int r1)
{
   int r =r1+1;
    int dp[r+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=r;i++)
    {
        dp[i]=price[i];
        int li=1;
        int ri=r-1;
        while(li<=ri)
        {
            if((dp[li]+dp[ri]) > dp[i]){
                dp[i]=dp[li]+dp[ri];
            }
            li++;
            ri--;    
        }
    }
    return dp[r-2];
}