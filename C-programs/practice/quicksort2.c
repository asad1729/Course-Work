#include<stdio.h>
int partition(int a[], int lb, int hb);
void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}
void quicksort(int a[], int low, int high)
{
    if(low<high)
    {
       int temp=partition(a,low,high);

       quicksort(a,low,temp-1);
       quicksort(a,temp+1,high);
    }
}
int partition(int a[], int low, int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<=pivot)
            i++;
        swap(&a[i],&a[j]);
    }
    swap(&a[i + 1], &a[high]);
        return (i + 1);
}
int main(){
    int a[]={34,23,12,53,2,3,89,11};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Array before sorting : ");
     printArray(a,n);
     quicksort(a,0,n-1);
    printf("Array after sorting : ");
     printArray(a,n);

}