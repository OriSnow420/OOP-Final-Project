/*************************************************************************
【文件名】Point3D.cpp
【功能模块和目的】实现Point3D.hpp中声明的函数
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了大部分函数的定义
    2024-07-27 新增Point3D坐标getter的定义
    2024-08-06 新增了Point3D重载流运算符函数的定义
*************************************************************************/

#include "header/Point3D.hpp"
#include <cmath>
#include <exception>
#include <initializer_list>
#include <ios>
#include <vector>

/*************************************************************************
【函数名称】Point3D::Point3D
【函数功能】通过初始化列表构造Point3D对象
【参数】
    Ilist: std::initializer_list类型。传入的列表。如果不指定默认为{0, 0, 0}
【返回值】构造函数无返回值
【异常】如果Ilist长度不合法会抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Point3D::Point3D(std::initializer_list<double> Ilist) :
m_coordinates(Ilist) {
    if (Ilist.size() != 3) {
        throw std::exception(
            "Passing wrong number of coordinates");
    }
}

/*************************************************************************
【函数名称】Point3D::Point3D
【函数功能】通过三个坐标值构造Point3D对象
【参数】
    x double类型，待构造的点的横坐标，无默认值
    y double类型，待构造的点的纵坐标，具有默认值0
    z double类型，待构造的点的竖坐标，具有默认值0
【返回值】构造函数无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Point3D::Point3D(double x, double y, double z) noexcept :
m_coordinates({x, y, z}) {}

/*************************************************************************
【函数名称】Point3D::operator+
【函数功能】将两个点的坐标分别相加
【参数】
    point: const Point&类型，和*this相加的另一个点。
【返回值】Point3D类型，相加的结果。
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Point3D Point3D::operator+(const Point3D& point) const noexcept {
    return Point3D(
        m_coordinates[0] + point.m_coordinates[0],
        m_coordinates[1] + point.m_coordinates[1],
        m_coordinates[2] + point.m_coordinates[2]
    );
}

/*************************************************************************
【函数名称】Point3D::operator-
【函数功能】将两个点的坐标分别相减
【参数】
    point: const Point&类型，作为减数。
【返回值】Point3D类型，相减的结果。
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Point3D Point3D::operator-(const Point3D& point) const noexcept {
    return Point3D(
        m_coordinates[0] - point.m_coordinates[0],
        m_coordinates[1] - point.m_coordinates[1],
        m_coordinates[2] - point.m_coordinates[2]
    );
}

/*************************************************************************
【函数名称】Point3D::operator==
【函数功能】判断两个点是否相等。若三坐标分别相等则认为两个点相等。
【参数】
    rhs: const Point3D&类型，==右侧用于比较的另一个点
【返回值】bool类型。若两个点相等返回true, 反之为false.
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
bool Point3D::operator==(const Point3D& rhs) const noexcept {
    return 
        m_coordinates[0] == rhs.m_coordinates[0] &&
        m_coordinates[1] == rhs.m_coordinates[1] &&
        m_coordinates[2] == rhs.m_coordinates[2];
}

/*************************************************************************
【函数名称】Point3D::AbsoluteValue()
【函数功能】计算点的绝对值，即与原点的欧几里得距离。为虚函数，便于Point3D的派生类重写
    距离函数，实现不同的功能。
【参数】无参数
【返回值】double类型，*this与原点的距离。
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
double Point3D::AbsoluteValue() const noexcept {
    return std::sqrt(
        std::pow(m_coordinates[0], 2.0) +
        std::pow(m_coordinates[1], 2.0) +
        std::pow(m_coordinates[2], 2.0)
    ); // Calcluate the euclid distance.
}
/*************************************************************************
【函数名称】Point3D::distance
【函数功能】基于AbsoluteValue()计算两个点的距离。
【参数】
    p1: const Point3D&类型，第一个点
    p2: const Point3D&类型，第二个点
【返回值】double类型，返回计算的结果
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
double Point3D::Distance(const Point3D &p1, const Point3D &p2) noexcept {
    return (p1 - p2).AbsoluteValue();
}

/*************************************************************************
【函数名称】Point3D::setCoordinate
【函数功能】设置单个坐标
【参数】
    newCoordinate: double类型，新的坐标值
    index: int类型，值应该为0, 1, 2中的一个，表示要改变哪个坐标值
【返回值】无返回值
【异常】如果index为不合法输入会抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Point3D::SetCoordinate(double newCoordinate, int index) {
    if (index < 0 || index > 2) {
        throw std::exception(
            "Passing wrong coordinate index");
    }
    m_coordinates[index] = newCoordinate;
}

/*************************************************************************
【函数名称】Point3D::setCoordinate
【函数功能】设置点的新坐标
【参数】
    newX: double类型，新的横坐标
    newY: double类型，新的纵坐标
    newZ: double类型，新的竖坐标
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Point3D::SetCoordinate(double newX, double newY, double newZ) noexcept {
    m_coordinates = {newX, newY, newZ};
}

/*************************************************************************
【函数名称】Point3D::getCoordinate
【函数功能】获取点的单个坐标
【参数】
    index: int类型，合法值为0, 1, 2，表示要获取哪个坐标
【返回值】double类型，获取到的坐标值
【异常】如果index为不合法输入会抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
double Point3D::GetCoordinate(int index) const {
    if(index < 0 || index >= 3) {
        throw std::exception("Index out of range!");
    }
    return m_coordinates[index];
}

/*************************************************************************
【函数名称】operator<<
【函数功能】将Point3D以(x, y, z)的格式输出到流中
【参数】
    out: std::ostrema&类型，要输出的流
    point: const Point3D&类型，要输出的点
【返回值】std::ostream&类型，输出完毕后的out本身
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
std::ostream& operator<<(std::ostream& out, const Point3D& point) {
    out << "(" << point.GetCoordinate(0) << ", "
               << point.GetCoordinate(1) << ", "
               << point.GetCoordinate(2) << ")";
    return out;
}

/*************************************************************************
【函数名称】operator>>
【函数功能】
    以(x, y, z)格式从流中获取Point3D类型。括号内部的空格将被忽略，不合
    法的输入将使得in变为failbit状态。
【参数】
    in: std::istrema&类型，输入的流
    point: Point3D&类型，待输入的点
【返回值】std::istream&类型，输入完毕后的in本身
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
std::istream& operator>>(std::istream& in, Point3D& point) {
    char leftParentheses;
    char comma1;
    char comma2;
    char rightParentheses;
    Point3D p;
    if (in >> leftParentheses && leftParentheses == '(') {
        double num[3];
        in >> num[0] >> comma1 >> num[1] >> 
                        comma2 >> num[2] >> rightParentheses;
        if (comma1 != ',' || comma2 != ',' || rightParentheses != ')') {
            // Invalid Inputs.
            in.setstate(std::ios_base::failbit); 
            return in; 
        }
        // Valid Inputs.
        point.SetCoordinate(num[0], num[1], num[2]);
        return in;
    }
    // Not begin with a '('
    in.setstate(std::ios_base::failbit);
    return in;
}
