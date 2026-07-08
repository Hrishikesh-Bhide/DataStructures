#include "../include/util.h"
#include "../include/comp_util.h"

int arrayutil::max(int a, int b)
{
    if (a < b) {
        return b;
    }
    return a;
}

int test::min(int a, int b) {
    if (a < b) {
        return b;
    }
    return a;
}

