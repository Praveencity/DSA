#include <bits/stdc++.h>
using namespace std;

int hmtRotated(vector<int> &nums)
{
    int index = 0;
    int mini = INT_MAX;
    int low = 0, high = nums.size() - 1;

    while(low<=high)
    {
        int mid = low + (high - low)/2;
        
        if(nums[mid] < nums[high])
        {
            if(nums[mid] <= mini)
            {
                mini = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
        else if(nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            if(nums[mid] <= mini)
            {
                mini = nums[mid];
                index = mid;
            }
            high--;
        }
    }

    return index;
}

int main()
{

}