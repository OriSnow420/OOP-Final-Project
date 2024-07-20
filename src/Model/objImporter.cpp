#include "header/objImporter.hpp"
#include "header/Face3D.hpp"
#include "header/Model3D.hpp"
#include "header/Point3D.hpp"

#include <exception>
#include <sstream>
#include <string>
#include <fstream>

Model3D objImporter::Load(std::string path){
    std::ifstream file {path};
    if(!file){
        throw std::exception("Cannot Open the File!");
    }
    Model3D result;
    std::vector<Point3D> listPoint;
    bool hasName = false;
    for(std::string line; std::getline(file, line); ){
        if (line[0] == '#') {
            continue;
        } else if (line[0] == 'g') {
            if (hasName) {
                throw std::exception("More than one nameline in the file.");
            }
            std::stringstream ss {line};
            char c;
            ss >> c;
            std::string name;
            ss >> name;
            result.modifyName(name);
            hasName = true;
        } else if (line[0] == 'v') {
            std::stringstream ss {line};
            listPoint.push_back(Point3D());
            char c;
            ss >> c;
            for(int i = 0; i < 3; i++){
                double coord;
                ss >> coord;
                listPoint.back().setCoordinate(coord, i);
            }
        } else if (line[0] == 'l') {
            std::stringstream ss {line};
            char c;
            int x;
            int y;
            ss >> c >> x >> y;
            if (x >= listPoint.size() || y >= listPoint.size()) {
                throw std::exception("Number of Points error!");
            }
            if (x < 0 || y < 0) {
                throw std::exception("Negative Index error!");
            }
            result.addLine(Line3D(listPoint[x], listPoint[y]));
        } else if (line[0] == 'f') {
            std::stringstream ss {line};
            char c;
            int x;
            int y;
            int z;
            ss >> c >> x >> y >> z;
            if (x >= listPoint.size() || y >= listPoint.size() || z >= listPoint.size()) {
                throw std::exception("Number of Points error!");
            }
            if (x < 0 || y < 0 || z < 0) {
                throw std::exception("Negative Index error!");
            }
            result.addFace(Face3D(listPoint[x], listPoint[y], listPoint[z]));
        }
    }
    return result;
}