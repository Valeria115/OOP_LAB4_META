#include "../include/square.h"
#include "../include/concepts.h"
#include <stdexcept>

template <geom::Scalar T>
Square<T>::Square() : points(std::make_unique<geom::Point<T>[]>(vertexCount)) {}

template <geom::Scalar T>
Square<T>::Square(const std::unique_ptr<geom::Point<T>[]>& pts) : points(std::make_unique<geom::Point<T>[]>(vertexCount)) {
    for (std::size_t i = 0; i < vertexCount; ++i)
        points[i] = pts[i];
}

template <geom::Scalar T>
Square<T>::Square(const Square& other) : points(std::make_unique<geom::Point<T>[]>(vertexCount)) {
    for (std::size_t i = 0; i < vertexCount; ++i)
        points[i] = other.points[i];
}

template <geom::Scalar T>
Square<T>::Square(Square&& other) noexcept : points(std::move(other.points)) {}

template <geom::Scalar T>
Square<T>& Square<T>::operator=(const Square& other) {
    if (this == &other) return *this;
    points = std::make_unique<geom::Point<T>[]>(vertexCount);
    for (std::size_t i = 0; i < vertexCount; ++i)
        points[i] = other.points[i];
    return *this;
}

template <geom::Scalar T>
Square<T>& Square<T>::operator=(Square&& other) noexcept {
    if (this == &other) return *this;
    points = std::move(other.points);
    return *this;
}


template <geom::Scalar T>
void Square<T>::read(std::istream& is) {
    for (std::size_t i = 0; i < vertexCount; ++i) {
        is >> points[i];
    }
}

template <geom::Scalar T>
void Square<T>::print(std::ostream& os) const {
    os << "Square vertices:\n";
    for (std::size_t i = 0; i < vertexCount; ++i)
        os << "  " << points[i] << "\n";
    os << "Area: " << area() << "\n";
    geom::Point<T> c = center();
    os << "Center: " << c.x() << " " << c.y() << "\n";
}


template <geom::Scalar T>
double Square<T>::area() const {
    double a = points[0].distance(points[1]);
    return a * a;
}

template <geom::Scalar T>
geom::Point<T> Square<T>::center() const {
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
Square<T>::operator double() const {
    return area();
}

template <geom::Scalar T>
bool Square<T>::equals(const Figure<T>& other) const {
    const Square<T>* sq = dynamic_cast<const Square<T>*>(&other);
    if (!sq) return false;

    for (std::size_t i = 0; i < vertexCount; ++i)
        if (!(points[i] == sq->points[i]))
            return false;
    return true;
}

template <geom::Scalar T>
std::unique_ptr<Figure<T>> Square<T>::clone() const {
    auto newSquare = std::make_unique<Square<T>>();
    for (std::size_t i = 0; i < vertexCount; ++i)
        newSquare->points[i] = points[i];
    return newSquare;
}

template class Square<int>;
template class Square<double>;
template class Square<float>;
