/*************************************************************************
【文件名】Exporter.cpp
【功能模块和目的】为Exporter类提供函数定义
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了大部分函数定义
*************************************************************************/

#include "header/Exporter.hpp"
#include "header/Model3D.hpp"
#include <exception>
#include <fstream>

/*************************************************************************
【函数名称】Exporter::getFile
【函数功能】为子类提供获取文件的接口
【参数】无参数
【返回值】std::ostream&类型，返回文件本身
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
std::ofstream& Exporter::getFile() {
    return m_file;
}

/*************************************************************************
【函数名称】Exporter::OpenFile
【函数功能】打开文件
【参数】
    path: 文件路径
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
void Exporter::OpenFile(std::string path) {
    m_file.open(path, std::ios::out | std::ios::trunc);
    if (!isOpen()) {
        throw std::exception("Cannot Open the File!");
    }
}

/*************************************************************************
【函数名称】Exporter::isOpen
【函数功能】判断是否已打开文件
【参数】无参数
【返回值】bool类型，文件已打开则返回true
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
bool Exporter::isOpen() const {
    return m_file.is_open();
}

/*************************************************************************
【函数名称】Exporter::close
【函数功能】关闭文件
【参数】无参数
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
void Exporter::close() {
    m_file.close();
}

/*************************************************************************
【函数名称】Exporter::writeToFile
【函数功能】将模型写入文件
【参数】
    path: 文件路径
    model: 待写入的模型
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数定义
*************************************************************************/
void Exporter::Write(std::string path, const Model3D& model) {
    if (!checkExtension(path)) {
        throw std::exception("Invalid file name!");
    }
    OpenFile(path);
    writeToFile(model, path);
    close();
}
