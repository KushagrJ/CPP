/*

 * https://codeforces.com/blog/entry/104671

 */





#include <iostream>


bool t_is_a_possible_answer(int*, int, int);


int main()
{

    int a[200001];

    int test_cases;
    std::cin >> test_cases;

    while ((test_cases)--)
    {
        int n, m;
        std::cin >> n >> m;

        std::fill((std::begin(a) + 1), (std::begin(a) + 1 + n), 0);

        for (int i = 0; i < m; ++i)
        {
            int x;
            std::cin >> x;

            ++(a[x]);
        }

        int lo = 1;
        int hi = 1;

        while (true)
        {
            int t = hi;
            if (t_is_a_possible_answer(a, n, t))
                break;

            lo = (hi + 1);
            hi *= 2;
        }

        while (lo < hi)
        {
            int t = (lo + ((hi - lo) / 2));

            if (t_is_a_possible_answer(a, n, t))
                hi = t;
            else
                lo = (t + 1);
        }

        // At this point, lo == hi.
        std::cout << lo << '\n';
    }

    return 0;

}


bool t_is_a_possible_answer(int* a, int n, int t)
{

    int extra_tasks_to_be_done = 0;
    int extra_tasks_that_can_be_done = 0;

    for (int i = 1; i <= n; ++i)
    {
        int min = std::min(a[i], t);
        extra_tasks_to_be_done += (a[i] - min);
        extra_tasks_that_can_be_done += ((t - min) / 2);
    }

    return (extra_tasks_that_can_be_done >= extra_tasks_to_be_done);

}
