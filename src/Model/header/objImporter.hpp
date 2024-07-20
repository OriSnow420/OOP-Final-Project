
// TODO: comment

#ifndef objImporter_hpp
#define objImporter_hpp

#include "Importer.hpp"
class objImporter : public Importer {
private:
    
public:

    virtual Model3D Load(std::string path) override;
};

#endif
