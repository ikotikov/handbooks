#include <string_view>

bool NextToken(std::string_view& line, char delim, std::string_view& token) {
    if (line.begin() == line.end()) {
        return false;
    } else {
        auto delim_pos = line.find(delim);    
        token = line.substr(0, delim_pos);
        if (line.size() > delim_pos) {
            line.remove_prefix(delim_pos + 1);
        } else {
            line = std::string_view{};
        }

        return true;
    }
}