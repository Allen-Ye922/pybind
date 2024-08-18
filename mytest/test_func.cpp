#include "lynn.h"


#define f(a) #a

int add(int i, int j)
{
    return i + j;
}

TEST_SUBMODULE(func_, m)
{
    m.def("add", &add, "add func for two integers",
          "i"_a = 1, "j"_a = 2
         );
}
