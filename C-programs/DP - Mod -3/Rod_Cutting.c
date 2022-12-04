#include <stdio.h>
int solution(int price[], int n1);
int main(void){
  int n;
  printf("Enter the size of the array : ");
  scanf("%d", &n);
  int price[n+1];
  printf("enter the size of the array : ");
  for(int i=1;i<=n;i++){
  scanf("%d", &price[i]);
  }
  int ans= solution(price,n);
  printf("Maximum Profit : ");
  printf( "%d", ans);
  return 0;
}
int solution(int price[], int n1)
{
   int n=n1+1;
   int dp[n+1];
   dp[0]=0;
   dp[1]=price[1];
   for(int i=2;i<n;i++)
     {
       dp[i]=price[i];
       int li=1;
       int ri=i-1;
       while(li<=ri)
         {
           if(dp[li]+dp[ri]>dp[i])
             dp[i]=dp[li]+dp[ri];
           li++;
           ri--;
         }
       
     }
  return dp[n-1];
}