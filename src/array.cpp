#include <cstddef>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <utility>

#include "../include/array.h"
#include "../include/concepts.h"
#include "../include/figure.h"


template<typename T>
Array<T>::Array() : m_size(0), m_capacity(0), m_data(nullptr) {}

template<typename T>
Array<T>::~Array() = default;

template<typename T>
Array<T>::Array(const Array& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(nullptr) {
    if (m_capacity > 0) {
        m_data = std::make_unique<T[]>(m_capacity);
        for (std::size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
}


template<typename T>
Array<T>::Array(Array&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_data(std::move(other.m_data)) {
    other.m_size = 0;
    other.m_capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this == &other) return *this;

    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = nullptr;

    if (m_capacity > 0) {
        m_data = std::make_unique<T[]>(m_capacity);
        for (std::size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this == &other) return *this;

    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = std::move(other.m_data);

    other.m_size = 0;
    other.m_capacity = 0;
    return *this;

}

// методы
template<typename T>
void Array<T>::add(const T& value) {
    if (m_size >= m_capacity) {
        if (m_capacity == 0)
            resize(2);
        else
            resize(m_capacity * 2);
    }
    m_data[m_size++] = value;
}

template<typename T>
void Array<T>::add(T&& value) {
    if (m_size >= m_capacity) {
        if (m_capacity == 0)
            resize(2);
        else 
            resize(m_capacity * 2);
    }
    m_data[m_size++] = std::move(value);
        
}

template<typename T>
void Array<T>::remove(std::size_t index) {
    if (index >= m_size)
        throw std::out_of_range("Index out of range");

    for (std::size_t i = index; i < m_size - 1; ++i)
        m_data[i] = std::move(m_data[i + 1]);

    --m_size;
}

template <typename T>
T& Array<T>::get(std::size_t index) const {
    if (index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

template<typename T>
std::size_t Array<T>::size() const noexcept {
    return m_size;
}

template<typename T>
std::size_t Array<T>::capacity() const noexcept {
    return m_capacity;
}

template<typename T>
void Array<T>::resize(std::size_t new_cap) {
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_cap);
    for (std::size_t i = 0; i < m_size; ++i)
        new_data[i] = std::move(m_data[i]);
    m_data = std::move(new_data);
    m_capacity = new_cap;
}

template<typename T>
void Array<T>::print(std::ostream& os) const {
    for (std::size_t i = 0; i < m_size; ++i)
        os << m_data[i] << '\n';
}

template<typename T>
double Array<T>::totalArea() const {
    double total = 0.0;
    for (std::size_t i = 0; i < m_size; ++i) {
        
        if constexpr (std::is_pointer_v<T>) {
            if (m_data[i] != nullptr) {
                total += static_cast<double>(*m_data[i]);
            }
        } else {
            total += static_cast<double>(*m_data[i]);
        }
    }
    return total;
}

template class Array<std::shared_ptr<Figure<int>>>;
template class Array<std::shared_ptr<Figure<double>>>;
