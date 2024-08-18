/*************************************************************************
【文件名】Model3D.hpp
【功能模块和目的】为Model3D提供声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了Model3D的大部分功能
    2024-08-06 添加了Model3D::empty()函数
    2024-08-09 为Model添加了默认拷贝构造和拷贝赋值
*************************************************************************/

#ifndef MODEL3D_HPP
#define MODEL3D_HPP

#include "Face3D.hpp"
#include "Line3D.hpp"
#include "Point3D.hpp"
#include <initializer_list>
#include <string>
#include <vector>
/*************************************************************************
【类名】Model3D
【功能】模拟三维模型
【接口说明】
    通过名字，线段列表，面列表的构造函数
    默认析构函数
    默认拷贝构造/拷贝复制函数
    获取点/线/面集合
    获取线/面数量
    更改线/面
    增加/删除线/面
    获取/更改模型名字
    查看模型是否为空
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了Model3D的大部分功能
    2024-08-06 添加了Model3D::empty()函数
    2024-08-09 为Model添加了默认拷贝构造和拷贝赋值
*************************************************************************/
class Model3D {

private:
    std::vector<Line3D> m_lines;
    std::vector<Face3D> m_faces;
    std::string m_name;

public:
    // Constructor
    explicit Model3D(
        std::string name="", 
        std::initializer_list<Line3D> lineList={}, 
        std::initializer_list<Face3D> faceList={}
    ) noexcept;

    // Default Destructor
    virtual ~Model3D() = default;

    // Default Copy Stuff
    Model3D& operator=(const Model3D&) = default;
    Model3D(const Model3D&) = default;

    // Getters
    std::vector<Point3D> GetPoints() const noexcept;
    std::vector<Line3D> GetLines() const noexcept;
    std::vector<Face3D> GetFaces() const noexcept;

    // Count getters
    int LineCount() const noexcept;
    int FaceCount() const noexcept;

    // Modifiy a Line/Face
    void ModifyLine(int index, int whichPoint, const Point3D& newPoint);
    void ModifyFace(int index, int whichPoint, const Point3D& newPoint);

    // Remover
    void RemoveLine(int index);
    void RemoveFace(int index);

    // Adder
    void AddLine(const Line3D& newLine);
    void AddFace(const Face3D& newFace);

    // Things related to name
    std::string GetName() const noexcept;
    void ModifyName(const std::string& newName) noexcept;

    // Check if the model is empty(no faces && no lines)
    bool Empty() const;

};

#endif
