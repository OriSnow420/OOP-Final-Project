// TODO: comments

#ifndef Point3D_hpp
#define Point3D_hpp

#include <initializer_list>
#include <vector>

class Point3D {

private:
    std::vector<double> m_coordinates;

public:
    explicit Point3D(std::initializer_list<double> 
    Ilist={0,0,0});
        
    Point3D(double x, double y, double z) noexcept;
    Point3D operator+(const Point3D& point) const noexcept;
    Point3D operator-(const Point3D& point) const noexcept;

    bool operator==(const Point3D& rhs) const noexcept;

    virtual double AbsoluteValue() const noexcept;

    static double distance(const Point3D& p1, const Point3D& p2) noexcept;

    double getCoordinate(int index) const;
    void setCoordinate(double newCoordinate, int index);
    void setCoordinate(double newX, double newY, double newZ) noexcept;
};

#endif
