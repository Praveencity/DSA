#include <iostream>
#include <vector>

void print(std::vector<int> nums)
{
    for(int i:nums) std::cout << i << " ";
    std::cout << std::endl;
}

// Time Complexity: O(n^2)
// Explanation: The outer loop runs (n - 1) times, and the inner loop runs up to (n - i - 1) times.
// Hence, total comparisons = n*(n-1)/2 in the worst, average, and best cases.

// Space Complexity: O(1)
// Explanation: The sorting is done in-place using constant extra space (only a few integer variables used).

void selectionSort(std::vector<int> &nums, int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int minValueIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(nums[minValueIndex] > nums[j]) minValueIndex = j;
        }

        if(minValueIndex != i)
        {
            int temp = nums[i];
            nums[i] = nums[minValueIndex];
            nums[minValueIndex] = temp;
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
    
    selectionSort(v,size);
    
    std::cout << "Array Sorting Array : " << std::endl;
    print(v);

    return 0;
}