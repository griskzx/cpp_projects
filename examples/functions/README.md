# 函数与多文件编译

[add.hpp](add.hpp) 声明函数，[add.cpp](add.cpp) 定义函数，
[main.cpp](main.cpp) 包含头文件并调用它。CMake 把两个 `.cpp` 文件编译后链接成一个程序。
`auto add(int a, int b) -> int` 使用尾置返回类型，等价于 `int add(int a, int b)`。

在仓库根目录执行（首次运行先执行 `cmake -S . -B build`）：

```bash
cmake --build build --target functions_example
./build/bin/functions_example
```

预期输出：

```text
add(5, 3) = 8
```

练习：添加 `subtract` 函数，分别写出声明、定义和调用。
