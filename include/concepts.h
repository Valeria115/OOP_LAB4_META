#pragma once
#include <type_traits>
#include <concepts>

namespace geom {
    template<typename T>
    concept Scalar = std::is_arithmetic_v<T>;

    template<typename T>
    concept FloatingPoint = std::is_floating_point_v<T>;

    template<typename T>
    concept Arithmetic = Scalar<T> && requires(T a, T b) {
        { a + b } -> std::convertible_to<T>;
        { a - b } -> std::convertible_to<T>;
        { a * b } -> std::convertible_to<T>;
        { a / b } -> std::convertible_to<T>;
    };

    template <typename T, typename U>
    concept PointerToFigure = requires(T ptr) {
        typename T::element_type;
        { dynamic_cast<U*>(ptr.get()) } -> std::convertible_to<U*>;
    };
    
}