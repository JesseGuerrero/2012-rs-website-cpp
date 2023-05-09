#include "JesseCSPHelpers.h"
#include "JesseGlobals.h"
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;
std::string readView(std::string viewName) { //perhaps write this in the csp files as a veriable then pass to [[ partial ]]
    fs::path filePath = viewsPath / viewName;
    std::cout << "curr dir " << filePath;
    std::ifstream indexFile(filePath);
    if (indexFile.good()) {
        std::string indexHtml((std::istreambuf_iterator<char>(indexFile)), std::istreambuf_iterator<char>());
        return indexHtml;
    }

    return "";
}