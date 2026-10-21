#include <memory>
#include <print>
import example3;

int main(){
  hello();
  auto head = std::make_unique<singly_linked_list::Node>(1, nullptr);
  auto new_node = std::make_unique<singly_linked_list::Node>(2, nullptr);
  singly_linked_list::push(head, new_node);
  std::println("head->next: {}", head->next->value);
}
