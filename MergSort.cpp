#include<iostream>
using namespace std ;
// void merge(vector<int >&arr,int s,int e,int mid,vector<int >&temp)
// {
//     int i=s,j=e,mainArrayIndex=s;
//     while(i<=mid && j<=e)
//     {
//         if(arr[i]<arr[j]) temp[mainArrayIndex++]=arr[i++];
//         else temp[mainArrayIndex++]=arr[j++];
//     }
//     while(i<=mid) arr[mainArrayIndex++]=arr[i++];
//     while(j<=e) arr[mainArrayIndex++]=arr[j++];
// }
void inplaceMerge(vector<int >&arr,int s,int e,int mid)
{
    int totallen=e-s+1;
    int gap=totallen/2 + totallen%2;
    while(gap>0)
    {
        int i=s,j=s+gap;
        while(j<=e)
        {   
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
            i++;j++;
        }
        gap= gap<=1 ? 0: gap/2 + gap%2;
    }
}

void mergesort(vector<int >&arr,int s,int e)
{
    if(s>=e) return ;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    inplaceMerge(arr,s,e,mid);
}

int main()
{
    vector<int> arr={10,40,30,20,60,50};
    mergesort(arr,0,arr.size()-1);
    for(int i:arr) cout<<i<<" ";
    return 0;
}