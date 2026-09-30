# C++ 学习示例

这是一个用于学习和练习 C++ 的仓库。每个主题放在 `examples/` 下的独立目录中，
有自己的 `main.cpp`、构建目标和说明，可以一次只学习、修改和运行一个例子。
手写数据结构和工具用于理解原理，不代表生产级实现。

## 示例与学习顺序

| 顺序 | 示例 | 学习内容 | 构建目标 |
| --- | --- | --- | --- |
| 1 | [hello_world](examples/hello_world/README.md) | 程序入口、标准输出 | `hello_world_example` |
| 2 | [functions](examples/functions/README.md) | 函数声明与定义、多文件编译和链接 | `functions_example` |
| 3 | [const](examples/const/README.md) | 指向常量的指针、常量指针 | `const_example` |
| 4 | [macros](examples/macros/README.md) | 预处理宏、字符串拼接、终端颜色 | `macros_example` |
| 5 | [result](examples/result/README.md) | 类模板、`std::variant`、`void` 特化 | `result_example` |
| 6 | [linked_list](examples/linked_list/README.md) | C++20 concept、单链表、指针与错误处理 | `linked_list_example` |

## 构建与运行

需要 CMake 3.20 或更新版本，以及支持 C++20 的编译器。
在仓库根目录执行：

```bash
cmake -S . -B build
cmake --build build
./build/bin/hello_world_example
```

只构建、运行某个示例，例如 const：

```bash
cmake --build build --target const_example
./build/bin/const_example
```

将目标名替换成表格中的其他名称即可运行对应示例。
以上路径适用于 Linux/macOS 的单配置构建；Windows 可执行文件带 `.exe` 后缀，
Visual Studio 等多配置生成器会放在 `build/bin/Debug/` 等配置目录中，
构建时使用 `cmake --build build --config Debug`。

运行全部示例检查和链表边界测试：

```bash
ctest --test-dir build --output-on-failure
```

多配置构建测试时加 `-C Debug`。只需要示例时，可以在配置时加 `-DBUILD_TESTING=OFF`。

## 目录结构

```text
cpp_projects/
├── CMakeLists.txt             # C++20 配置、输出目录和测试开关
├── README.md
└── examples/
    ├── CMakeLists.txt         # 注册各个示例目录
    ├── hello_world/
    ├── functions/             # main.cpp + add.hpp + add.cpp
    ├── const/
    ├── macros/
    ├── result/                # Result 头文件及使用示例
    └── linked_list/           # 节点、链表实现、示例和插入测试
```

每个示例目录都包含 `CMakeLists.txt` 和 `README.md`。
链表示例通过 CMake 的 `result_headers` 目标复用 Result 头文件；
其他示例分别构建，不需要链接统一的工具库。

## 添加新示例

以学习引用为例，以下是新增步骤；`references` 是待创建示例的名称。
所有命令都在仓库根目录执行。

1. 创建目录：

   ```bash
   mkdir -p examples/references
   ```

2. 创建 `examples/references/main.cpp`：

   ```cpp
   #include <iostream>

   int main() {
       int value = 10;
       int& ref = value; // ref 是 value 的别名。
       ref = 20;
       std::cout << "value = " << value << '\n';
       return 0;
   }
   ```

3. 创建 `examples/references/CMakeLists.txt`：

   ```cmake
   add_executable(references_example main.cpp)

   if(BUILD_TESTING)
       add_test(NAME references_example COMMAND references_example)
   endif()
   ```

   `references_example` 是构建目标和可执行文件名，`main.cpp` 是参与编译的源文件。
   如果示例有多个 `.cpp`，都列在这里，例如
   `add_executable(references_example main.cpp helper.cpp)`。
   不同例子的目标名必须不同。

4. 在 `examples/CMakeLists.txt` 末尾添加：

   ```cmake
   add_subdirectory(references)
   ```

5. 配置、编译并运行：

   ```bash
   cmake -S . -B build
   cmake --build build --target references_example
   ./build/bin/references_example
   ```

   预期输出 `value = 20`。第一条命令生成构建规则和 clangd 的编译数据库，
   第二条命令编译、链接指定示例，第三条命令运行编译好的程序。

6. 添加 `examples/references/README.md` 记录学习点和预期输出，并更新上面的示例表。

之后只修改已有 `.cpp` 的代码，执行编译和运行两条命令即可。
新增目录、源文件或修改 CMake 配置后，重新执行配置命令，更新构建规则和编译数据库。
不要直接在 `examples/` 下随意放一个未注册的 `.cpp`，它不会自动成为构建目标。

## 使用 clangd 提示

clangd 给编辑器提供补全、错误提示、悬停类型说明和跳转定义。
需要系统中的 `clangd` 程序、编辑器的 clangd/LSP 支持，以及项目的编译配置。
它可以分析使用 GCC 构建的项目，无须为了启用补全切换编译器。

本仓库已默认启用 `CMAKE_EXPORT_COMPILE_COMMANDS`，配置后会生成
`build/compile_commands.json`。根目录的 [.clangd](.clangd) 指定从 `build/` 读取它，
clangd 因此能知道每个源文件使用 C++20、哪些头文件目录和编译选项。
这些机制见 [clangd 项目配置](https://clangd.llvm.org/config#compilationdatabase)
和 [CMake 编译数据库说明](https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html)。
编译数据库导出适用于 Makefiles 和 Ninja 生成器。
若改用其他构建目录，要同步修改 `.clangd` 的 `CompilationDatabase`。

先在当前开发环境检查并生成配置：

```bash
clangd --version
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

配置成功就可以启动提示，不必先编译所有示例。
如果未安装 clangd，按 [官方安装说明](https://clangd.llvm.org/installation.html)安装对应系统的软件包。

### VS Code

1. 打开整个仓库目录，安装 LLVM 发布的 **clangd** 扩展，扩展 ID 为 `llvm-vs-code-extensions.vscode-clangd`。
2. 如果使用 WSL，先通过 VS Code 的 WSL 扩展连接到 WSL，再打开仓库；clangd 扩展要安装在 WSL 环境中。
   编辑器使用的 clangd 和生成编译数据库的环境应一致。
3. 如果同时安装了 Microsoft C/C++ 扩展，在工作区设置里关闭它的 IntelliSense，避免重复提示。
   可将以下内容合并到 `.vscode/settings.json`：

   ```json
   {
       "C_Cpp.intelliSenseEngine": "disabled",
       "clangd.arguments": ["--background-index"]
   }
   ```

4. 打开任意已注册示例的 `main.cpp`，输入 `std::`，或按 `Ctrl+Space` 请求补全。
   悬停可以查看类型，`F12` 可以跳转定义，错误会显示在编辑器和 Problems 面板里。
   快捷键可在编辑器设置中调整。

如果扩展找不到 clangd，用 `command -v clangd` 查出路径，再在工作区设置中添加
`"clangd.path": "查到的完整路径"`。
VS Code 连接方式与扩展说明见 [clangd 编辑器配置](https://clangd.llvm.org/installation.html#editor-plugins)。
其他编辑器也复用本仓库的 `.clangd` 和编译数据库，只需启用相应的 clangd/LSP 客户端。

### 提示异常时

1. 重新运行 `cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`。
2. 确认新示例通过 `add_subdirectory` 和 `add_executable` 注册，源文件出现在
   `build/compile_commands.json` 中。
3. 在 VS Code 命令面板运行 **clangd: Restart language server**。
4. 仍有问题时，在终端检查单个文件，查看是否加载了编译数据库，以及具体报错：

   ```bash
   clangd --check=examples/const/main.cpp
   ```
