#include <stdio.h>
int partitionsort(int *a, int n, int i, int j)
{
    if (i == j)
    {
        return j;
    }
    int pivot = i;
    while (1)
    {
        while (a[j] > a[pivot] && j > pivot)
        {
            j--;
        }
        while (a[i] < a[pivot] && i < n)
        {
            i++;
        }
        if (j == pivot || i == n)
        {
            break;
        }
        if (i < j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            continue;
        }
        else
        {
            int tmp = a[pivot];
            a[pivot] = a[j];
            a[j] = tmp;
            break;
        }
    }
    return j;
}
void quicksort(int *a, int n, int i, int j)
{
    if (i < j)
    {
        int partition = partitionsort(a,n, i, j);
        quicksort(a, n, i, partition - 1);
        quicksort(a, n, partition + 1, n - 1);
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
    printf("\nSorted Array\n");
    quicksort(arr, n, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}