#include "header/objImporter.hpp"

#include <string>
#include <sstream>
#include <regex>

bool objImporter::checkExtension(std::string path){
    return std::regex_match(path, std::regex("^.*\\.obj$"));
}

Model3D objImporter::read(){
    Model3D result;
    std::vector<Point3D> listPoint;
    bool hasName = false;
    for(std::string line; std::getline(getFile(), line); ){
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