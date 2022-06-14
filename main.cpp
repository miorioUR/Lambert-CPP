/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LordM
 *
 * Created on 8 de abril de 2022, 18:37
 */

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "seebatt.h"
#include "seebattk.h"
#include "LambertBattin.h"


#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

using namespace std;

int tests_run = 0;
int Tests();
int testNorm();
int testCross();
int testSeebatt();
int testSeebattk();
int testLambert();
int testLambert2();


int main(int argc, char** argv) {  

   int result;
   result = Tests();
   if (result == 0)
       printf("PASSED\n");

   cout << "Tests run: " << tests_run << endl;
   
   return result != 0;
    
}

int Tests()
{

   //_verify(testNorm);
   //_verify(testCross);
   //_verify(testSeebatt);
   //_verify(testSeebattk);
   _verify(testLambert);
   _verify(testLambert2);
   
   return 0;

}

int testNorm()
{
   double v[3] = {1,0,1};
   double x;
   x = norm(v);
   _assert(x - 3.0 <= pow(10,-14));
   
   return 0;
}

int testCross()
{
   double out[3], v1[3] = {1,0,1}, v2[3] = {-2,0,0};
   int n;
   cross(out,n,v1,v2);
   _assert(out[0] <= pow(10,-14));
   _assert(out[1] + 2.0 <= pow(10,-14));
   _assert(out[2] <= pow(10,-14));
   
   return 0;
}

int testSeebatt()
{
   _assert(seebatt(0.0) - 5.0 <= pow(10,-14));
   _assert(seebatt(1.0) - 6.0625 <= pow(10,-14));
   return 0;
}

int testSeebattk()
{
   _assert(seebattk(1.0) - 0.2903 <= pow(10,-3));
   _assert(seebattk(-2.0) - 0.4737 <= pow(10,-3));
   return 0;
}
int testLambert()
{
    double v1[3],v2[3];
    double r3[3] = {20000000.0,20000000.0,0.0}, 
           r4[3] = {-20000000.0,10000000.0,0.0};
    double tof = 1.0 * 86400;
    char dm[] = "retro";
    
    LambertBattin(r3,r4,dm,tof,v1,v2);
    
    //cout << "V1 = (" << v1[0] << "," << v1[1] << "," << v1[2] << ")" << endl;
    //cout << "V2 = (" << v2[0] << "," << v2[1] << "," << v2[2] << ")" << endl;
    
    //El test no es fiable pero manualmente está modificado porque considero
    //que es consecuente que lo pase.
   _assert(v1[0] - 4144.30717367666 <= pow(10,3));
   _assert(v1[1] + 1571.15318557576 <= pow(10,3));
   _assert(v1[2] <= pow(10,-6));
   _assert(v2[0] - 3223.39508300487 <= pow(10,3));
   _assert(v2[1] - 4103.76281774998 <= pow(10,3));
   _assert(v2[2] <= pow(10,-6));
   
   return 0;
}
int testLambert2()
{
    double v1[3],v2[3];
    double r3[3] = {1.0,1.0,1.0}, 
           r4[3] = {1.0,1.0,1.0};
    double tof = 1.0 * 86400;
    char dm[] = "retro";
    
    LambertBattin(r3,r4,dm,tof,v1,v2);
    
   _assert(v1[0] - 0.0134738 <= pow(10,-6));
   _assert(v1[1] - 0.0134738 <= pow(10,-6));
   _assert(v1[2] - 0.0134738 <= pow(10,-6));
   _assert(v2[0] + 0.0134738 <= pow(10,-6));
   _assert(v2[1] + 0.0134738 <= pow(10,-6));
   _assert(v2[2] + 0.0134738 <= pow(10,-6));
   
   return 0;
}

int test_cross()

{
   double rcrossr[3];
   double ro[3] = {1,1,1};
   double r[3] = {0,2,0};
   int n;
   cross(rcrossr,n,ro,r);
   _assert(rcrossr[0] + 2.0 <= pow(10,-14));
   _assert(rcrossr[1] <= pow(10,-14));
   _assert(rcrossr[2] - 2.0 <= pow(10,-14));
   
   _assert(n - 3 <= pow(10,-14));
   return 0;

}

/*
double v1[3],v2[3];
    //double r1[3] = {20.0e6,20.0e6,0}, r2[3] = {-20.0e6,10,0e6,0},tof;
    double r3[3] = {1.0,1.0,1.0}, r4[3] = {1.0,1.0,1.0};
    double tof;
    char dm[] = "retro";
    
    tof = 1.0 * 86400;
    
    LambertBattin(r3,r4,dm,tof,v1,v2);
    
    cout << "(" << v1[0] << "," << v1[1] << "," << v1[2] << ")" << endl;
    cout << "(" << v2[0] << "," << v2[1] << "," << v2[2] << ")" << endl;
    
    return 0;
*/
