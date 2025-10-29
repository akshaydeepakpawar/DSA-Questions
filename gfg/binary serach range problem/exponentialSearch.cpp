#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int> arr,int s,int e,int target)
{
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) e=mid-1;
        else s=mid+1;
    }
    return -1;
}

int main() {
    vector<int> arr={3,2,5,6,11,13,14,15,56,70};
    int n=arr.size(),target=13,i=1;
    if(arr[0]==target) i=0;
    while(i<n && arr[i]<target)     i=i<<1;
    cout<<solve(arr,i/2,min(i,n-1),target)<<endl;
    return 0;
}

// applications :
// 1. search in unbounded/infinite array which is sorted
// 2. better then bs when x present in beginning