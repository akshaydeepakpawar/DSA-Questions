#include<iostream>
using namespace std ;
long merge(vector<int >&arr,vector<int >&temp,int s,int e,int mid)
{
    int i=s,j=mid+1,tempIndex=s;
    long c=0;
    while(i<=mid&&j<=e)
    {
        if(arr[i]<=arr[j]) temp[tempIndex++]=arr[i++];
        else{
            c+=mid-i+1;
             temp[tempIndex++]=arr[j++];
        }
    }
        
    while(i<=mid)
    {
        temp[tempIndex++]=arr[i++];
    }
    while(j<=e)
    {
        temp[tempIndex++]=arr[j++];
    }
    
    while(s<=e)
    {
        arr[s]=temp[s];
        ++s;
    }
    return c;
}

long mergeSort(vector<int >&arr,vector<int >&temp,int s,int e)
{
    long c=0;
    if(s>=e) return 0;
    int mid=s+(e-s)/2;
    c+=mergeSort(arr,temp,s,mid);
    c+=mergeSort(arr,temp,mid+1,e);
    c+=merge(arr,temp,s,e,mid);
    return c;
}


long countInversions(vector<int> arr) {
    int n=arr.size();
    vector<int>temp(n);
    long c=mergeSort(arr,temp,0,n-1);
    return c;
}

int main()
{
return 0;
}