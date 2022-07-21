#include <iostream>
#include <cctype>


int main()
{

    int t;
    std::cin >> t;
    getchar();

    while (t--)
    {
        std::string s;

        int c;
        while (((c = getchar()) != '\n') && (c != EOF))
            s += static_cast<char>(toupper(c));

        if (s == "YES")
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;

}
