#include<iostream>
#include<vector>
#include <algorithm>
using namespace std ;

bool isPossible(int n,int m,vector<int>&arr,int mid)
{
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid)
        {
        sum+=arr[i]-mid;
        }
    }
    return sum>=m;
}

int solution(int n,int m,vector<int>&arr)
{
    int s=0,e=*max_element(arr.begin(),arr.end()),ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(isPossible(n,m,arr,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    return ans;
}

int main()
{
    long long  m;
    int n;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=solution(n,m,arr);
    cout<<ans<<endl;
    return 0;
}