#include "header/Viewer.hpp"
#include "../Model/header/objImporter.hpp"
#include "../Model/header/objExporter.hpp"
#include <iostream>
#include <optional>
#include <ostream>

Viewer::Viewer() {
    initialize();
    main_loop();
    exit();
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
              << "13. Show Statistics." << std::endl
              << "14. Exit." << std::endl;
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
        showStatistics();
    } else if (num == 14) {
        return false;
    } else {
        std::cout << "Invalid Input. Please retry." << std::endl;
    }
    return true;
}

void Viewer::importModel() {
    std::string path;
    std::cout << "Input filepath:";
    std::cin >> path;
    if (m_pController->read(path)) {
        std::cout << "Imported Model Successfully!" << std::endl;
    } else {
        std::cout << "Import Model Failed! Please retry!" << std::endl;
        importModel();
    }
}

void Viewer::exportModel() {
    std::string path;
    std::cout << "Input filepath:";
    std::cin >> path;
    if (m_pController->write(path)) {
        std::cout << "Exported Model Successfully!" << std::endl;
    } else {
        std::cout << "Export Model Failed! Please retry!" << std::endl;
        exportModel();
    }
}

void Viewer::listAllFaces() {
    auto faceList = m_pController->getFace();
    for (int i = 0; i < faceList.size(); i++) {
        std::cout << "#" << i << ": " << faceList[i] << std::endl;
    }
}
void Viewer::deleteFace() {
    int index;
    std::cout << "Input the index of the face to be deleted: ";
    std::cin >> index;
    if (m_pController->deleteFace(index)) {
        std::cout << "Deleted face #" << index << " successfully!" << std::endl;
    } else {
        std::cout << "Delete face failed! Please retry!" << std::endl;
        deleteFace();
    }
}

void Viewer::addFace() {
    Point3D PointArray[3];
    std::cout << "Input the first point: ";
    std::cin >> PointArray[0];
    std::cout << "Input the second point: ";
    std::cin >> PointArray[1];
    std::cout << "Input the third point: ";
    std::cin >> PointArray[2];
    if (m_pController->addFace(PointArray[0], PointArray[1], PointArray[2])) {
        std::cout << "Added Face Successfully" << std::endl;
    } else {
        std::cout << "Add Face Failed! Please retry!" << std::endl;
        addFace();
    }
}

void Viewer::pointsInFace() {
    std::cout << "Input the index of the face: ";
    int index;
    std::cin >> index;
    auto points_opt = m_pController->pointsInFace(index);
    if (points_opt != std::nullopt) {
        auto points = points_opt.value();
        for (int i = 0; i < 3; i++) {
            std::cout << "#" << i << ":" << points[i] << std::endl;
        }
    } else {
        std::cout << "Get points in face failed! Please retry!" << std::endl;
        pointsInFace();
    }
}

void Viewer::modifyFace() {
    std::cout << "Input the index of the face: ";
    int index;
    std::cin >> index;
    std::cout << "Input the num of the point: ";
    int whichPoint;
    std::cin >> whichPoint;
    std::cout << "Input the new point: ";
    Point3D newPoint;
    std::cin >> newPoint;
    if (m_pController->modifyPointInFace(index, whichPoint, newPoint)) {
        std::cout << "Modified face successfully!" << std::endl;
    } else {
        std::cout << "Modify face failed! Please retry!" << std::endl;
        modifyFace();
    }
}

void Viewer::listAllLines() {
    auto lineList = m_pController->getLine();
    for (int i = 0; i < lineList.size(); i++) {
        std::cout << "#" << i << ": " << lineList[i] << std::endl;
    }
}

void Viewer::deleteLine() {
    int index;
    std::cout << "Input the index of the line to be deleted: ";
    std::cin >> index;
    if (m_pController->deleteLine(index)) {
        std::cout << "Deleted line #" << index << " successfully!" << std::endl;
    } else {
        std::cout << "Delete line failed! Please retry!" << std::endl;
        deleteLine();
    }
}

void Viewer::addLine() {
    Point3D PointArray[2];
    std::cout << "Input the first point: ";
    std::cin >> PointArray[0];
    std::cout << "Input the second point: ";
    std::cin >> PointArray[1];
    if (m_pController->addLine(PointArray[0], PointArray[1])) {
        std::cout << "Added Line Successfully" << std::endl;
    } else {
        std::cout << "Add Line Failed! Please retry!" << std::endl;
        addLine();
    }
}

void Viewer::pointsInLine() {
    std::cout << "Input the index of the line: ";
    int index;
    std::cin >> index;
    auto points_opt = m_pController->pointsInLine(index);
    if (points_opt != std::nullopt) {
        auto points = points_opt.value();
        for (int i = 0; i < 2; i++) {
            std::cout << "#" << i << ":" << points[i] << std::endl;
        }
    } else {
        std::cout << "Get points in line failed! Please retry!" << std::endl;
        pointsInLine();
    }
}

void Viewer::modifyLine() {
    std::cout << "Input the index of the line: ";
    int index;
    std::cin >> index;
    std::cout << "Input the num of the point: ";
    int whichPoint;
    std::cin >> whichPoint;
    std::cout << "Input the new point: ";
    Point3D newPoint;
    std::cin >> newPoint;
    if (m_pController->modifyPointInLine(index, whichPoint, newPoint)) {
        std::cout << "Modified line successfully!" << std::endl;
    } else {
        std::cout << "Modify line failed! Please retry!" << std::endl;
        modifyLine();
    }
}

void Viewer::showStatistics() {
    auto stat = m_pController->showStat();
    std::cout << "Face Count: " << stat.FaceCount << std::endl
              << "Face Area: " << stat.FaceArea << std::endl
              << "Line Count: " << stat.LineCount << std::endl 
              << "Line Length:" <<stat.LineLength << std::endl 
              << "Point Count: " << stat.PointCount << std::endl 
              << "Volume of Axix-Aligned Bounding Box: " << stat.AABBVolume
              << std::endl;
}

void Viewer::exit() {
    std::cout << "Exiting..." << std::endl;
}