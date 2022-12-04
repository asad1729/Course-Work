#include<stdio.h>
void merge(int a[], int mid,int lb, int ub);
void mergesort(int a[], int lb, int ub);
void printArray(int a[], int n);
void merge(int a[], int lb,int mid, int ub)
{
    int n1=mid-lb+1;
    int n2=ub-mid;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){
        left[i]=a[lb+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=a[mid+i+1];
    }

    int i=0,j=0;
    int k = lb;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
            k++;
        }
        else if(right[j]<left[i])
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        k++;
        i++;

    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;

    }

}
void mergesort(int a[], int lb, int ub)
{
    if(lb<ub){
        int mid=lb + (ub-lb)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);

        merge(a,lb,mid,ub);
    }
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int a[]={12,34,11,4,56,42,10};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Array before sorting : ");
    printArray(a, n);
    printf("Array after sorting : ");
    mergesort(a, 0 ,n-1);
    printArray(a,n);
    return 0;
}