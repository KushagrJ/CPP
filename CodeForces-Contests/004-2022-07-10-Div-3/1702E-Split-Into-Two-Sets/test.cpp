/*

 * It is given that every integer is greater than or equal to 1 and less than or
   equal to n.

   Since 2n integers are entered, therefore in order for the answer to be "YES",
   every integer from 1 to n must occur exactly twice.
   This is because if an integer occurs more than 2 times, then the answer will
   definitely be "NO", and if an integer occurs less than 2 times, then there
   will definitely be some other integer occurring more than 2 times, making the
   answer "NO".

   Also, if a domino contains the same integer twice, then also the answer will
   be "NO".

   Now, if every integer occurs exactly twice, and if no domino contains the
   same integer twice, then we move on.

   Since every integer occurs exactly twice, and no domino contains the same
   integer twice, therefore if the integers are considered as vertices and the
   dominoes are considered as edges, then one or more cycles will always get
   formed. Also, the corresponding graph will consist only of separate cycles,
   and there will be no interior connections between the vertices.

   For eg., if the input integers are 1 2, 5 6, 2 3, 4 5, 8 4, 1 3, 7 6, 8 7,
   then the corresponding graph will look like this -

    ---       ---       ---         ---       ---       ---       ---       ---
   | 1 | --- | 2 | --- | 3 |       | 4 | --- | 5 | --- | 6 | --- | 7 | --- | 8 |
    ---       ---       ---         ---       ---       ---       ---       ---
     |                   |           |                                       |
      -------------------             ---------------------------------------

   Here, no interior connections means that 4 will not be adjacent to 6,
   4 will not be adjacent to 7, 5 will not be adjacent to 7, and so on.

   Now, the aim is to colour the edges of the graph such that no two adjacent
   edges are coloured using the same colour.
   If the edges of the graph can be coloured using exactly 2 colours, then the
   answer will be "YES", i.e. the dominoes can be divided into exactly 2 sets so
   that all the numbers on the dominoes of each set are different.
   Otherwise, the answer will be "NO".

   In order to check whether the edges of the graph can be coloured using
   exactly two colours, a disjoint sets data structure can be used.
   Initially, every vertex will form a separate set.
   Then, for every input a b, the sets containing a and b will be united.
   At the end, if every set consists of even number of vertices, then the answer
   will be "YES".
   Otherwise, the answer will be "NO".

 */





#include <iostream>
#include <vector>
#include <algorithm>


void unite(int, int, std::vector<int>&, std::vector<int>&);


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> link(n+1);
        for (int i = 1; i <= n; ++i)
            link[i] = i;

        std::vector<int> size((n+1), 1);

        std::vector<int> count((n+1), 0);

        bool input_is_definitely_faulty = false;

        for (int i = 1; i <= n; ++i)
        {
            int a, b;
            std::cin >> a >> b;

            if (a == b)
                input_is_definitely_faulty = true;

            ++(count[a]);
            ++(count[b]);

            if ((count[a] > 2) || (count[b] > 2))
                input_is_definitely_faulty = true;

            unite(a, b, link, size);
        }

        if (input_is_definitely_faulty)
        {
            std::cout << "NO\n";
        }

        else
        {
            for (int i = 1; i <= n; ++i)
            {
                // i.e. if i is the representative.
                if (link[i] == i)
                {
                    // i.e. if size[i] is odd.
                    if (size[i] & 1)
                    {
                        std::cout << "NO\n";
                        goto end;
                    }
                }
            }

            std::cout << "YES\n";

            end: ;
        }
    }

    return 0;

}


void unite(int a, int b, std::vector<int>& link, std::vector<int>& size)
{

    int x = link[a];
    while (x != link[x])
        x = link[x];

    int y = link[b];
    while (y != link[y])
        y = link[y];

    if (x != y)
    {
        if (size[x] > size[y])
            std::swap(x, y);

        size[y] += size[x];
        link[x] = y;
    }

}
