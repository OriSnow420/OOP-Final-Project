// TODO: file comment

#ifndef Face3D_hpp
#define Face3D_hpp

#include "MultiPoint.hpp"
#include "Point3D.hpp"
#include <initializer_list>

class Face3D : public MultiPoint<3>{
public:
    explicit Face3D(std::initializer_list<Point3D> iList);

    Face3D(const Point3D& point1, const Point3D& point2, const Point3D& point3) noexcept;

    double area() const noexcept;
};

#endif
