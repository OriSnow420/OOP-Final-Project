/*************************************************************************
【文件名】Line3D.hpp
【功能模块和目的】提供了Line3D类的声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了绝大多数函数的声明
    2024-08-16 为Line3D加入了默认构造和析构函数
*************************************************************************/

#ifndef Line3D_hpp
#define Line3D_hpp

#include "MultiPoint.hpp"
#include "Point3D.hpp"
#include <initializer_list>

/*************************************************************************
【类名】Line3D
【功能】模拟三维模型中的线段
【接口说明】         （必需）
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了绝大多数函数的声明
    2024-08-16 加入了默认构造和析构函数
*************************************************************************/
class Line3D : public MultiPoint<2>{

public:
    // Constructors
    explicit Line3D(std::initializer_list<Point3D> Ilist);
    explicit Line3D(const Point3D& point1 = Point3D(), 
                    const Point3D& point2 = Point3D());

    // Default Destructor
    ~Line3D() = default;

    // Default copy assignment and constructor
    Line3D& operator=(const Line3D&) = default;
    Line3D(const Line3D&) = default;

    // The length of the line.
    double length() const noexcept;
    
};

#endif
