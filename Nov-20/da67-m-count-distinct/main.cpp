#include "vector.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    CP::vector<int> vec;
    std::string cmd;
    while (true)
    {
        cin >> cmd;
        if (cmd == "p")
        {
            for (auto &x : vec)
            {
                cout << x << " ";
            }
            cout << "\n";
            cout << vec.size() << "\n";
        }
        else if (cmd == "a")
        {
            int X, Y;
            cin >> X >> Y;
            vec.insert(vec.begin() + X, Y);
        }
        else if (cmd == "c")
        {
            int P, Q;
            cin >> P >> Q;
            cout << vec.count_distinct(vec.begin() + P, vec.begin() + Q) << "\n";
        }
        else if (cmd == "q")
        {
            break;
        }
    }
}