// TODO: comment

#ifndef Line3D_hpp
#define Line3D_hpp

#include "Point3D.hpp"
#include <initializer_list>
#include <vector>

class Line3D {

private:
    std::vector<Point3D> m_points;

public:
    explicit Line3D(std::initializer_list<Point3D> Ilist);

    Line3D(const Point3D& point1, const Point3D& point2) noexcept;

    bool operator==(const Line3D& rhs) const noexcept;

    double length() const noexcept;

    void setPoint(const Point3D& newPoint, int index);

    std::vector<Point3D> getPoints() const noexcept;
    Point3D getPoint(int index) const;
     
};

#endif
