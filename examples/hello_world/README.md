# Hello World

从 [main.cpp](main.cpp) 开始，了解 `main` 程序入口、`std::cout`、换行符和返回值。
`return 0` 表示程序正常结束。

在仓库根目录执行（首次运行先执行 `cmake -S . -B build`）：

```bash
cmake --build build --target hello_world_example
./build/bin/hello_world_example
```

预期输出：

```text
Hello, C++!
```

练习：修改输出内容，尝试在同一行输出数字和字符串。
