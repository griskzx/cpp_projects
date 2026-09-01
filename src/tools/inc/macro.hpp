//
// Created by HP on 2026/9/1.
//

#ifndef CPP_PROJECT_MACRO_HPP
#define CPP_PROJECT_MACRO_HPP

// 字体颜色
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"

// 恢复终端默认颜色
#define COLOR_RESET   "\033[0m"

#define INFO(message)    COLOR_GREEN  "[INFO] "    message COLOR_RESET
#define WARNING(message) COLOR_YELLOW "[WARNING] " message COLOR_RESET
#define ERROR(message)   COLOR_RED    "[ERROR] "   message COLOR_RESET

#endif //CPP_PROJECT_MACRO_HPP
