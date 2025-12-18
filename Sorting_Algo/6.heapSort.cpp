#include <bits/stdc++.h>
using namespace std;

// hepify : ? TC : O(logN)
void hepify(vector<int> &v,int n,int i){
    while(true){
        int lar = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left < n && v[lar]< v[left])
            lar = left;
        if(right < n && v[lar]< v[right])
            lar = right;

        if(lar!=i){
            swap(v[lar],v[i]);
            i = lar;
       }
       else return;
    }
}

// Function for Heap sort
void heapSort(vector<int> &v){
    int n = v.size();
    // First make it heap ? TC : O(N).
    for(int i=n/2-1;i>=0;i--){
        hepify(v,n,i); 
    }

    // Then just send root to the end of the heap then hepify it. ? TC : O(NlogN).
    for(int i=n-1;i>=0;--i){
        swap(v[0],v[i]);
        hepify(v,i,0);
    }
}

void print(vector<int> &v){
    for(auto i:v)
        cout << i << ' ';
    cout << '\n'; 
}

int main(){
    vector<int> v({43,21,45,65,2,34,3,42});
    cout << "Original Array: ";
    print(v);
    cout << "After Heap Sort: ";
    heapSort(v); // ? TC : O(NlogN)
    print(v);
    
}

