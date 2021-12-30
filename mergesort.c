#include<stdio.h>
#include<math.h>
void merge(int arr[],int low,int mid,int high){
    int lsize= mid-low+1;int rsize = high-mid;
    int left[lsize],right[rsize];
    for(int i=0;i<lsize;i++){
        left[i] = arr[low+i];
    }
    for(int j=0;j<rsize;j++){
        right[j] = arr[mid+1+j];
    }
    int j=0,i=0,k=low;
    while(j<rsize && i<lsize){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<lsize){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<rsize){
        arr[k] = right[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int low,int high){
    if(low<high){
        int mid = floor((double)high+(low-high)/(double)2);
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    return;
}
int main(){
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("----------\nSorted Array\n---------\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}