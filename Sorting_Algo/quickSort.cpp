#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

void print(std::vector<int> &nums)
{
    for(int i:nums) std::cout << i << " ";
    std::cout << std::endl;
}

/*
    Time Complexity:
    - Best Case:     O(n log n)   → When the pivot splits the array evenly
    - Average Case:  O(n log n)   → For random input
    - Worst Case:    O(n^2)       → When pivot is smallest/largest (already sorted input)

    Space Complexity:
    - O(log n) → Due to recursion stack (in-place sorting, no extra array used)
    - Worst-case space (unbalanced recursion): O(n)
*/

int pivotIndex(std::vector<int> &nums, int low, int high)
{
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i<j)
    {
        while(nums[i] <= pivot && i < high) i++;
        while(nums[j] > pivot && j > low ) j--;
        if(i<j) std::swap(nums[i], nums[j]);
    }
    
    std::swap(nums[low], nums[j]);
    
    return j;
}

void quickSort(std::vector<int> &nums, int low,int high)
{
    if(low < high)
    {
        int p = pivotIndex(nums,low,high);
        quickSort(nums,low,p-1);
        quickSort(nums,p+1,high);

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
    
    quickSort(v,0,size-1);
    
    std::cout << "After Sorting Array : " << std::endl;
    print(v);

    return 0;
}