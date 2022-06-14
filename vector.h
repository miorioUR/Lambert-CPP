#ifndef _VECTOR_
#define _VECTOR_

double norm(double v[], int n = 3);
double dot(double v1[], double v2[], int nv1 = 3, int nv2 = 3);
void cross(double v[], int &nv, double v1[], double v2[], int nv1 = 3, int nv2 = 3);

//double norm2(double v[]);
//void cross2(double v[], double v1[], double v2[]);

//void cross2(double v[], int &nv, double v1[], double v2[], int nv1, int nv2);

#endif