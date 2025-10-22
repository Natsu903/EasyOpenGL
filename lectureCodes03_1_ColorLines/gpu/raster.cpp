#include "raster.h"
#include <vector>

Raster::Raster()
{

}

Raster::~Raster()
{

}

void Raster::interpolantLine(const Point& v0, const Point& v1, Point& target)
{
	float weight = 1.0f;
	if (v1.x != v0.x)
	{
		weight = (float)(target.x - v0.x) / (float)(v1.x - v0.x);
	}
	else if (v1.y != v0.y)
	{
        weight = (float)(target.y - v0.y) / (float)(v1.y - v0.y);
	}
	RGBA result;
	result.mR = static_cast<byte>(static_cast<float>(v1.color.mR) * weight + (1.0f - weight) * static_cast<float>(v0.color.mR));
    result.mG = static_cast<byte>(static_cast<float>(v1.color.mG) * weight + (1.0f - weight) * static_cast<float>(v0.color.mG));
    result.mB = static_cast<byte>(static_cast<float>(v1.color.mB) * weight + (1.0f - weight) * static_cast<float>(v0.color.mB));
    result.mA = static_cast<byte>(static_cast<float>(v1.color.mA) * weight + (1.0f - weight) * static_cast<float>(v0.color.mA));
	target.color = result;
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
        interpolantLine(start, end, currentPoint);
		result.push_back(currentPoint);
    }
}

