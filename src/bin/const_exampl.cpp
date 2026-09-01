//
// Created by HP on 2026/9/1.
//
#include <iostream>

#include "../tools/inc/tools.hpp"

int main() {
    int a = 10;
    int b = 12;
    //从又往左读
    // const int* p == int const* p 指针本身指向可以变动，但指向的值不能修改
    const int *p = nullptr;
    p = &a;
    std::cout << "ptr -> a: " << *p << std::endl;
    p = &b;
    std::cout << "ptr -> b: " << *p << std::endl;
    // 此处报错
    // *p = 15;
    b = 15;
    // std::cout << "指针指向的内容无关可变性，即不能通过指针修改指向对象，但原对象本身是否可以被修改对const T* 无影响 " << b << std::endl;
    std::cout <<
            "Content-independent mutability of the pointer, \r\n "
            "i.e., the pointer object cannot be modified by the pointer, \r\n "
            "but whether the original object itself can be modified has no effect on const T*.  "
            << b << std::endl;

    separator();

    //  int* const  ptr
    int *const ptr = &b;
    std::cout << "int *const ptr = &b;" << std::endl;
    std::cout << "const modifies the variable itself, in this case a pointer variable \r\n" <<
            "*ptr = 15 is ok \r\n" << "p = &a is failed" << std::endl;
}
