/*************************************************************************
【文件名】objExporter.hpp
【功能模块和目的】为objExporter提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/

#ifndef objExporter_hpp
#define objExporter_hpp

#include "Exporter.hpp"
#include "Model3D.hpp"

/*************************************************************************
【类名】objExporter
【功能】将三维模型导出为obj文件
【接口说明】         （必需）
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/
class objExporter : public Exporter {
private:
    // Overridden functions
    virtual bool checkExtension(const std::string& path) const override;
    virtual void writeToFile(const Model3D& model, 
    const std::string& finename) override;

public:
    // Default Destructor and Constructor
    virtual ~objExporter();
    objExporter() = default;
};

#endif
