
// TODO: comment

#ifndef objImporter_hpp
#define objImporter_hpp

#include "Importer.hpp"
#include "Model3D.hpp"

class objImporter : public Importer {
private:
    virtual bool checkExtension(std::string path) const override;
    virtual Model3D read() override;

public:
    ~objImporter();

};

#endif
