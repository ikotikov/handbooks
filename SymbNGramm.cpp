#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

int main() {
    size_t n, m;
    std::cin >> m >> n;
    
    std::unordered_map<std::string, int> n_gramms;
    
    for (size_t i = 0; i != m; ++i) {
        std::string word;
        std::cin >> word;
        if (word.size() >= n) {
            for (size_t j = 0; j < word.size() - n + 1; ++j) {
                std::string n_grm = word.substr(j, n);
                ++n_gramms[n_grm];
            }
        }
    }
    
    std::vector<std::pair<std::string, int>> sortedByFreq (n_gramms.begin(), n_gramms.end());
    
    std::sort(
            sortedByFreq.begin(),
            sortedByFreq.end(),
            [](const auto& p1, const auto& p2) {
                return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
            });
    
    for (const auto& [n_gramm, freq] : sortedByFreq) {
        std::cout << n_gramm << " - " << freq <<std::endl;
    }
}
