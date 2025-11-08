#include <type_traits>
#include <concepts>
#include <cmath>
#include <iostream>
#include <utility>
#include "concepts.h"


#pragma once


namespace geom {
    
    template<Scalar T>
    class Point {
    public:
        using value_type = T;

        Point() noexcept;
        Point(T x, T y) noexcept;
        ~Point() = default;

        Point(const Point& other) = default;
        Point(Point&& other) noexcept = default;

        Point& operator=(const Point& other);
        Point& operator=(Point&& other) noexcept;

        T x() const noexcept;
        T y() const noexcept;

        void set_x(T x) noexcept;
        void set_y(T y) noexcept;
        void set(T x, T y) noexcept;

        Point operator+(const Point& other) const noexcept;
        Point operator-(const Point& other) const noexcept;
        Point operator*(T scalar) const noexcept;
        Point operator/(T scalar) const noexcept;

        bool operator==(const Point& other) const noexcept;

        T dot(const Point& other) const noexcept;
        T dist2(const Point& other) const noexcept;
        double distance(const Point& other) const noexcept;

        std::pair<T,T> as_pair() const noexcept;

        template<Scalar U>
        friend std::ostream& operator<<(std::ostream& os, const Point<U>& p);

        template<Scalar U>
        friend std::istream& operator>>(std::istream& is, Point<U>& p);

    private:
        T x_;
        T y_;
        

    };

    template<Scalar T>
    Point<T> mid_point(const Point<T>& a, const Point<T>& b) noexcept;

}
