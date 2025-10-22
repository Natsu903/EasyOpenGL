#include "raster.h"
#include <vector>

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

    //保证x方向递增，否则交换两个点的位置
    if (start.x > end.x)
    {
        std::swap(start, end);
    }
    result.push_back(start);

    //保证y方向递增，如果需要反转，则需要记录
    bool flipY = false;
    if (start.y > end.y)
    {
        start.y *= -1.0f;
        end.y *= -1.0f;
        flipY = true;
    }

    //保障线段斜率在0-1之间，如需调整，则需要记录
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

    //brensenham
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
            p-= 2 * deltaX;
        }
        currentX++;
        p+= 2 * deltaY;

		//处理新xy
		resultX = currentX;
		resultY = currentY;
		if (swapXY)
		{
			std::swap(resultX, resultY);
		}
		if (flipY)
		{
			resultY *= -1.0f;
		}

		//产生新顶点
		currentPoint.x = resultX;
		currentPoint.y = resultY;
		result.push_back(currentPoint);
    }
}

