#include <iostream>

#include "macro.hpp"

// 学习点：预处理宏、字符串字面量拼接和 ANSI 终端颜色。
int main() {
    std::cout << INFO("This is an info message") << '\n';
    std::cout << WARNING("This is a warning message") << '\n';
    std::cout << ERROR("This is an error message") << '\n';
    return 0;
}
