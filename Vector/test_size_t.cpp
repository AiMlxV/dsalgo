#include <iostream>
#include <cstddef>   // for size_t
#include <limits>    // for std::numeric_limits

int main() {
    std::cout << "Maximum int value: " << std::numeric_limits<int>::max() << '\n';
    std::cout << "Maximum u_int value: " << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "Maximum ull_int value: " << std::numeric_limits<unsigned long long int>::max() << '\n';
    // std::cout << "Maximum size_t value: " << std::numeric_limits<double>::max() << '\n';
    std::cout << "Maximum size_t value: " << std::numeric_limits<size_t>::max() << '\n';
    return 0;
}
