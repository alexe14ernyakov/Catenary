#ifndef CATENARY_CATENARY_H
#define CATENARY_CATENARY_H
#include <cmath>

namespace Catenary {
    struct Point {
        double x, y;

        Point() {
            x = 0;
            y = 0;
        }

        Point(double value_x, double value_y) {
            x = value_x;
            y = value_y;
        }

        double get_x() const { return x; }

        double get_y() const { return y; }
    };

    class Catenary {
    private:
        double x1, x2;
        double a;

        void correct_check();

        double manual_integral() const;

    public:
        Catenary();

        Catenary(double value_x1, double value_x2, double parameter);

        void set_x1(double new_value);

        void set_x2(double new_value);

        void set_parameter(double new_value) { a = new_value; }

        double get_x1() const { return x1; }

        double get_x2() const { return x2; }

        double get_parameter() const { return a; }

        double f(double x) const { return a * cosh(x / a); }

        double arc_length() const;

        double curvature_radius(double x) const;

        Point curvature_center(double x0) const;

        double trapezoid_area() const;
    };
}

#endif
