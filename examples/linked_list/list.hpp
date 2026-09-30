#ifndef CPP_EXAMPLES_LIST_HPP
#define CPP_EXAMPLES_LIST_HPP

#include <cstddef>
#include <cstdint>
#include <string_view>

#include "node.hpp"
#include "result.hpp"

// 练习用的非拥有型单链表：节点由调用者管理，链表不分配或释放节点。
// 节点必须比链表活得更久；同一个节点不能重复插入或同时加入多个链表。
class List {
public:
    // index 从 0 开始，有效范围为 [0, 当前节点数]。
    [[nodiscard]] Result<void, std::string_view> insert(Node<std::uint32_t>* data,
                                                      std::size_t index);

    Node<std::uint32_t>* head_ptr();
    const Node<std::uint32_t>* head_ptr() const;

private:
    Node<std::uint32_t>* head_{nullptr};
};

#endif // CPP_EXAMPLES_LIST_HPP
