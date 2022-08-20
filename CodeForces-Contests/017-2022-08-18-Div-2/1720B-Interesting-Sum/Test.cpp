/*

 * https://codeforces.com/blog/entry/106136

 */





#include <iostream>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int largest = 0;
        int second_largest = 0;
        int smallest = 1000000001;
        int second_smallest = 1000000001;

        int n;
        std::cin >> n;

        while (n--)
        {
            int a;
            std::cin >> a;

            if (a >= largest)
            {
                second_largest = largest;
                largest = a;
            }

            else if (a >= second_largest)
            {
                second_largest = a;
            }

            if (a <= smallest)
            {
                second_smallest = smallest;
                smallest = a;
            }

            else if (a <= second_smallest)
            {
                second_smallest = a;
            }
        }

        std::cout << (largest + second_largest - smallest - second_smallest)
                  << '\n';
    }

    return 0;

}
