#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

namespace Const {

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

    TEST(TestConst, test_Const) {
        Car *car = new Car;
        carFunc(car);
    }
}
