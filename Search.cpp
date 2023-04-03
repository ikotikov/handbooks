#include <iostream>
#include <vector>
#include <algorithm>


int main () {
    size_t n, m;
    std::cin >> n >> m;
    
    std::vector<int> range(n);
    for (size_t i = 0; i != n; ++i) {
        std::cin >> range[i];
    }
    
    for (size_t i = 0; i != m; ++i) {
        int toFind;
        std::cin >> toFind;
        
        auto upperBound = std::lower_bound(range.begin(), range.end(), toFind);
        
        if (upperBound == range.end()) {
            std::cout << *(std::prev(upperBound)) << std::endl;
        } else if (*upperBound == toFind) {
            std::cout << *upperBound << std::endl;
        } else {
            auto lowerBound = upperBound;
            while (*lowerBound == *upperBound && lowerBound != range.begin()) {
                --lowerBound;
            }
            
            if (!(std::abs(*upperBound - toFind) < std::abs(toFind - *lowerBound))) {
                std::cout << *lowerBound << std::endl;
            } else {
                std::cout << *upperBound << std::endl;
            }
        }
    }
}
