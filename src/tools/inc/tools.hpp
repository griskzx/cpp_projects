//
// Created by HP on 2026/8/31.
//

#ifndef CPP_PROJECT_TOOLS_HPP
#define CPP_PROJECT_TOOLS_HPP

#include <iostream>

auto add(int a, int b) -> int;

inline auto separator() {
    std::cout << "\r\n" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\r\n" << std::endl;
}
#endif //CPP_PROJECT_TOOLS_HPP
