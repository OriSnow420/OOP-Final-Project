#include "header/Importer.hpp"
#include "header/Model3D.hpp"
#include <exception>
#include <fstream>
#include <string>

bool Importer::isOpen(){
    return static_cast<bool>(m_file);
}

void Importer::OpenFile(std::string path){
    m_file.close();
    m_file.open(path);
    if(!isOpen()){
        throw std::exception("Cannot Open the File!");
    }
}

void Importer::close(){
    m_file.close();
}

Model3D Importer::Load(std::string path){
    if (!checkExtension(path)) {
        throw std::exception("Extension Name Error!");
    }
    OpenFile(path);
    Model3D model = read();
    close();
    return model;
}

std::ifstream& Importer::getFile() {
    return m_file;
}