/*

 * If the array has more than 2 positive/negative elements, then it is not
   3SUM-closed, as the sum of the largest/smallest 3 elements will not be
   present in the array.

   Also, if the array has more than 1 zero, then we can remove the extra zeroes
   until only 1 zero remains, as any additional zeroes won't change the sums
   that can be formed.

   Thus, the actual testing needs to be done only on an array having at most 5
   elements, which can be done using a brute-force approach.

 */





#include <iostream>


int main()
{

    int arr[7];

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int no_of_positives = 0;
        int no_of_zeroes = 0;
        int no_of_negatives = 0;

        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];

            if (arr[i] > 0)
            {
                if (no_of_positives == 3)
                    --i, --n;
                else
                    ++(no_of_positives);
            }

            else if (arr[i] == 0)
            {
                if (no_of_zeroes == 1)
                    --i, --n;
                else
                    ++(no_of_zeroes);
            }

            else
            {
                if (no_of_negatives == 3)
                    --i, --n;
                else
                    ++(no_of_negatives);
            }
        }

        if ((no_of_positives == 3) || (no_of_negatives == 3))
        {
            std::cout << "NO\n";
        }

        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = (i + 1); j < n; j++)
                {
                    for (int k = (j + 1); k < n; k++)
                    {
                        int sum = (arr[i] + arr[j] + arr[k]);

                        bool sum_is_in_arr = false;

                        for (int l = 0; l < n; l++)
                        {
                            if (sum == arr[l])
                            {
                                sum_is_in_arr = true;
                                break;
                            }
                        }

                        if (!(sum_is_in_arr))
                        {
                            std::cout << "NO\n";
                            goto end_of_loop;
                        }
                    }
                }
            }

            std::cout << "YES\n";

            end_of_loop: ;
        }
    }

    return 0;

}
