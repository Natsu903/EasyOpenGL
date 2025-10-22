#pragma once
#include "../application/application.h"
#include "../gpu/frameBuffer.h"

#define sgl GPU::getInstance()

class GPU {
public: 
    static GPU& getInstance();
    GPU();
    ~GPU();

    void initSurface(const uint32_t& width, const uint32_t& height, void* buffer = nullptr);

    void clear();

    void drawPoint(const uint32_t& x, const uint32_t& y, const RGBA& color);

private:
    static GPU* instance;
    FrameBuffer* mframeBuffer{ nullptr };
};
