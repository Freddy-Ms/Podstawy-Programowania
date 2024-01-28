#include <iostream>


struct Point {
    double x, y;
};


double determinant(const Point& p1, const Point& p2, const Point& p3) {
    return p1.x * (p2.y - p3.y) - p2.x * (p1.y - p3.y) + p3.x * (p1.y - p2.y);
}


bool czyWspolliniowe(const Point& p1, const Point& p2, const Point& p3) {
    return determinant(p1, p2, p3) == 0;
}

int main() {

    Point p1, p2, p3;

    std::cout << "Podaj wspolrzedne punktu P1 (x y): ";
    std::cin >> p1.x >> p1.y;

    std::cout << "Podaj wspolrzedne punktu P2 (x y): ";
    std::cin >> p2.x >> p2.y;

    std::cout << "Podaj wspolrzedne punktu P3 (x y): ";
    std::cin >> p3.x >> p3.y;

    if (czyWspolliniowe(p1, p2, p3)) {
        std::cout << "Punkty sa wspolliniowe." << std::endl;
    } else {
        std::cout << "Punkty nie sa wspolliniowe." << std::endl;
    }

    return 0;
}
