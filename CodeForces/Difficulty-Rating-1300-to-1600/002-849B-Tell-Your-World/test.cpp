#include <iostream>
#include <vector>
#include <unordered_set>


bool is_a_possible_slope(const std::vector<int>&, int, double);


int main()
{

    int n;
    std::cin >> n;

    std::vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i];

    if (is_a_possible_slope(v, n, (v[2] - v[1])))
        std::cout << "Yes\n";
    else if (is_a_possible_slope(v, n, (v[3] - v[2])))
        std::cout << "Yes\n";
    else if (is_a_possible_slope(v, n, (0.5 * (v[3] - v[1]))))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;

}


bool is_a_possible_slope(const std::vector<int>& v, int n, double m)
{

    std::unordered_set<double> s;

    for (int i = 1; i <= n; i++)
        s.insert(v[i] - (m * i));

    return (s.size() == 2);

}
