#include "point.h"
#include <iostream>
#include <memory>

#pragma once


template <geom::Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual double area() const = 0;
    virtual geom::Point<T> center() const = 0;
    virtual bool equals(const Figure<T>& other) const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    virtual std::unique_ptr<Figure<T>> clone() const = 0;

    virtual explicit operator double() const = 0;
};

template <geom::Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& fig) {
    fig.print(os);
    return os;
}

template <geom::Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& fig) {
    fig.read(is);
    return is;
}

template <geom::Scalar T>
bool operator==(const Figure<T>& lhs, const Figure<T>& rhs) {
    return lhs.equals(rhs);
}