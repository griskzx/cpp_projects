#include <iostream>

// 学习点：const 修饰的是指针，还是指针指向的值。
int main() {
    int a = 10;
    int b = 12;

    // const int* 与 int const* 等价：允许改变指向，禁止通过 p 修改值。
    const int* p = &a;
    std::cout << "const int*: a = " << *p << '\n';
    p = &b;
    std::cout << "const int*: b = " << *p << '\n';
    // *p = 15; // 编译错误：不能通过 p 写入。
    b = 15; // b 本身不是 const，仍可以直接修改。
    std::cout << "after b = 15: *p = " << *p << '\n';

    // int* const：禁止改变指向，允许通过 ptr 修改值。
    int* const ptr = &b;
    *ptr = 20;
    // ptr = &a; // 编译错误：ptr 本身是 const。
    std::cout << "int* const: b = " << b << '\n';

    // const int* const：指向和通过指针访问的值都不能修改。
    const int* const fixed = &a;
    // fixed = &b; // 编译错误。
    // *fixed = 30; // 编译错误。
    std::cout << "const int* const: a = " << *fixed << '\n';
    return 0;
}
