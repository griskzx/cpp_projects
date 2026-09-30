# 单链表与节点模板

[node.hpp](node.hpp) 定义带有 C++20 `std::default_initializable` 约束的节点模板。
[list.hpp](list.hpp) 和 [list.cpp](list.cpp) 实现保存 `Node<std::uint32_t>` 的单链表，
[main.cpp](main.cpp) 演示插入、只读遍历和 Result 错误处理。

插入位置从 0 开始，有效范围为 `[0, 节点数]`：0 表示头插，节点数表示尾插。
空节点或越界位置返回错误，原有链接保持不变。

这是非拥有型链表，节点由调用者创建和管理。节点必须比链表活得更久；
同一个节点不能重复插入，也不能同时属于多个链表。
示例把节点放在栈上，不涉及动态内存分配。

在仓库根目录执行（首次运行先执行 `cmake -S . -B build`）：

```bash
cmake --build build --target linked_list_example
./build/bin/linked_list_example
```

预期输出：

```text
list: 12 -> 13 -> 15 -> null
insert at index 10: index is out of range
insert nullptr: node pointer is null
```

插入边界测试位于 [insert_test.cpp](insert_test.cpp)。默认启用测试时可单独运行：

```bash
cmake --build build --target list_insert_test
ctest --test-dir build -R '^list_insert_test$' --output-on-failure
```

练习：添加节点计数或按索引查找功能；尝试画出插入前后各节点的 `next` 指向。
