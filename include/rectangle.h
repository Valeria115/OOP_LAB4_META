#include "figure.h"
#include "point.h"
#include <memory>
#include <iostream>

#pragma once


template <geom::Scalar T>
class Rectangle : public Figure<T> {
public:

    Rectangle();
    Rectangle(const std::unique_ptr<geom::Point<T>[]>& pts);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    ~Rectangle() override = default;

    void read(std::istream& is) override;
    void print(std::ostream& os) const override;
    double area() const override;
    geom::Point<T> center() const override;
    bool equals(const Figure<T>& other) const override;
    explicit operator double() const override;
    std::unique_ptr<Figure<T>> clone() const override;

private:
    std::unique_ptr<geom::Point<T>[]> points;
    static constexpr std::size_t vertexCount = 4;
};
