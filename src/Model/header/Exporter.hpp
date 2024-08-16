/*************************************************************************
【文件名】Exporter.hpp
【功能模块和目的】为Exporter提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/

#ifndef Exporter_hpp
#define Exporter_hpp

#include "Model3D.hpp"
#include <fstream>
#include <string>

/*************************************************************************
【类名】Exporter
【功能】为所有特殊Exporter提供共同基类
【接口说明】         （必需）
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/
class Exporter {
private:
    std::ofstream m_file;

protected:
    // Provides Access to file for the derived class
    std::ofstream& getFile();

private:
    // Open the file
    void OpenFile(std::string path);

    // Pure Virtual, check if extension name is correct
    virtual bool checkExtension(const std::string& path) const = 0;

    // Returns true if the file is open
    bool isOpen() const;

    // Close the file
    void close();

    // Write to the file when the file is open.
    virtual void writeToFile(const Model3D& model, 
    const std::string& filename) = 0;


public:
    // Write the model to the file.
    void Write(std::string path, const Model3D& model);
};

#endif
