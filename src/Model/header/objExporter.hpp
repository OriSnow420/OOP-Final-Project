
// TODO: comment

#ifndef objExporter_hpp
#define objExporter_hpp

// TODO: finish the class
#include "Exporter.hpp"
#include "Model3D.hpp"

class objExporter : public Exporter {
private:
    virtual bool checkExtension(const std::string& path) const override;
    virtual void writeToFile(const Model3D& model, 
    const std::string& finename) override;

public:
    ~objExporter();
};

#endif
