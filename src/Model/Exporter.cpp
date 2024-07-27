#include "header/Exporter.hpp"
#include "header/Model3D.hpp"
#include <exception>
#include <fstream>

std::ofstream& Exporter::getFile() {
    return m_file;
}

void Exporter::OpenFile(std::string path) {
    m_file.open(path, std::ios::out | std::ios::trunc);
    if (!isOpen()) {
        throw std::exception("Cannot Open the File!");
    }
}

bool Exporter::isOpen() const {
    return m_file.is_open();
}

void Exporter::close() {
    m_file.close();
}

void Exporter::Write(std::string path, const Model3D& model) {
    if (!checkExtension(path)) {
        throw std::exception("Invalid file name!");
    }
    OpenFile(path);
    writeToFile(model, path); // TODO: get filename by path
    close();
}
