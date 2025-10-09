#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums,int value)
{
    int low = 0,high = nums.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2; //To prevent from overflow error
        if(nums[mid] == value) return mid;
        else if(nums[mid] > value) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    //Sorted Array 
    vector<int> v = {1,1,2,5,8,9,23,56};

    cout << "23 is in the index : " << binarySearch(v,23) << endl;
}