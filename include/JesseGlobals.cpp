#include "JesseGlobals.h"
#include <filesystem>
namespace fs = std::filesystem;
const fs::path viewsPath = fs::current_path().parent_path() / "views/";
const fs::path documentRootPath = fs::current_path().parent_path() / "public/";