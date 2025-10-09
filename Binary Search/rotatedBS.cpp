#include <bits/stdc++.h>
using namespace std;

// Finds the index of the minimum element in a rotated sorted array. (No Duplicates)

int minValueInRotatedArray(vector<int> &nums)
{
    if(nums.size() == 0) return -1;

    int low = 0, high = nums.size() - 1;

    if(nums[low] <= nums[high]) return 0;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(mid > 0 && nums[mid - 1] > nums[mid])
            return mid;

        if(mid < nums.size() - 1 && nums[mid] > nums[mid+1])
            return mid+1;

        if( nums[low] > nums[mid])
            high = mid - 1;
        
        else
            low = mid + 1;
    }
    return 0;
}

//Second Methord;

int minValueInRotated(vector<int>& nums)
{
    if(nums.size() == 0) return -1;

    int low = 0, high = nums.size() - 1;

    if(nums[low] <= nums[high]) return nums[low];

    int minimum = INT_MAX;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[low] <= nums[mid])
        {
            minimum = min(nums[low],minimum);
            low = mid + 1;
        }
        else
        {
            minimum = min(nums[mid],minimum);
            high = mid - 1;
        }
    }
    return minimum;
}

// Finds the index of the minimum element in a rotated sorted array. (With Duplicates)

int minValueInRotatedWithDuplicate(vector<int>& nums)
{
    if(nums.size() == 0) return -1;

    int low = 0, high = nums.size() - 1;

    int minimum = INT_MAX;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(nums[high] < nums[mid])
        {
            low = mid+1;
        }
        else if(nums[high] > nums[mid])
        {
            minimum = min(nums[mid],minimum);
            high = mid - 1;
        }
        else
        {
            minimum = min(nums[high],minimum);
            high--;
        }
    }
    return minimum;
}

//Searching an element in rotated array (No Duplicates)
int searchInRotatedArray(vector<int> &nums,int val)
{
    if(nums.size() == 0) return -1;

    int low = 0,high = nums.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == val) return mid;

        if(nums[mid] >= nums[low])
        {
            if(nums[low] <= val && val < nums[mid])
                high = mid - 1;
            else 
                low = mid + 1;
        }
        else{
            if(nums[mid] < val && val <= nums[high])
                low = mid + 1;
            else 
                high = mid -1;
        }
    }
    return -1;
}

//Searching an element in rotated array (Contains Duplicates)
int searchRotatedWithDuplicates(vector<int> &nums,int val)
{
    if(nums.size() == 0) return -1;

    int low = 0,high = nums.size() - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(val == nums[mid]) return mid;

        if(nums[mid]== nums[low] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }
        if(nums[mid] >= nums[low])
        {
            if(nums[low] <= val && val < nums[mid])
                high = mid - 1;
            else 
                low = mid + 1;
        }
        else{
            if(nums[mid] < val && val <= nums[high])
                low = mid + 1;
            else 
                high = mid -1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int minIndex1 = minValueInRotatedArray(nums1);
    cout << "The array is: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "The minimum element is at index: " << minIndex1 << " (value: " << nums1[minIndex1] << ")" << endl;
    cout << minValueInRotated(nums1) << endl;
    cout << "------------------------------------" << endl;

    vector<int> nums2 = {3, 4, 5, 1, 2};
    int minIndex2 = minValueInRotatedArray(nums2);
    cout << "The array is: [3, 4, 5, 1, 2]" << endl;
    cout << "The minimum element is at index: " << minIndex2 << " (value: " << nums2[minIndex2] << ")" << endl;
    cout << "------------------------------------" << endl;

    // Example with a non-rotated array
    vector<int> nums3 = {1, 2, 3, 4, 5};
    int minIndex3 = minValueInRotatedArray(nums3);
    cout << "The array is: [1, 2, 3, 4, 5]" << endl;
    cout << "The minimum element is at index: " << minIndex3 << " (value: " << nums3[minIndex3] << ")" << endl;

    cout << "------------------------------------" << endl;
    // Creates a vector and the target value to search for.
    vector<int> nums4 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;

    // Calls the function and stores the returned index in the 'index1' variable.
    int index1 = searchInRotatedArray(nums4, target1);

    // Checks if the function returned a valid index (-1 means not found).
    if (index1 != -1) {
        // If found, it prints the index.
        cout << "Result: Found at index " << index1 << endl;
    } else {
        // If not found, it says so.
        cout << "Result: Target not found." << endl;
    }

    cout << "------------------------------------" << endl;
    // Creates a new vector with duplicates and a target value.
    vector<int> nums5 = {1, 0, 1, 1, 1};
    int target2 = 0;

    // Calls the specialized function for duplicates.
    int index2 = searchRotatedWithDuplicates(nums5, target2);

    // Prints the result in the same way.
    if (index2 != -1) {
        cout << "Result: Found at index " << index2 << endl;
    } else {
        cout << "Result: Target not found." << endl;
    }
    return 0;
}
