#include<stdio.h>

void radixsort(int a[],int n){
    int max = 0;
    for(int i=0;i<n;i++){
        if (a[i] > max) {
            max = a[i];
        }
    }
    int p =1;
    while(max/p != 0){
        countsort(a,n,p);
        p = p*10;
    }
}

void countsort(int a[],int n,int p){
    int countarr[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<n;i++){
        countarr[(a[i]%(p*10))/p]++;
    }
    for(int i=1;i<10;i++){
        countarr[i] = countarr[i] + countarr[i-1];
    }
    for (int i=8;i>=0;i--){
        countarr[i+1] = countarr[i];
    }
    countarr[0] = 0;
    int sortarr[n];
    for (int i=0;i<n;i++){
        sortarr[countarr[(a[i]%(p*10))/p]] = a[i];
        countarr[(a[i]%(p*10))/p]++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i]=sortarr[i];
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements in the array\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Using Radix sort\n");
    radixsort(a, n);
    for (int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}