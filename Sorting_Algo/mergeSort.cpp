#include <iostream>
#include <vector>

void print(std::vector<int> &nums)
{
    for(int i:nums) std::cout << i << " ";
    std::cout << std::endl;
}

/*
    Time Complexity:
    - Best Case: O(n log n)
    - Average Case: O(n log n)
    - Worst Case: O(n log n)
    → Due to recursive division (log n) and merging (n)

    Space Complexity:
    - O(n) → Due to use of temporary vector in merge step
    → Not in-place; requires auxiliary space equal to the input size
*/

void merge(std::vector<int> &nums,int low,int mid,int high)
{
    std::vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high)
    {
        if(nums[left]<nums[right]) temp.push_back(nums[left++]);
        else temp.push_back(nums[right++]); 
    }

    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);

    for(int i = low;i<=high; i++) nums[i] = temp[i-low];
}

void mergeSort(std::vector<int> &nums, int low, int high)
{
    if(low<high)
    {
        int mid = (low + high)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}

int main()
{
    std::vector<int> v;
    int x;
    std::cin >> x;
    int size = x;
    while(x--)
    {
        int i;
        std::cin >> i;
        v.push_back(i);
    }
    std::cout << "Before Sorting Array : " << std::endl;
    print(v);
    
    mergeSort(v,0,size-1);
    
    std::cout << "After Sorting Array : " << std::endl;
    print(v);

    return 0;
}