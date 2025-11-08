#include "figure.h"
#include "point.h"
#include <memory>
#include <iostream>

#pragma once


template <geom::Scalar T>
class Trapezoid : public Figure<T> {
public:

    Trapezoid();
    Trapezoid(const std::unique_ptr<geom::Point<T>[]>& pts);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    ~Trapezoid() override;

    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
    double area() const override;
    geom::Point<T> center() const override;
    bool equals(const Figure<T>& other) const override;
    explicit operator double() const override;
    std::unique_ptr<Figure<T>> clone() const override;

private:

    std::unique_ptr<geom::Point<T>[]> points;
    const std::size_t vertexCount = 4;
};
