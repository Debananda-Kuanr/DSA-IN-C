#include <stdio.h>
int partition(int arr[],int L,int H){
    int pivot = arr[L];
    int i = L;
    int j = H;
    int temp;
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[L] = arr[j];
    arr[j] = pivot;
    return j;
}

void quicksort(int arr[],int L,int H){
    int partition_position;
    if(L<H){
        partition_position = partition(arr,L,H);
        quicksort(arr,L,partition_position-1);
        quicksort(arr,partition_position+1,H);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    printf("Before Sorted:\n");
    display(arr,n);

     printf("After Sorted:\n");
     quicksort(arr,0,n-1);
     display(arr,n);


    return 0;
}