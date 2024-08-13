#include "header/Controller.hpp"
#include <algorithm>
#include <exception>
#include <memory>
#include <optional>
#include <string>
#include <vector>


std::shared_ptr<Controller> Controller::m_Ptr = nullptr;

Controller::Controller(Importer* importer, Exporter* exporter) :
    m_pImporter(importer), m_pExporter(exporter), 
    m_pModel(new Model3D()) {}

Controller::~Controller() {}

std::vector<Face3D> Controller::getFace() const noexcept{
    return m_pModel->getFaces();
}

bool Controller::deleteFace(int index) noexcept{
    try {
    m_pModel->removeFace(index);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

bool Controller::addFace(const Point3D& point1, const Point3D& point2,
                         const Point3D& point3) noexcept {
    try {
        m_pModel->addFace(Face3D(point1, point2, point3));
    } catch (std::exception e) {
        return false;
    }
    return true;
}

std::optional<std::vector<Point3D>> Controller::pointsInFace
(int index) const noexcept {
    try {
        return m_pModel->getFaces().at(index).getPoints();
    } catch (std::exception e) {
        return std::nullopt;
    }
}

bool Controller::modifyPointInFace(int index, int whichPoint,
                                   const Point3D& newPoint) noexcept {
    try {
        m_pModel->modifyFace(index, whichPoint, newPoint);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

bool Controller::modifyPointInLine(int index, int whichPoint,
                                   const Point3D& newPoint) noexcept {
    try {
        m_pModel->modifyLine(index, whichPoint, newPoint);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

std::vector<Line3D> Controller::getLine() const noexcept {
    return m_pModel->getLines();
}

bool Controller::deleteLine(int index) noexcept {
    try { 
        m_pModel->removeLine(index);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

bool Controller::addLine(const Point3D& point1, const Point3D& point2) 
noexcept{
    try {
        m_pModel->addLine(Line3D(point1, point2));
    } catch (std::exception e) {
        return false;
    }
    return true;
}

std::optional<std::vector<Point3D>> Controller::pointsInLine(int index) 
const noexcept {
    try {
        return m_pModel->getLines().at(index).getPoints();
    } catch (std::exception e) {
        return std::nullopt;
    }
}

Controller::Statistics Controller::showStat() const noexcept{
    auto faces = m_pModel->getFaces();
    auto lines = m_pModel->getLines();
    double face_area = 0.0;
    double line_length = 0.0;

    std::for_each(faces.begin(), faces.end(), 
    [&](const Face3D& face)->void {
        face_area += face.area();
    });
    std::for_each(lines.begin(), lines.end(), 
    [&](const Line3D& line)->void {
        line_length += line.length();
    });
    return Statistics{
        m_pModel->face_count(),
        face_area,
        m_pModel->line_count(),
        line_length,
        3 * m_pModel->face_count() + 2 * m_pModel->line_count(),
        calculateAABB()
    };
}

double Controller::calculateAABB() const {
    double result = 0.0;
    if (!m_pModel->empty()) {
        auto points = m_pModel->getPoints();
        // {x_max, x_min, y_max, y_min, z_max, z_min}
        double MaxAndMins[6] = {
            points.at(0).getCoordinate(0),
            points.at(0).getCoordinate(0),
            points.at(0).getCoordinate(1),
            points.at(0).getCoordinate(1),
            points.at(0).getCoordinate(2),
            points.at(0).getCoordinate(2)
        };
        std::for_each(points.begin() + 1, points.end(), 
        [&MaxAndMins](const Point3D& point)->void {
            MaxAndMins[0] = MaxAndMins[0] < point.getCoordinate(0) 
            ? point.getCoordinate(0) : MaxAndMins[0];
            MaxAndMins[1] = MaxAndMins[1] > point.getCoordinate(0) 
            ? point.getCoordinate(0) : MaxAndMins[1];
            MaxAndMins[2] = MaxAndMins[2] < point.getCoordinate(1) 
            ? point.getCoordinate(1) : MaxAndMins[2];
            MaxAndMins[3] = MaxAndMins[3] > point.getCoordinate(1) 
            ? point.getCoordinate(1) : MaxAndMins[3];
            MaxAndMins[4] = MaxAndMins[4] < point.getCoordinate(2) 
            ? point.getCoordinate(2) : MaxAndMins[4];
            MaxAndMins[5] = MaxAndMins[5] > point.getCoordinate(2) 
            ? point.getCoordinate(2) : MaxAndMins[5];
        });
        result = (MaxAndMins[0] - MaxAndMins[1]) * 
                 (MaxAndMins[2] - MaxAndMins[3]) * 
                 (MaxAndMins[4] - MaxAndMins[5]);
    }
    return result;
}

bool Controller::read(std::string path) noexcept{
    try {
        *m_pModel = m_pImporter->Load(path);
    } catch (std::exception e) {
        return false;
    }
    return true;
}

bool Controller::write(std::string path) const noexcept {
    try {
        m_pExporter->Write(path, *m_pModel);
    } catch (std::exception e) {
        return false;
    }
    return true;
}