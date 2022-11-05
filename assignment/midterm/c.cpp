using namespace std;
#include <iostream>

unsigned int block(const unsigned int *first, const unsigned int *second=NULL)
{

    auto _ = [](const unsigned int s, const unsigned int i) {

    return 1812433253u * (s ^ (s >> 30)) + i + 1u;

    };

    unsigned int x = _(*first, second?*second:0);

    unsigned int y = _(x, 1);

    unsigned int z = _(y, 2);

    unsigned int w = _(z, 3);

    return w;
}