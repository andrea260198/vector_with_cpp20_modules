import my_module;
import std;


int main()
{
    my_ns::Vector<int> v;

    v.push_back(123);
    v.push_back(456);
    v.push_back(789);

    std::cout << v.get(0) << std::endl;
    std::cout << v.get(1) << std::endl;
    std::cout << v.get(2) << std::endl;
}
