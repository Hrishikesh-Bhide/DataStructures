#include <iostream>
#include "include/comp_util.h"
#include "include/math_util.h"
#include "include/util.h"

int main() {
    int x = 5;
    int a = 10, b = 3;

    std::cout << "Square(" << x << ") = " << mathutil::square(x) << "\n";
    std::cout << "Cube(" << x << ")   = " << mathutil::cube(x) << "\n";

    std::cout << "Min(" << a << ", " << b << ") = " << arrayutil::min(a, b) << "\n";
    std::cout << "Max(" << a << ", " << b << ") = " << arrayutil::max(a, b) << "\n";

    return 0;
}
