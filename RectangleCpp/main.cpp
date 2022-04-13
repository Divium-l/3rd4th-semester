#include <iostream>
#include "Rectangle.h"
#include "Point.h"


using namespace std;

int main() {
    auto firstPoint = Point(0, 0);
    auto secondPoint = Point(1, 1);
    auto color = Color(0, 0, 0);
    auto rectangle = Rectangle(firstPoint, secondPoint, color);
    cout << endl << endl;
    cout << rectangle.toString() << endl;
    cout << endl << endl;
}