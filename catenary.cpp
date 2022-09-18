#include "catenary.h"

Catenary::Catenary() {
    x1 = -1;
    x2 = 1;
    a = 1;
}

Catenary::Catenary(double value_x1, double value_x2, double parameter) {
    if(value_x1 > value_x2){
        x1 = value_x2;
        x2 = value_x1;
    }else{
        x1 = value_x1;
        x2 = value_x2;
    }
    a = parameter;
}

double Catenary::arc_length() const {
    return a*sinh(x2/a) - a*sinh(x1/a);
}
