#include <ranges>

import std;
import my_module;


int main()
{
    my_ns::Vector<int> v;

    v.push_back(123);
    v.push_back(456);
    v.push_back(789);
    v.push_back(12);
    v.push_back(23);
    v.push_back(34);
    v.push_back(45);

    for (int k : std::views::iota(0, 7)) {
        std::cout << v.get(k) << std::endl;
    }
}
