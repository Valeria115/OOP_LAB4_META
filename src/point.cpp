#include <limits>
#include <cmath>
#include <type_traits>
#include "../include/point.h"

namespace geom {

    template<Scalar T>
    Point<T>::Point() noexcept : x_(T{}), y_(T{}) {}

    template<Scalar T>
    Point<T>::Point(T x, T y) noexcept : x_(x), y_(y) {}

    template<Scalar T>
    Point<T>& Point<T>::operator=(const Point& other) {
        if (this != &other) {
            x_ = other.x_;
            y_ = other.y_;
        }
        return *this;
    }

    template<Scalar T>
    Point<T>& Point<T>::operator=(Point&& other) noexcept {
        if (this != &other) {
            x_ = std::move(other.x_);
            y_ = std::move(other.y_);
        }
        return *this;
    }

    template<Scalar T>
    T Point<T>::x() const noexcept { return x_; }

    template<Scalar T>
    T Point<T>::y() const noexcept { return y_; }

    template<Scalar T>
    void Point<T>::set_x(T x) noexcept { x_ = x; }

    template<Scalar T>
    void Point<T>::set_y(T y) noexcept { y_ = y; }

    template<Scalar T>
    void Point<T>::set(T x, T y) noexcept { x_ = x; y_ = y; }

    template<Scalar T>
    Point<T> Point<T>::operator+(const Point& other) const noexcept {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    template<Scalar T>
    Point<T> Point<T>::operator-(const Point& other) const noexcept {
        return Point(x_ - other.x_, y_ - other.y_);
    }

    template<Scalar T>
    Point<T> Point<T>::operator*(T scalar) const noexcept {
        return Point(x_ * scalar, y_ * scalar);
    }

    template<Scalar T>
    Point<T> Point<T>::operator/(T scalar) const noexcept {
        return Point(x_ / scalar, y_ / scalar);
    }

    template<Scalar T>
    bool Point<T>::operator==(const Point& other) const noexcept {
        if constexpr (std::is_floating_point_v<T>) {
            T eps = std::numeric_limits<T>::epsilon() * 100;
            return (std::fabs(x_ - other.x_) <= eps) && (std::fabs(y_ - other.y_) <= eps);
        } else {
            return (x_ == other.x_) && (y_ == other.y_);
        }
    }

    template<Scalar T>
    T Point<T>::dot(const Point& other) const noexcept {
        return x_ * other.x_ + y_ * other.y_;
    }

    template<Scalar T>
    T Point<T>::dist2(const Point& other) const noexcept {
        T dx = x_ - other.x_;
        T dy = y_ - other.y_;
        return dx * dx + dy * dy;
    }

    template<Scalar T>
    double Point<T>::distance(const Point& other) const noexcept {
        return std::sqrt(static_cast<double>(dist2(other)));
    }

    template<Scalar T>
    std::pair<T, T> Point<T>::as_pair() const noexcept {
        return {x_, y_};
    }

    template<Scalar T>
    std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << p.x_ << " " << p.y_;
        return os;
    }

    template<Scalar T>
    std::istream& operator>>(std::istream& is, Point<T>& p) {
        is >> p.x_ >> p.y_;
        return is;
    }

    template<Scalar T>
    Point<T> mid_point(const Point<T>& a, const Point<T>& b) noexcept {
        return Point<T>((a.x() + b.x()) / static_cast<T>(2),
                        (a.y() + b.y()) / static_cast<T>(2));
    }

    template class Point<int>;
    template class Point<float>;
    template class Point<double>;

    template std::ostream& operator<<<int>(std::ostream&, const Point<int>&);
    template std::ostream& operator<<<float>(std::ostream&, const Point<float>&);
    template std::ostream& operator<<<double>(std::ostream&, const Point<double>&);

    template std::istream& operator>><int>(std::istream&, Point<int>&);
    template std::istream& operator>><float>(std::istream&, Point<float>&);
    template std::istream& operator>><double>(std::istream&, Point<double>&);

    template Point<int> mid_point(const Point<int>&, const Point<int>&) noexcept;
    template Point<float> mid_point(const Point<float>&, const Point<float>&) noexcept;
    template Point<double> mid_point(const Point<double>&, const Point<double>&) noexcept;
}