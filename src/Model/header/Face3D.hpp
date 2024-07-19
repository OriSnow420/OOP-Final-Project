// TODO: file comment

#ifndef Face3D_hpp
#define Face3D_hpp

#include "Point3D.hpp"
#include <initializer_list>
#include <vector>

class Face3D {

private:
    std::vector<Point3D> m_points;

public:
    explicit Face3D(std::initializer_list<Point3D> iList);

    Face3D(const Point3D& point1, const Point3D& point2, const Point3D& point3) noexcept;

    bool operator==(const Face3D& rhs) const noexcept;

    double area() const noexcept;

    void setPoint(const Point3D& newPoint, int index);

    std::vector<Point3D> getPoints() const noexcept;
    Point3D getPoint(int index) const;

};

#endif
