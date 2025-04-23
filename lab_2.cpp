#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    while (true) {
        Triangle t;
        char lbl = 'A';
        double x, y;

        // Введення координат для трикутника
        for (int i = 0; i < 3; i++) {
            cout << "Enter x, y for point " << lbl << ": ";
            cin >> x >> y;
            if (lbl == 'A') t.A = { x, y };
            else if (lbl == 'B') t.B = { x, y };
            else t.C = { x, y };

            lbl = (lbl == 'A') ? 'B' : (lbl == 'B') ? 'C' : 'A';
        }

        // Дозволяє вибрати метод для перевірки виродженості трикутника
        char methodChoice;
        cout << "Choose method for checking degenerate triangle (H for Heron, V for Vector Cross Product): ";
        cin >> methodChoice;

        // Перевірка на виродженість трикутника
        bool isDegenerate = false;
        if (methodChoice == 'H' || methodChoice == 'h') {
            // Перевірка виродженості за допомогою формули Герона
            if (t.area() == 0) {
                isDegenerate = true;
            }
        }
        else if (methodChoice == 'V' || methodChoice == 'v') {
            // Перевірка виродженості за допомогою векторного добутку
            if (t.isDegenerate()) {
                isDegenerate = true;
            }
        }

        if (isDegenerate) {
            cout << "The triangle is degenerate!" << endl;
        }
        else {
            cout << "The triangle is not degenerate." << endl;
        }

        // Перевірка, скільки точок потрібно перевірити
        int numPoints;
        cout << "How many points do you want to check? ";
        cin >> numPoints;

        // Цикл для перевірки кожної точки
        for (int i = 0; i < numPoints; i++) {
            Point p;
            cout << "Enter x, y for point " << i + 1 << ": ";
            cin >> x >> y;
            p = { x, y };

            // Перевірка, чи точка знаходиться всередині, на межі або зовні трикутника
            t.containsAlt(p); 
        }



        // Запит для продовження або виходу
        char choice;
        cout << "Continue? (y/n): ";
        cin >> choice;
        if (choice != 'y') break;
    }

    return 0;
}
