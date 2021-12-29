#include <stdio.h>
void bucket_sort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int bucket[max], i;
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}
int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array values\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("----------------\nSorted Array\n---------------\n");
    bucket_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}