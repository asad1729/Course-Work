#include<stdio.h>
#include<stdlib.h>
int maximum(int a, int b, int c)
{
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  return c;
}
int center(int a[],int low,int mid, int high)
{
    int sum=0;
    int max_left=-1000000;
    for(int i=mid;i>=low;i--)
    {
        sum=sum+a[i];
        if(sum>max_left)
           max_left=sum;
    }
    sum=0;
    int max_right=-1000000;;
    for(int i=mid+1;i<=high;i++)
    {
      sum=sum+a[i];
      if(sum>max_right)
         max_right=sum;
    }
    return (max_left+max_right);
    
}
int max_subarray(int a[], int low, int high)
{
    if (high == low) 
  {
    return a[high];
  }
    int mid=low+high/2;
    int left_sub=max_subarray(a,low,mid);
    int right_sub=max_subarray(a,mid+1,high);
    int center2 = center(a, low, mid, high);

    return maximum(left_sub,right_sub,center2);
}
int main()
{
    int a[]={2,-3,4,6, 8,9};
    int ans=max_subarray(a,0,5);
    printf("Maximum subarray sum : %d",ans);
    return 0;
}
