/*
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "seebatt.h"


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

using namespace std;
int tests_run = 0;
int all_tests();
int test_01();
int main()

{
   int result = all_tests();
   if (result == 0)
       printf("PASSED\n");

   cout << "Tests run: " << tests_run << endl;

   return result != 0;

}



int all_tests()

{

   _verify(test_01);
   return 0;

}



int test_01()

{
   int x = 5;
   _assert(seebatt(0.0) - 5.0 <= pow(10,-14));
   _assert(seebatt(1.0) - 6.0625 <= pow(10,-14));
   return 0;

}
 * */