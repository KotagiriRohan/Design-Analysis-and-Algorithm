#include<stdio.h>
void countsort(int a[],int n){
    int countarr[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<n;i++){
        countarr[a[i]]++;
    }
    for(int i=1;i<10;i++){
        countarr[i] = countarr[i] + countarr[i-1];
    }
    for (int i=8;i>=0;i--){
        countarr[i+1] = countarr[i];
    }
    int sortarr[n];
    for (int i=0;i<n;i++){
        sortarr[countarr[a[i]]] = a[i];
        countarr[a[i]]++;
    }
    for (int i=0;i<n;i++){
        printf("%d  ",sortarr[i]);
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
    printf("Using Count sort\n");
    countsort(a,n);
    return 0;
}
