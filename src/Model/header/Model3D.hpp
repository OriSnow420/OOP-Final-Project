/*************************************************************************
【文件名】Model3D.hpp
【功能模块和目的】为Model3D提供声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-07-20 完成了Model3D的大部分功能
    2024-08-06 添加了Model3D::empty()函数
    2024-08-09 为Model添加了默认拷贝构造和拷贝赋值
*************************************************************************/

#ifndef Model3D_hpp
#define Model3D_hpp

#include "Face3D.hpp"
#include "Line3D.hpp"
#include "Point3D.hpp"
#include <initializer_list>
#include <string>
#include <vector>
/*************************************************************************
【类名】Model3D
【功能】模拟三维模型
【接口说明】         （必需）
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
    ~Model3D() = default;

    // Default Copy Stuff
    Model3D& operator=(const Model3D&) = default;
    Model3D(const Model3D&) = default;

    // Getters
    std::vector<Point3D> getPoints() const noexcept;
    std::vector<Line3D> getLines() const noexcept;
    std::vector<Face3D> getFaces() const noexcept;

    // Count getters
    int line_count() const noexcept;
    int face_count() const noexcept;

    // Modifiy a Line/Face
    void modifyLine(int index, int whichPoint, const Point3D& newPoint);
    void modifyFace(int index, int whichPoint, const Point3D& newPoint);

    // Remover
    void removeLine(int index);
    void removeFace(int index);

    // Adder
    void addLine(const Line3D& newLine);
    void addFace(const Face3D& newFace);

    // Things related to name
    std::string getName() const noexcept;
    void modifyName(const std::string& newName) noexcept;

    // Check if the model is empty(no faces && no lines)
    bool empty() const;

};

#endif
