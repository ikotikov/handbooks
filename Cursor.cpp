#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> canvas;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty()) {
        canvas.push_back(line);
    }

    bool shift = false;
    int cut_range = 0;
    std::list<std::string> selector;
    auto cursor = canvas.begin();
    auto cursor_shift = canvas.begin();

    while (std::getline(std::cin, line)) {
        if (line == "Shift") {
            shift = true;
        } else if (line == "Down") {
            if (cursor != canvas.end()) {
                ++cursor;
                if (!shift) {
                    cursor_shift = cursor;
                } else {
                    ++cut_range;
                }
            }
        } else if (line == "Up") {
            if (cursor != canvas.begin()) {
                --cursor;
                if (!shift) {
                    cursor_shift = cursor;
                } else {
                    --cut_range;
                }
            }
        } else if (line == "Ctrl+X") {
            if (cursor_shift == cursor && cursor == canvas.end()) {
                continue;
            }
            selector.clear();
            if (cursor_shift == cursor) {
                auto cut = cursor;
                cursor = std::next(cursor);
                selector.splice(selector.begin(), canvas, cut);
            } else if (cut_range < 0) {
                selector.splice(selector.begin(), canvas, cursor, cursor_shift);
                cursor = cursor_shift;
            } else {
                selector.splice(selector.begin(), canvas, cursor_shift, cursor);
            }   
            shift = false;
            cursor_shift = cursor;
            cut_range = 0; 
        } else if (line == "Ctrl+V") {
            if (!selector.empty()) {
                if (cut_range < 0) {
                    cursor = canvas.erase(cursor, cursor_shift);
                } else if (cut_range > 0) {
                    cursor = canvas.erase(cursor_shift, cursor);
                }
                canvas.insert(cursor, selector.begin(), selector.end());
                shift = false;
                cursor_shift = cursor;
                cut_range = 0; 
            }
        }
    }

    for (const auto& text : canvas) {
        std::cout << text << std::endl;
    }
}