/*************************************************************************
【文件名】ObjExporter.cpp
【功能模块和目的】为ObjExporter提供函数实现
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数实现
*************************************************************************/

#include "header/ObjExporter.hpp"
#include "header/Model3D.hpp"
#include <regex>

/*************************************************************************
【函数名称】ObjExporter::checkExtension
【函数功能】检查文件扩展名是否为obj
【参数】
    path: 待检查的文件路径
【返回值】bool类型，若文件扩展名为obj则返回true
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
bool ObjExporter::CheckExtension(const std::string& path) const {
    return std::regex_match(path, std::regex("^.*\\.obj$"));
}

/*************************************************************************
【函数名称】ObjExporter::writeToFile
【函数功能】将模型写入文件
【参数】
    model 待写入的模型
    filename 文件名
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
void ObjExporter::WriteToFile(const Model3D& model, 
const std::string& filename) {
    GetFile() 
        << "# " << filename << std::endl
        << "g " << model.GetName() << std::endl;
    for (const auto& point : model.GetPoints()) {
        GetFile() 
            << "v " << point.GetCoordinate(0) << ' '
            << point.GetCoordinate(1) << ' '
            << point.GetCoordinate(2) << ' '
            << std::endl;
    }
    int i = 1;
    for (const auto& line : model.GetLines()) {
        GetFile() << "l " << i << ' ';
        i++;
        GetFile() << i << ' ';
        i++;
        GetFile() << std::endl;
    }
    for (const auto& face : model.GetFaces()) {
        GetFile() << "f " << i << ' ';
        i++;
        GetFile() << i << ' ';
        i++;
        GetFile() << i << ' ';
        i++;
        GetFile() << std::endl;
    }
}

/*************************************************************************
【函数名称】ObjExporter::~ObjExporter
【函数功能】默认析构函数
【参数】无参数
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
ObjExporter::~ObjExporter() {}
