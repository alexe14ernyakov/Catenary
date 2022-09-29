#include "catenary.h"

namespace Catenary{
    void Catenary::correct_check() {
        if (x1 > x2) {
            double tmp = x2;
            x2 = x1;
            x1 = tmp;
        }
    }

    Catenary::Catenary() {
        x1 = -1;
        x2 = 1;
        a = 1;
    }

    Catenary::Catenary(double value_x1, double value_x2, double parameter) {
        if (value_x1 > value_x2) {
            x1 = value_x2;
            x2 = value_x1;
        } else {
            x1 = value_x1;
            x2 = value_x2;
        }
        a = parameter;
    }

    void Catenary::set_x1(double new_value) {
        x1 = new_value;
        correct_check();
    }

    void Catenary::set_x2(double new_value) {
        x2 = new_value;
        correct_check();
    }

    double Catenary::manual_integral() const {
        double c = x1;
        double S = 0;
        while (c < x2) {
            S += sqrt(1 + (sinh(c / a)) * (sinh(c / a))) * 0.00005;
            c += 0.00005;
        }
        return S;
    }

    double Catenary::arc_length() const {
        return a * sinh(x2 / a) - a * sinh(x1 / a);
        //return manual_integral();
    }

    double Catenary::curvature_radius(double x) const {
        return a * cosh(x / a) * cosh(x / a);
    }

    Point Catenary::curvature_center(double x0) const {
        double derivative = sinh(x0 / a);
        double r = curvature_radius(x0);
        double dx = r / sqrt(1 + (1 / (derivative * derivative)));
        double dy = -dx / derivative;
        if (x0 < 0)
            return {x0 + dx, f(x0) + dy};
        else if (x0 > 0)
            return {x0 - dx, f(x0) - dy};
        else
            return {0, f(0) + curvature_radius(0)};
    }

    double Catenary::trapezoid_area() const {
        return a * a * (sinh(x2 / a) - sinh(x1 / a));
    }
}





