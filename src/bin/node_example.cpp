//
// Created by grisk on 2026/9/1.
//

#include <cstdint>
#include <iostream>

#include "../tools/inc/tools.hpp"
#include "../data_structure/inc/node.hpp"
#include "../data_structure/inc/list.hpp"
#include "../tools/inc/macro.hpp"

int main() {
    auto node = Node<uint32_t>();
    auto next = Node<uint32_t>();
    node.set_data(12);
    next.set_data(15);
    node.set_next(&next);
    auto v1 = node.get_data();
    auto v2 = next.get_data();
    std::cout << "The first node:node.get_data() " << static_cast<int>(node.get_data()) << std::endl;
    std::cout << "The first node: auto v1 =node.get_data(); " << static_cast<int>(v1) << std::endl;
    std::cout << "Second node: node.get_next()->get_data() " << static_cast<int>(node.get_next()->get_data()) <<
            std::endl;

    separator();

    List list{};

    if (auto result = list.insert(&node, 0); result.is_err()) {
        std::cout << "insert failed: " << result.get_error() << std::endl;
    }

    if (auto result = list.insert(&next, 1); result.is_err()) {
        std::cout << "insert failed: " << result.get_error() << std::endl;
    }
    const auto ptr = list.head_ptr();
    std::cout << "The first node: ptr->get_data() " << static_cast<int>(ptr->get_data()) << std::endl;
    std::cout << "Second node: ptr->get_next()->get_data() " << static_cast<int>(ptr->get_next()->get_data()) <<
            std::endl;
    std::cout << INFO("The first node: ptr->get_data() ") << std::endl;
}
