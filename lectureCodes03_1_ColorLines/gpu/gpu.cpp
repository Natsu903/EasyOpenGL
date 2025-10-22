#include "gpu.h"
#include "frameBuffer.h"
#include <algorithm>
#include <vector>
#include "raster.h"

GPU* GPU::instance = nullptr;

GPU& GPU::getInstance()
{
	if (!instance)
	{
		instance = new GPU();
	}
	return *instance;
}

GPU::GPU()
{
}

GPU::~GPU()
{
	if (mframeBuffer)
	{
		delete mframeBuffer;
	}
}

void GPU::initSurface(const uint32_t& width, const uint32_t& height, void* buffer)
{
	mframeBuffer = new FrameBuffer(width, height, buffer);
}

void GPU::clear()
{
	size_t size = mframeBuffer->mWidth * mframeBuffer->mHeight;
	std::fill_n(mframeBuffer->mColorBuffer, size, RGBA(0, 0, 0, 0));
}

void GPU::drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color)
{
	if (x >= mframeBuffer->mWidth || y >= mframeBuffer->mHeight) return;
	uint32_t pixelPos=y*mframeBuffer->mWidth+x;
    mframeBuffer->mColorBuffer[pixelPos]=color;
}

void GPU::drawLine(const Point& p1, const Point& p2)
{
	std::vector<Point> pixels;
	Raster::rasterLine(pixels, p1, p2);
	for (Point p : pixels)
	{
		drawPoint(p.x, p.y, p.color);
	}
}
