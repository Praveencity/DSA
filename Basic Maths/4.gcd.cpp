#include <iostream>

//This Problem Will be done using Euclidean algorithm

int main()
{
    int a,b;
    std::cin >> a >> b;

    /*
    int min = (a>b) ? b : a;

    // Tc --> O(min(a,b))

    for(int i = min; i>=1 ; i--)
    {
        if(a%i == 0 && b%i == 0) 
        {
            std::cout << i;
            exit(0);
        }
    }
    */

   while(a>0 && b>0)  // O(logϕ(max(a,b)))
   {
       if(a>b) a %= b;
       else b %= a;
   }

   if(a == 0) std::cout << b;
   else std::cout << a;

}