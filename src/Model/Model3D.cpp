#include "header/Model3D.hpp"
#include "header/Face3D.hpp"
#include "header/Line3D.hpp"
#include "header/Point3D.hpp"
#include <exception>
#include <initializer_list>

Model3D::Model3D(std::string name, std::initializer_list<Line3D> lineList, 
std::initializer_list<Face3D> faceList) noexcept : m_lines(lineList), m_faces(faceList), m_name(name) {}

std::vector<Point3D> Model3D::getPoints() const noexcept {
    std::vector<Point3D> result;
    for (const auto& line : m_lines) {
        for (const auto& point : line.getPoints()) {
            result.push_back(point);
        }
    }
    for (const auto& face : m_faces) {
        for (const auto& point : face.getPoints()) {
            result.push_back(point);
        }
    }
    return result;
}

std::vector<Line3D> Model3D::getLines() const noexcept {
    return m_lines;
}

std::vector<Face3D> Model3D::getFaces() const noexcept {
    return m_faces;
}

int Model3D::line_count() const noexcept {
    return m_lines.size();
}

int Model3D::face_count() const noexcept {
    return m_faces.size();
}

void Model3D::modifyLine(int index, int whichPoint, const Point3D& newPoint){
    if(index < 0 || index >= line_count()){
        throw std::exception("Index out of range Error!");
    }
    m_lines[index].setPoint(newPoint, whichPoint);
}

void Model3D::modifyFace(int index, int whichPoint, const Point3D& newPoint){
    if(index < 0 || index >= face_count()){
        throw std::exception("Index out of range Error!");
    }
    m_faces[index].setPoint(newPoint, whichPoint);
}

void Model3D::removeLine(int index){
    if(index < 0 || index >= line_count()){
        throw std::exception("Index out of range Error!");
    }
    m_lines.erase(m_lines.begin() + index);
}

void Model3D::removeFace(int index){
    if(index < 0 || index >= face_count()){
        throw std::exception("Index out of range Error!");
    }
    m_faces.erase(m_faces.begin() + index);
}

void Model3D::addLine(const Line3D& newLine){
    if (std::find(m_lines.begin(), m_lines.end(), newLine) != m_lines.end()) {
        throw std::exception("Same Line already exists!");
    }
    m_lines.push_back(newLine);
}

void Model3D::addFace(const Face3D& newFace){
    if (std::find(m_faces.begin(), m_faces.end(), newFace) != m_faces.end()) {
        throw std::exception("Same Face already exists!");
    }
    m_faces.push_back(newFace);
}

std::string Model3D::getName() const noexcept {
    return m_name;
}

void Model3D::modifyName(const std::string& newName) noexcept {
    m_name = newName;
}

bool Model3D::empty() const {
    return m_lines.empty() && m_faces.empty();
}