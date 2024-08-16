/*************************************************************************
【文件名】Face3D.hpp
【功能模块和目的】为Viewer提供类声明
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-09
【更改记录】
    2024-08-09 完成了函数声明
*************************************************************************/

#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <memory>
#include "../../Controller/header/Controller.hpp"

/*************************************************************************
【类名】Viewer
【功能】作为Viewer提供用户交互界面
【接口说明】         （必需）
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-09
【更改记录】
    2024-08-09 完成了函数声明
*************************************************************************/
class Viewer {
private:

    std::shared_ptr<Controller> m_pController;

    // Useful Functions
    virtual void initialize();
    void main_loop();
    virtual bool one_loop();
    virtual void exit();

    // Operations
    virtual void importModel();
    virtual void exportModel();
    virtual void listAllFaces();
    virtual void deleteFace();
    virtual void addFace();
    virtual void pointsInFace();
    virtual void modifyFace();
    virtual void listAllLines();
    virtual void deleteLine();
    virtual void addLine();
    virtual void pointsInLine();
    virtual void modifyLine();
    virtual void showStatistics();


public:
    // Constructor, and is the start of the program
    Viewer();

    // Destructor
    virtual ~Viewer();
};

#endif
