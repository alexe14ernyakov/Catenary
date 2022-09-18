#include <iostream>
#include "catenary.h"

int main() {
    Catenary a(-3, -1, 2);
    std::cout << a.arc_length() << std::endl;
    return 0;
}
