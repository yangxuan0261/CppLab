#include <iostream>
#include "test.h"

#include "library.h"

int main() {
    std::cout << "Hello, World 3!" << std::endl;
    CTest::print();
    hello();

#if (USE_LOG == 3)
    std::cout << USE_LOG << std::endl;
    std::cout << "USE_LOG yes! " << std::endl;
#endif

#ifdef USE_FILTER
    std::cout << "USE_FILTER yes!" << std::endl;
#endif
    system("pause");
    return 0;
}
