#ifndef CATENARY_CATENARY_H
#define CATENARY_CATENARY_H
#include <cmath>

class Catenary{
private:
    double x1, x2;
    double a;
public:
    Catenary();
    Catenary(double value_x1, double value_x2, double parameter);
    void set_x1(double new_value) {x1 = new_value;}
    void set_x2(double new_value) {x2 = new_value;}
    void set_parameter(double new_value) {a = new_value;}
    double f(double x) const {return a*cosh(x/a);}
    double arc_length() const;
};

#endif
