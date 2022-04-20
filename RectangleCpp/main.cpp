#include <iostream>
#include "Rectangle.h"
#include "Point.h"


using namespace std;

int main() {
    auto firstPoint = Point(0, 0);
    auto secondPoint = Point(1, 1);
    auto color = Color(Colors::BLACK);
    auto rectangle = Rectangle(firstPoint, secondPoint, color);
    
    cout << endl << endl;
    cout << rectangle << endl;
    cout << endl << endl;

    cout << endl << endl;
    cout << Rectangle(Point(5, 5), Point(-10, 10), Color(255, 0, 46)).toString() << endl;
    cout << endl << endl;
}