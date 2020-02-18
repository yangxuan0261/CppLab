#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "gtest/gtest.h"

namespace FileIO {

    TEST(TestFileIO, tes_fileOut) {
        std::string content("");
        for (size_t i = 0; i < 5; i++) {
            content.append("------ test content\n");
        }
        content.append("\n");
        std::ofstream outFile("temp_logaaa.lua", std::ios::app);
        if (outFile.is_open()) {
            outFile << content;
        }
        outFile.close();
        std::cout << "--- write success" << std::endl;
    }
}
