#include <iostream>
using namespace std;

void heapify(int index,int size,int arr[])
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(largest,size,arr);
    }
}

void sortArray(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(0,i,arr);
    }
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    //build heap
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,n,arr);
    }
    //Print
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortArray(arr,n);
    //Print
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}