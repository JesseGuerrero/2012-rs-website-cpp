#include "routes/indexRoutes.hpp"
#include "JesseGlobals.h"

void reloadCsp()
{
    std::string base_dir = viewsPath.string();
    std::string arr[] = { base_dir + "ListParameters.csp" };
    std::vector<std::string> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::string arr2[] = { base_dir };
    std::vector<std::string> v2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    drogon::app().enableDynamicViewsLoading(v, base_dir);
    //memories above deallocate
}

int main() {
    reloadCsp();
    drogon::app().addListener("0.0.0.0",3000);
    drogon::app().setDocumentRoot(documentRootPath.string());
    handleRoutes();

    drogon::app().run();
    return 0;
}
