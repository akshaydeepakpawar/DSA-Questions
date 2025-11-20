// Square root of number upto given precision
// Given a positive number n and an integer p representing the desired precision, your task is to find the square root of n, accurate to p decimal places. The solution should avoid using built-in square root functions.

// Note: Precision control is required to ensure the output is correctly rounded or truncated at p digits after the decimal.

// Examples:

// Input: n = 50, p = 3
// Output: 7.071
// Explanation: The square root of 50 up to 3 decimal places is 7.071

class Solution {
  public:
  
  int findsqrt(int &n)
  {
      int s=0,e=n,ans=-1;
      while(s<=e)
      {
          int mid=s+((e-s)>>1);
          if(mid*mid<=n)
          {
              ans=mid;
              s=mid+1;
          }
          else e=mid-1;
      }
      return ans;
  }
  double solve(int &n,int &p)
  {
      double sqrt=findsqrt(n);
      double step=0.1;
      while(p--)
      {
          double j=sqrt;
          while(j*j<=n)
          {
              sqrt=j;
              j+=step;
          }
          step/=10;
      }
      return sqrt;
  }
  
    double squareRoot(int n, int p) {
        return solve(n,p);
    }
};