//
// Created by grisk on 2026/9/1.
//

#include <cstdint>
#include <iostream>

#include "../data_structure/inc/Node.hpp"

int main() {
    auto node = Node<uint8_t>();
    auto next = Node<uint8_t>();
    node.set_data(12);
    next.set_data(15);
    node.set_next(&next);
    auto v1 =node.get_data();
    auto v2 = next.get_data();
    std::cout << "The first node:node.get_data() " << node.get_data() << std::endl;
    std::cout << "The first node: auto v1 =node.get_data(); " << v1 << std::endl;
    std::cout << "The first node: auto v1 =node.get_data(); " << 12 << std::endl;
    std::cout<<"Second node: node.get_next()->get_data() "<<node.get_next()->get_data()<<std::endl;
}