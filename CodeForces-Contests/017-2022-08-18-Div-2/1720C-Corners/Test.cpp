/*

 * We look at all possible 2x2 blocks.

   If there is at least one 2x2 block having >= 2 zeroes, then the maximum
   number of operations will always be equal to the number of ones.
   This is because we can start our operations with a block having >= 2 zeroes.
   This will make all ones in that block equal to zeroes using 1 operation for
   every one which was originally present in that block.
   Now, since that block now contains all zeroes, thus we can move on to any
   adjacent block which shares 2 cells with this block and we can make all
   ones present in that adjacent block equal to zeroes using 1 operation for
   every one.
   And we can continue doing this until the entire matrix is filled with zeroes.

   Similarly, if the maximum number of zeroes out of all the blocks is equal to
   1, then the number of operations will always be equal to the number of ones
   minus 1.
   This is because that block will contain 3 ones, and the maximum number of
   operations that we can use to convert 3 ones in a block to zeroes is 2.

   Finally, if the maximum number of zeroes out of all the blocks is equal to
   0, then the number of operations will always be equal to the number of ones
   minus 2.

 */





#include <iostream>
#include <vector>
#include <cstdio>


int main()
{

    std::vector<std::vector<int>> v(500, std::vector<int>(500));

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        int number_of_ones = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%1d", &(v[i][j]));

                if (v[i][j] == 1)
                    ++(number_of_ones);
            }
        }

        int maximum_number_of_zeroes_in_a_block = 0;

        for (int i = 0; i < (n-1); ++i)
        {
            for (int j = 0; j < (m-1); ++j)
            {
                int number_of_zeroes_in_current_block = 0;

                if (v[i][j] == 0)
                    ++(number_of_zeroes_in_current_block);

                if (v[i+1][j] == 0)
                    ++(number_of_zeroes_in_current_block);

                if (v[i][j+1] == 0)
                    ++(number_of_zeroes_in_current_block);

                if (v[i+1][j+1] == 0)
                    ++(number_of_zeroes_in_current_block);

                if (number_of_zeroes_in_current_block >
                        maximum_number_of_zeroes_in_a_block)
                {
                    maximum_number_of_zeroes_in_a_block =
                        number_of_zeroes_in_current_block;
                }
            }
        }

        if (maximum_number_of_zeroes_in_a_block >= 2)
            std::cout << number_of_ones << '\n';
        else if (maximum_number_of_zeroes_in_a_block == 1)
            std::cout << (number_of_ones - 1) << '\n';
        else
            std::cout << (number_of_ones - 2) << '\n';
    }

    return 0;

}
