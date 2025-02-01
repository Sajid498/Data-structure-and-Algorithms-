#include<iostream>
using namespace std;
#define INFINITY 0x7F7F7F
void combine(int arr[],int low,int mid,int high)
{
    int l=(mid-low)+2;
    int r=(high-mid+1)+2;
int idx=0;
    for(int i=low; i<=mid; i++)
    {
        l[idx++] = arr[i];
    }
    l[idx] = INFINITY;
    int idx=0;
    for(int i=mid+1;i<=high;i++)
    {
        r[idx++]=arr[i];
    }
    r[idx]=INFINITY;
    int i=0;
    int j=0;
    idx=low;
    while(l[i]!=INFINITY||r[j]!=INFINITY)
    {
        if(l[i]<r[j])
        {
            arr[idx]=l[i];
            i++;
        }
        else
        {
            arr[idx]=r[j];
            j++;
        }
        idx++;
    }
}
void merges(int arr[],int low,int high)
{
    int mid=(low+high)/2;
    if(low==high)
    {
        return;
    }
    else
    {
        merges(arr,low,mid);
        merges(arr,mid+1,high);
        combine(arr,low,mid,high);
    }
}
void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main()
{
    int n = 8;
    int arr[n] = {5, 6, 3, 2, 1, 8, 12, 9};

    printArray(arr, n);

    merge_sort(arr, 0, n-1);

    printArray(arr, n);
    return 0;
}
