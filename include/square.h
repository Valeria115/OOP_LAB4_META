#include "figure.h"
#include "point.h"
#include <memory>
#include <iostream>
#include <cmath>
#include <array>

#pragma once


template <geom::Scalar T>
class Square : public Figure<T> {
public:
    Square();
    Square(const std::unique_ptr<geom::Point<T>[]>& pts);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    ~Square() override = default;

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
