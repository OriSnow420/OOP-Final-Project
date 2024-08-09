#include "header/Viewer.hpp"
#include "../Model/header/objImporter.hpp"
#include "../Model/header/objExporter.hpp"
#include <iostream>
#include <ostream>

Viewer::Viewer() {
    initialize();
    main_loop();
}

Viewer::~Viewer() {}

void Viewer::initialize() {
    // TODO: Let user able to choose importer and exporter 
    // (Although there is only one choice)
    m_pController = Controller::GetInstance<objImporter, objExporter>();
}

void Viewer::main_loop() {
    while (one_loop()) {
        // Empty loop
    }
}

bool Viewer::one_loop() {
    std::cout << "1. Import Model." << std::endl
              << "2. Export Model." << std::endl
              << "3. List all faces." << std::endl
              << "4. Delete face." << std::endl 
              << "5. Add face." << std::endl 
              << "6. Points in face." << std::endl 
              << "7. Modify face." << std::endl 
              << "8. List all lines." << std::endl 
              << "9. Delete line." << std::endl 
              << "10. Add line." << std::endl 
              << "11. Points in line. " << std::endl
              << "12. Modify line." << std::endl
              << "13. Exit." << std::endl;
    std::cout << "Type the number of the options:";
    int num;
    std::cin >> num;
    if (num == 1) {
        importModel();
    } else if (num == 2) {
        exportModel();
    } else if (num == 3) {
        listAllFaces();
    } else if (num == 4) {
        deleteFace();
    } else if (num == 5) {
        addFace();
    } else if (num == 6) {
        pointsInFace();
    } else if (num == 7) {
        modifyFace();
    } else if (num == 8) {
        listAllLines();
    } else if (num == 9) {
        deleteLine();
    } else if (num == 10) {
        addLine();
    } else if (num == 11) {
        pointsInLine();
    } else if (num == 12) {
        modifyLine();
    } else if (num == 13) {
        std::cout << "Exiting..." << std::endl;
        return false;
    } else {
        std::cout << "Invalid Input. Please retry." << std::endl;
    }
    return true;
}

void Viewer::importModel() {

}
void Viewer::exportModel() {
    
}
void Viewer::listAllFaces() {
    
}
void Viewer::deleteFace() {
    
}
void Viewer::addFace() {
    
}
void Viewer::pointsInFace() {
    
}
void Viewer::modifyFace() {
    
}
void Viewer::listAllLines() {
    
}
void Viewer::deleteLine() {
    
}
void Viewer::addLine() {
    
}
void Viewer::pointsInLine() {
    
}
void Viewer::modifyLine() {
    
}