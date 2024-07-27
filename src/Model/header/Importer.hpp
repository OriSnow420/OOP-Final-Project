// TODO: comment

#ifndef Importer_cpp
#define Importer_cpp

#include "Model3D.hpp"
#include <fstream>
#include <string>

class Importer {
private:
    std::ifstream m_file;

protected:
    std::ifstream& getFile();

private:
    void OpenFile(std::string path);
    virtual bool checkExtension(std::string path) const = 0;
    bool isOpen();
    void close();
    virtual Model3D read() = 0;

public:
    virtual ~Importer();
    Model3D Load(std::string path);

};

#endif
