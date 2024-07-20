// TODO: comment

#ifndef Line3D_hpp
#define Line3D_hpp

#include "MultiPoint.hpp"
#include "Point3D.hpp"
#include <initializer_list>

class Line3D : public MultiPoint<2>{

public:
    explicit Line3D(std::initializer_list<Point3D> Ilist);

    Line3D(const Point3D& point1, const Point3D& point2) noexcept;

    double length() const noexcept;
    
};

#endif
