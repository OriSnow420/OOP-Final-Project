/*************************************************************************
【文件名】objImporter.cpp
【功能模块和目的】为objImporter提供函数实现
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了函数实现
*************************************************************************/

#include "header/objImporter.hpp"

#include <string>
#include <sstream>
#include <regex>

/*************************************************************************
【函数名称】objImporter::checkExtension
【函数功能】检查文件扩展名是否为obj
【参数】
    path: 待检查的文件路径
【返回值】bool类型，若文件扩展名为obj则返回true
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了函数定义
*************************************************************************/
bool objImporter::checkExtension(std::string path) const {
    return std::regex_match(path, std::regex("^.*\\.obj$"));
}

/*************************************************************************
【函数名称】objImporter::read
【函数功能】从已打开的文件读取Model3D
【参数】无参数
【返回值】Model3D类型，返回读取到的模型
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了函数定义
*************************************************************************/
Model3D objImporter::read(){
    Model3D result;
    std::vector<Point3D> listPoint;
    bool hasName = false;
    for(std::string line; std::getline(getFile(), line); ){
        if (line[0] == '#') {
            continue;
        } else if (line[0] == 'g') {
            if (hasName) {
                // More than one line begin with a 'g'
                throw std::exception(
                    "More than one nameline in the file.");
            }
            std::stringstream ss {line};
            char c;
            ss >> c;
            std::string name;
            ss >> name;
            result.modifyName(name);
            hasName = true;
        } else if (line[0] == 'v') {
            // A Point
            std::stringstream ss {line};
            listPoint.push_back(Point3D());
            char c;
            ss >> c;
            for(int i = 0; i < 3; i++){
                double coord;
                ss >> coord;
                listPoint.back().setCoordinate(coord, i);
            }
        } else if (line[0] == 'l') {
            // A Line
            std::stringstream ss {line};
            char c;
            int x;
            int y;
            ss >> c >> x >> y;
            if (x > listPoint.size() || y > listPoint.size()) {
                throw std::exception("Number of Points error!");
            }
            if (x <= 0 || y <= 0) {
                throw std::exception("Non-positive Index error!");
            }
            result.addLine(Line3D(
                listPoint[x - 1], listPoint[y - 1]));
        } else if (line[0] == 'f') {
            // A Face
            std::stringstream ss {line};
            char c;
            int x;
            int y;
            int z;
            ss >> c >> x >> y >> z;
            if (x > listPoint.size() || y > listPoint.size() || 
                z > listPoint.size()) {
                throw std::exception("Number of Points error!");
            }
            if (x <= 0 || y <= 0 || z <= 0) {
                throw std::exception("Non-positive Index error!");
            }
            result.addFace(Face3D(listPoint[x - 1], 
                listPoint[y - 1], listPoint[z - 1]));
        } else {
            // Unexpected Cases, throw.
            throw std::exception("File Broken!");
        }
    }
    return result;
}

/*************************************************************************
【函数名称】objImporter::~objImporter
【函数功能】默认析构函数
【参数】无参数
【返回值】无返回值
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了函数定义
*************************************************************************/
objImporter::~objImporter() {}
