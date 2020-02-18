#pragma once

class ClassTemplate {
public:
    ClassTemplate();

    ~ClassTemplate();

    static void test();

    void testInline(int a);
};

inline void ClassTemplate::testInline(int a) {
    a = 123;
}