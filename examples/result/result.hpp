#ifndef CPP_EXAMPLES_RESULT_HPP
#define CPP_EXAMPLES_RESULT_HPP

#include <variant>
#include <utility>

template<typename T>
class Ok {
public:
    explicit Ok(T value)
        : value_(std::move(value)) {
    }

    T &get_value() {
        return value_;
    }

    const T &get_value() const {
        return value_;
    }

private:
    T value_;
};

template<>
class Ok<void> {
public:
    Ok() = default;
};

template<typename E>
class Err {
public:
    explicit Err(E value)
        : value_(std::move(value)) {
    }

    E &get_value() {
        return value_;
    }

    const E &get_value() const {
        return value_;
    }

private:
    E value_;
};


// 先判断状态再取值；读取不匹配的分支会抛出 std::bad_variant_access。
template<typename T, typename E>
class Result {
public:
    Result(Ok<T> value) : data_(std::move(value)) {
    }

    Result(Err<E> value) : data_(std::move(value)) {
    }

    [[nodiscard]] bool is_ok() const {
        return std::holds_alternative<Ok<T> >(data_);
    }

    [[nodiscard]] bool is_err() const {
        return std::holds_alternative<Err<E> >(data_);
    }

    T &get_value() {
        return std::get<Ok<T> >(data_).get_value();
    }

    const T &get_value() const {
        return std::get<Ok<T> >(data_).get_value();
    }

    E &get_error() {
        return std::get<Err<E> >(data_).get_value();
    }

    const E &get_error() const {
        return std::get<Err<E> >(data_).get_value();
    }

private:
    std::variant<Ok<T>, Err<E> > data_;
};

// 成功时不需要返回值的特化，例如链表插入。
template<typename E>
class Result<void, E> {
public:
    Result(Ok<void> ok) : data_(ok) {
    }

    Result(Err<E> value) : data_(std::move(value)) {
    }

    [[nodiscard]] bool is_ok() const {
        return std::holds_alternative<Ok<void> >(data_);
    }

    [[nodiscard]] bool is_err() const {
        return std::holds_alternative<Err<E> >(data_);
    }

    E &get_error() {
        return std::get<Err<E> >(data_).get_value();
    }

    const E &get_error() const {
        return std::get<Err<E> >(data_).get_value();
    }

private:
    std::variant<Ok<void>, Err<E> > data_;
};

#endif // CPP_EXAMPLES_RESULT_HPP
