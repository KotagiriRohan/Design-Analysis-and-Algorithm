#include<stdio.h>
int binary_search_iterative(int a[], int x, int n){ 
    int lb =0, ub = n-1; 
    while(lb<=ub){ 
        int mid = ub + (lb-ub)/2; 
        if(a[mid] == x){ 
            return mid; 
        }
        else if(a[mid] < x){ 
            lb = mid+1; 
        } else{ 
            ub = mid-1; 
        } 
    }
    return -1; 
}

int binary_search_recursive(int a[],int x,int lb,int ub){ 
    if(lb <= ub){ 
        int mid = ub +(lb-ub)/2; 
        if(a[mid] == x){ 
            return mid; 
        } 
        else if(a[mid] < x){ 
            return binary_search_recursive(a,x,mid+1,ub); 
        } 
        else{ 
            return binary_search_recursive(a,x,lb,mid-1); 
            } 
        } 
        else{ 
            return -1; 
        }
}
int main(int argc, char const *argv[])
{
    int n,num;
    printf("Enter the length of the array: "); 
    scanf("%d",&n); 
    int a[n]; 
    printf("Enter the values of the array:\n ");
    for(int i=0;i<n;i++){ 
        scanf("%d",&a[i]); 
    } 
    printf("Enter the number to be searched: "); 
    scanf("%d",&num);

    printf("Using recursive binary search %d",binary_search_recursive(a,num,0,n-1));
    printf("Using iterative binary search %d",iterative_binary_search_recursive(a,num,n));
    return 0;
}
