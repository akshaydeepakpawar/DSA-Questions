#include<iostream>
using namespace std ;

// First negative in every window of size k (GFG)

 vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        queue<int> q;
        //process first window
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0) q.push(i);
        }
        if(!q.empty()) {
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        } 
        //process remaining
        for(int i=k;i<arr.size();i++)
        {
            if(!q.empty() && i-q.front()>=k){
                q.pop();
            }
            if(arr[i]<0) q.push(i);
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[q.front()]);
            }
        }
        return ans;
    }


int main()
{
    return 0;
}

