#include <iostream>
#include <cmath>

int power(int a,int digit) //Function for Power..
{
    int ans = 1;
    while(digit)
    {
        if(digit%2 == 1)
        {
            ans *= a;
            digit--;
        }
        else
        {
            digit /= 2;
            a = a*a;
        }
    }
    
    return ans;
}

int main()
{
    int x;
    std::cin >> x;
    int check = x;

    int digits = std::log10(x) + 1;
    
    int sum = 0;

    while(x>0) //This loop time complexity is O(log10(N)).
    {
        int a = x%10;
        sum += power(a,digits);
        
        //sum += (int)std::pow(a,digits); Its Not working here due to precision errors when added to sum.
        x /= 10;
    }

    if(sum == check) std::cout << "This is an armstrong number " << std::endl;
    else std::cout << "Not an armstrog number" << std::endl;

}