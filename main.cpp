#include <iostream>
#include "test.h"

#include "library.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    CTest::print();
    hello();
    system("pause");
    return 0;
}
