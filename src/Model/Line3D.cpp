#include "header/Line3D.hpp"
#include "header/Point3D.hpp"
#include <exception>
#include <initializer_list>

Line3D::Line3D(std::initializer_list<Point3D> Ilist):
m_points(Ilist){
    if(Ilist.size() != 2){
        throw std::exception("[Line3D::Line3D] Passing wrong number of points");
    }
}

Line3D::Line3D(const Point3D& point1, const Point3D& point2) noexcept : m_points({point1, point2}) {}



double Line3D::length() const noexcept {
    return Point3D::distance(m_points[0], m_points[1]);
}

void Line3D::setPoint(const Point3D& newPoint, int index){
    if(index < 0 || index > 1){
        throw std::exception("[Line3D::setPoint] Passing wrong index");
    }
    m_points[index] = newPoint;
}

std::vector<Point3D> Line3D::getPoints() const noexcept {
    return m_points;
}

Point3D Line3D::getPoint(int index) const {
    if(index < 0 || index > 1){
        throw std::exception(
            "[Line3D::getPoint] Passing wrong index"
        );
    }
    return m_points[index];
}