#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#define HEADER                                                                          \
    "// WARNING: THIS FILE IS AUTOMATICALLY\n// GENERATED USING ../scripts/headerGen\n" \
    "// This is built from ../scripts/headerList.cpp\n"                                      \
    "// Contains all headers used in this library\n\n"                                  \
    "#pragma once\n"

namespace fs = std::filesystem;

// Function to check if a string ends with a certain suffix
bool ends_with(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main()
{
    std::string include_dir = "./include";
    std::string output_file = include_dir + "/allheaders.h";

    // Open the output file
    std::ofstream outfile(output_file);
    if (!outfile.is_open())
    {
        std::cerr << "Error opening the output file." << std::endl;
        return 1;
    }
    outfile << HEADER << "#ifdef DEVELOPMENT_MODE\n";
    // Iterate over files in the directory
    for (const auto &entry : fs::directory_iterator(include_dir))
    {
        if (entry.is_regular_file())
        {
            std::string filename = entry.path().filename().string();

            // Skip the output file itself
            if (filename != "allheaders.h" && ends_with(filename, ".h"))
            {
                outfile << "#include \"" << filename << "\"" << std::endl;
            }
        }
    }
    outfile << "#else\n";
    for (const auto &entry : fs::directory_iterator(include_dir))
    {
        if (entry.is_regular_file())
        {
            std::string filename = entry.path().filename().string();

            // Skip the output file itself
            if (filename != "allheaders.h" && ends_with(filename, ".h"))
            {
                outfile << "#include <mathlib/" << filename << ">" << std::endl;
            }
        }
    }
    outfile << "#endif" << std::endl;

    // Close the output file
    outfile.close();

    std::cout << "Header files have been written to allheaders.h." << std::endl;
    return 0;
}
