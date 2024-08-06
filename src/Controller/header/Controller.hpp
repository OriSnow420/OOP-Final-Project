#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <memory>
#include <vector>
#include "../../Model/header/Model3D.hpp"
#include "../../Model/header/Importer.hpp"
#include "../../Model/header/Exporter.hpp"


class Controller {
private:
    std::shared_ptr<Model3D> m_pModel;
    const Importer* m_pImporter;
    const Exporter* m_pExporter;
    explicit Controller(const Importer* importer, const Exporter* exporter);

    static std::shared_ptr<Controller> m_Ptr;

    double calculateAABB() const;

    Controller& operator=(const Controller&) = delete;
    Controller& operator=(Controller&&) = delete;
    Controller() = delete;
    Controller(const Controller&) = delete;

public:

    struct Statistics {
        int FaceCount;
        double FaceArea;
        int LineCount;
        double LineLength;
        int PointCount;
        double AABBVolume; // Volume of Axis-Aligned Bounding Box.
    };

    virtual ~Controller();
    static std::shared_ptr<Controller> GetInstance(
        const Importer* importer, const Exporter* exporter
    );

    std::vector<Face3D> getFace() const;
    void deleteFace(int index);
    void addFace(const Point3D& point1, const Point3D& point2,
                 const Point3D& point3);
    std::vector<Point3D> pointsInFace(int index) const;
    void modifyPointInFace(int index, int whichPoint, 
                           const Point3D& newPoint);

    std::vector<Line3D> getLine() const;
    void deleteLine(int index);
    void addLine(const Point3D& point1, const Point3D& point2);
    std::vector<Point3D> pointsInLine(int index) const;
    void modifyPointInLine(int index, int whichPoint, 
                           const Point3D& newPoint);
    
    Statistics showStat() const;


};

#endif
