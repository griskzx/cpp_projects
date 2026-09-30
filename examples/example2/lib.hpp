#pragma once
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <print>
#include <string>
#include <string_view>
#include <vector>
class A{
    private:
        std::string_view name_;
        uint32_t age_;
    public:
        void setAge(uint32_t age);
        int getAge() const;

        // 类内直接定义的成员函数会被编译器隐式建议为 inline
        void printInfo() const {
            std::println("Name:{}, Age:{}",name_,age_);
        }
};

//构造与析构
class Vector2D{
    private:
        double x_;
        double y_;
    public:
        // 默认构造函数
        Vector2D():x_(0.0),y_(0.0){}
        Vector2D(double x,double y):x_(x),y_(y){}

        // 防止隐式转换:explicit
        explicit Vector2D(double val):x_(val),y_(val){}
};

class DynameicArry{
    private:
        int* data_;
        size_t size_;
    public:
        DynameicArry(size_t size):size_(size){}
        //析构
        ~DynameicArry(){
            delete []  data_;
        }
};

class B{
    private:
        size_t b_={0};
        std::string_view s_={};
        std::vector<std::string> v_={};
    public:
        //默认构造函数,如果已经有了其他构造函数则需要手动打上default
        B()=default;

        // 普通构造函数
        B(size_t b ):b_(b){}

        //转换构造函数 允许隐式转换
        B(const char* str);

        // 禁止隐式转换
        explicit B(std::string_view s ):s_(s){}

        //拷贝构造函数
        B(const B& other):b_(other.b_),s_(other.s_),v_(new std::vector(std::string) ){
            std::copy(other.v_.begin(), other.v_.end(), v_.begin());
        }

}
