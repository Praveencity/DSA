#include <bits/stdc++.h>
using namespace std;


// Using Fully Binary Search
int firstOccurrence(vector<int> &nums,int val)
{
    int low = 0,high = nums.size() - 1;
    int index = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == val)
        {
            index = mid;
            high = mid - 1;
        }
        else if(nums[mid] > val)
             high = mid - 1;
             
        else low = mid + 1;
    }
    return index;
}

int lastOccurrence(vector<int> &nums,int val)
{
    int low = 0,high = nums.size() - 1;
    int index = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == val)
        {
            index = mid;
            low = mid + 1;
        }
        else if(nums[mid] > val)
             high = mid - 1;
             
        else low = mid + 1;
    }
    return index;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int val = 2;

    int first = firstOccurrence(nums, val);
    int last = lastOccurrence(nums, val);

    if (first != -1)
        cout << "First Occurrence: " << first << "\nLast Occurrence: " << last << endl;
    else
        cout << "Element not found.\n";

    cout << "Total Occurrence : " << last - first + 1 << endl;


    //Using Upper and lower bound
    first = lower_bound(nums.begin(), nums.end(), val) - nums.begin();
    last = upper_bound(nums.begin(), nums.end(), val) - nums.begin() - 1;
    
    if (first <= last && nums[first] == val) {
        int count = last - first + 1;
        cout << "First Occurrence: " << first << endl;
        cout << "Last Occurrence: " << last << endl;
        cout << "Total Occurrences: " << count << endl;
    }
    else
    {
        cout << "Element not found.\n";
    }

    return 0;
}