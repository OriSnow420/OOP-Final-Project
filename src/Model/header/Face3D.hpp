/*************************************************************************
【文件名】Face3D.hpp
【功能模块和目的】为Face3D提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数声明
*************************************************************************/

#ifndef FACE3D_HPP
#define FACE3D_HPP

#include "MultiPoint.hpp"
#include "Point3D.hpp"
#include <initializer_list>

/*************************************************************************
【类名】Face3D
【功能】模拟三维模型中的面
【接口说明】
    公有继承得到父类全部接口
    通过初始化列表/三个点构造
    默认构造函数
    默认拷贝赋值/构造函数
    计算面积函数
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数声明
*************************************************************************/
class Face3D : public MultiPoint<3>{

public:
    // Constructors
    explicit Face3D(std::initializer_list<Point3D> iList);
    Face3D(
        const Point3D& point1 = Point3D(),
        const Point3D& point2 = Point3D(), 
        const Point3D& point3 = Point3D());

    // Default Destructor
    virtual ~Face3D() = default;

    // Default copy constructor and assignment.
    Face3D& operator=(const Face3D&) = default;
    Face3D(const Face3D&) = default;

    // Calculate the area
    double Area() const noexcept;
};

#endif
