#include <iostream>
using namespace std;
void QuickSort(vector<int> &nums, int low, int high)
{
    // the low and high taken as the reffrence of main array
    // we are not changing the low and high its used for the partition only
    // we taken the s and e for the swaping the elements
    if (low >= high)
        return;
    int s = low, e = high, mid = s + (e - s) / 2, pivot = nums[mid];
    while (s <= e)
    {
        // reason if we already sorted it will not swap
        while (nums[s] < pivot)
            s++;
        while (nums[e] > pivot)
            e--;
        // start and end both are voilating the condition so swap both
        if (s <= e)
            swap(nums[s++], nums[e--]);
    }
    // now my pivot is at my correct index , please sort two halves now
    QuickSort(nums, low, e);
    QuickSort(nums, s, high);
}
int main()
{
    vector<int> arr = {7, 2, 1, 8, 6, 3, 5, 4};
    QuickSort(arr, 0, arr.size() - 1);
    for(int i: arr){
        cout<<i<<" ";
    }
    return 0;
}
