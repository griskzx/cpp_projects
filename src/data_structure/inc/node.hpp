//
// Created by grisk on 2026/9/1.
//

#ifndef CPP_PROJECT_NODE_HPP
#define CPP_PROJECT_NODE_HPP

#include <concepts>

// 手写版本（与 std::default_initializable<T> 基本等价，二选一即可）：
// template <typename T>
// concept DefaultInitializable = requires { T{}; };

template<std::default_initializable T>
class Node {
public:
    Node() = default;

    auto get_data() {
        return this->data;
    }

    auto get_prev() {
        return this->prev;
    }

    auto get_next() {
        return this->next;
    }

    auto set_data(const T data) {
        this->data = data;
    }

    auto set_prev(Node<T> *_prev) {
        this->prev = _prev;
    }

    auto set_next(Node<T> *next) {
        this->next = next;
    }

private:
    T data{};
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};


#endif //CPP_PROJECT_NODE_HPP
