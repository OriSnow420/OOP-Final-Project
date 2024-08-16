/*************************************************************************
【文件名】Point3D.hpp
【功能模块和目的】包含了Point3D类的声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了Point3D绝大部分函数的声明
    2024-07-27 为Point3D新增获取单个坐标的getter
    2024-08-06 为Point3D新增了流运算符<<和>>的重载
    2024-08-16 为文件完善了注释和代码规范
*************************************************************************/

#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <initializer_list>
#include <vector>
#include <iostream>

/*************************************************************************
【类名】Point3D
【功能】模拟三维空间中点的行为
【接口说明】
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了绝大部分函数的声明
    2024-07-27 新增获取单个坐标的getter
    2024-08-06 新增了流运算符<<和>>的重载
*************************************************************************/
class Point3D {

private:
    std::vector<double> m_coordinates;

public:
    // Construct with initializer_list containing coordinates
    explicit Point3D(std::initializer_list<double> 
        Ilist = {0,0,0});
    
    // Construct with coordinates
    explicit Point3D(double x, double y = 0, double z = 0) noexcept;

    // Default Copy Constructor and Assignment
    Point3D(const Point3D&) = default;
    Point3D& operator=(const Point3D&) = default;

    // Default Destructor
    ~Point3D() = default;

    // Add/Substract each coordinate respectively
    // e.g. (1, 3, 2) + (1, 1, 1) == (2, 4, 3)
    Point3D operator+(const Point3D& point) const noexcept;
    Point3D operator-(const Point3D& point) const noexcept;

    // True when each coordinate is equal.
    bool operator==(const Point3D& rhs) const noexcept;

    // Distance from (0, 0, 0). Default implementation returns euclid distance.
    virtual double AbsoluteValue() const noexcept;

    // Returns AbsoulteValue(p1 - p2)
    static double distance(const Point3D& p1, const Point3D& p2) noexcept;

    // index should be 0, 1, 2. Returns m_coordinates[index].
    double getCoordinate(int index) const;

    // Coordinate Setters.
    void setCoordinate(double newCoordinate, int index);
    void setCoordinate(double newX, double newY, double newZ) noexcept;

    // Input and Output. Format is (x, y, z) where x, y, z are the coordinates.
    friend std::ostream& operator<<(std::ostream& out, const Point3D& point);
    friend std::istream& operator>>(std::istream& in, Point3D& point);
};

#endif
