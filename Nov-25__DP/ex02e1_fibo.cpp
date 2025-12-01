#include <cstddef>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t n,b = 0,a = 1,c;
    std::cin >> n;
    if (n <= 1) {
        std::cout << n; 
        return 0;
    }
    for (size_t i = 2; i <= n; i++) {
        c = b + a;
        b = a;
        a = c;
    }
    std::cout << c;
    return 0;
}