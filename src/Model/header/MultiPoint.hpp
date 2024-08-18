/*************************************************************************
【文件名】MultiPoint.hpp
【功能模块和目的】提供了MultiPoint类的声明和函数实现
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了绝大多数函数的定义
    2024-08-13 为MultiPoint重载<<运算符
    2024-08-16 为构造函数加入了重复点检查
*************************************************************************/

#ifndef MULTIPOINT_HPP
#define MULTIPOINT_HPP

#include "Point3D.hpp"
#include <algorithm>
#include <cstddef>
#include <exception>
#include <initializer_list>
#include <ostream>
/*************************************************************************
【类名】MultiPoint
【功能】表示多个点的集合体，作为Line3D和Face3D的共同基类
【模板参数】
    N: size_t类型，集合体中点的数量
【接口说明】

【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了大部分函数的定义
    2024-08-13 为MultiPoint重载<<运算符
*************************************************************************/
template<size_t N>
class MultiPoint {

private:
    std::vector<Point3D> m_points; // The Points
    void AssertNoDuplicate(
        const std::vector<Point3D>& PointList);

    virtual void InnerSet(const Point3D& newPoint, int index);
public:

    // Default copy constructor and copy assignment.
    MultiPoint<N>& operator=(const MultiPoint<N>&) = default;
    MultiPoint(const MultiPoint<N>&) = default;

    // Construct with Ilist.
    MultiPoint(std::initializer_list<Point3D> Ilist = {});

    // Destructor.
    ~MultiPoint();

    // Equality check.
    bool operator==(const MultiPoint<N>& rhs) const noexcept;

    // Point getter.
    std::vector<Point3D> GetPoints() const;

    // Point Getter.
    Point3D GetPoint(int index) const;

    // Overload <<. Format: [(x1, y1, z1), (x2, y2, z2), ...]
    template<size_t M>
    friend std::ostream& operator<<
    (std::ostream& out, const MultiPoint<M>& points); 

    // Setter.
    void SetPoint(const Point3D& newPoint, int index);


};
/*************************************************************************
【函数名称】MultiPoint::InnerSet
【函数功能】更改单个点。是虚函数，支持派生类有特殊修改规则。
【参数】
    newPoint: const Point3D&类型，修改后的点
    index: 待修改的点的下标，应为0~N-1
【返回值】无返回值
【异常】若index为不合法输入则抛出异常。修改后有重复点则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
template<size_t N>
void MultiPoint<N>::InnerSet(const Point3D& newPoint, int index) {
    if (index < 0 || index >= N) {
        // Index Error, throws
        throw std::exception(
            "Passing wrong number of arguments");
    }
    if (newPoint == m_points[index]) {
        // Point is the same. Do nothing
        return;
    } else {
        // Try modifying the point
        if (std::find(m_points.begin(), m_points.end(), 
        newPoint) != m_points.end()) {
            // Duplicate point, throws.
            throw std::exception("Duplicate Points!");
        }
    }
    // Everything goes well.
    m_points[index] = newPoint;
}

/*************************************************************************
【函数名称】MultiPoint::AssertNoDuplicate
【函数功能】断言PointList中没有重复点。如果有，抛出异常。
【参数】
    PointList: std::vector<Point3D>类型，待判断的点列
【返回值】无返回值
【异常】若PointList中存在重复点则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-16
【更改记录】
    2024-08-16 完成了函数定义
*************************************************************************/
template<size_t N>
void MultiPoint<N>::AssertNoDuplicate(const std::vector<Point3D>& PointList) {
    if (PointList.size() <= 32) {
        // Small List, use o(n^2) algorithm
        for (int i = 0; i < PointList.size(); i++) {
            for(int j = i + 1; j < PointList.size(); j++) {
                if (PointList[i] == PointList[j]) {
                    throw std::exception("Duplicate Points!");
                }
            }
        }
    } else {
        // Large List, use o(nlog n) algorithm
        std::vector newList {PointList};
        std::sort(newList.begin(), newList.end(),
        [](const Point3D& lhs, const Point3D& rhs)->bool {
            for(int i = 0; i < 3; i++) {
                if (lhs.GetCoordinate(i) != rhs.GetCoordinate(i)) {
                    return lhs.GetCoordinate(i) > rhs.GetCoordinate(i);
                }
            }
            return false;
        });
        for (int i = 0; i < newList.size() - 1; i++) {
            if (newList[i] == newList[i + 1]) {
                throw std::exception("Duplicate Points!");
            }
        }
    }
}

