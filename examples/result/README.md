# Result：成功值与错误值

[result.hpp](result.hpp) 用 `std::variant<Ok<T>, Err<E>>` 存储结果。
`Result<T, E>` 的成功分支带有返回值，`Result<void, E>` 的成功分支只表示操作成功。
读取前先检查 `is_ok()` 或 `is_err()`，取错分支会抛出 `std::bad_variant_access`。

[main.cpp](main.cpp) 分别演示除法结果和正数检查，包含成功、失败、只读结果访问。
示例里的错误使用 `std::string_view` 指向字符串字面量，因此这些文本始终有效。

在仓库根目录执行（首次运行先执行 `cmake -S . -B build`）：

```bash
cmake --build build --target result_example
./build/bin/result_example
```

预期输出：

```text
12 / 3 = 4
12 / 0: cannot divide by zero
5 is positive (Result<void, E>)
-1: value must be positive
```

这是手写的学习版本，链表示例也复用此头文件。
练习：写一个返回 `Result<int, std::string>` 的函数，尝试使用另一种成功值和错误类型。
