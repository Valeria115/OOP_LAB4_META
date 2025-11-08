#include <memory>
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <utility>
#include <type_traits>

#pragma once

template <class T>
class Array {
public: 
    Array();
    ~Array();
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;


    void add(const T& value);
    void add(T&& value);
    void remove(std::size_t index);
    T& get(std::size_t index) const;
    std::size_t size() const noexcept;
    std::size_t capacity() const noexcept;
    void print(std::ostream& os = std::cout) const;
    double totalArea() const;

private:
    std::size_t m_size;
    std::size_t m_capacity;
    std::unique_ptr<T[]> m_data;

    void resize(std::size_t new_cap);
};
