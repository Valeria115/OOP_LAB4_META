#include "../include/rectangle.h"
#include "../include/concepts.h"
#include <stdexcept>

template <geom::Scalar T>
Rectangle<T>::Rectangle() : points(std::make_unique<geom::Point<T>[]>(Rectangle<T>::vertexCount)) {}

template <geom::Scalar T>
Rectangle<T>::Rectangle(const std::unique_ptr<geom::Point<T>[]>& pts) : points(std::make_unique<geom::Point<T>[]>(Rectangle<T>::vertexCount)) {
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        points[i] = pts[i];
}

template <geom::Scalar T>
Rectangle<T>::Rectangle(const Rectangle& other) : points(std::make_unique<geom::Point<T>[]>(Rectangle<T>::vertexCount)) {
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        points[i] = other.points[i];
}

template <geom::Scalar T>
Rectangle<T>::Rectangle(Rectangle&& other) noexcept : points(std::move(other.points)) {}


template <geom::Scalar T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle& other) {
    if (this == &other) return *this;
    points = std::make_unique<geom::Point<T>[]>(Rectangle<T>::vertexCount);
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        points[i] = other.points[i];
    return *this;
}

template <geom::Scalar T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle&& other) noexcept {
    if (this == &other) return *this;
    points = std::move(other.points);
    return *this;
}


template <geom::Scalar T>
void Rectangle<T>::read(std::istream& is) {
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        is >> points[i];
}

template <geom::Scalar T>
void Rectangle<T>::print(std::ostream& os) const {
    os << "Rectangle vertices:\n";
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        os << "  " << points[i] << "\n";
    os << "Area: " << area() << "\n";
    geom::Point<T> c = center();
    os << "Center: " << c.x() << " " << c.y() << "\n";
}


template <geom::Scalar T>
double Rectangle<T>::area() const {
    double width = points[0].distance(points[1]);
    double height = points[1].distance(points[2]);
    return width * height;
}

template <geom::Scalar T>
geom::Point<T> Rectangle<T>::center() const {
    T cx = 0, cy = 0;
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i) {
        cx += points[i].x();
        cy += points[i].y();
    }
    cx /= static_cast<T>(Rectangle<T>::vertexCount);
    cy /= static_cast<T>(Rectangle<T>::vertexCount);
    return geom::Point<T>(cx, cy);
}

template <geom::Scalar T>
Rectangle<T>::operator double() const {
    return area();
}


template <geom::Scalar T>
bool Rectangle<T>::equals(const Figure<T>& other) const {
    const Rectangle<T>* rect = dynamic_cast<const Rectangle<T>*>(&other);
    if (!rect) return false;
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        if (!(points[i] == rect->points[i]))
            return false;
    return true;
}

template <geom::Scalar T>
std::unique_ptr<Figure<T>> Rectangle<T>::clone() const {
    auto newRect = std::make_unique<Rectangle<T>>();
    for (std::size_t i = 0; i < Rectangle<T>::vertexCount; ++i)
        newRect->points[i] = points[i];
    return newRect;
}


template class Rectangle<int>;
template class Rectangle<double>;
template class Rectangle<float>;