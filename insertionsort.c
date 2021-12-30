#include <stdio.h>

void insertionsort(int a[],int n){
    int temp;
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        for (int j = i-1; j >= 0; j--)
        {
            if(key<a[j]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp; 
            }
            else {
                break;
            }
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
    printf("Enter the no of elements");
    scanf("%d",&n);
    printf("enter all the elements to be sorted");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    return 0;
}
