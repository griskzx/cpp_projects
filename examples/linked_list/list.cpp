#include "list.hpp"

Result<void, std::string_view> List::insert(Node<std::uint32_t>* const data,
                                          const std::size_t index) {
    if (data == nullptr) {
        return Err<std::string_view>{"node pointer is null"};
    }

    if (index == 0) {
        data->set_next(head_);
        head_ = data;
        return Ok<void>{};
    }

    auto* previous = head_;
    for (std::size_t current_index = 0;
         current_index < index - 1 && previous != nullptr; ++current_index) {
        previous = previous->get_next();
    }

    // 找不到前一个节点时，先返回错误，避免访问空指针或改变链表。
    if (previous == nullptr) {
        return Err<std::string_view>{"index is out of range"};
    }

    data->set_next(previous->get_next());
    previous->set_next(data);
    return Ok<void>{};
}

Node<std::uint32_t>* List::head_ptr() {
    return head_;
}

const Node<std::uint32_t>* List::head_ptr() const {
    return head_;
}
