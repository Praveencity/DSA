#include <bits/stdc++.h>
using namespace std;

//TODO : Implementation of max heap.
class Heap{
    int *arr;
    int capacity;
    int rear = -1;
    public:
        Heap(int n){
            capacity = n;
            arr = new int[capacity];
        }

        int parent(int idx){
            return (idx-1)/2;
        }

        int leftChild(int idx){
            int a = 2*idx+1;
            return a;
        }

        int rightChild(int idx){
            int a = 2*idx+2;
            return a;
        }

        // ? TC : O(logN)
        void heapifyUp(int idx){
            while (idx > 0) {
                int p = parent(idx);
                    //* For min heap just reverse the conditon
                if (arr[idx] > arr[p]) {
                    swap(arr[idx], arr[p]);
                    idx = p;
                } 
                else
                    return;
            }
        }

        // ? TC : O(logN)
        void heapifyDown(int i){
            while(true){
                int lar = i;
                int left = leftChild(i);
                int right = rightChild(i);
                            //* For min heap just reverse the condition
                if(left<=rear && arr[left]>arr[lar])
                    lar = left;
                if(right<=rear && arr[right]>arr[lar])
                    lar = right;
                
                if(lar!=i){
                    swap(arr[lar],arr[i]);
                    i = lar;
                }
                else
                    return;
                
            }
        }

        void insert(int val){
            if(rear==capacity-1){
                cout << "Heap Overflow\n";
                return;
            }
            arr[++rear] = val;
            heapifyUp(rear);
        }

        void deletion(){
            if(rear==-1){
                cout << "Heap Underflow\n";
                return;
            }

            swap(arr[0],arr[rear]);
            rear--;
            if (rear >= 0) {
                heapifyDown(0);
            }
        }

        int top(){
            if(rear==-1) return -1;
            return arr[0];
        }

        void print(){
            for(int i=0;i<=rear;i++)
                cout << arr[i] << ' ';
            cout << endl;
        }

};

int main(){
    Heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(14);
    h.insert(17);
    h.insert(40);

    h.print();
    h.deletion();
    h.deletion();
    h.print();
    cout << h.top() << endl;

    
}