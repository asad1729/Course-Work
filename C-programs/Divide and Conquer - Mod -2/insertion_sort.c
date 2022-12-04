#include<stdio.h>
void insertion(int a[], int n);

int main(){
    int n=5;
    int a[]={23,12,19,2,4};
    printf("Array before sorting : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("Array after sortig : ");
    insertion(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

}
void insertion(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}