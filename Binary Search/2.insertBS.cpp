#include <bits/stdc++.h>
using namespace std;

//Simply it is upper bound ..
void insertEle(vector<int> &nums,int el)
{
    int low = 0,high = nums.size() - 1;
    int index = nums.size();
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] > el)
        {
            index = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    nums.insert(nums.begin() + index, el); //To insert at that position
}

int main()
{
    vector<int> v = {1, 2, 4, 4, 5, 6, 8};
    insertEle(v, 0);  // Insert 3 in sorted order

    for (int x : v) cout << x << " ";
    return 0;
}