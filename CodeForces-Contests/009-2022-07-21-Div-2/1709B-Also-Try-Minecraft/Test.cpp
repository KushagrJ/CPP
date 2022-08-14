/*

 * https://codeforces.com/blog/entry/105164

 */





#include <iostream>
#include <vector>


int main()
{

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> v(n+1);
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];

    std::vector<long long> v_forward(n+1);
    v_forward[1] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (v[i+1] < v[i])
            v_forward[i+1] = (v_forward[i] + (v[i] - v[i+1]));
        else
            v_forward[i+1] = v_forward[i];
    }

    std::vector<long long> v_backward(n+1);
    v_backward[n] = 0;
    for (int i = n; i > 1; --i)
    {
        if (v[i-1] < v[i])
            v_backward[i-1] = (v_backward[i] + (v[i] - v[i-1]));
        else
            v_backward[i-1] = v_backward[i];
    }

    while (m--)
    {
        int s, t;
        std::cin >> s >> t;

        if (s < t)
            std::cout << (v_forward[t] - v_forward[s]) << '\n';
        else
            std::cout << (v_backward[t] - v_backward[s]) << '\n';
    }

    return 0;

}
