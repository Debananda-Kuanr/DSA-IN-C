#include <stdio.h>
void merge(int a[],int LB ,int mid,int UB){
    int i=LB;
    int j=mid+1;
    int k=LB;
    int b[100];
    while(i<=mid && j<=UB){
        if(a[i]<=a[j]){
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=UB){
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=LB;i<k;i++){
        a[i]=b[i];
    }
}

void merge_Sort(int a[],int LB,int UB){
    if(LB<UB){
        int mid=(LB+UB)/2;
        merge_Sort(a,LB,mid);
        merge_Sort(a,mid+1,UB);
        merge(a,LB,mid,UB);
    }
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[]={38,27,43,3,9,82,10};
    int n=7;
    printf("Before Sorted:\n");
    display(arr,n);
    printf("After Sorted:\n");
    merge_Sort(arr,0,n-1);
    display(arr,n);
    return 0;
}
