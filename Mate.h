#pragma once
#include <iostream>
#include <cmath>
//pentru functie

struct
{
    double a, b, c;
}fc1;

double x2(double x)
{
    return   0.1*x * x;
}

double x3(double x)
{
    return 0.01*x * x * x ;
}

double sqrtx(double x)
{
    return 3*sqrt(x);
}

double lnx(double x)
{
    return 20*log(x);
}

double xp2(double x)
{
    return pow(1.1,x);
}

double x1(double x)
{
    return 10000 * 1 / x;
}



