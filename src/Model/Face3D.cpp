#include "header/Face3D.hpp"
#include "header/Point3D.hpp"
#include <cmath>

Face3D::Face3D(std::initializer_list<Point3D> Ilist):
MultiPoint<3>(Ilist){}

Face3D::Face3D(const Point3D& point1, const Point3D& point2, const Point3D& point3) noexcept : 
MultiPoint<3>({point1, point2, point3}) {}

double Face3D::area() const noexcept {
    auto points = getPoints();
    double a = Point3D::distance(points[0], points[1]);
    double b = Point3D::distance(points[1], points[2]);
    double c = Point3D::distance(points[2], points[0]);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); // Heron's Formula
}
