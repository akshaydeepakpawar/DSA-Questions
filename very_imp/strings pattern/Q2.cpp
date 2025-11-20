// same like the Q1 but what if the precision is not given 

#include<iostream>
using namespace std ;

double sqrt(int n)
{
    double s=0,e=n,ans=0;
    while((e-s)>0.0000001) //accurate answer ke liye ye kiya to get int-int =0
    {
        double mid=s+(e-s)/2;
        if(mid*mid<=n)
        {
            ans=mid;
            s=mid;
        }
        else e=mid;
    }
    return ans;
}

int main()
{
    int n=63;
    double ans=sqrt(n);
    printf("\n THE FINAL ANSWER : %.9f \n \n",ans);
    return 0;
}