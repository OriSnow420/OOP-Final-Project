/*************************************************************************
【文件名】Face3D.cpp
【功能模块和目的】为Face3D类提供函数定义
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了大部分函数定义
*************************************************************************/

#include "header/Face3D.hpp"
#include "header/Point3D.hpp"
#include <cmath>

/*************************************************************************
【函数名称】Face3D::Face3D
【函数功能】通过初始化列表构造Face3D
【参数】
    Ilist: 用于构造的初始化列表
【返回值】无返回值
【异常】若Ilist长度不为3则抛出异常；若存在重复点则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Face3D::Face3D(std::initializer_list<Point3D> Ilist):
MultiPoint<3>(Ilist){}

/*************************************************************************
【函数名称】Face3D::Face3D
【函数功能】通过三个点构造Face3D
【参数】
    point1: 第一个点
    point2: 第二个点
【返回值】无返回值
【异常】若Ilist长度不为3则抛出异常；若存在重复点则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Face3D::Face3D(const Point3D& point1, 
               const Point3D& point2, const Point3D& point3): 
MultiPoint<3>({point1, point2, point3}) {}

/*************************************************************************
【函数名称】Face3D::area
【函数功能】计算三角形面积
【参数】无参数
【返回值】double类型，三角形的面积
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
double Face3D::area() const noexcept {
    auto points = getPoints();
    double a = Point3D::distance(points[0], points[1]);
    double b = Point3D::distance(points[1], points[2]);
    double c = Point3D::distance(points[2], points[0]);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); // Heron's Formula
}
