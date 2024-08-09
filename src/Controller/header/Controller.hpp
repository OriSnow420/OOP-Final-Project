#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <memory>
#include <vector>
#include <optional>
#include "../../Model/header/Model3D.hpp"
#include "../../Model/header/Importer.hpp"
#include "../../Model/header/Exporter.hpp"


class Controller {
private:
    std::shared_ptr<Model3D> m_pModel;
    std::unique_ptr<Importer> m_pImporter;
    std::unique_ptr<Exporter> m_pExporter;
    explicit Controller(Importer* importer, Exporter* exporter);

    static std::shared_ptr<Controller> m_Ptr;

    double calculateAABB() const;

    Controller& operator=(const Controller&) = delete;
    Controller& operator=(Controller&&) = delete;
    Controller() = delete;
    Controller(const Controller&) = delete;
    Controller(Controller&&) = delete;


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

    template<class Imp, class Exp>
    static std::shared_ptr<Controller> GetInstance() {
        if (!m_Ptr) {
            m_Ptr = std::make_shared<Controller>(new Controller(
                new Imp(), new Exp()
            ));
        }
        return m_Ptr;
    }

    std::vector<Face3D> getFace() const noexcept;
    bool deleteFace(int index) noexcept;
    bool addFace(const Point3D& point1, const Point3D& point2,
                 const Point3D& point3) noexcept;
    std::optional<std::vector<Point3D>> pointsInFace(int index) const noexcept;
    bool modifyPointInFace(int index, int whichPoint, 
                           const Point3D& newPoint) noexcept;

    std::vector<Line3D> getLine() const noexcept;
    bool deleteLine(int index) noexcept;
    bool addLine(const Point3D& point1, const Point3D& point2) noexcept;
    std::optional<std::vector<Point3D>> pointsInLine(int index) const noexcept;
    bool modifyPointInLine(int index, int whichPoint, 
                           const Point3D& newPoint) noexcept;
    
    Statistics showStat() const noexcept;

    bool read(std::string path) noexcept;
    bool write(std::string path) const noexcept;

};

#endif
