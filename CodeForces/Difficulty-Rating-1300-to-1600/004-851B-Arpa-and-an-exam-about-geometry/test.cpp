/*

 * For the question to have a solution, the points a, b and c must lie on a
   circle and the distance between a and b must be equal to the distance
   between b and c.

   Three points lie on a circle if and only if they are not collinear.

 */





#include <iostream>


int main()
{

    long long ax, ay, bx, by, cx, cy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy;

    long long d1 = (bx - ax), d2 = (by - ay), d3 = (cx - bx), d4 = (cy - by);

    if (((d2 * d3) != (d1 * d4)) &&
           (((d1 * d1) + (d2 * d2)) == ((d3 * d3) + (d4 * d4))))
    {
        std::cout << "Yes\n";
    }

    else
    {
        std::cout << "No\n";
    }

    return 0;

}
