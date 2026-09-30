# const 与指针

[main.cpp](main.cpp) 演示三种写法，并用注释保留会导致编译错误的操作。

| 写法 | 能否改变指向 | 能否通过指针修改值 |
| --- | --- | --- |
| `const int*` / `int const*` | 可以 | 不可以 |
| `int* const` | 不可以 | 可以 |
| `const int* const` | 不可以 | 不可以 |

`const int*` 限制通过该指针写入；如果原变量不是 const，仍然可以直接修改原变量。

在仓库根目录执行（首次运行先执行 `cmake -S . -B build`）：

```bash
cmake --build build --target const_example
./build/bin/const_example
```

预期输出：

```text
const int*: a = 10
const int*: b = 12
after b = 15: *p = 15
int* const: b = 20
const int* const: a = 10
```

练习：每次取消一行错误操作的注释，观察编译器提示，理解后恢复注释。
