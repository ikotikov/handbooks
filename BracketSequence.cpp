#include <iostream>
#include <stack>

char Reversed_bracket (char bracket) {
    if (bracket == ')') {
        bracket = '(';
    } else if (bracket == '}') {
        bracket = '{';
    } else if (bracket == ']') {
        bracket = '[';
    }
    return bracket;
}

int main() {
    std::stack<char> brackets;
    char bracket;
    while (std::cin >> bracket) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            brackets.push(bracket);
        } else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (!brackets.empty() && brackets.top() == Reversed_bracket(bracket)) {
                brackets.pop();
            } else { 
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }
    
    if (brackets.empty()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}