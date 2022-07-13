/*

 * Let's assume that there exists a partitioning of the points into two
   non-empty sets such that all of the points of the first set lie on the first
   line, all of the points of the second set lie on the second line, and the
   two lines are parallel and non-overlapping.

   Now, let a(x1, y1), b(x2, y2) and c(x3, y3) be any 3 points, out of the n
   given points, henceforth referred to as the 'reference points'.
   Then, since there exists an aforementioned partitioning, therefore
   (1) a and b lie on the same line, (2) b and c lie on the same line, or
   (3) a and c lie on the same line.
   [The case where a, b and c all lie on the same line doesn't need to be
    considered separately, as if a, b and c all lie on the same line, then
    all of the above conditions will be simultaneously true]

   In other words, since parallel lines have the same slope, therefore if we
   set the slope to (1) ((y2 - y1) / (x2 - x1)), (2) ((y3 - y2) / (x3 - x2)),
   or (3) ((y3 - y1) / (x3 - x1)), then in at least one of these cases, the no.
   of parallel lines required to cover all of the points must be exactly 2.

   If the slope is set to m, then according to the equation y - mx = c,
   putting in the values of the coordinates of the points will give the
   corresponding values of c, and the no. of distinct values of c thus obtained
   will be the number of distinct parallel straight lines required to cover all
   of the points.

   Now, it is beneficial to choose 3 consecutive points as the reference
   points, as then the value of the denominator when calculating the slope will
   either be 1 or 2, meaning that either 1 or 0.5 will be multiplied with the
   numerator to obtain the slope, and since any integral multiple of 1 or 0.5
   results in a number which is exactly representable in IEEE floating-point
   format, therefore choosing 3 consecutive points guarantees that the required
   floating-point calculations will always be accurate.

 */





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
