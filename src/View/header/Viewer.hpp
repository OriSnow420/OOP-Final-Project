#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <memory>
#include "../../Controller/header/Controller.hpp"

class Viewer {
private:
    std::shared_ptr<Controller> m_pController;
    virtual void initialize();
    void main_loop();
    virtual bool one_loop();

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


public:
    Viewer();
    virtual ~Viewer();
    void start();
};

#endif
