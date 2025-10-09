#include <bits/stdc++.h>
using namespace std;

//Upper Bound
int upperBound(vector<int> &nums,int val)
{
    int low = 0, high = nums.size() - 1;
    int index = nums.size();
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] > val)
        {
            index = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return index;
}

//Lower Bound
int lowerBound(vector<int> &nums,int val)
{
    int low = 0,high = nums.size() - 1;
    int index = nums.size();
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] >= val)
        {
            index = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return index;
}

int main()
{
    vector<int> nums = {1, 2, 4, 4, 5, 6, 8};
    int val = 4;

    int lb = lowerBound(nums, val);
    int ub = upperBound(nums, val);

    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nValue: " << val << endl;

    cout << "Lower Bound Index (last index with >= " << val << "): " << lb << endl;
    cout << "Upper Bound Index (first index with > " << val << "): " << ub << endl;

    return 0;
}