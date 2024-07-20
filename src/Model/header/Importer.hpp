// TODO: comment

#ifndef Importer_cpp
#define Importer_cpp

#include "Model3D.hpp"
#include <string>

class Importer {
private:
    
public:
    virtual Model3D Load(std::string path) = 0;

};

#endif
