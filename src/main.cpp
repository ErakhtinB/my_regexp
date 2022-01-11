#include <iostream>
#include <memory>

#include "Regex.h"
#include "FileLineProvider.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Wrong number of arguments passed: " << std::to_string(argc - 1)
            << ", strictly 2 is required" << std::endl;
        return -1;
    }
    try
    {
        regex::Match(std::make_shared<regex::FileLineProvider>(argv[2]),
            argv[1], std::cout);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -2;
    }
    return 0;
}
