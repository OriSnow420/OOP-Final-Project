
// TODO: comment

#ifndef Exporter_hpp
#define Exporter_hpp

#include "Model3D.hpp"
#include <fstream>
#include <string>

class Exporter {
private:
    std::ofstream m_file;

protected:
    std::ofstream& getFile();

private:
    void OpenFile(std::string path);
    virtual bool checkExtension(const std::string& path) const = 0;
    bool isOpen() const;
    void close();
    virtual void writeToFile(const Model3D& model, 
    const std::string& filename) = 0;


public:
    void Write(std::string path, const Model3D& model);
};

#endif
