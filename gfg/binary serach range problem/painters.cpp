#include <iostream>
#include <numeric>

using namespace std;

bool isPossible(vector<int> &arr, int k, int mid)
{
    int painter = 1, boardSum = 0;
    for (auto i : arr)
    {
        if (boardSum + i <= mid)
        {
            boardSum += i;
        }
        else
        {
            painter++;
            if (i > mid || painter > k)
                return false;
            boardSum = i;
        }
    }
    return true;
}

int minTime(vector<int> &arr, int k)
{
    int s = 0, e = accumulate(arr.begin(), arr.end(), 0), ans = -1;
    while (s <= e)
    {
        int mid = s + ((e - s) >> 1);
        if (isPossible(arr, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
   vector<int>arr = {5, 10, 30, 20, 15};
    int k = 3;
    cout << minTime(arr, k) << endl;
    return 0;
}