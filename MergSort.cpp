#include<iostream>
using namespace std ;
void merge(vector<int >&arr,int s,int e,int mid,vector<int >&temp)
{
    int i=s,j=e,mainArrayIndex=s;
    while(i<=mid && j<=e)
    {
        if(arr[i]<arr[j]) temp[mainArrayIndex++]=arr[i++];
        else temp[mainArrayIndex++]=arr[j++];
    }
    while(i<=mid) arr[mainArrayIndex++]=arr[i++];
    while(j<=e) arr[mainArrayIndex++]=arr[j++];
}

void mergesort(vector<int >&arr,int s,int e,vector<int >&temp)
{
    if(s>=e) return ;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid,temp);
    mergesort(arr,mid+1,e,temp);
    merge(arr,s,e,mid,temp);
}

int main()
{
    vector<int> arr={10,40,30,20,60,50};
    vector<int> temp(arr.size());
    mergesort(arr,0,arr.size()-1,temp);
    for(int i:arr) cout<<i<<" ";
    return 0;
}