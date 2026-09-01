//
// Created by HP on 2026/9/1.
//
#include <string_view>

#include "../inc/list.hpp"
#include "../../tools/inc/result.hpp"


// 头插法
//Node<uint32_t> *const data,代表此时指针指向不能发生改变。指向内容无关
Result<void, std::string_view> List::insert(Node<uint32_t> *const data, const size_t index) {
    if (data == nullptr) {
        return Err<std::string_view>{"insert data ptr is null"};
    }

    if (index == 0) {
        data->set_next(head_);
        head_ = data;
        return Ok<void>{};
    }

    auto previous = head_;
    for (size_t current_index = 0; current_index < index - 1 && previous != nullptr; current_index++) {
        previous = previous->get_next();
    }

    data->set_next(previous->get_next());
    previous->set_next(data);

    //空链表,
    return Ok<void>{};
}

Node<uint32_t> *List::head_ptr() const {
    return head_;
}
