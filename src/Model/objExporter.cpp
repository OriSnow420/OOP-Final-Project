#include "header/objExporter.hpp"
#include "header/Model3D.hpp"
#include <regex>

bool objExporter::checkExtension(const std::string& path) const {
    return std::regex_match(path, std::regex("^.*\\.obj$"));
}

void objExporter::writeToFile(const Model3D& model, 
const std::string& filename) {
    getFile() << "# " << filename << std::endl
              << "g " << model.getName() << std::endl;
    for (const auto& point : model.getPoints()) {
        getFile() << "v " << point.getCoordinate(0) << ' '
                          << point.getCoordinate(1) << ' '
                          << point.getCoordinate(2) << ' ';
    }
    int i = 1;
    for (const auto& line : model.getLines()) {
        getFile() << "l " << i << ' ';
        i++;
        getFile() << "i" << ' ';
        i++;
        getFile() << std::endl;
    }
    for (const auto& face : model.getFaces()) {
        getFile() << "f " << i << ' ';
        i++;
        getFile() << i << ' ';
        i++;
        getFile() << i << ' ';
        i++;
        getFile() << std::endl;
    }
}

objExporter::~objExporter() {}