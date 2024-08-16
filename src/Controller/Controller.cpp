/*************************************************************************
【文件名】Controller.hpp
【功能模块和目的】为Controller提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-08-06 完成了大部分函数声明和其中模板函数的实现
    2024-08-09 完善了错误处理
*************************************************************************/
#include "header/Controller.hpp"
#include <algorithm>
#include <exception>
#include <memory>
#include <optional>
#include <string>
#include <vector>

// Initialize the m_Ptr
std::shared_ptr<Controller> Controller::m_Ptr = nullptr;

/*************************************************************************
【函数名称】Controller::Controller
【函数功能】通过importer和exporter指针构造新Controller对象
【参数】
    importer: 导入器的指针
    exporter: 导出器的指针
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
Controller::Controller(Importer* importer, Exporter* exporter) :
    m_pImporter(importer), m_pExporter(exporter), 
    m_pModel(new Model3D()) {}

/*************************************************************************
【函数名称】Controller::~Controller
【函数功能】默认析构函数
【参数】无参数
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
Controller::~Controller() {}

/*************************************************************************
【函数名称】Controller::getFace
【函数功能】获取模型中面的集合
【参数】无参数
【返回值】返回面的集合
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
std::vector<Face3D> Controller::getFace() const noexcept{
    return m_pModel->getFaces();
}

/*************************************************************************
【函数名称】Controller::deleteFace
【函数功能】删除模型中指定的面
【参数】
    index 删除面的下标
【返回值】bool类型，反应删除操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::deleteFace(int index) noexcept{
    try {
    m_pModel->removeFace(index);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::addFace
【函数功能】向模型中增加面
【参数】
    point{1,2,3} 新的面的三个点
【返回值】bool类型，反应增加操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::addFace(const Point3D& point1, const Point3D& point2,
                         const Point3D& point3) noexcept {
    try {
        m_pModel->addFace(Face3D(point1, point2, point3));
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::pointsInFace
【函数功能】获取指定面中的点
【参数】
    index 指定面的下标
【返回值】std::optional<...>类型, 若获取出错, 返回std::nullopt；若获取成功，返回
    有值的optional
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由std::vector<Point3D>
        变为std::optional<std::vector<Point3D>>
*************************************************************************/
std::optional<std::vector<Point3D>> Controller::pointsInFace
(int index) const noexcept {
    try {
        return m_pModel->getFaces().at(index).getPoints();
    } catch (std::exception e) {
        return std::nullopt;
    }
}

/*************************************************************************
【函数名称】Controller::modifyPointInFace
【函数功能】更改指定面中的一个点
【参数】
    index 指定面的下标
    whichPoint 指定面中点的序号，有效值为0, 1, 2
    newPoint 新的点
【返回值】bool类型，反应修改操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::modifyPointInFace(int index, int whichPoint,
                                   const Point3D& newPoint) noexcept {
    try {
        m_pModel->modifyFace(index, whichPoint, newPoint);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::modifyPointInLine
【函数功能】更改指定线段中的一个点
【参数】
    index 指定线段的下标
    whichPoint 指定线段中点的序号，有效值为0, 1
    newPoint 新的点
【返回值】bool类型，反应修改操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::modifyPointInLine(int index, int whichPoint,
                                   const Point3D& newPoint) noexcept {
    try {
        m_pModel->modifyLine(index, whichPoint, newPoint);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::getLine
【函数功能】获取模型中线段的集合
【参数】无参数
【返回值】返回线段的集合
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
std::vector<Line3D> Controller::getLine() const noexcept {
    return m_pModel->getLines();
}

/*************************************************************************
【函数名称】Controller::deleteLine
【函数功能】删除模型中指定的线段
【参数】
    index 删除线段的下标
【返回值】bool类型，反应删除操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::deleteLine(int index) noexcept {
    try { 
        m_pModel->removeLine(index);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::addLine
【函数功能】向模型中增加线段
【参数】
    point{1,2} 新的线段的两个点
【返回值】bool类型，反应增加操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::addLine(const Point3D& point1, const Point3D& point2) 
noexcept{
    try {
        m_pModel->addLine(Line3D(point1, point2));
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::pointsInLine
【函数功能】获取指定线段中的点
【参数】
    index 指定线段的下标
【返回值】std::optional<...>类型, 若获取出错, 返回std::nullopt；若获取成功，返回
    有值的optional
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由std::vector<Point3D>
        变为std::optional<std::vector<Point3D>>
*************************************************************************/
std::optional<std::vector<Point3D>> Controller::pointsInLine(int index) 
const noexcept {
    try {
        return m_pModel->getLines().at(index).getPoints();
    } catch (std::exception e) {
        return std::nullopt;
    }
}

