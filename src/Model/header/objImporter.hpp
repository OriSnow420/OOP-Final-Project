/*************************************************************************
【文件名】objImporter.hpp
【功能模块和目的】为objImporter提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了函数声明
*************************************************************************/

#ifndef objImporter_hpp
#define objImporter_hpp

#include "Importer.hpp"
#include "Model3D.hpp"

/*************************************************************************
【类名】objImporter
【功能】将从obj格式文件读取Model3D
【接口说明】
    公有继承获得父类全部接口
    默认构造函数
    析构函数
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了函数声明
*************************************************************************/
class ObjImporter : public Importer {
private:
    // Override functions
    virtual bool CheckExtension(std::string path) const override;
    virtual Model3D Read() override;

public:
    // Default stuff
    ObjImporter() = default;

    // Deleted Stuff
    ObjImporter& operator=(const ObjImporter&) = delete;
    ObjImporter& operator=(ObjImporter&&) = delete;
    ObjImporter(const ObjImporter&) = delete;
    ObjImporter(ObjImporter&&) = delete;

    // Destructor
    virtual ~ObjImporter();

};

#endif
