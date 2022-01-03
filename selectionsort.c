#include <stdio.h>

void selectionsort(int a[],int n){
    int temp,index;
    for (int i = 0; i < n-1; i++)
    {
        int min;
        for (int j = i+1; j < n; j++)
        {
            if (j == i+1){
                min = a[j];
                index = j;
            }
            if (a[j]<min){
                min = a[j];
                index = j;
            }
        }
        if (min < a[i]){
            a[index] = a[i];
            a[i] = min;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",a[i]); 
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no of elements \t");
    scanf("%d",&n);
    printf("enter all the elements to be sorted \t");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    return 0;
}
