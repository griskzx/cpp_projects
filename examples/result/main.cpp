#include <iostream>
#include <string_view>

#include "result.hpp"

// 学习点：用 std::variant 表示成功或失败，以及 void 的模板特化。
Result<double, std::string_view> divide(double numerator, double denominator) {
    if (denominator == 0.0) {
        return Err<std::string_view>{"cannot divide by zero"};
    }
    return Ok<double>{numerator / denominator};
}

Result<void, std::string_view> require_positive(int value) {
    if (value <= 0) {
        return Err<std::string_view>{"value must be positive"};
    }
    return Ok<void>{};
}

int main() {
    const auto success = divide(12.0, 3.0);
    if (success.is_ok()) {
        std::cout << "12 / 3 = " << success.get_value() << '\n';
    }

    const auto failure = divide(12.0, 0.0);
    if (failure.is_err()) {
        std::cout << "12 / 0: " << failure.get_error() << '\n';
    }

    const auto valid = require_positive(5);
    if (valid.is_ok()) {
        std::cout << "5 is positive (Result<void, E>)\n";
    }

    const auto invalid = require_positive(-1);
    if (invalid.is_err()) {
        std::cout << "-1: " << invalid.get_error() << '\n';
    }
    return 0;
}
