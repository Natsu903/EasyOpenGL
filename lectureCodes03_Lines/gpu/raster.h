#pragma once
#include "../global/base.h"

/**
 * 对外提供静态函数接口，传入离线的图元点，返回光栅化后的像素数组.
 */
class Raster {
public:
    Raster();
    ~Raster();

    static void rasterLine(std::vector<Point>& result, const Point& v0, const Point& v1);
};
