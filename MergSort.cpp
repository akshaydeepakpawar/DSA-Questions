#include<iostream>
using namespace std ;

void merge(vector<int >&arr,int s,int e,int mid)
{
    int leftLength=mid-s+1;
    int rightLength=e-mid;
    vector<int>leftArr(leftLength);
    vector<int>rightArr(rightLength);
    int index=s;
    for(int i=0;i<leftLength;i++)
    {
        leftArr[i]=arr[index++];
    }
    index=mid+1;
    for(int i=0;i<rightLength;i++)
    {
        rightArr[i]=arr[index++];
    }
    int i=0,j=0,mainArrayIndex=s;
    while(i<leftLength && j<rightLength)
    {
        if(leftArr[i]<rightArr[j]) arr[mainArrayIndex++]=leftArr[i++];
        else arr[mainArrayIndex++]=rightArr[j++];
    }
    while(i<leftLength) arr[mainArrayIndex++]=leftArr[i++];
    while(j<rightLength) arr[mainArrayIndex++]=rightArr[j++];
}

void mergesort(vector<int >&arr,int s,int e)
{
    if(s>=e) return ;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e,mid);
}

int main()
{
    vector<int> arr={10,40,30,20,60,50};
    mergesort(arr,0,arr.size()-1);
    for(int i:arr) cout<<i<<" ";
    return 0;
}