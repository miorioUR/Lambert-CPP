#include "vector.h"
#include <math.h>

// Función que calcula la norma de un vector
// In: v vector (double)
// In: n dimensión (int)
// Out: devuelve la norma de v
double norm(double v[], int n)
{
    double sum = 0;
    int i;

    if( n <= 0)
	throw "Empty vector";

    for(i = 0; i < n; i++)
	sum += v[i]*v[i];

    return sqrt(sum);
}

/*
double norm2(double v[])
{
    double sum = 0;
    int i;
    int vlength = sizeof(v)/sizeof(*v);

    for(i = 0; i < vlength; i++)
	sum += v[i]*v[i];

    return sqrt(sum);
}
 */ 

// Función que calcula el producto escalar de dos vectores
// In: v1, v2 vectores (double)
// In: nv1, nv2 dimensiones (int)
// Out: devuelve el producto escalar de v1 y v2
double dot(double v1[], double v2[], int nv1, int nv2)
{
    double sum = 0;
    int i;

    if((nv1 <= 0) || (nv2 <= 0) | (nv1 != nv2))
        throw "Empty vector or different dimensions";

    for(i = 0; i < nv1; i++)
        sum += v1[i]*v2[i];

    return sum;
}

// Función que calcula el producto vectorial de dos vectores
// In: v1, v2 vectores (double)
// In: nv1, nv2 dimensiones (int)
// Out: devuelve el producto vectorial de v1 y v2
void cross(double v[], int &nv, double v1[], double v2[], int nv1, int nv2)
{
    double sum = 0;
    int i;

    if((nv1 <= 0) || (nv2 <= 0) | (nv1 != nv2))
        throw "Empty vector or different dimensions";

    v[0] = -v1[2]*v2[1] + v1[1]*v2[2];
    v[1] = v1[2]*v2[0] - v1[0]*v2[2];
    v[2] =  -v1[1]*v2[0] + v1[0]*v2[1];
    nv = nv1;
}

/*
void cross2(double v[], double v1[], double v2[])
{
    v[0] = -v1[2]*v2[1] + v1[1]*v2[2];
    v[1] = v1[2]*v2[0] - v1[0]*v2[2];
    v[2] =  -v1[1]*v2[0] + v1[0]*v2[1];

}
*/