/*************************************************************************
【函数名称】Controller::showStat
【函数功能】获取模型中的统计信息
【参数】无参数
【返回值】Controller::Statistics类型，包含程序需要的统计信息
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
Controller::Statistics Controller::showStat() const noexcept{
    auto faces = m_pModel->getFaces();
    auto lines = m_pModel->getLines();
    double face_area = 0.0;
    double line_length = 0.0;

    std::for_each(faces.begin(), faces.end(), 
    [&](const Face3D& face)->void {
        face_area += face.area();
    });
    std::for_each(lines.begin(), lines.end(), 
    [&](const Line3D& line)->void {
        line_length += line.length();
    });
    return Statistics{
        m_pModel->face_count(),
        face_area,
        m_pModel->line_count(),
        line_length,
        3 * m_pModel->face_count() + 2 * m_pModel->line_count(),
        calculateAABB()
    };
}

/*************************************************************************
【函数名称】Controller::calculateAABB
【函数功能】计算模型的包围盒体积
【参数】无参数
【返回值】返回包围盒的体积
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
*************************************************************************/
double Controller::calculateAABB() const {
    double result = 0.0;
    if (!m_pModel->empty()) {
        auto points = m_pModel->getPoints();
        // {x_max, x_min, y_max, y_min, z_max, z_min}
        double MaxAndMins[6] = {
            points.at(0).getCoordinate(0),
            points.at(0).getCoordinate(0),
            points.at(0).getCoordinate(1),
            points.at(0).getCoordinate(1),
            points.at(0).getCoordinate(2),
            points.at(0).getCoordinate(2)
        };
        std::for_each(points.begin() + 1, points.end(), 
        [&MaxAndMins](const Point3D& point)->void {
            MaxAndMins[0] = MaxAndMins[0] < point.getCoordinate(0) 
            ? point.getCoordinate(0) : MaxAndMins[0];
            MaxAndMins[1] = MaxAndMins[1] > point.getCoordinate(0) 
            ? point.getCoordinate(0) : MaxAndMins[1];
            MaxAndMins[2] = MaxAndMins[2] < point.getCoordinate(1) 
            ? point.getCoordinate(1) : MaxAndMins[2];
            MaxAndMins[3] = MaxAndMins[3] > point.getCoordinate(1) 
            ? point.getCoordinate(1) : MaxAndMins[3];
            MaxAndMins[4] = MaxAndMins[4] < point.getCoordinate(2) 
            ? point.getCoordinate(2) : MaxAndMins[4];
            MaxAndMins[5] = MaxAndMins[5] > point.getCoordinate(2) 
            ? point.getCoordinate(2) : MaxAndMins[5];
        });
        result = (MaxAndMins[0] - MaxAndMins[1]) * 
                 (MaxAndMins[2] - MaxAndMins[3]) * 
                 (MaxAndMins[4] - MaxAndMins[5]);
    }
    return result;
}

/*************************************************************************
【函数名称】Controller::read
【函数功能】从文件中读取模型，存储在m_pModel指向的空间中。
【参数】
    path 读取的文件路径
【返回值】bool类型，反应读取操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::read(std::string path) noexcept{
    try {
        *m_pModel = m_pImporter->Load(path);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

/*************************************************************************
【函数名称】Controller::write
【函数功能】将m_pModel指向的模型写入文件中
【参数】
    path 读取的文件路径
【返回值】bool类型，反应写入操作是否成功
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
【更改记录】
    2024-08-06 完成了函数定义
    2024-08-09 增加了try-catch语句，将返回值由void变为bool
*************************************************************************/
bool Controller::write(std::string path) const noexcept {
    try {
        m_pExporter->Write(path, *m_pModel);
    } catch (std::exception e) {
        return false;
    }
    return true;
}
