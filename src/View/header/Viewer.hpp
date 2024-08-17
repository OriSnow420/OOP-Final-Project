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
【接口说明】
    默认构造函数
    默认析构函数
【开发者及日期】李宜阳(liyiyang23@mails.tsinghua.edu.cn) 2024-08-09
【更改记录】
    2024-08-09 完成了函数声明
*************************************************************************/
class Viewer {
private:

    std::shared_ptr<Controller> m_pController;

    // Useful Functions
    virtual void Initialize();
    void MainLoop();
    virtual bool OneLoop();
    virtual void Exit();

    // Operations
    virtual void ImportModel();
    virtual void ExportModel();
    virtual void ListAllFaces();
    virtual void DeleteFace();
    virtual void AddFace();
    virtual void PointsInFace();
    virtual void ModifyFace();
    virtual void ListAllLines();
    virtual void DeleteLine();
    virtual void AddLine();
    virtual void PointsInLine();
    virtual void ModifyLine();
    virtual void ShowStatistics();


public:
    // Constructor, and is the start of the program
    Viewer();

    // Destructor
    virtual ~Viewer();

    // Deleted Stuff: Moving and Copying is unnecessary.
    Viewer& operator=(const Viewer&) = delete;
    Viewer& operator=(Viewer&&) = delete;
    Viewer(const Viewer&) = delete;
    Viewer(Viewer&&) = delete;
};

#endif
