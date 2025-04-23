#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    while (true) {
        Triangle t;
        char lbl = 'A';
        double x, y;

        // Input coordinates for the triangle
        for (int i = 0; i < 3; i++) {
            cout << "Enter x, y for point " << lbl << ": ";
            cin >> x >> y;
            if (lbl == 'A') t.A = { x, y };
            else if (lbl == 'B') t.B = { x, y };
            else t.C = { x, y };

            lbl = (lbl == 'A') ? 'B' : (lbl == 'B') ? 'C' : 'A';
        }

        Point p;
        cout << "Enter x, y for the point: ";
        cin >> x >> y;
        p = { x, y };

        // Check if the triangle is degenerate
        if (t.isDegenerate()) {
            cout << "The triangle is degenerate!" << endl;
        }
        else {
            cout << "The triangle is not degenerate." << endl;
        }

        // Check if the point is inside the triangle or on its boundary
        if (t.containsAlt(p)) {
            cout << "Point is inside or on the edge of the triangle!" << endl;
        }
        else {
            cout << "Point is outside the triangle!" << endl;
        }

        // Option to continue or exit
        char choice;
        cout << "Countinue? (y/n): ";
        cin >> choice;
        if (choice != 'y') break;
    }

    return 0;
}
