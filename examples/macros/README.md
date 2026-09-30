# 预处理宏与终端颜色

[macro.hpp](macro.hpp) 定义颜色和日志宏，[main.cpp](main.cpp) 演示调用。
宏在预处理阶段展开，例如 `INFO("hello")` 会展开为相邻的字符串字面量，
这些字面量随后拼成一个字符串。

在仓库根目录执行（首次运行先执行 `cmake -S . -B build`）：

```bash
cmake --build build --target macros_example
./build/bin/macros_example
```

预期文本（支持 ANSI 转义序列的终端分别显示绿色、黄色、红色）：

```text
[INFO] This is an info message
[WARNING] This is a warning message
[ERROR] This is an error message
```

当前宏的参数必须是字符串字面量，不能直接传入 `std::string` 变量。
练习：添加一个蓝色的 `DEBUG` 宏；进一步尝试改写成接受 `std::string_view` 的函数。
