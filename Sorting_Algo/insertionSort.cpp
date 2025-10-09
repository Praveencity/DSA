#include <iostream>
#include <vector>

void print(std::vector<int> &nums)
{
    for(int i:nums) std::cout << i << " ";
    std::cout << std::endl;
}

// Time Complexity:
    // Best Case: O(n)         → when the array is already sorted
    // Average Case: O(n^2)    → typical scenario with random data
    // Worst Case: O(n^2)      → when the array is sorted in reverse order

// Space Complexity: O(1)
// Sorting is done in-place with constant extra space

void insertionSort(std::vector<int> &nums,int n)
{
    for(int i = 1;i<n;i++)
    {
        int j =i;
        while(j>0 && nums[j]<nums[j-1])
        {
            int temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
            j--;
        }
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
    
    insertionSort(v,size);
    
    std::cout << "After Sorting Array : " << std::endl;
    print(v);

    return 0;
}