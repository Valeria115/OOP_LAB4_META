#include "../include/trapezoid.h"
#include "../include/concepts.h"
#include <stdexcept>

template <geom::Scalar T>
Trapezoid<T>::Trapezoid() : points(std::make_unique<geom::Point<T>[]>(vertexCount)) {}

template <geom::Scalar T>
Trapezoid<T>::~Trapezoid() = default;


template <geom::Scalar T>
Trapezoid<T>::Trapezoid(const std::unique_ptr<geom::Point<T>[]>& pts) : points(std::make_unique<geom::Point<T>[]>(vertexCount)) {
    for (std::size_t i = 0; i < vertexCount; ++i)
        points[i] = pts[i];
}

template <geom::Scalar T>
Trapezoid<T>::Trapezoid(const Trapezoid& other) : points(std::make_unique<geom::Point<T>[]>(vertexCount)) {
    for (std::size_t i = 0; i < vertexCount; ++i)
        points[i] = other.points[i];
}

template <geom::Scalar T>
Trapezoid<T>::Trapezoid(Trapezoid&& other) noexcept : points(std::move(other.points)) {}

template <geom::Scalar T>
Trapezoid<T>& Trapezoid<T>::operator=(const Trapezoid& other) {
    if (this == &other) return *this;
    points = std::make_unique<geom::Point<T>[]>(vertexCount);
    for (std::size_t i = 0; i < vertexCount; ++i)
        points[i] = other.points[i];
    return *this;
}

template <geom::Scalar T>
Trapezoid<T>& Trapezoid<T>::operator=(Trapezoid&& other) noexcept {
    if (this == &other) return *this;
    points = std::move(other.points);
    return *this;
}


template <geom::Scalar T>
void Trapezoid<T>::read(std::istream& is) {
    for (std::size_t i = 0; i < vertexCount; ++i)
        is >> points[i];
}

template <geom::Scalar T>
void Trapezoid<T>::print(std::ostream& os) const {
    os << "Trapezoid vertices:\n";
    for (std::size_t i = 0; i < vertexCount; ++i)
        os << "  " << points[i] << "\n";
    os << "Area: " << area() << "\n";
    geom::Point<T> c = center();
    os << "Center: " << c.x() << " " << c.y() << "\n";
}


template <geom::Scalar T>
double Trapezoid<T>::area() const {
    double sum = 0.0;
    for (std::size_t i = 0; i < vertexCount; ++i) {
        const auto& p1 = points[i];
        const auto& p2 = points[(i + 1) % vertexCount];
        sum += static_cast<double>(p1.x()) * p2.y();
        sum -= static_cast<double>(p1.y()) * p2.x();
    }
    return std::fabs(sum) / 2.0;
}


template <geom::Scalar T>
geom::Point<T> Trapezoid<T>::center() const {
    T cx = 0, cy = 0;
    for (std::size_t i = 0; i < vertexCount; ++i) {
        cx += points[i].x();
        cy += points[i].y();
    }
    cx /= static_cast<T>(vertexCount);
    cy /= static_cast<T>(vertexCount);
    return geom::Point<T>(cx, cy);
}


template <geom::Scalar T>
Trapezoid<T>::operator double() const {
    return area();
}


template <geom::Scalar T>
bool Trapezoid<T>::equals(const Figure<T>& other) const {
    const Trapezoid<T>* trap = dynamic_cast<const Trapezoid<T>*>(&other);
    if (!trap) return false;
    for (std::size_t i = 0; i < vertexCount; ++i)
        if (!(points[i] == trap->points[i]))
            return false;
    return true;
}


template <geom::Scalar T>
std::unique_ptr<Figure<T>> Trapezoid<T>::clone() const {
    auto newTrap = std::make_unique<Trapezoid<T>>();
    for (std::size_t i = 0; i < vertexCount; ++i)
        newTrap->points[i] = points[i];
    return newTrap;
}


template class Trapezoid<int>;
template class Trapezoid<double>;
template class Trapezoid<float>;