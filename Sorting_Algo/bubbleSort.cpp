#include <iostream>
#include <vector>

void print(std::vector<int> &nums)
{
    for(int i:nums) std::cout << i << " ";
    std::cout << std::endl;
}

// Time Complexity:
// Best Case: O(n)       → when the array is already sorted (with optimization flag).
// Average Case: O(n^2)
// Worst Case: O(n^2)    → when the array is sorted in reverse order.
// Explanation: Two nested loops – outer loop runs n times, inner loop up to n - 1 times.

// Space Complexity: O(1) → Sorting is done in-place with no extra memory used.

void bubbleSort(std::vector<int> &nums,int n)
{
    for(int i = n - 2; i>=0;i--)
    {
        int flag = true;
        for(int j = 0; j <= i; j++)
        {
            if(nums[j]>nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                flag = false;       // if it does not run then time complexity is O(n)
            }
        }
        if(flag) break;
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
    
    bubbleSort(v,size);
    
    std::cout << "After Sorting Array : " << std::endl;
    print(v);

    return 0;
}