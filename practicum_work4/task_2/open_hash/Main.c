#include "Common.h"
#include "Testing.h"

int main()
{
    for (double load_factor = 0.1; load_factor < 1; load_factor += 0.05)
    {
        int capacity = NUMBER_OF_ELEMENTS / load_factor;
        LoadFactorTester(capacity, load_factor);
    }

    FirstTest(MAX_LOAD_FACTOR);
    SecondTest(MAX_LOAD_FACTOR);

    return 0;
}