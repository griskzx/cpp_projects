#include <cstdlib>
#include <iostream>
#include <limits>
#include <string_view>

#include "list.hpp"

namespace {
void require(bool condition, std::string_view message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(EXIT_FAILURE);
    }
}
} // namespace

int main() {
    Node<std::uint32_t> first;
    Node<std::uint32_t> second;
    Node<std::uint32_t> middle;
    Node<std::uint32_t> new_head;
    Node<std::uint32_t> pending;
    Node<std::uint32_t> sentinel;
    pending.set_next(&sentinel);
    List list;

    require(list.insert(nullptr, 0).is_err(), "reject null node in empty list");
    require(list.insert(&pending, 1).is_err(), "reject nonzero index in empty list");
    require(list.insert(&pending, std::numeric_limits<std::size_t>::max()).is_err(),
            "reject largest possible index");
    require(list.head_ptr() == nullptr && pending.get_next() == &sentinel,
            "failed insert preserves empty list and incoming node");

    require(list.insert(&first, 0).is_ok(), "insert first node");
    require(list.insert(&second, 1).is_ok(), "append at size");
    require(list.insert(&middle, 1).is_ok(), "insert in middle");
    require(list.insert(&new_head, 0).is_ok(), "insert at head");
    require(list.head_ptr() == &new_head && new_head.get_next() == &first
            && first.get_next() == &middle && middle.get_next() == &second
            && second.get_next() == nullptr, "preserve node order and terminate list");

    require(list.insert(&pending, 5).is_err(), "reject index beyond size");
    require(list.insert(nullptr, 1).is_err(), "reject null node in nonempty list");
    require(list.head_ptr() == &new_head && new_head.get_next() == &first
            && first.get_next() == &middle && middle.get_next() == &second
            && second.get_next() == nullptr && pending.get_next() == &sentinel,
            "failed insert preserves every link");
    return 0;
}
