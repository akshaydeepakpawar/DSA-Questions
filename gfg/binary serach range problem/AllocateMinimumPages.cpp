#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSol(vector<int> &arr, int &k,int &mid)
{
    int sum=0,count=1;
    for(int i=0;i<arr.size();i++)
    {
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else {
            count++;
           if(count>k || arr[i]>mid) return false;
            sum=arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k)
{
    if(k>arr.size()) return -1;
    int s=0,e=accumulate(arr.begin(),arr.end(),0),ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(isPossibleSol(arr,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {
        12, 34, 67, 90};
    int k=2;
    cout<<findPages(arr,k);
    return 0;
}