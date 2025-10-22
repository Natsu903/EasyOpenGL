#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <assert.h>

#define PI 3.1415926535897932384626433832795
#define DEG2RAD(theta) (0.0174532925199433 * theta)
#define FRACTION(v) ((v)-(int)(v))

using byte = unsigned char;

struct RGBA
{
	byte mB;
    byte mG;
    byte mR;
    byte mA;

    RGBA(byte r = 255, byte g = 255, byte b = 255, byte a = 255)
    {
        mR = r;
        mG = g;
        mB = b;
        mA = a;
    }
};

struct Point
{
    int32_t x;
    int32_t y;
    RGBA color;
};
