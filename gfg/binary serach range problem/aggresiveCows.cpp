#include<iostream>
using namespace std ;

bool isPossible(vector<int> &arr, int k,int mid)
  {
      int cows=1,lastPos=arr[0];
      for(int i=1;i<arr.size();i++)
      {
          if(arr[i]-lastPos>=mid)
          {
              cows++;
              if(cows==k) return true;
              lastPos=arr[i];
          }
      }
      return false;
  }
  
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int s=0,e=arr.back()-arr.front(),ans=-1;
        while(s<=e)
        {
            int mid=s+((e-s)>>1);
            if(isPossible(arr,k,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else 
                e=mid-1;
        }
        return ans;
    }

int main()
{
    vector<int> arr={
       10, 1, 2, 7, 5
    };
    int k=3;
    cout<<aggressiveCows(arr,k)<<endl;
    return 0;
}