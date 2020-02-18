#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

namespace Const {

    class CConst : public ::testing::Test {
    public:
        CConst() : Test() {
            std::cout << std::endl;
            std::cout << "------ constructor" << std::endl;
        }

        ~CConst() {
        }

        virtual void SetUp() {
            Test::SetUp();
        }

        virtual void TearDown() {
            Test::TearDown();
        }
    };

    class Car {
    public:
        void Run() const { printf("--- Car Run\n"); }

        void Stop() { printf("--- Car Stop\n"); }
    };

    void carFunc(const Car *_car) {
        _car->Run();

        Car *tmpCar = const_cast<Car *>(_car); //ȥ��const�޶�
        tmpCar->Stop();
    }

    TEST_F(CConst, test_Const) {
        Car *car = new Car;
        carFunc(car);
    }
}
