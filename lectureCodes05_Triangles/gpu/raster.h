#pragma once
#include "../global/base.h"

// Provides static function interfaces for rasterization
// Takes offline primitive points and returns rasterized pixel array
class Raster {
public:
    Raster();
    ~Raster();

    static void rasterLine(std::vector<Point>& result, const Point& v0, const Point& v1);
    static void rasterizeTriangle(std::vector<Point>& result, const Point& v0, const Point& v1, const Point& v2);
};
