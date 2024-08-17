/*************************************************************************
【文件名】ObjExporter.hpp
【功能模块和目的】为ObjExporter提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/

#ifndef objExporter_hpp
#define objExporter_hpp

#include "Exporter.hpp"
#include "Model3D.hpp"

/*************************************************************************
【类名】ObjExporter
【功能】将三维模型导出为obj文件
【接口说明】
    公有继承得到父类所有接口
    默认构造函数
    虚默认析构函数
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/
class ObjExporter : public Exporter {
private:
    // Overridden functions
    virtual bool CheckExtension(const std::string& path) const override;
    virtual void WriteToFile(const Model3D& model, 
    const std::string& finename) override;

public:
    // Default Destructor and Constructor
    virtual ~ObjExporter();
    ObjExporter() = default;

    // Deleted Stuff
    ObjExporter& operator=(const ObjExporter&) = delete;
    ObjExporter& operator=(ObjExporter&&) = delete;
    ObjExporter(const ObjExporter&) = delete;
    ObjExporter(ObjExporter&&) = delete;
};

#endif
