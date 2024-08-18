/*************************************************************************
【文件名】Exporter.hpp
【功能模块和目的】为Exporter提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/

#ifndef EXPORTER_HPP
#define EXPORTER_HPP

#include "Model3D.hpp"
#include <fstream>
#include <string>

/*************************************************************************
【类名】Exporter
【功能】为所有特殊Exporter提供共同基类
【接口说明】
    默认构造函数
    虚默认析构函数
    向指定路径的文件写入模型
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-27
【更改记录】
    2024-07-27 完成了函数声明
*************************************************************************/
class Exporter {
private:
    std::ofstream m_file;

protected:
    // Provides Access to file for the derived class
    std::ofstream& GetFile();

private:
    // Open the file
    void OpenFile(std::string path);

    // Pure Virtual, check if extension name is correct
    virtual bool CheckExtension(const std::string& path) const = 0;

    // Returns true if the file is open
    bool IsOpen() const;

    // Close the file
    void Close();

    // Write to the file when the file is open.
    virtual void WriteToFile(const Model3D& model, 
        const std::string& filename) = 0;


public:
    // Default stuff
    Exporter() = default;
    virtual ~Exporter() = default;

    // Deleted stuff; Copying and Moving is unnecessary.
    Exporter& operator=(const Exporter&) = delete;
    Exporter& operator=(Exporter&&) = delete;
    Exporter(const Exporter&) = delete;
    Exporter(Exporter&&) = delete;

    // Write the model to the file.
    void Write(std::string path, const Model3D& model);
};

#endif
