#include "header/Face3D.hpp"
#include "header/Point3D.hpp"
#include <cmath>

Face3D::Face3D(std::initializer_list<Point3D> Ilist):
m_points(Ilist){
    if(Ilist.size() != 3){
        throw std::exception("[Face3D::Face3D] Passing wrong number of points");
    }
}

Face3D::Face3D(const Point3D& point1, const Point3D& point2, const Point3D& point3) noexcept : m_points({point1, point2, point3}) {}

double Face3D::area() const noexcept {
    double a = Point3D::distance(m_points[0], m_points[1]);
    double b = Point3D::distance(m_points[1], m_points[2]);
    double c = Point3D::distance(m_points[2], m_points[0]);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); // Heron's Formula
}

void Face3D::setPoint(const Point3D& newPoint, int index){
    if(index < 0 || index > 2){
        throw std::exception("[Face3D::setPoint] Passing wrong index");
    }
    m_points[index] = newPoint;
}

std::vector<Point3D> Face3D::getPoints() const noexcept {
    return m_points;
}

Point3D Face3D::getPoint(int index) const {
    if(index < 0 || index > 2){
        throw std::exception(
            "[Face3D::getPoint] Passing wrong index"
        );
    }
    return m_points[index];
}