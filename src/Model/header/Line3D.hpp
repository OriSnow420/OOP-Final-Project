/*************************************************************************
【文件名】Line3D.hpp
【功能模块和目的】提供了Line3D类的声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了绝大多数函数的声明
    2024-08-16 为Line3D加入了默认构造和析构函数
*************************************************************************/

#ifndef LINE3D_HPP
#define LINE3D_HPP

#include "MultiPoint.hpp"
#include "Point3D.hpp"
#include <initializer_list>

/*************************************************************************
【类名】Line3D
【功能】模拟三维模型中的线段
【接口说明】
    公有继承得到父类全部接口
    通过初始化列表/三个点构造
    默认构造函数
    默认拷贝赋值/构造函数
    计算长度函数
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了绝大多数函数的声明
    2024-08-16 加入了默认构造和析构函数
*************************************************************************/
class Line3D : public MultiPoint<2>{

public:
    // Constructors
    explicit Line3D(std::initializer_list<Point3D> Ilist);
    explicit Line3D(
        const Point3D& point1 = Point3D(), 
        const Point3D& point2 = Point3D());

    // Default Destructor
    virtual ~Line3D() = default;

    // Default copy assignment and constructor
    Line3D& operator=(const Line3D&) = default;
    Line3D(const Line3D&) = default;

    // The length of the line.
    double Length() const noexcept;
    
};

#endif
