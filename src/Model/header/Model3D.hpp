// TODO: file comment

#ifndef Model3D_hpp
#define Model3D_hpp

// TODO: finish class Model
#include "Face3D.hpp"
#include "Line3D.hpp"
#include "Point3D.hpp"
#include <initializer_list>
#include <vector>

class Model3D {

private:
    std::vector<Line3D> m_lines;
    std::vector<Face3D> m_faces;

public:
    explicit Model3D(
        std::initializer_list<Line3D> lineList={},
        std::initializer_list<Face3D> faceList={}
    ) noexcept;

    std::vector<Point3D> getPoints() const noexcept;
    std::vector<Line3D> getLines() const noexcept;
    std::vector<Face3D> getFaces() const noexcept;

    int line_count() const noexcept;
    int face_count() const noexcept;

    void modifyLine(int index, int whichPoint, const Point3D& newPoint);
    void modifyFace(int index, int whichPoint, const Point3D& newPoint);

    void removeLine(int index);
    void removeFace(int index);

    void addLine(const Line3D& newLine) noexcept;
    void addFace(const Face3D& newFace) noexcept;

};

#endif
