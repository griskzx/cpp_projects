module;

#include <memory>
#include <utility>

export module example3;

export void hello();

export namespace singly_linked_list{

    struct Node{
        int value;
        std::unique_ptr<Node> next;
    };

    auto push(std::unique_ptr<Node> &head,std::unique_ptr<Node> &new_node){
        head->next =std::move(new_node);
    }


}