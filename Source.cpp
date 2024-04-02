#include <iostream>
#include "VectorN.h"

int main() {
    // Створення об'єктів класу Object
    Object obj1;
    Object obj2;
    Object obj3;

    std::cout << "Count of objects: " << Object::Count() << std::endl;

    // Створення векторів та виконання операцій
    double values1[] = { 1.0, 2.0, 3.0 };
    VectorN vector1(3, values1);

    double values2[] = { 4.0, 5.0, 6.0 };
    VectorN vector2(3, values2);

    VectorN vector3 = vector1 + vector2;
    VectorN vector4 = vector1 - vector2;
    VectorN vector5 = vector1 * vector2;

    std::cout << "Vector1: " << vector1;
    std::cout << "Vector2: " << vector2;
    std::cout << "Vector1 + Vector2: " << vector3;
    std::cout << "Vector1 - Vector2: " << vector4;
    std::cout << "Vector1 * Vector2 (dot product): " << vector5;

    // Перевірка операторів інкремента та декремента
    ++vector1;
    std::cout << "After pre-increment Vector1: " << vector1;
    vector2++;
    std::cout << "After post-increment Vector2: " << vector2;

    --vector1;
    std::cout << "After pre-decrement Vector1: " << vector1;
    vector2--;
    std::cout << "After post-decrement Vector2: " << vector2;

    return 0;
}
