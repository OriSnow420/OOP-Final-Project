/*************************************************************************
【文件名】Model3D.cpp
【功能模块和目的】为Model3D提供实现
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了大部分的函数实现
    2024-08-06 添加了Model3D::empty()函数
*************************************************************************/

#include "header/Model3D.hpp"
#include "header/Face3D.hpp"
#include "header/Line3D.hpp"
#include "header/Point3D.hpp"
#include <exception>
#include <initializer_list>

/*************************************************************************
【函数名称】Model3D::Model3D
【函数功能】构造函数
【参数】
    name: 模型的名字
    lineList: 线段列表
    faceList: 面的列表
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
Model3D::Model3D(std::string name, std::initializer_list<Line3D> lineList, 
    std::initializer_list<Face3D> faceList) noexcept : 
    m_lines(lineList), m_faces(faceList), m_name(name) {}

/*************************************************************************
【函数名称】Model3D::getPoints
【函数功能】获取点的列表
【参数】无参数
【返回值】点的列表
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
std::vector<Point3D> Model3D::getPoints() const noexcept {
    std::vector<Point3D> result;
    for (const auto& line : m_lines) {
        for (const auto& point : line.getPoints()) {
            result.push_back(point);
        }
    }
    for (const auto& face : m_faces) {
        for (const auto& point : face.getPoints()) {
            result.push_back(point);
        }
    }
    return result;
}

/*************************************************************************
【函数名称】Model3D::getLines
【函数功能】获取线端的列表
【参数】无参数
【返回值】线段的列表
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
std::vector<Line3D> Model3D::getLines() const noexcept {
    return m_lines;
}

/*************************************************************************
【函数名称】Model3D::getFaces
【函数功能】获取面的列表
【参数】无参数
【返回值】面的列表
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
std::vector<Face3D> Model3D::getFaces() const noexcept {
    return m_faces;
}

/*************************************************************************
【函数名称】Model3D::line_count
【函数功能】获取线的数量
【参数】无参数
【返回值】线的数量
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
int Model3D::line_count() const noexcept {
    return m_lines.size();
}

/*************************************************************************
【函数名称】Model3D::line_count
【函数功能】获取面的数量
【参数】无参数
【返回值】面的数量
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
int Model3D::face_count() const noexcept {
    return m_faces.size();
}

/*************************************************************************
【函数名称】Model3D::modifyLine
【函数功能】更改线段
【参数】
    index 线段的下标
    whichPoint 点在线段内部的序号 合法值为0, 1
    newPoint 修改后的点
【返回值】无返回值
【异常】当index下标越界或whichPoint为非法值会抛出异常；修改后线段有重复点会抛出异常；
    修改后的线段与原有线段重合会抛出异常。
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
    2024-08-13 增加了重复线段检查
*************************************************************************/
void Model3D::modifyLine(int index, int whichPoint, const Point3D& newPoint){
    if(index < 0 || index >= line_count()){
        throw std::exception("Index out of range Error!");
    }
    Line3D newLine = m_lines[index];
    newLine.setPoint(newPoint, whichPoint);
    if (newLine != m_lines[index] && std::find(
        m_lines.begin(), m_lines.end(), newLine
    ) != m_lines.end()) {
        throw std::exception("Duplicate Lines!");
    } else {
        m_lines[index].setPoint(newPoint, whichPoint);
    }
}

/*************************************************************************
【函数名称】Model3D::modifyFace
【函数功能】更改面
【参数】
    index 面的下标
    whichPoint 点在面内部的序号 合法值为0, 1, 2
    newPoint 修改后的点
【返回值】无返回值
【异常】当index下标越界或whichPoint为非法值会抛出异常；修改后面有重复点会抛出异常；
    修改后的面与原有面重合会抛出异常。
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
    2024-08-13 增加了重复面检查
*************************************************************************/
void Model3D::modifyFace(int index, int whichPoint, const Point3D& newPoint){
    if(index < 0 || index >= face_count()){
        throw std::exception("Index out of range Error!");
    }
    Face3D newFace = m_faces[index];
    newFace.setPoint(newPoint, whichPoint);
    if (newFace != m_faces[index] && std::find(
        m_faces.begin(), m_faces.end(), newFace
    ) != m_faces.end()) {
        throw std::exception("Duplicate Faces!");
    }
}

/*************************************************************************
【函数名称】Model3D::removeLine
【函数功能】删除线段
【参数】
    index 线段的下标
【返回值】无返回值
【异常】当index下标越界会抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Model3D::removeLine(int index){
    if(index < 0 || index >= line_count()){
        throw std::exception("Index out of range Error!");
    }
    m_lines.erase(m_lines.begin() + index);
}

/*************************************************************************
【函数名称】Model3D::removeFace
【函数功能】删除面
【参数】
    index 面的下标
【返回值】无返回值
【异常】当index下标越界会抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Model3D::removeFace(int index){
    if(index < 0 || index >= face_count()){
        throw std::exception("Index out of range Error!");
    }
    m_faces.erase(m_faces.begin() + index);
}

/*************************************************************************
【函数名称】Model3D::addLine
【函数功能】新增线段
【参数】
    newLine 新的线段
【返回值】无返回值
【异常】当模型中已有相同线段时抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Model3D::addLine(const Line3D& newLine){
    if (std::find(m_lines.begin(), 
        m_lines.end(), newLine) != m_lines.end()) {
        throw std::exception("Same Line already exists!");
    }
    m_lines.push_back(newLine);
}

/*************************************************************************
【函数名称】Model3D::addFace
【函数功能】新增面
【参数】
    newLine 新的面
【返回值】无返回值
【异常】当模型中已有相同面时抛出异常
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Model3D::addFace(const Face3D& newFace){
    if (std::find(m_faces.begin(), 
        m_faces.end(), newFace) != m_faces.end()) {
        throw std::exception("Same Face already exists!");
    }
    m_faces.push_back(newFace);
}

/*************************************************************************
【函数名称】Model3D::getName
【函数功能】获取模型名字
【参数】无参数
【返回值】模型的名字
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
std::string Model3D::getName() const noexcept {
    return m_name;
}

/*************************************************************************
【函数名称】Model3D::modifyName
【函数功能】更改模型名字
【参数】
    newName: 模型的新名字
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了函数定义
*************************************************************************/
void Model3D::modifyName(const std::string& newName) noexcept {
    m_name = newName;
}

/*************************************************************************
【函数名称】Model3D::empty
【函数功能】判断模型是否为空
【参数】无参数
【返回值】若模型为空返回true
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
bool Model3D::empty() const {
    return m_lines.empty() && m_faces.empty();
}
