#include "header/Point3D.hpp"
#include <cmath>
#include <exception>
#include <initializer_list>
#include <string>
#include <vector>

Point3D::Point3D(std::initializer_list<double> Ilist):
m_coordinates(Ilist) {
    if(Ilist.size() != 3){
        throw std::exception("[Point3D::Point3D] Passing wrong number of coordinates");
    }
}

Point3D::Point3D(double x, double y, double z) noexcept:
m_coordinates({x, y, z}) {}

Point3D Point3D::operator+(const Point3D& point) const noexcept {
    return Point3D(
        m_coordinates[0] + point.m_coordinates[0],
        m_coordinates[1] + point.m_coordinates[1],
        m_coordinates[2] + point.m_coordinates[2]
    );
}

Point3D Point3D::operator-(const Point3D& point) const noexcept {
    return Point3D(
        m_coordinates[0] - point.m_coordinates[0],
        m_coordinates[1] - point.m_coordinates[1],
        m_coordinates[2] - point.m_coordinates[2]
    );
}

bool Point3D::operator==(const Point3D& rhs) const noexcept {
    return 
        m_coordinates[0] == rhs.m_coordinates[0] &&
        m_coordinates[1] == rhs.m_coordinates[1] &&
        m_coordinates[2] == rhs.m_coordinates[2];
}

double Point3D::AbsoluteValue() const noexcept {
    return std::sqrt(
        std::pow(m_coordinates[0], 2.0) +
        std::pow(m_coordinates[1], 2.0) +
        std::pow(m_coordinates[2], 2.0)
    );
}

double Point3D::distance(const Point3D &p1, const Point3D &p2) noexcept {
    return (p1 - p2).AbsoluteValue();
}

void Point3D::setCoordinate(double newCoordinate, int index) {
    if (index < 0 || index > 2) {
        throw std::exception("[Point3D::setCoordinate] Passing wrond coordinate index");
    }
    m_coordinates[index] = newCoordinate;
}

void Point3D::setCoordinate(double newX, double newY, double newZ) noexcept {
    m_coordinates = {newX, newY, newZ};
}
