#include <bits/stdc++.h>
using namespace std;


int merge(int arr[],int temp[],int left,int mid,int right )
{       int count=0;
        int i=left;
        int j=mid;
        int k=left;
        while((i<=mid-1 )&& (j<=right))
        {
            if(arr[i]<arr[j]){
            temp[k++]=arr[i++];}
            else{
            temp[k++]=arr[j];
                count=count+(mid-i);
             }
        }
        while(i<=mid-1) { temp[k++]=arr[i++];}
        while(j<=right)  {  temp[k++]=arr[j++];}

        for (int l = left; l <= right; l++)
        {
            arr[l]=temp[l];
        }
    return count;
}

int mergesort(int arr[],int temp[],int left,int right){
   int mid,count=0;
   
    if (right>left){
     mid=(left+right)/2;
     count+=mergesort(arr,temp,left,mid);
     count+=mergesort(arr,temp,mid+1,right);
    count+=merge(arr,temp,left,mid+1,right);
    }

    return count;

    
}

int main(){

    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans = mergesort(arr,temp,0,n-1);
    cout << " Number of inversions are " << ans;
    return 0;
}



