#include<iostream>
using namespace std ;
void check(int i,int j,string &s,int n,int &count){
    while(i>=0 && j<n && s[i]==s[j])
    {
        count++;
        i--;j++;
    }
}

int countSubstrings(string s) {
    int count=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        check(i,i,s,n,count); //odd check
        check(i,i+1,s,n,count); //even check
    }
    return count;
}
int main()
{
    cout<<countSubstrings("cat");
    return 0;
}   