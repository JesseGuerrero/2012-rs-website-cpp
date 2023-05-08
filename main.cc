#include <drogon/drogon.h>
#include "controllers/Hello.h"
#include <iostream>
#include "routes/index.hpp"

void reloadCsp()
{
    std::string filePath(__FILE__);  // Get the file path of the current file
    std::string base_dir = filePath.substr(0, filePath.find_last_of("/\\"));
    std::string arr[] = { base_dir + "/views/ListParameters.csp" };
    std::vector<std::string> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::string arr2[] = { base_dir + "/views/" };
    std::vector<std::string> v2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    drogon::app().enableDynamicViewsLoading(v, base_dir + "/views/");
    //memories above deallocate
}


int main() {
    reloadCsp();
    drogon::app().addListener("0.0.0.0",3000);
    handleRoutes();

    drogon::app().run();
    return 0;
}




