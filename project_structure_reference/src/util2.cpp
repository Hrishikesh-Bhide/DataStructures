#include "../include/util.h"

int arrayutil::max(int a, int b)
{
    if (a < b) {
        return b;
    }
    return a;
}