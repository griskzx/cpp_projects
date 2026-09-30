#include <iostream>

#include "add.hpp"

// 学习点：头文件声明、源文件定义，以及多个源文件的编译和链接。
int main() {
    std::cout << "add(5, 3) = " << add(5, 3) << '\n';
    return 0;
}
