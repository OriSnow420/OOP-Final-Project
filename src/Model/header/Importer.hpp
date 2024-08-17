/*************************************************************************
【文件名】Importer.hpp
【功能模块和目的】声明Importer类
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了Importer类的声明
*************************************************************************/

#ifndef Importer_cpp
#define Importer_cpp

#include "Model3D.hpp"
#include <fstream>
#include <string>

/*************************************************************************
【类名】Importer
【功能】作为所有特殊Importer的基类
【接口说明】
    默认构造/析构函数
    从路径中导入模型
    对子类：获取文件流
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-07-23
【更改记录】
    2024-07-23 完成了类的声明
*************************************************************************/
class Importer {
private:
    std::ifstream m_file;

protected:
    // Provides Access to file for the derived class
    std::ifstream& GetFile();

private:
    // Open the file
    void OpenFile(std::string path);

    // Pure Virtual, check if extension name is correct
    virtual bool CheckExtension(std::string path) const = 0;

    // Returns true if the file is open
    bool IsOpen();

    // Close the file
    void Close();

    // Read from the file when the file is open.
    virtual Model3D Read() = 0;

public:
    // Default Stuff
    Importer() = default;

    // Deleted Stuff
    Importer& operator=(const Importer&) = delete;
    Importer& operator=(Importer&&) = delete;
    Importer(const Importer&) = delete;
    Importer(Importer&&) = delete;

    // Virtual Destructor
    virtual ~Importer();

    // Load from the file
    Model3D Load(std::string path);

};

#endif
