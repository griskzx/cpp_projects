# cpp_projects

这是我用来存放学习代码的项目仓库，内容比较杂乱，主要用于记录和练习各种 C++ 相关的知识点，不代表生产级代码质量。

## 构建方式

项目使用 CMake Presets，编译器为 Clang，提供 `debug` 和 `release` 两种预设：

```powershell
# 配置
cmake --preset debug
cmake --preset release

# 构建
cmake --build --preset debug
cmake --build --preset release
```

构建产物统一放在 `build/debug` 和 `build/release` 目录下，已加入 `.gitignore`。

### 多个 `main` 文件时如何选择编译目标

如果 `src/` 下有多个 `*.cpp`（每个文件都可能有 `main`），可以在配置时通过 `MAIN_FILE` 指定本次要编译的入口文件：

```powershell
# 例如只编译 src/hello.cpp
cmake --preset debug -DMAIN_FILE=hello.cpp
cmake --build --preset debug
```

生成的可执行文件名会自动使用该文件名（不带扩展名），例如 `hello.cpp` 会生成 `hello`。
