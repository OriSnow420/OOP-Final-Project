#include "header/Line3D.hpp"
#include "header/Point3D.hpp"
#include <initializer_list>
Line3D::Line3D(std::initializer_list<Point3D> Ilist):
MultiPoint<2>(Ilist) {}
 

Line3D::Line3D(const Point3D& point1, const Point3D& point2) noexcept : MultiPoint<2>({point1, point2}) {}



double Line3D::length() const noexcept {
    return Point3D::distance(getPoint(0), getPoint(1));
}
