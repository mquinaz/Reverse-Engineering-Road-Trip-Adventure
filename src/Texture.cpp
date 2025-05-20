#include "Texture.hpp"
#include "File.hpp"

#include <cstdint>
#include <cmath>
#include <set>

//std::set<uint8_t[16]> pixelFlag = {"0x1012","0x1040","0x1087"};

Texture::Texture(const std::string path)
{
    
}

void Texture::process()
{
    File f = File("/run/media/quinaz/ROAD_TRIP_ADVENTURE/car0/q00_07.bin");
    
    uint32_t index = 0;
    while(true)
    {
        chunkSize = f.readUint() >> 16;
        f.seek(-4, 1);
        break;
    }
}

uint8_t* Texture::rgba32(uint32_t rawPixel)
{
    uint8_t t[4];
    t[0] = rawPixel & 0xFF;
    t[1] = (rawPixel >> 8) & 0xFF;
    t[2] = (rawPixel >> 16)  & 0xFF;
    t[3] = std::min(((rawPixel >> 24) & 0xFF)*2, (unsigned) 255);
    return t;
}