/*************************************************************************
【函数名称】MultiPoint::MultiPoint
【函数功能】构造函数
【参数】
    Ilist: std::initializer_list<Point3D>类型，包含点的列表。
【返回值】无返回值
【异常】若Ilist长度不合法则抛出异常。有重复点则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
    2024-08-16 在构造时会检查是否有重复点，若有会抛出异常
*************************************************************************/
template<size_t N>
MultiPoint<N>::MultiPoint(std::initializer_list<Point3D> Ilist = {}) :
m_points(Ilist) {
    if (Ilist.size() != N) {
        throw std::exception(
            "Passing wrong number of arguments");
    }
    AssertNoDuplicate(Ilist); // Ilist converted to vector.
}

/*************************************************************************
【函数名称】MultiPoint::~MultiPoint
【函数功能】默认析构函数
【参数】无参数。
【返回值】无返回值。
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
template<size_t N>
MultiPoint<N>::~MultiPoint() {}

/*************************************************************************
【函数名称】MultiPoint::operator==
【函数功能】判断两个MultiPoint是否相等，忽略点的顺序
【参数】
    rhs: const MultiPoint<N>&类型，==右手侧的待比较对象。
【返回值】返回比较结果
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
template<size_t N>
bool MultiPoint<N>::operator==(const MultiPoint<N>& rhs) const noexcept {
    for (const auto& point : m_points) {
        if (std::find(rhs.m_points.begin(), rhs.m_points.end(), point) 
            == rhs.m_points.end()) {
            return false;
        }
    }
    return true;
}

/*************************************************************************
【函数名称】MultiPoint::SetPoint
【函数功能】更改单个点，为public接口，调用内部的InnerSet
【参数】
    newPoint: const Point3D&类型，修改后的点
    index: 待修改的点的下标，应为0~N-1
【返回值】无返回值
【异常】若index为不合法输入则抛出异常。修改后有重复点则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
template<size_t N>
void MultiPoint<N>::SetPoint(const Point3D& newPoint, int index) {
    InnerSet(newPoint, index);
}

/*************************************************************************
【函数名称】MultiPoint::GetPoints
【函数功能】获取所有点的坐标
【参数】无参数
【返回值】std::vector<Point3D>类型，存储所有点的坐标
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
template<size_t N>
std::vector<Point3D> MultiPoint<N>::GetPoints() const noexcept {
    return m_points;
}

/*************************************************************************
【函数名称】MultiPoint::GetPoint
【函数功能】获取单个点的坐标
【参数】
    index: int类型，获取点坐标的下标
【返回值】Point3D类型，获取到的点
【异常】若index为不合法输入则抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
template<size_t N>
Point3D MultiPoint<N>::GetPoint(int index) const {
    if(index < 0 || index >= N){
        throw std::exception(
            "Passing wrong index!");
    }
    return m_points[index];
}

/*************************************************************************
【函数名称】operator<<
【函数功能】将MultiPoint对象输出到流中
【模板参数】
    M: 待输出的MultiPoint点的个数
【参数】
    std::ostream&类型 待输出的流
    points: const MultiPoint<M>& 待输出的MultiPoint
【返回值】std::ostream&类型，返回输出后的out本身
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-13
【更改记录】
    2024-08-13 完成了函数定义
*************************************************************************/
template<size_t M>
inline std::ostream& operator<<
(std::ostream& out, const MultiPoint<M>& points) {
    out << "[";
    for (int i = 0; i < points.m_points.size(); i++) {
        out << points.m_points[i];
        if (i < points.m_points.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

#endif
