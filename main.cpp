#include <iostream>
#include "catenary.h"

template <typename T>
int get_num(T &a){
    std::cin >> a;
    if(!std::cin.good())
        return 1;
    return 0;
}
void menu();
void action(Catenary::Catenary &c, int s);

int main() {
    double x1, x2, a;
    std::cout << "Enter parameter (a) of catenary: ";
    get_num(a);
    std::cout << "Enter left border (x1) of catenary: ";
    get_num(x1);
    std::cout << "Enter right border (x2) of catenary: ";
    get_num(x2);

    try{
        Catenary::Catenary c(x1, x2, a);
        int s = 1;
        while(s != 0){
            menu();
            get_num(s);
            action(c, s);
        }
    }
    catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
        return 0;
    }

    return 0;
}

void menu(){
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "0. Exit program " << std::endl;
    std::cout << "1. Check catenary's info " << std::endl;
    std::cout << "2. Set new left border (x1)" << std::endl;
    std::cout << "3. Set new right border (x2)" << std::endl;
    std::cout << "4. Set new parameter (a)" << std::endl;
    std::cout << "5. Find f(x) value" << std::endl;
    std::cout << "6. Find arc length" << std::endl;
    std::cout << "7. Find curvature radius by x" << std::endl;
    std::cout << "8. Find curvature center" << std::endl;
    std::cout << "9. Find area of trapezoid" << std::endl;
    std::cout << ">";
}

void action(Catenary::Catenary &c, int s){
    switch (s) {
        case 0: break;
        case 1:
            std::cout << "x1=" << c.get_x1() << "\t x2=" << c.get_x2() << "\t a=" << c.get_parameter() << std::endl;
            std::cout << std::endl;
            break;
        case 2:
            double x1;
            std::cout << "Enter new left border: ";
            get_num(x1);
            std::cout << std::endl;
            c.set_x1(x1);
            break;
        case 3:
            double x2;
            std::cout << "Enter new right border: ";
            get_num(x2);
            std::cout << std::endl;
            c.set_x2(x2);
            break;
        case 4:
            double a;
            std::cout << "Enter new parameter: ";
            get_num(a);
            std::cout << std::endl;
            c.set_parameter(a);
            break;
        case 5:
            double x;
            std::cout << "Enter x0:  ";
            get_num(x);
            std::cout << std::endl;
            std::cout << "f(" << x << ") = " << c.f(x) << std::endl;
            break;
        case 6:
            std::cout << "L = " << c.arc_length() << std::endl;
            break;
        case 7:
            double x0;
            std::cout << "Enter x0:  ";
            get_num(x0);
            std::cout << std::endl;
            std::cout << "In x0 = " << x0 << "  R = " << c.curvature_radius(x0) << std::endl;
            break;
        case 8:
            double xr;
            std::cout << "Enter x0:  ";
            get_num(xr);
            std::cout << std::endl;
            std::cout << "Curvature radius is point P(" << c.curvature_center(xr).get_x() << ";"
                      << c.curvature_center(xr).get_y() << ")" << std::endl;
            break;
        case 9:
            std::cout << "S = " << c.trapezoid_area() << std::endl;
            break;
        default:
            std::cout << "Invalid choice..." << std::endl;
    }
}

