#ifndef CPP_EXAMPLES_NODE_HPP
#define CPP_EXAMPLES_NODE_HPP

#include <concepts>

// 模板约束要求 T 可以默认初始化；这是单链表节点，只保存后继指针。
template<std::default_initializable T>
class Node {
public:
    T get_data() const {
        return data_;
    }

    Node<T>* get_next() {
        return next_;
    }

    const Node<T>* get_next() const {
        return next_;
    }

    void set_data(const T& data) {
        data_ = data;
    }

    void set_next(Node<T>* next) {
        next_ = next;
    }

private:
    T data_{};
    Node<T>* next_{nullptr};
};

#endif // CPP_EXAMPLES_NODE_HPP
