/******************************************************
#@Description : ipb::named_vector container - Homework 4
#@Author : Leonardo Anjos Chaves    [lchavesbr @gmail.com]
#@Date : 17 / Oct / 2025
#Copyright(c) 2025 Leonardo Chaves, all rights reserved
******************************************************/

#ifndef NAMED_VECTOR_H
#define NAMED_VECTOR_H

#include <string>
#include <vector>

namespace ipb {

template <typename T>
struct named_vector {
    std::string name_;
    std::vector<T> std_vector_;

    named_vector<T>() : name_{}, std_vector_{} {};

    named_vector<T>(const std::string& name, const std::vector<T>& vec)
        : name_{name}, std_vector_{vec} {};

    std::vector<T>& vector() { return std_vector_; };
    [[nodiscard]] std::string& name() { return name_; };

    [[nodiscard]] int size() const {
        return (name_.size() + std_vector_.size());
    };

    [[nodiscard]] bool empty() const {
        return (name_.empty() || std_vector_.empty());
    };

    void reserve(std::size_t new_capacity) {
        std_vector_.reserve(new_capacity);
    };
    void resize(std::size_t new_size) { std_vector_.resize(new_size); };
    [[nodiscard]] std::size_t capacity() const {
        return std_vector_.capacity();
    };
};

};  // namespace ipb

// namespace ipb
#endif  // NAMED_VECTOR_H