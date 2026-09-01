//
// Created by HP on 2026/9/1.
//

#ifndef CPP_PROJECT_LIST_HPP
#define CPP_PROJECT_LIST_HPP

#include <cstdint>
#include <string>

#include "../../tools/inc/result.hpp"
#include "../inc/node.hpp"

// 单链表实例化
class List {
public:
    List() = default;

    ~List() = default;

    [[nodiscard]] Result<void, std::string_view> insert(Node<uint32_t> *data, size_t index);

    Node<uint32_t> *head_ptr() const;

private:
    Node<uint32_t> *head_{nullptr};
};


#endif //CPP_PROJECT_LIST_HPP
