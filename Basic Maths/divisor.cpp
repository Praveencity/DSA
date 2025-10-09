#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    //for(int i = 1; i<=n; i++) if(n%i == 0) std::cout << i << std::endl; // O(N)

    for(int i = 1; i*i <= n; i++) // O(sqrt(N))
    {
        if(n%i == 0)
        {
            std::cout << i << std::endl;
            if(n/i != i)
            {
                std::cout << n/i << std::endl;
            }
        }
    }
}