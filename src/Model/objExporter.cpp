/*************************************************************************
【文件名】objExporter.cpp
【功能模块和目的】为objExporter提供函数实现
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数实现
*************************************************************************/

#include "header/objExporter.hpp"
#include "header/Model3D.hpp"
#include <regex>

/*************************************************************************
【函数名称】objExporter::checkExtension
【函数功能】检查文件扩展名是否为obj
【参数】
    path: 待检查的文件路径
【返回值】bool类型，若文件扩展名为obj则返回true
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
bool objExporter::checkExtension(const std::string& path) const {
    return std::regex_match(path, std::regex("^.*\\.obj$"));
}

/*************************************************************************
【函数名称】objExporter::writeToFile
【函数功能】将模型写入文件
【参数】
    model 待写入的模型
    filename 文件名
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
void objExporter::writeToFile(const Model3D& model, 
const std::string& filename) {
    getFile() << "# " << filename << std::endl
              << "g " << model.getName() << std::endl;
    for (const auto& point : model.getPoints()) {
        getFile() << "v " << point.getCoordinate(0) << ' '
                          << point.getCoordinate(1) << ' '
                          << point.getCoordinate(2) << ' '
                          << std::endl;
    }
    int i = 1;
    for (const auto& line : model.getLines()) {
        getFile() << "l " << i << ' ';
        i++;
        getFile() << i << ' ';
        i++;
        getFile() << std::endl;
    }
    for (const auto& face : model.getFaces()) {
        getFile() << "f " << i << ' ';
        i++;
        getFile() << i << ' ';
        i++;
        getFile() << i << ' ';
        i++;
        getFile() << std::endl;
    }
}

/*************************************************************************
【函数名称】objExporter::~objExporter
【函数功能】默认析构函数
【参数】无参数
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
objExporter::~objExporter() {}
