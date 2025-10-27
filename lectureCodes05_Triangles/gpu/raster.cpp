#include "raster.h"
#include <vector>
#include <math/math.h>

Raster::Raster()
{

}

Raster::~Raster()
{

}

void Raster::rasterLine(std::vector<Point>& result, const Point& v0, const Point& v1)
{
    Point start = v0;
    Point end = v1;

    // Ensure x increases, swap if needed
    if (start.x > end.x)
    {
        std::swap(start, end);
    }
    result.push_back(start);

    // Ensure y increases, record if flip needed
    bool flipY = false;
    if (start.y > end.y)
    {
        start.y = static_cast<int32_t>(start.y * -1);
        end.y = static_cast<int32_t>(end.y * -1);
        flipY = true;
    }

    // Ensure slope is between 0-1, record if swap needed
    int deltaX = static_cast<int>(end.x - start.x);
    int deltaY = static_cast<int>(end.y - start.y);

    bool swapXY = false;
    if (deltaX < deltaY)
    {
        std::swap(start.x, start.y);
        std::swap(end.x, end.y);
        std::swap(deltaX, deltaY);
        swapXY = true;
    }

    // Bresenham algorithm
    int currentX = static_cast<int>(start.x);
    int currentY = static_cast<int>(start.y);

    int resultX = 0;
    int resultY = 0;

    Point currentPoint;
    int p = 2 * deltaY - deltaX;

    for (int i = 0; i < deltaX; ++i)
    {
        if (p >= 0)
        {
            currentY++;
            p -= 2 * deltaX;
        }
        currentX++;
        p += 2 * deltaY;

        // Process new x, y
        resultX = currentX;
        resultY = currentY;
        if (swapXY)
        {
            std::swap(resultX, resultY);
        }
        if (flipY)
        {
            resultY = static_cast<int>(resultY * -1);
        }

        // Generate new vertex
        currentPoint.x = resultX;
        currentPoint.y = resultY;
        result.push_back(currentPoint);
    }
}

void Raster::rasterizeTriangle(std::vector<Point>& result, const Point& v0, const Point& v1, const Point& v2)
{
    // Find bounding box of the triangle
    int maxX = static_cast<int>(std::max(v0.x, std::max(v1.x, v2.x)));
    int maxY = static_cast<int>(std::max(v0.y, std::max(v1.y, v2.y)));
    int minX = static_cast<int>(std::min(v0.x, std::min(v1.x, v2.x)));
    int minY = static_cast<int>(std::min(v0.y, std::min(v1.y, v2.y)));

    math::vec2f pv0, pv1, pv2;
    Point currentPoint;
    for (int i = minX; i <= maxX; ++i)
    {
		for (int j = minY; j <= maxY; ++j)
		{
            pv0 = math::vec2f(static_cast<float>(v0.x - i), static_cast<float>(v0.y - j));
            pv1 = math::vec2f(static_cast<float>(v1.x - i), static_cast<float>(v1.y - j));
            pv2 = math::vec2f(static_cast<float>(v2.x - i), static_cast<float>(v2.y - j));

            float cross1=math::cross(pv0, pv1);
            float cross2=math::cross(pv1, pv2);
            float cross3=math::cross(pv2, pv0);

            bool  negativeAll = cross1 < 0 && cross2 < 0 && cross3 < 0;
            bool positiveAll = cross1 > 0 && cross2 > 0 && cross3 > 0;

            if (negativeAll || positiveAll)
            {
                currentPoint.x = i;
                currentPoint.y = j;
                result.push_back(currentPoint);
            }
		}
    }

}
