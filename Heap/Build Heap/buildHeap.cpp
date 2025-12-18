#include<bits/stdc++.h>
using namespace std;

// To get the maximum element in the correct postion.
void heapifyDown(int arr[],int i,int n){
    while(true){
        int lar = i;
        int left = (2*i+1);
        int right = (2*i+2);
    
        if(left<n && arr[left] > arr[lar])
            lar = left;
        if(right<n && arr[right] > arr[lar])
            lar = right;
    
        if(lar!=i){
            swap(arr[lar],arr[i]);
            i = lar;
        }
        else  return;
    }
}

// Function for bulding Max Heap from min heap.
void makeHeap(int arr[],int n){
    for(int i=(n)/2-1;i>=0;i--){
        heapifyDown(arr,i,n);
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main()
{
    int arr[] = {23,45,12,45,7,68,9,56};
    // TODO We Have to convert this to a Heap(Max one).
    int n = sizeof(arr)/sizeof(int);

    cout << "Before : ";
    print(arr,n);

    /*
    1. Time Complexity: O(n)
    It is a common misconception that building a heap is O(nlogn). It is actually linear, O(n)
    */
    makeHeap(arr,n);
    cout << "After making heap : ";
    print(arr,n);

    return 0;
}