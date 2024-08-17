/*************************************************************************
【文件名】Controller.hpp
【功能模块和目的】为Controller提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-08-06 完成了大部分函数声明和其中模板函数的实现
*************************************************************************/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <memory>
#include <vector>
#include <optional>
#include "../../Model/header/Model3D.hpp"
#include "../../Model/header/Importer.hpp"
#include "../../Model/header/Exporter.hpp"

/*************************************************************************
【类名】Controller
【功能】作为程序的Controller完成各种功能
【接口说明】
    虚析构函数
    静态，获取实例
    更改导入器
    更改导出器
    获取/增加/删除修改面/线段
    获取单个面/线段内的点
    从文件读入
    向文件输出
    获取模型统计信息
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-20
【更改记录】
    2024-08-06 完成了函数声明
*************************************************************************/
class Controller {
private:
    std::shared_ptr<Model3D> m_pModel;
    std::unique_ptr<Importer> m_pImporter;
    std::unique_ptr<Exporter> m_pExporter;

    // Private Constructor
    Controller(Importer* importer, Exporter* exporter);

    static std::shared_ptr<Controller> m_Ptr;

    // Calculate the volume of *m_pModel's AABB
    double CalculateAABB() const;

    // Banned operations
    Controller& operator=(const Controller&) = delete;
    Controller& operator=(Controller&&) = delete;
    Controller() = delete;
    Controller(const Controller&) = delete;
    Controller(Controller&&) = delete;


public:

    // Required Statistics Infomation
    struct Statistics {
        int FaceCount;
        double FaceArea;
        int LineCount;
        double LineLength;
        int PointCount;
        double AABBVolume; // Volume of Axis-Aligned Bounding Box.
    };

    // Destructor
    virtual ~Controller();

    /*************************************************************************
    【函数名称】Controller::GetInstance
    【函数功能】获取Controller的shared_ptr，是单例模式设计的一部分
    【模板参数】
        Imp: 导入器类型, 要求是Importer的子类
        Exp: 导出器类型, 要求是Exporter的子类
        注意：这两个模板参数仅在构造新Controller时生效。
    【参数】无参数
    【返回值】无返回值
    【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
    【更改记录】
        2024-08-06 完成了函数定义
    *************************************************************************/
    template<class Imp, class Exp>
    static std::shared_ptr<Controller> GetInstance() {
        if (!m_Ptr) {
            m_Ptr = std::shared_ptr<Controller>(new Controller(
                new Imp(), new Exp()
            ));
        }
        return m_Ptr;
    }

    /*************************************************************************
    【函数名称】Controller::ChangeImporter
    【函数功能】将Controller的导入器指定为新导入器
    【模板参数】
        Imp: 导入器类型, 要求是Importer的子类
    【参数】无参数
    【返回值】无返回值
    【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
    【更改记录】
        2024-08-06 完成了函数定义
    *************************************************************************/
    template<class Imp>
    void ChangeImporter() noexcept {
        m_pImporter = std::make_unique(new Imp());
    }

    /*************************************************************************
    【函数名称】Controller::ChangeExporter
    【函数功能】将Controller的导出器指定为新的导出器
    【模板参数】
        Exp: 导出器类型, 要求是Exporter的子类
    【参数】无参数
    【返回值】无返回值
    【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-06
    【更改记录】
        2024-08-06 完成了函数定义
    *************************************************************************/
    template<class Exp>
    void ChangeExporter() noexcept {
        m_pExporter = std::make_unique(new Exp());
    }

    // Face Operations
    std::vector<Face3D> GetFace() const noexcept;
    bool DeleteFace(int index) noexcept;
    bool AddFace(
        const Point3D& point1, 
        const Point3D& point2,
        const Point3D& point3) noexcept;
    std::optional<std::vector<Point3D>> PointsInFace(int index) const noexcept;
    bool ModifyPointInFace(
        int index, 
        int whichPoint, 
        const Point3D& newPoint) noexcept;

    // Line Operations
    std::vector<Line3D> GetLine() const noexcept;
    bool DeleteLine(int index) noexcept;
    bool AddLine(const Point3D& point1, const Point3D& point2) noexcept;
    std::optional<std::vector<Point3D>> PointsInLine(int index) const noexcept;
    bool ModifyPointInLine(
        int index, 
        int whichPoint, 
        const Point3D& newPoint) noexcept;
    
    // Show Statistics
    Statistics ShowStat() const noexcept;

    // File Operations
    bool Read(std::string path) noexcept;
    bool Write(std::string path) const noexcept;

};

#endif
