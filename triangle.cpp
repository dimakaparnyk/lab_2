#include <cmath>
#include <iostream>
#include "triangle.h"

using namespace std;

// Функція для обчислення відстані між двома точками
double dist(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Функція для обчислення векторного добутку двох векторів
double cross(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

// Функція для обчислення площі трикутника за формулою Герона
double heronArea(const Triangle& t) {
    double a = dist(t.A, t.B), b = dist(t.B, t.C), c = dist(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Метод для обчислення площі трикутника
double Triangle::area() const {
    return heronArea(*this);
}

// Метод для перевірки, чи є трикутник виродженим (якщо його площа дорівнює нулю)
bool Triangle::isDegenerate() const {
    // Використовуємо векторний добуток для перевірки, чи площа трикутника дорівнює нулю
    double crossProduct = cross({ B.x - A.x, B.y - A.y }, { C.x - A.x, C.y - A.y });
    return fabs(crossProduct) < 1e-9;  // Якщо площа дорівнює нулю, векторний добуток також буде нулем
}

// Метод для перевірки, чи точка знаходиться всередині трикутника
bool Triangle::contains(const Point& p) const {
    Triangle t1 = { A, B, p }, t2 = { B, C, p }, t3 = { C, A, p };
    return fabs(area() - (t1.area() + t2.area() + t3.area())) < 1e-9;
}

// Альтернативний метод перевірки приналежності точки трикутнику через векторний добуток
bool Triangle::containsAlt(const Point& p) const {
    // Створюємо вектори для сторін трикутника та точок
    Point ab = { B.x - A.x, B.y - A.y }, bc = { C.x - B.x, C.y - B.y },
        ca = { A.x - C.x, A.y - C.y }, ap = { p.x - A.x, p.y - A.y },
        bp = { p.x - B.x, p.y - B.y }, cp = { p.x - C.x, p.y - C.y };

    // Обчислюємо векторні добутки
    double cross1 = cross(ab, ap), cross2 = cross(bc, bp), cross3 = cross(ca, cp);

    // Якщо всі векторні добутки мають однаковий знак, точка всередині трикутника
    if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0)) return true;

    // Якщо один з добутків дорівнює нулю, точка на межі трикутника
    if (cross1 == 0 || cross2 == 0 || cross3 == 0) {
        cout << "A point on the edge of a triangle." << endl;
        return true;
    }
    return false;
}
