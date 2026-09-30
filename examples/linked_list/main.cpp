#include <cstdint>
#include <iostream>

#include "list.hpp"

// 学习点：类模板、concept、指针连接、链表插入和 Result 错误处理。
int main() {
    Node<std::uint32_t> first;
    Node<std::uint32_t> second;
    Node<std::uint32_t> middle;
    Node<std::uint32_t> extra;
    first.set_data(12);
    second.set_data(15);
    middle.set_data(13);

    // 节点先声明、链表后声明，离开作用域时链表先销毁。
    List list;
    if (auto result = list.insert(&first, 0); result.is_err()) {
        std::cerr << result.get_error() << '\n';
        return 1;
    }
    if (auto result = list.insert(&second, 1); result.is_err()) {
        std::cerr << result.get_error() << '\n';
        return 1;
    }
    if (auto result = list.insert(&middle, 1); result.is_err()) {
        std::cerr << result.get_error() << '\n';
        return 1;
    }

    const List& view = list;
    std::cout << "list: ";
    for (auto* node = view.head_ptr(); node != nullptr; node = node->get_next()) {
        std::cout << node->get_data() << " -> ";
    }
    std::cout << "null\n";

    // 错误也是预期的学习输出；插入失败不改变原有链表。
    if (auto result = list.insert(&extra, 10); result.is_err()) {
        std::cout << "insert at index 10: " << result.get_error() << '\n';
    }
    if (auto result = list.insert(nullptr, 0); result.is_err()) {
        std::cout << "insert nullptr: " << result.get_error() << '\n';
    }
    return 0;
}
