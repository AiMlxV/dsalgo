#include <iostream>
#include <cstddef>   // for size_t
#include <limits>    // for std::numeric_limits

int main() {
    std::cout << "Maximum size_t value: " << std::numeric_limits<size_t>::max() << '\n';
    return 0;
}
