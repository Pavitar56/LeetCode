//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int start, int mid, int end)
    {
         // Your code here
         
         int *output = new int[end - start + 1];
         
         int i = start;
         int j = mid+1;
         
         int k=0;
         
         while(i <= mid && j <= end)
         {
             
             if(arr[i] <= arr[j])
             {
                 output[k] = arr[i];
                 k++;
                 i++;
             }
             else
             {
                 output[k] = arr[j];
                 k++;
                 j++;
             }
             
         }
         
         
         while(i<=mid)
         {
             output[k] = arr[i];
             i++;
             k++;
         }
         
         while(j<=end)
         {
             output[k] = arr[j];
             j++;
             k++;
         }
         
         k=0;
         for(int m=start;m<=end;m++)
         {
             arr[m] = output[k];
             k++;
         }
         
    }
    public:
    void mergeSort(int arr[], int start, int end)
    {
        //code here
        
        if(start >= end)
        {
            return;
        }
        
        int mid = start + (end-start)/2;
        
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        
        merge(arr,start,mid,end);
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends