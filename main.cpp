#include <iostream>
#include "catenary.h"

int main() {
    Catenary a(-1, 2, 4);

    Point p = a.curvature_center(0);
    std::cout << p.get_x() << "     " << p.get_y() << std::endl;


    //std::cout << a.trapezoid_area();
    //std::cout << a.arc_length() << std::endl;
    return 0;
}
